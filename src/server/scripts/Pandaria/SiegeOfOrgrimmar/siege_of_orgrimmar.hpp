#ifndef SIEGE_OF_ORGRIMMAR_HPP
# define SIEGE_OF_ORGRIMMAR_HPP

#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

# define MAX_FALLEN_PROTECTORS 3
# define MAX_KORKRON_DARK_SHAMANS 2
# define MAX_PARAGONS_OF_THE_KLAXXI 9

enum Data
{
    // First part
    DATA_IMMERSEUS              = 0,
    DATA_FALLEN_PROTECTORS      = 1,
    DATA_NORUSHEN               = 2,
    DATA_SHA_OF_PRIDE           = 3,

    // Second part
    DATA_GALAKRAS               = 4,
    DATA_IRON_JUGGERNAUT        = 5,
    DATA_KORKRON_DARK_SHAMANS   = 6,
    DATA_GENERAL_NAZGRIM        = 7,

    // Third part
    DATA_MALKOROK               = 8,
    DATA_SPOILS_OF_PANDARIA     = 9,
    DATA_THOK_THE_BLOODTHIRSTY  = 10,

    // Last part
    DATA_SIEGECRAFTER_BLACKFUSE = 11,
    DATA_PARAGONS_OF_THE_KLAXXI = 12,
    DATA_GARROSH_HELLSCREAM     = 13,

    DATA_MAX_BOSS_DATA          = 14,

    DATA_SWIRL_TARGET,

    DATA_LOREWALKER_CHO_1,
    DATA_LOREWALKER_CHO_2,
    DATA_LOREWALKER_CHO_INTRO,
    DATA_LOREWALKER_CHO_INTRO_IMMERSEUS,

    DATA_ROOK_STONETOE,
    DATA_HE_SOFTFOOT,
    DATA_SUN_TENDERHEART,

    DATA_VANITY,
    DATA_ARROGANCE,
    DATA_ZEAL,

    DATA_PRESSURE_PLATE_EVENT,

    DATA_TEARS_OF_THE_VALE_10N,
    DATA_TEARS_OF_THE_VALE_25N,
    DATA_TEARS_OF_THE_VALE_10H,
    DATA_TEARS_OF_THE_VALE_25H,

    DATA_AMALGAM_OF_CORRUPTION,

    DATA_LIGHT_CONTAINMENT_1,
    DATA_LIGHT_CONTAINMENT_2,
    DATA_LIGHT_CONTAINMENT_3,
    DATA_LIGHT_CONTAINMENT_4,
    DATA_LIGHT_CONTAINMENT_TOP,
    DATA_LIGHT_CONTAINMENT_BOTTOM,

    DATA_WEST_SHADOW_PRISON,
    DATA_WEST_SHADOW_PRISON_A,
    DATA_WEST_SHADOW_PRISON_B,
    DATA_WEST_SHADOW_PRISON_C,

    DATA_NORTH_SHADOW_PRISON,
    DATA_NORTH_SHADOW_PRISON_A,
    DATA_NORTH_SHADOW_PRISON_B,
    DATA_NORTH_SHADOW_PRISON_C,

    DATA_EAST_SHADOW_PRISON,
    DATA_EAST_SHADOW_PRISON_A,
    DATA_EAST_SHADOW_PRISON_B,
    DATA_EAST_SHADOW_PRISON_C,

    DATA_SOUTH_SHADOW_PRISON,
    DATA_SOUTH_SHADOW_PRISON_A,
    DATA_SOUTH_SHADOW_PRISON_B,
    DATA_SOUTH_SHADOW_PRISON_C,

    DATA_SHA_OF_PRIDE_NORUSHEN,

    DATA_VAULT_OF_FORBIDDEN_TREASURES_10,
    DATA_VAULT_OF_FORBIDDEN_TREASURES_25,
    DATA_VAULT_OF_FORBIDDEN_TREASURES_10H,
    DATA_VAULT_OF_FORBIDDEN_TREASURES_25H,

    DATA_BEACH_CAPTURED,

    DATA_TEAM_IN_INSTANCE,

    DATA_FIRST_GALAKRAS_INTRO,
    DATA_KORKRON_CANNON_DESTROYED,
    DATA_START_GALAKRAS,
    DATA_RESET_GALAKRAS,
    DATA_WARLORD_ZAELA,

