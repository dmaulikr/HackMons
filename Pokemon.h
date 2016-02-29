#include <string.h>
#include <stdlib.h>

struct Pokemon
{
      char *name;

      int hp;
      int attack;
      int defense;
      int speed;
      int special;
      int accuracy;
      int evasion;

      int type[ 2 ];
      int move[ 4 ];
};

/* enum for Attack and Pokemon Types */
typedef enum { normal, fire, water, electric, grass, ice, fighting, poison, ground, flying, psychic, bug, rock, ghost, dragon, none } types;

struct Pokemon pokemon[ 50 ];

/* Initializes Pokemon Array */
static void initializePokemonStructure()
{
      pokemon[ 3 ].name = "Venusaur";
      pokemon[ 3 ].hp = 363;
      pokemon[ 3 ].attack = 262;
      pokemon[ 3 ].defense = 264;
      pokemon[ 3 ].speed = 298;
      pokemon[ 3 ].special = 258;
      pokemon[ 3 ].accuracy = 0;
      pokemon[ 3 ].evasion = 0;
      pokemon[ 3 ].type[ 0 ] = grass;
      pokemon[ 3 ].type[ 1 ] = poison;
      pokemon[ 3 ].move[ 0 ] = 2;
      pokemon[ 3 ].move[ 1 ] = 4;
      pokemon[ 3 ].move[ 2 ] = 5;
      pokemon[ 3 ].move[ 3 ] = 6;
      
      pokemon[ 6 ].name = "Charizard";
      pokemon[ 6 ].hp = 359;
      pokemon[ 6 ].attack = 266;
      pokemon[ 6 ].defense = 254;
      pokemon[ 6 ].speed = 268;
      pokemon[ 6 ].special = 298;
      pokemon[ 6 ].accuracy = 0;
      pokemon[ 6 ].evasion = 0;
      pokemon[ 6 ].type[ 0 ] = fire;
      pokemon[ 6 ].type[ 1 ] = flying;
      pokemon[ 6 ].move[ 0 ] = 0;
      pokemon[ 6 ].move[ 1 ] = 1;
      pokemon[ 6 ].move[ 2 ] = 2;
      pokemon[ 6 ].move[ 3 ] = 3;
      
      pokemon[ 9 ].name = "Blastoise";
      pokemon[ 9 ].hp = 361;
      pokemon[ 9 ].attack = 264;
      pokemon[ 9 ].defense = 298;
      pokemon[ 9 ].speed = 268;
      pokemon[ 9 ].special = 254;
      pokemon[ 9 ].accuracy = 0;
      pokemon[ 9 ].evasion = 0;
      pokemon[ 9 ].type[ 0 ] = water;
      pokemon[ 9 ].type[ 1 ] = none;
      pokemon[ 9 ].move[ 0 ] = 7;
      pokemon[ 9 ].move[ 1 ] = 8;
      pokemon[ 9 ].move[ 2 ] = 9;
      pokemon[ 9 ].move[ 3 ] = 10;
}
