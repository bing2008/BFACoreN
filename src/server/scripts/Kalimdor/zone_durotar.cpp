/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ObjectMgr.h"

/*######
## Quest 37446: Lazy Peons
## npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = 0
};

enum LazyPeon
{
    QUEST_LAZY_PEONS    = 37446,
    GO_LUMBERPILE       = 175784,
    SPELL_BUFF_SLEEP    = 17743,
    SPELL_AWAKEN_PEON   = 19938
};

class npc_lazy_peon : public CreatureScript
{
public:
    npc_lazy_peon() : CreatureScript("npc_lazy_peon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lazy_peonAI(creature);
    }

    struct npc_lazy_peonAI : public ScriptedAI
    {
        npc_lazy_peonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            RebuffTimer = 0;
            work = false;
        }

        uint32 RebuffTimer;
        bool work;

        void Reset() override
        {
            Initialize();
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id != SPELL_AWAKEN_PEON)
                return;

            Player* player = caster->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                Talk(SAY_SPELL_HIT, caster);
                me->RemoveAllAuras();
                if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
                    me->GetMotionMaster()->MovePoint(1, Lumberpile->GetPositionX()-1, Lumberpile->GetPositionY(), Lumberpile->GetPositionZ());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (work == true)
                me->HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);
            if (RebuffTimer <= diff)
            {
                DoCast(me, SPELL_BUFF_SLEEP);
                RebuffTimer = 300000; //Rebuff agian in 5 minutes
            }
            else
                RebuffTimer -= diff;
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }
    };
};

enum VoodooSpells
{
    SPELL_BREW      = 16712, // Special Brew
    SPELL_GHOSTLY   = 16713, // Ghostly
    SPELL_HEX1      = 16707, // Hex
    SPELL_HEX2      = 16708, // Hex
    SPELL_HEX3      = 16709, // Hex
    SPELL_GROW      = 16711, // Grow
    SPELL_LAUNCH    = 16716, // Launch (Whee!)
};

// 17009
class spell_voodoo : public SpellScriptLoader
{
    public:
        spell_voodoo() : SpellScriptLoader("spell_voodoo") { }

        class spell_voodoo_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voodoo_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_BREW,
                    SPELL_GHOSTLY,
                    SPELL_HEX1,
                    SPELL_HEX2,
                    SPELL_HEX3,
                    SPELL_GROW,
                    SPELL_LAUNCH
                });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellid = RAND(SPELL_BREW, SPELL_GHOSTLY, RAND(SPELL_HEX1, SPELL_HEX2, SPELL_HEX3), SPELL_GROW, SPELL_LAUNCH);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, spellid, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_voodoo_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_voodoo_SpellScript();
        }
};

/*######
## Quest 25205: The Wolf and The Kodo
## spell_rumbling_hooves_73868
######*/
class spell_rumbling_hooves_73868 : public SpellScriptLoader
{
public:
    spell_rumbling_hooves_73868() : SpellScriptLoader("spell_rumbling_hooves_73868") { }

    class IsEntry
    {
    public:
        explicit IsEntry(uint32 entry) : _entry(entry) { }

        bool operator()(WorldObject* obj) const
        {
            if (Creature* target = obj->ToCreature())
                return target->GetEntry() == _entry;

            return true;
        }

    private:
        uint32 _entry;
    };

    class spell_rumbling_hooves_73868_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rumbling_hooves_73868_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(IsEntry(GetCaster()->GetEntry()));
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rumbling_hooves_73868_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rumbling_hooves_73868_SpellScript();
    }
};

enum quests{
    QUEST_LOST_IN_THE_FLOODS = 25187,
};

// thonk spyglass - 73817
class spell_thonk_spyglass :public SpellScript
{
    PrepareSpellScript(spell_thonk_spyglass);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Player* player = caster->ToPlayer();
        if (!player)
            return;

        if (!(player->GetQuestStatus(QUEST_LOST_IN_THE_FLOODS) == QUEST_STATUS_INCOMPLETE))
            return;

        if (!player->GetQuestObjectiveData(QUEST_LOST_IN_THE_FLOODS, 0))
        {
            player->CastSpell(player, 73741);
            return;
        }
        if (!player->GetQuestObjectiveData(QUEST_LOST_IN_THE_FLOODS, 1))
        {
            player->CastSpell(player, 73763);
            return;
        }
        if (!player->GetQuestObjectiveData(QUEST_LOST_IN_THE_FLOODS, 2))
        {
            player->CastSpell(player, 73764);
            return;
        }
        if (!player->GetQuestObjectiveData(QUEST_LOST_IN_THE_FLOODS, 3))
        {
            player->CastSpell(player, 73765);
            return;
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_thonk_spyglass::HandleAfterCast);
    }
};