    DATA_VOLJIN_1,
    DATA_BAINE_BLOODHOOF_1,
    DATA_IRON_JUGGERNAUT_START,
    DATA_IRON_JUGGERNAUT_DEAD,

    DATA_EARTHBREAKER_HAROMM,
    DATA_WAVEBINDER_KARDRIS,
    DATA_AYSA_CLOUDSINGER,
    DATA_JI_FIREPAW,
    DATA_OVERSEER_KOMAK,

    DATA_UNLOCKED_STOCKPILE_10,
    DATA_UNLOCKED_STOCKPILE_25,
    DATA_UNLOCKED_STOCKPILE_10H,
    DATA_UNLOCKED_STOCKPILE_25H,
    DATA_SPOILS_OF_PANDARIA_GATE_NORTH,
    DATA_SPOILS_OF_PANDARIA_GATE_WEST,
    DATA_SPOILS_OF_PANDARIA_GATE_SOUTH,
    DATA_SPOILS_OF_PANDARIA_GATE_EAST,
    DATA_SPOILS_OF_PANDARIA_GATE_NORTH_WEST,
    DATA_SPOILS_OF_PANDARIA_GATE_SOUTH_EAST,
    DATA_SPOILS_OF_PANDARIA_LEVER_NORTH,
    DATA_SPOILS_OF_PANDARIA_LEVER_WEST,
    DATA_SPOILS_OF_PANDARIA_LEVER_SOUTH,
    DATA_SPOILS_OF_PANDARIA_LEVER_EAST,

    DATA_THOK_THE_BLOODTHRISTY_INTRO,
    DATA_ENRAGED_MUSHAN_BEAST,
    DATA_STARVED_YETTI,
    DATA_SAUROK_PRISON_1,
    DATA_SAUROK_PRISON_2,
    DATA_YAUNGOL_PRISON_1,
    DATA_YAUNGOL_PRISON_2,
    DATA_JINYU_PRISON_1,
    DATA_JINYU_PRISON_2,

    DATA_BLACKFUSE_INTRO,

    DATA_GARROSH_HELLSCREAM_INTRO,
    DATA_GARROSH_HELLSCREAM_ENERGY,
};

enum Creatures
{
    NPC_LOREWALKER_CHO_1                = 73330, // near entrance and immerseus
    NPC_LOREWALKER_CHO_2                = 72872, // near sha of pride

    NPC_VANITY                          = 72662,
    NPC_ARROGANCE                       = 72663,
    NPC_ZEAL                            = 72661,
    NPC_PRESSURE_PLATE                  = 73124,

    // Immerseus
    NPC_IMMERSEUS                       = 71543,
    NPC_SWIRL_TARGET                    = 71550,

    // Fallen Protectors
    NPC_ROOK_STONETOE                   = 71475,
    NPC_HE_SOFTFOOT                     = 71479,
    NPC_SUN_THUNDERHEART                = 71480,

    // Norushen
    NPC_NORUSHEN                        = 71967,
    NPC_AMALGAM_OF_CORRUPTION           = 72276,
    NPC_SUN_TENDERHEART_1               = 72000, // in the healer's test

    // Sha of Pride
    NPC_SHA_OF_PRIDE                    = 71734,
    NPC_NORUSHEN_1                      = 71965, // near sha of pride, he is not a boss
    NPC_LINGERING_CORRUPTION            = 72791, // mobs that triggers sha of pride

    NPC_LORTHEMAR_THERON_1              = 73605, // after sha's death
    NPC_JAINA_PROUDMOORE_1              = 73598, // after sha's death
    NPC_PORTAL_TO_ORGRIMMAR_1           = 73535,
    NPC_PORTAL_TO_ORGRIMMAR_2           = 73536,

    // Galakras
    NPC_GALAKRAS                        = 72249,
    NPC_WARLORD_ZAELA                   = 72248,
    NPC_JAINA_PROUDMOORE_2              = 72302,
    NPC_KING_VARIAN_WRYNN_2             = 72311,
    NPC_SYLVANAS_WINDRUNNER_2           = 72561,
    NPC_LORTHEMAR_THERON_2              = 72560,
    NPC_AETHAS_SUNREAVER                = 73909,

