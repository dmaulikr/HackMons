#include "Pokemon.h"

struct Attack
{
      char *name;
      
      int accuracy;
      int base_power;
      int spetrum;
      int type;
};

struct Attack attack[ 100 ];

double type_damage[16][16];

/* Initializes Attack Array */
static void initilializeAttackStructure()
{
      attack[ 4 ].name = "Razor Leaf";
      attack[ 4 ].accuracy = 1;
      attack[ 4 ].base_power = 55;
      attack[ 4 ].spetrum = 1;
      attack[ 4 ].type = grass;
      
      attack[ 5 ].name = "Cut";
      attack[ 5 ].accuracy = 0.95;
      attack[ 5 ].base_power = 50;
      attack[ 5 ].spetrum = 0;
      attack[ 5 ].type = normal;
      
      attack[ 6 ].name = "Sludge Bomb";
      attack[ 6 ].accuracy = 100;
      attack[ 6 ].base_power = 90;
      attack[ 6 ].spetrum = 1;
      attack[ 6 ].type = poison;
      
      attack[ 0 ].name = "Fire Blast";
      attack[ 0 ].accuracy = 0.85;
      attack[ 0 ].base_power = 120;
      attack[ 0 ].spetrum = 1;
      attack[ 0 ].type = fire;
      
      attack[ 1 ].name = "Slash";
      attack[ 1 ].accuracy = 1.0;
      attack[ 1 ].base_power = 70;
      attack[ 1 ].spetrum = 0;
      attack[ 1 ].type = normal;
      
      attack[ 2 ].name = "Earthquake";
      attack[ 2 ].accuracy = 1.0;
      attack[ 2 ].base_power = 100;
      attack[ 2 ].spetrum = 0;
      attack[ 2 ].type = ground;
      
      attack[ 3 ].name = "Swift";
      attack[ 3 ].accuracy = 100;
      attack[ 3 ].base_power = 20;
      attack[ 3 ].spetrum = 1;
      attack[ 3 ].type = normal;
      
      attack[ 7 ].name = "Hydro Pump";
      attack[ 7 ].accuracy = 0.85;
      attack[ 7 ].base_power = 120;
      attack[ 7 ].spetrum = 1;
      attack[ 7 ].type = water;
      
      attack[ 8 ].name = "Ice Beam";
      attack[ 8 ].accuracy = 1.0;
      attack[ 8 ].base_power = 90;
      attack[ 8 ].spetrum = 1;
      attack[ 8 ].type = ice;
      
      attack[ 9 ].name = "Rock Slide";
      attack[ 9 ].accuracy = 0.90;
      attack[ 9 ].base_power = 75;
      attack[ 9 ].spetrum = 0;
      attack[ 9 ].type = Rock;
      
      attack[ 10 ].name = "Aura Sphere";
      attack[ 10 ].accuracy = 100;
      attack[ 10 ].base_power = 80;
      attack[ 10 ].spetrum = 1;
      attack[ 10 ].type = fighting;
}

/* Initializes Type Damage Table */
static void initializeTypeDamage()
{
      memset( type_damage, 1, sizeof type_damage );
      
      type_damage[ normal ][ rock ] = 0.5;
      type_damage[ normal ][ ghost ] = 0;
      
      type_damage[ fire ][ fire ] = 0.5;
      type_damage[ fire ][ water ] = 0.5;
      type_damage[ fire ][ grass ] = 2;
      type_damage[ fire ][ ice ] = 2;
      type_damage[ fire ][ bug ] = 2;
      type_damage[ fire ][ rock ] = 0.5;
      type_damage[ fire ][ dragon ] = 0.5;
      
      type_damage[ water ][ fire ] = 2;
      type_damage[ water ][ water ] = 0.5;
      type_damage[ water ][ grass ] = 0.5;
      type_damage[ water ][ ground ] = 2;
      type_damage[ water ][ rock ] = 2;
      type_damage[ water ][ dragon ] = 0.5;
      
      type_damage[ electric ][ water ] = 2;
      type_damage[ electric ][ grass ] = 0.5;
      type_damage[ electric ][ ground ] = 0.0;
      type_damage[ electric ][ flying ] = 2;
      type_damage[ electric ][ dragon ] = 0.5;
      
      type_damage[ grass ][ fire ] = 0.5;
      type_damage[ grass ][ water ] = 2;
      type_damage[ grass ][ grass ] = 0.5;
      type_damage[ grass ][ poison ] = 0.5;
      type_damage[ grass ][ flying ] = 0.5;
      type_damage[ grass ][ bug ] = 0.5;
      type_damage[ grass ][ rock ] = 2;
      type_damage[ grass ][ dragon ] = 0.5;
      
      type_damage[ ice ][ fire ] = 0.5;
      type_damage[ ice ][ water ] = 0.5;
      type_damage[ ice ][ grass ] = 2;
      type_damage[ ice ][ ground ] = 2;
      type_damage[ ice ][ flying ] = 2;
      type_damage[ ice ][ dragon ] = 2;
      
      type_damage[ fighting ][ normal ] = 2;
      type_damage[ fighting ][ ice ] = 2;
      type_damage[ fighting ][ poison ] = 0.5;
      type_damage[ fighting ][ flying ] = 0.5;
      type_damage[ fighting ][ psychic ] = 0.5;
      type_damage[ fighting ][ ghost ] = 0;
      
      type_damage[ poison ][ grass ] = 2;
      type_damage[ poison ][ poison ] = 0.5;
      type_damage[ poison ][ ground ] = 0.5;
      type_damage[ poison ][ bug ] = 2;
      type_damage[ poison ][ rock ] = 0.5;
      type_damage[ poison ][ ghost ] = 0.5;
      
      type_damage[ ground ][ fire ] = 2;
      type_damage[ ground ][ electric ] = 2;
      type_damage[ ground ][ grass ] = 0.5;
      type_damage[ ground ][ poison ] = 2;
      type_damage[ ground ][ flying ] = 0;
      type_damage[ ground ][ bug ] = 0.5;
      type_damage[ ground ][ rock ] = 2;
      
      type_damage[ flying ][ electric ] = 0.5;
      type_damage[ flying ][ grass ] = 2;
      type_damage[ flying ][ fighting ] = 2;
      type_damage[ flying ][ bug ] = 2;
      type_damage[ flying ][ rock ] = 0.5;
      
      type_damage[ psychic ][ fighting ] = 2;
      type_damage[ psychic ][ poison ] = 2;
      type_damage[ psychic ][ psychic ] = 0.5;
      
      type_damage[ bug ][ fire ] = 0.5;
      type_damage[ bug ][ grass ] = 2;
      type_damage[ bug ][ fighting ] = 0.5;
      type_damage[ bug ][ poison ] = 2;
      type_damage[ bug ][ flying ] = 0.5;
      type_damage[ bug ][ psychic ] = 2;
      type_damage[ bug ][ ghost ] = 0.5;
      
      type_damage[ rock ][ fire ] = 2;
      type_damage[ rock ][ ice ] = 2;
      type_damage[ rock ][ fighting ] = 0.5;
      type_damage[ rock ][ ground ] = 0.5;
      type_damage[ rock ][ flying ] = 2;
      type_damage[ rock ][ bug ] = 2;
      
      type_damage[ ghost ][ normal ] = 0;
      type_damage[ ghost ][ fighting ] = 0;
      type_damage[ ghost ][ ghost ] = 2;
      
      type_damage[ dragon ][ dragon ] = 2;
}