// 39464
class npc_drowned_thunder_lizard_39464 : public CreatureScript
{
public:
    npc_drowned_thunder_lizard_39464() : CreatureScript("npc_drowned_thunder_lizard_39464") { }

    enum eQuest
    {
        QUEST_THUNDER_DOWN_UNDER = 25236,
        NPC_THUNDER_LIZARD = 39464,
        NPC_HULKING_ORCISH_LABORER = 39465,
        SPELL_ATTACH_TETHER = 73945,
        SPELL_LIFT_DROWNED_THUNDER_LIZARD_TARGET = 73950,
        SPELL_LIFT_DROWNED_THUNDER_LIZARD = 73951,
        SPELL_LIGHTNING_DISCHARGE = 73958,
        EVENT_WAIT_ON_HULK = 101,
        EVENT_LIGHTNING_DISCHARGE,
        EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET1,
        EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET2,
        EVENT_RESET_FOR_HULK,
    };

    struct npc_drowned_thunder_lizard_39464AI : public ScriptedAI
    {
        npc_drowned_thunder_lizard_39464AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        EventMap m_events;
        ObjectGuid   m_hulkGUID;
        ObjectGuid   m_playerGUID;
        bool m_isWorking;
        std::list<Position> m_hulkList;

        void Initialize()
        {
            m_hulkGUID = ObjectGuid::Empty;
            m_playerGUID = ObjectGuid::Empty;
            FillHulkPositionList();
        }

        void Reset() override
        {
            m_events.Reset();
            m_events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(20000, 60000));
            m_isWorking = false;
        }

        void OnSpellClick(Unit* clicker, bool& result)
        {
            if (!m_isWorking)
                if (Player* player = clicker->ToPlayer())
                    if (player->GetQuestStatus(QUEST_THUNDER_DOWN_UNDER) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_isWorking = true;
                        m_playerGUID = player->GetGUID();
                        m_events.ScheduleEvent(EVENT_WAIT_ON_HULK, 250);
                        m_events.ScheduleEvent(EVENT_RESET_FOR_HULK, 10000);
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LIGHTNING_DISCHARGE:
                {
                    me->CastSpell(me, SPELL_LIGHTNING_DISCHARGE);
                    m_events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(10000, 15000));
                    break;
                }
                case EVENT_WAIT_ON_HULK:
                {
                    if (Creature* hulk = me->FindNearestCreature(NPC_HULKING_ORCISH_LABORER, 15.0f))
                    {
                        m_hulkGUID = hulk->GetGUID();
                        Position pos = FindBestHulkPosition(hulk->GetPosition());
                        hulk->NearTeleportTo(pos.m_positionX, pos.m_positionY, pos.m_positionZ, pos.GetOrientation(), true);
                        m_events.ScheduleEvent(EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET1, 25);
                    }
                    else
                        m_events.ScheduleEvent(EVENT_WAIT_ON_HULK, 100);

                    break;
                }
                case EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET1:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* hulk = ObjectAccessor::GetCreature(*me, m_hulkGUID))
                        {
                            hulk->CastSpell(me, SPELL_LIFT_DROWNED_THUNDER_LIZARD, true);
                            hulk->CastSpell(hulk, SPELL_LIFT_DROWNED_THUNDER_LIZARD_TARGET, true);
                        }