    // Iron Juggernaut
    NPC_IRON_JUGGERNAUT                 = 71466,
    NPC_VOLJIN_1                        = 73942, // before the boss
    NPC_BAINE_BLOODHOOF_1               = 73941, // before the boss

    // Kor'Kron Dark Shamans
    NPC_EARTHBREAKER_HAROMM             = 71859,
    NPC_WAVEBINDER_KARDIS               = 71858,
    NPC_AYSA_CLOUDSINGER                = 72438,
    NPC_JI_FIREPAW                      = 72454,
    NPC_OVERSEER_KOMAK                  = 72455,

    // General Nazgrim
    NPC_GENERAL_NAZGRIM                 = 71515,

    // Malkorok
    NPC_MALKOROK                        = 71454,

    // Spoils ofPandaria
    NPC_SECURED_STOCKPILE_OF_PANDAREN_SPOILS = 71889,

    // Thok the Bloothirsty
    NPC_THOK_THE_BLOODTHIRSTY           = 71529,

    // Siegecrafter Blackfuse
    NPC_SIEGECRAFTER_BLACKFUSE          = 71504,

    // Paragons of the Klaxxi
    NPC_KLAXXI_PARAGONS                 = 71592, // controller 1588.356, -5683.408, -269.9715, 0.5899213
    NPC_KILRUK_THE_WIND_REAVER          = 71161,
    NPC_XARIL_THE_POISONED_MIND         = 71157,
    NPC_KAZTIK_THE_MANIPULATOR          = 71156,
    NPC_KORVEN_THE_PRIME                = 71155,
    NPC_IYYOKUK_THE_LUCID               = 71160,
    NPC_KAROZ_THE_LOCUST                = 71154,
    NPC_SKEER_THE_BLOODSEEKER           = 71152,
    NPC_RIKKAL_THE_DISSECTOR            = 71158,
    NPC_HISEK_THE_SWARMKEEPER           = 71153,

    // Garrosh Hellscream
    NPC_GARROSH_HELLSCREAM              = 71865,

    NPC_THRALL_1                        = 73483, // for the Garrosh' intro
    NPC_THRALL_2                        = 73591, // for the Garrosh' outro

    NPC_KING_VARIAN_WRYNN               = 73592,
    NPC_LADY_JAINA_PROUDMOORE           = 73598,
    NPC_ANDUIN_WRYNN                    = 73607,
    NPC_TYRANDE_WHISPERWIND             = 74216,
    NPC_MOIRA_THAURISSAN                = 70279,
    NPC_HIGH_TINKER_MEKKATORQUE         = 74217,
    NPC_IRONFORGE_GUARD                 = 74218,
    NPC_DARNASSUS_SENTINEL              = 74219,
    NPC_STORMWIND_ROYAL_GUARD           = 73600,
    NPC_LADY_SYLVANAS_WINDRUNNER        = 73606,
    NPC_LORTHEMAR_THERON                = 73605,
    NPC_VOLJIN                          = 73597,
    NPC_TRADE_PRINCE_GALLYWIX           = 73604,
    NPC_BAINE_BLOODHOOF                 = 73603,
    NPC_ORGRIMMAR_GRUNT                 = 73602,
    NPC_TARAN_ZHU                       = 73593,
    NPC_LOREWALKER_CHO_3                = 73318,

};

enum GameObjects
{
    GO_PRESSURE_PLATE_DOOR      = 221663,   ///< Pressure Plate Event Door
    GO_IMMERSEUS_DOOR           = 221245,
    GO_SHA_ENERGY_WALL          = 221602,   // fallen protectors
    GO_MYSTERIOUS_ORNATE_DOOR   = 221620,

    GO_TEARS_OF_THE_VALE_10N    = 221776,
    GO_TEARS_OF_THE_VALE_25N    = 223236,
    GO_TEARS_OF_THE_VALE_10H    = 223237,
    GO_TEARS_OF_THE_VALE_25H    = 223238,

    GO_TEARS_OF_THE_VALE_1      = 232092, // in which difficulty ?
    GO_TEARS_OF_THE_VALE_2      = 232093, // in which difficulty ?
    GO_TEARS_OF_THE_VALE_3      = 233028, // in which difficulty ?

    GO_NORUSHEN_EXIT            = 221447,

    GO_LIGHT_CONTAINMENT_1      = 223142,
    GO_LIGHT_CONTAINMENT_2      = 223143,
    GO_LIGHT_CONTAINMENT_3      = 223144,
    GO_LIGHT_CONTAINMENT_4      = 223145,
    GO_LIGHT_CONTAINMENT_TOP    = 223146,
    GO_LIGHT_CONTAINMENT_BOTTOM = 223147,

    GO_PRIDE_ENTRANCE           = 221446,

    GO_WEST_SHADOW_PRISON       = 221676,
    GO_NORTH_SHADOW_PRISON      = 221677,
    GO_EAST_SHADOW_PRISON       = 221678,
    GO_SOUTH_SHADOW_PRISON      = 221679,

    GO_WEST_SHADOW_PRISON_A     = 221758,
    GO_WEST_SHADOW_PRISON_B     = 221759,
    GO_WEST_SHADOW_PRISON_C     = 221757,

    GO_NORTH_SHADOW_PRISON_A    = 221755,
    GO_NORTH_SHADOW_PRISON_B    = 221750,
    GO_NORTH_SHADOW_PRISON_C    = 221754,

    GO_EAST_SHADOW_PRISON_A     = 221753,
    GO_EAST_SHADOW_PRISON_B     = 221751,
    GO_EAST_SHADOW_PRISON_C     = 221752,

    GO_SOUTH_SHADOW_PRISON_A    = 221761,
    GO_SOUTH_SHADOW_PRISON_B    = 221760,
    GO_SOUTH_SHADOW_PRISON_C    = 221756,

    GO_VAULT_OF_FORBIDDEN_TREASURES_10 = 221739,
    GO_VAULT_OF_FORBIDDEN_TREASURES_25 = 221740,
    GO_VAULT_OF_FORBIDDEN_TREASURES_10H = 221741,
    GO_VAULT_OF_FORBIDDEN_TREASURES_25H = 221742,

    GO_MINOR_PORTAL             = 221522,

    GO_WIND_DOOR                = 223219, // Iron Juggernaut entrance

    GO_ORGRIMMAR_FRONT_GATE     = 223120, // Iron Juggernaut exit
    GO_GATES_OF_ORGRIMMAR       = 223739, // Iron Juggernaut exit
    GO_OGRAID_FRONT_GATE_BACK   = 223814, // Before Dark Shamans
    GO_RUSTED_IRON_PORTCULLIS   = 223231, // After Dark Shamans
    GO_NAZGRIM_ENTRY_DOOR       = 223276, // General Nazgrim entrance

    GO_MASSIVE_IRONBOUND_DOOR_1 = 221793, // General Nazgrim exit

    GO_ORGRIMMAR_ELEVATOR       = 220364, // After General Nazgrim

    GO_MASSIVE_IRONBOUND_DOOR_4 = 221622, // After Malkorok
    GO_MASSIVE_IRONBOUND_DOOR_5 = 221911, // After Malkorok
    GO_MASSIVE_IRONBOUND_DOOR_2 = 223056, // Spoils of Pandaria entrance

    // Spoils of Pandaria objects
    GO_IRON_GATE_NORTH                  = 221798,
    GO_IRON_GATE_EAST                   = 221800,
    GO_IRON_GATE_WEST                   = 221799,
    GO_IRON_GATE_SOUTH                  = 221801,
    GO_IRON_GATE_NORTH_WEST             = 223032,
    GO_IRON_GATE_SOUTH_EAST             = 223033,
    GO_IRON_GATE_OUT_1                  = 221796,
    GO_IRON_GATE_OUT_2                  = 221797,
    GO_IRON_GATE_OUT_3                  = 221795,
    GO_IRON_GATE_OUT_4                  = 221794,

    GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_10    = 222749,
    GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_25    = 222750,
    GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_10H   = 222751,
    GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_25H   = 222752,