                    m_events.ScheduleEvent(EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET2, 2000);
                    break;
                }
                case EVENT_LIFT_DROWNED_THUNDER_LIZARD_TARGET2:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* hulk = ObjectAccessor::GetCreature(*me, m_hulkGUID))
                        {
                            Position pos = me->GetPosition();
                            pos.m_positionZ = 12.0f;
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                            me->SetSpeed(MOVE_RUN, 0.15f);
                            //me->GetMotionMaster()->MoveTakeoff(101, pos);
                            me->GetMotionMaster()->MoveFollow(hulk, 5, 0);
                            me->DespawnOrUnsummon(10000);
                            hulk->DespawnOrUnsummon(10000);
                        }
                    break;
                }
                case EVENT_RESET_FOR_HULK:
                {
                    Reset();
                    break;
                }
                }
            }
        }

        Position FindBestHulkPosition(Position pos)
        {
            float dist = 500.0f;
            Position newPos;
            for (std::list<Position>::iterator itr = m_hulkList.begin(); itr != m_hulkList.end(); ++itr)
            {
                Position p = (*itr);
                float d = p.GetExactDist2d(pos.m_positionX, pos.m_positionY);
                if (d < dist)
                {
                    dist = d;
                    newPos = p;
                }
            }
            return newPos;
        }

        void FillHulkPositionList()
        {
            m_hulkList.clear();
            m_hulkList.push_back(Position(761.681519f, -4114.352539f, 27.533762f, 1.669859f));
            m_hulkList.push_back(Position(789.240173f, -4105.788574f, 26.680470f, 1.956528f));
            m_hulkList.push_back(Position(843.065918f, -4059.360596f, 27.911030f, 2.596630f));
            m_hulkList.push_back(Position(769.185669f, -4030.059082f, 26.620789f, 4.336287f));
            m_hulkList.push_back(Position(868.856018f, -4027.161377f, 32.579823f, 3.539107f));
            m_hulkList.push_back(Position(885.622131f, -4024.350342f, 33.658619f, 6.154483f));
            m_hulkList.push_back(Position(921.469360f, -4034.692871f, 36.609566f, 0.256142f));
            m_hulkList.push_back(Position(961.751343f, -4070.507324f, 23.249489f, 2.918641f));
            m_hulkList.push_back(Position(945.061340f, -4078.592041f, 27.331806f, 0.558519f));
            m_hulkList.push_back(Position(941.900757f, -4121.144043f, 23.914780f, 5.867807f));
            m_hulkList.push_back(Position(899.980408f, -4170.012207f, 24.881603f, 1.709126f));
            m_hulkList.push_back(Position(965.486877f, -4204.474121f, 22.279196f, 3.095355f));
            m_hulkList.push_back(Position(940.573730f, -4231.450195f, 20.181242f, 5.592918f));
            m_hulkList.push_back(Position(905.344482f, -4176.950195f, 26.277588f, 0.307187f));
            m_hulkList.push_back(Position(972.444702f, -4222.325684f, 22.747892f, 3.550868f));
            m_hulkList.push_back(Position(801.102844f, -4089.484619f, 25.795090f, 4.882112f));
            m_hulkList.push_back(Position(810.994995f, -4087.808594f, 25.023535f, 5.612078f));
            m_hulkList.push_back(Position(829.534973f, -4022.998779f, 20.646587f, 4.626402f));
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drowned_thunder_lizard_39464AI(creature);
    }
};

enum UnbiddenVisitors {
    QUEST_UNBIDDEN_VISITORS = 25194,
    SPELL_WATER_WALK = 73757,
    NPC_CREDIT = 39336,
};

struct npc_wayward_plainstrider : public ScriptedAI
{
    npc_wayward_plainstrider(Creature* pCreature) : ScriptedAI(pCreature){}

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (Player* player = attacker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_UNBIDDEN_VISITORS) == QUEST_STATUS_INCOMPLETE)
            {
                if (me->GetHealth() - damage < me->GetHealth() * 0.4)
                {
                    me->AddAura(SPELL_WATER_WALK);
                    player->KilledMonsterCredit(NPC_CREDIT);
                    me->SetFlag(UNIT_FIELD_FLAGS, 8388608);
                    me->AI()->EnterEvadeMode();
                    // todo sniff all positions and make them go to the closest
                    me->GetMotionMaster()->MovePoint(0, 308.72f, -3752, 16.3f);
                    me->ForcedDespawn(15000);
                    damage = 0;
                }
            }
        }
    }

};

enum ElementalSparring {
    NPC_WATER_ELEMENTAL = 39596,
    NPC_EARTH_ELEMENTAL = 39595,
};

//todo make them fight

struct npc_water_elemental : public ScriptedAI
{
    npc_water_elemental(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset() override
    {
        sparing = true;
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (Creature* creature = attacker->ToCreature())
            if (creature->GetEntry() != NPC_EARTH_ELEMENTAL)
                sparing = false;
        if (attacker->IsPlayer())
            sparing = false;


        if (sparing && me->GetHealthPct() < 80)
        {
            damage = 0;
        }
    }

private:
    bool sparing = true;
};

struct npc_earth_elemental : public ScriptedAI
{
    npc_earth_elemental(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset() override
    {
        sparing = true;
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (Creature* creature = attacker->ToCreature())
            if (creature->GetEntry() != NPC_EARTH_ELEMENTAL)
                sparing = false;
        if (attacker->IsPlayer())
            sparing = false;

        if (sparing && me->GetHealthPct() < 80)
        {
            damage = 0;
        }
    }

private:
    bool sparing = false;
};


void AddSC_durotar()
{
    new npc_lazy_peon();
    new spell_voodoo();
    new spell_rumbling_hooves_73868();
    RegisterSpellScript(spell_thonk_spyglass);
    new npc_drowned_thunder_lizard_39464();
    RegisterCreatureAI(npc_wayward_plainstrider);
    RegisterCreatureAI(npc_water_elemental);
    RegisterCreatureAI(npc_earth_elemental);
}