    GO_SECURED_STOCKPILE                    = 220823,
    GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_NORTH  = 221771,
    GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_WEST   = 221773,
    GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_SOUTH  = 221772,
    GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_EAST   = 221774,
    // north
    GO_CRATE_OF_PANDAREN_RELICS_1       = 221878,
    GO_CRATE_OF_PANDAREN_RELICS_2       = 221879,
    // south
    GO_CRATE_OF_PANDAREN_RELICS_3       = 221880,
    GO_CRATE_OF_PANDAREN_RELICS_4       = 221881,
    // west
    GO_CRATE_OF_PANDAREN_RELICS_5       = 222691,
    GO_CRATE_OF_PANDAREN_RELICS_6       = 222692,
    // east
    GO_CRATE_OF_PANDAREN_RELICS_7       = 222693,
    GO_CRATE_OF_PANDAREN_RELICS_8       = 222694,
    // Crates in north room
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_1      = 221807,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_2      = 221832,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_3      = 221833,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_4      = 221835,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_5      = 221836,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_6      = 221837,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_7      = 221839,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_8      = 221840,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_9      = 221841,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_10     = 221842,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_11     = 221843,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_12     = 221844,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_13     = 221845,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_14     = 221846,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_15     = 221847,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_16     = 221848,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_17     = 221851,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_18     = 221852,
    // Crates in east room
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_19     = 221882,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_20     = 221883,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_21     = 221884,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_22     = 221886,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_23     = 221894,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_24     = 221896,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_25     = 221898,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_26     = 221900,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_27     = 221901,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_28     = 221902,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_29     = 221903,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_30     = 221904,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_31     = 221905,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_32     = 221906,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_33     = 221907,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_34     = 221908,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_35     = 221909,
    GO_LIGHTWEIGHT_CRATE_OF_MOGU_36     = 221910,
    // Crates in north room
    GO_STOUT_CRATE_OF_MOGU_1            = 221805,
    GO_STOUT_CRATE_OF_MOGU_2            = 221830,
    GO_STOUT_CRATE_OF_MOGU_3            = 221834,
    GO_STOUT_CRATE_OF_MOGU_4            = 221838,
    GO_STOUT_CRATE_OF_MOGU_5            = 221849,
    GO_STOUT_CRATE_OF_MOGU_6            = 221850,
    // Crates in east room
    GO_STOUT_CRATE_OF_MOGU_7            = 221887,
    GO_STOUT_CRATE_OF_MOGU_8            = 221888,
    GO_STOUT_CRATE_OF_MOGU_9            = 221889,
    GO_STOUT_CRATE_OF_MOGU_10           = 221890,
    GO_STOUT_CRATE_OF_MOGU_11           = 221892,
    GO_STOUT_CRATE_OF_MOGU_12           = 221893,
    // Crates in north room
    GO_MASSIVE_CRATE_OF_MOGU_1          = 221803,
    GO_MASSIVE_CRATE_OF_MOGU_2          = 221831,
    // Crates in east room
    GO_MASSIVE_CRATE_OF_MOGU_3          = 221885,
    GO_MASSIVE_CRATE_OF_MOGU_4          = 221891,
    // Crates in south room
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_1    = 221806,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_2    = 221808,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_3    = 221809,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_4    = 221810,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_5    = 221812,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_6    = 221813,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_7    = 221814,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_8    = 221815,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_9    = 221818,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_10   = 221819,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_11   = 221822,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_12   = 221823,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_13   = 221824,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_14   = 221826,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_15   = 221827,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_16   = 221828,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_17   = 221829,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_18   = 221854,
    // Crates in west room
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_19   = 221856,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_20   = 221858,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_21   = 221861,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_22   = 221862,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_23   = 221863,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_24   = 221864,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_25   = 221865,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_26   = 221866,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_27   = 221868,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_28   = 221869,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_29   = 221870,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_30   = 221871,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_31   = 221872,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_32   = 221873,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_33   = 221876,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_34   = 221877,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_35   = 223224,
    GO_LIGHTWEIGHT_CRATE_OF_MANTID_36   = 223245,
    // Crates in south room
    GO_STOUT_CRATE_OF_MANTID_1          = 221802,
    GO_STOUT_CRATE_OF_MANTID_2          = 221811,
    GO_STOUT_CRATE_OF_MANTID_3          = 221816,
    GO_STOUT_CRATE_OF_MANTID_4          = 221817,
    GO_STOUT_CRATE_OF_MANTID_5          = 221820,
    GO_STOUT_CRATE_OF_MANTID_6          = 221821,
    // Crates in west room
    GO_STOUT_CRATE_OF_MANTID_7          = 221853,
    GO_STOUT_CRATE_OF_MANTID_8          = 221857,
    GO_STOUT_CRATE_OF_MANTID_9          = 221860,
    GO_STOUT_CRATE_OF_MANTID_10         = 221867,
    GO_STOUT_CRATE_OF_MANTID_11         = 221874,
    GO_STOUT_CRATE_OF_MANTID_12         = 221875,
    // Crates in south room
    GO_MASSIVE_CRATE_OF_MANTID_1        = 221804,
    GO_MASSIVE_CRATE_OF_MANTID_2        = 221825,
    // Crates in west room
    GO_MASSIVE_CRATE_OF_MANTID_3        = 221855,
    GO_MASSIVE_CRATE_OF_MANTID_4        = 221859,

    GO_MASSIVE_IRONBOUND_DOOR_3         = 223058, // Spoils of Pandaria exit

    GO_OGRAID_LARGE_DOOR                = 223805, // Thok the Bloodthristy entrance/exit
    GO_TREX_DOOR                        = 223222, // Thok's cage
    GO_SAUROK_PRISON_1                  = 222046,
    GO_SAUROK_PRISON_2                  = 222047,
    GO_YAUNGOL_PRISON_1                 = 223005,
    GO_YAUNGOL_PRISON_2                 = 223006,
    GO_JINYU_PRISON_1                   = 222010,
    GO_JINYU_PRISON_2                   = 222011,

    GO_MASSIVE_IRONBOUND_DOOR_6         = 223057, // Siegeworks entrance

    GO_MASSIVE_IRONBOUND_DOOR_7         = 221912, // to paragons after Blackfuse

    GO_MASSIVE_IRONBOUND_DOOR_8         = 223235, // after paragons

    GO_SANCTUM_DOOR                     = 221792,

    GO_ENTRANCE_1                       = 221438, // gobject in the Garosh' room ?
    GO_ENTRANCE_2                       = 221441, // gobject in the Garosh' room ?
    GO_SOUTH_EAST_DOOR                  = 221439, // gobject in the Garosh' room ?
    GO_SOUTH_WEST_DOOR                  = 221440, // gobject in the Garosh' room ?

};

enum ShadowPrisons : uint8
{
    SHADOW_PRISON_WEST  = 0,
    SHADOW_PRISON_NORTH = 1,
    SHADOW_PRISON_EAST  = 2,
    SHADOW_PRISON_SOUTH = 3,

    MAX_SHADOW_PRISONS  = 4,
};

enum ShadowPrisonTraps : uint8
{
    SHADOW_PRISON_TRAP_A    = 0,
    SHADOW_PRISON_TRAP_B    = 1,
    SHADOW_PRISON_TRAP_C    = 2,

    MAX_SHADOW_PRISON_TRAPS = 3,
};

enum InstanceSpells
{
    SPELL_GOREHOWL                      = 146058, // a weapon on the floor after sha of pride's death

    SPELL_MINOR_PORTAL                  = 145531,
    SPELL_MINOR_PORTAL_TELEPORT_PLAYER  = 145524, // to teleport players to the docks
    SPELL_TELEPORT_TO_DOCKS             = 149563, // for npcs
    SPELL_MINOR_PORTAL_TELEPORT_NPC     = 149564, // for npcs

    SPELL_PRESSURE_PLATE                = 147626
};

enum InstanceEvents
{
    EVENT_SPAWN_NPC_SHA_OF_PRIDE    = 100,
    EVENT_FIRST_GALAKRAS_INTRO,
    EVENT_SECOND_GALAKRAS_INTRO,
    EVENT_START_GALAKRAS,
    EVENT_PRESSURE_PLATE = 37642
};

enum InstanceActions
{
    ACTION_SHA_OF_PRIDE_JAINA = 100,
    ACTION_SHA_OF_PRIDE_LORTHEMAR,

    ACTION_FIRST_INTRO_GALAKRAS,
    ACTION_SECOND_INTRO_GALAKRAS,
    ACTION_START_GALAKRAS,
    ACTION_RESET_GALAKRAS,
    ACTION_END_GALAKRAS,

    ACTION_IRON_JUGGERNAUT_INTRO,
    ACTION_IRON_JUGGERNAUT_START,
    ACTION_IRON_JUGGERNAUT_DEAD,

    ACTION_THOK_THE_BLOODTHIRSTY_INTRO,

    ACTION_GARROSH_HELLSCREAM_INTRO,
};

enum InstanceScenes
{
    SCENE_SIEGECRAFTER_INTRO_ALLIANCE   = 541,
    SCENE_SIEGECRAFTER_INTRO_HORDE      = 562,
    SCENE_SIEGECRAFTER_PIPE_EJECTION    = 478, // player exits the conveyor
    SCENE_SIEGECRAFTER_PIPE_ENTRANCE    = 508, // player enters the siegeworks
    SCENE_SIEGECRAFTER_ENTRANCE_REJECTION   = 569, // player cannot enter the siegeworks
    SCENE_SIEGECRAFTER_PIPE_EXIT        = 509, // player exits the siegeworks
    SCENE_SIEGECRAFTER_PIPE_TRANSITION  = 476, // player enters the conveyor
    SCENE_SIEGECRAFTER_PIPE_REJECTION   = 497, // player cannot enter the conveyor

};

/*Position npcAfterShaOfPridePos[7] =
{
    { 750.75f, 1131.48f, 356.08f, 1.73f}, // Jaina
    { 740.28f, 1129.70f, 356.08f, 1.73f}, // Lor'themar
    { 744.46f, 1134.51f, 356.08f, 1.73f}, // Gorehowl
    { 785.54f, 1171.07f, 356.08f, 4.14f}, // Portal to Orgrimmar (alliance)
    { 782.49f, 1165.84f, 356.08f, 0.82f}, // Jaina near portal
    { 688.79f, 1151.24f, 356.08f, 5.81f}, // Portal to Orgrimmar (horde)
    { 695.27f, 1146.95f, 356.08f, 2.62f}  // Lor'themar near portal
};*/

/*Position galakrasPlayersPos[3] =
{
    { 1366.50f, -5416.54f, 10.47f, 1.59f}, // alliance intro position
    { 1767.58f, -5265.74f, 6.97f, 2.90f},  // horde intro position
    { 1440.49f, -5015.87f, 12.11f, 1.67f}  // position at the docks
};

Position galakrasNpcPos[4] =
{
    { 1360.96f, -5404.39f, 10.32f, 1.75f}, // jaina moves at the ship
    { 1360.96f, -5404.39f, 10.32f, 4.89f}, // jaina's orientation

    { 1431.70f, -4898.23f, 11.34f, 1.75f}, // jaina/lor'themar position after intro
    { 1421.77f, -4901.12f, 11.36f, 1.76f}  // wrynn/sylvanas position after intro
};*/

/*const Position norushenTeleportPos = { 800.0f, 866.0f, 371.1f, 1.82f };
const Position immersusTeleportPos = { 1459.0883f, 1037.2127f, 340.2553f, 3.12f };
const Position afterIronJuggernautPos = { 1384.97f, -4369.95f, 25.80f, 0.15f };
const Position afterGeneralNazgrimPos = { 1799.07f, -4779.58f, -255.24f, 5.31f };
const Position afterMalkorokPos = { 1982.62f, -5177.68f, -271.88f, 3.74f };
const Position afterParagonsPos = { 1494.18f, -5744.90f, -306.73f, 3.72f };*/

#define GARROSH_FINALE_NPC_COUNT 34
const uint32 garroshFinaleNpcSequence[GARROSH_FINALE_NPC_COUNT] =
{
    NPC_THRALL_2,
    NPC_TARAN_ZHU,
    NPC_LOREWALKER_CHO_3,

    NPC_KING_VARIAN_WRYNN,
    NPC_LADY_JAINA_PROUDMOORE,
    NPC_ANDUIN_WRYNN,
    NPC_TYRANDE_WHISPERWIND,
    NPC_MOIRA_THAURISSAN,
    NPC_HIGH_TINKER_MEKKATORQUE,
    NPC_IRONFORGE_GUARD,
    NPC_DARNASSUS_SENTINEL,
    NPC_STORMWIND_ROYAL_GUARD,
    NPC_LADY_SYLVANAS_WINDRUNNER,
    NPC_LORTHEMAR_THERON,
    NPC_VOLJIN,
    NPC_TRADE_PRINCE_GALLYWIX,
    NPC_BAINE_BLOODHOOF,
    NPC_ORGRIMMAR_GRUNT
};
const Position garroshFinaleNpcPositions[GARROSH_FINALE_NPC_COUNT] =
{
    { 1110.557f, -5709.077f, -317.6185f, 2.382352f }, // Thrall
    { 1120.26f, -5647.049f, -290.4517f, 2.831381f }, // Taran Zhu
    { 1120.625f, -5641.347f, -290.4517f, 3.023815f }, // Lorewalker Cho

    { 1126.637f, -5576.927f, -317.6219f, 3.639089f }, // King Varian Wrynn
    { 1129.066f, -5571.287f, -317.6252f, 3.56244f }, // Lady Jaina Proudmoore
    { 1131.083f, -5580.971f, -317.6332f, 3.519089f }, // Anduin Wrynn
    { 1132.441f, -5583.607f, -317.6338f, 2.819433f }, // Tyrande Whisperwind
    { 1128.094f, -5568.636f, -317.6224f, 3.513577f }, // Moira Thaurissan
    { 1132.447f, -5586.413f, -317.6154f, 3.67496f },  // High Tinker Mekkatorque
    { 1128.246f, -5564.49f, -317.4998f, 3.450823f }, // Ironforge Guard
    { 1133.392f, -5582.204f, -317.6385f, 3.58929f }, // Darnassus Sentinel
    { 1134.354f, -5579.366f, -317.6278f, 4.625327f }, // Stormwind Royal Guard
    { 1134.248f, -5577.13f, -317.6265f, 4.333719f }, // Stormwind Royal Guard
    { 1135.563f, -5578.41f, -317.632f, 4.821605f }, // Stormwind Royal Guard
    { 1133.7f, -5574.863f, -317.6237f, 4.015383f }, // Stormwind Royal Guard
    { 1135.767f, -5576.627f, -317.6319f, 4.821605f }, // Stormwind Royal Guard
    { 1132.384f, -5572.779f, -317.6552f, 3.900164f }, // Stormwind Royal Guard
    { 1136.116f, -5574.278f, -317.6321f, 4.821605f }, // Stormwind Royal Guard
    { 1132.266f, -5570.249f, -317.6196f, 3.74931f }, // Stormwind Royal Guard
    { 1135.535f, -5571.986f, -317.6292f, 3.391848f }, // Stormwind Royal Guard
    { 1131.254f, -5568.151f, -317.6176f, 3.447176f }, // Stormwind Royal Guard
    { 1134.95f, -5569.868f, -317.6263f, 3.219107f }, // Stormwind Royal Guard
    { 1130.806f, -5565.51f, -317.6219f, 3.388714f }, // Stormwind Royal Guard
    { 1134.028f, -5567.306f, -317.6219f, 3.204831f }, // Stormwind Royal Guard
    { 1133.092f, -5564.96f, -317.3969f, 3.168675f }, // Stormwind Royal Guard

    { 1115.558f, -5707.972f, -317.6222f, 2.229297f }, // Lady Sylvanas Windrunner
    { 1096.68f, -5722.994f, -317.6445f, 2.457345f },  // Lor'themar Theron
    { 1106.379f, -5713.292f, -317.6158f, 2.41948f },  // Vol'jin
    { 1119.94f, -5705.496f, -317.6732f, 2.317593f },  // Trade Prince Gallywix
    { 1101.683f, -5718.464f, -317.6143f, 2.362022f }, // Baine Bloodhoof
    { 1126.476f, -5710.087f, -317.6386f, 2.340839f }, // Orgrimmar Grunt
    { 1125.665f, -5713.617f, -317.6606f, 2.796912f }, // Orgrimmar Grunt
    { 1125.898f, -5718.382f, -317.6386f, 2.907503f }, // Orgrimmar Grunt
    { 1124.993f, -5721.679f, -317.6386f, 3.168255f }  // Orgrimmar Grunt
};

void ApplySpellToPlayersInRange(Unit* searcher, uint32 spellId, float range, bool isAura);

enum InstanceWorldStates
{
    WORLDSTATE_SPOILS_OF_PANDARIA_TIMER         = 8381,
    WORLDSTATE_SPOILS_OF_PANDARIA_TIMER_VISUAL  = 8431,
};

class CombatAuraHelper
{
    public:

        explicit CombatAuraHelper(Creature* owner);

        void RegisterCombatAura(uint32 spellId);

        void UnregisterCombatAura(uint32 p_SpellId);

        void UpdateCombatAuras(const uint32 diff);

    private:

        Creature* m_Owner;
        uint32 m_CombatAurasTimer;
        std::list<uint32> m_CombatAuras;
};

#endif
