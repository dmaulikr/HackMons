#include "Pokemon.h"
#include "Attack.h"

/* Probability of an attack hitting based on the user's accuracy stat, and the defending Pokemon's evasion stat */
double accuracy_evasion[] = { 0.25, 0.28, 0.33, 0.40, 0.50, 0.66, 1, 1.50, 2.00, 2.50, 3.00, 3.50, 4.00 };

/* Determine if an attack hit or missed based on the accuracy of the attack, the 
      user's accuracy stat, and the defending Pokemon's evasion stat */
static int attackConnect( int attack_id, int accuracy, int evasion )
{
      double P = attack[ attack_id ].accuracy;
      
      int diff = accuracy - evasion;
      
      P *= accuracy_evasion[ 6 + diff ];
      
      int ret = ( P >= 1.0 ) ? 1 : 0;     // If P >= 1, then the attack will hit the defending Pokemon
      
      return ret;
}

/* Displays "The Attack Missed" */
static void displayAttackMissed()
{
      /* Display "Attack Missed" */
}

static void displaySuperEffective()
{
      /* Display "It's Super-Effective! */
}

/* Displays "It's a critical hit." */
static void displayCriticalHit()
{
      /* Display "It's a Critical Hit!" */
}

/* Return damage done to the defending Pokemon */
static int attackAttempt( int attack_id, struct Pokemon r, struct Pokemon s )
{
      /* If the attack missed, then display a message letting the users
            know. No damage is done to the defending player, so return. */
      if( attackConnect( attack_id, r.accuracy, s.evasion ) == 0 )
      {
            displayAttackMissed();
            return 0;
      }

      /* Determine the attack/defense stats that will be used based on if 
            the attack is "Physical" or "Special" */
      int att = ( attack[ attack_id ].spetrum == 0 ) ? r.attack : r.special;
      int def = ( attack[ attack_id ].spetrum == 0 ) ? s.defense : s.special;
      
      /* Calculate values that will be used when calculating the damage */
      double STAB = ( attack[ attack_id ].type == r.type[ 0 ] || attack[ attack_id ].type == r.type[ 1 ] ) ? 1.5 : 1.0;
      double effectiveness = type_chart[ attack[ attack_id ].type ][ s.type[ 0 ] ] * type_chart[ attack[ attack_id ].type ][ s.type[ 1 ] ];
      int ran = rand() % 100;
      double critical_hit = ( ran % 16 == 0 ) ? 1.5 : 1;
      double mult = (double) ran / 100.0;
      
      /* Calculate the damage done to the defending Pokemon */
      double damage = (double) ( 0.84 * att / def * attack[ attack_id ].base_power + 2 ) * STAB * effectiveness * critical_hit * mult;
      
      /* If the attack is super-effective, then display a message letting 
            the users know. */
      if( effectiveness >= 2.0 )
      {
            displaySuperEffective();
      }

      /* If the attack is critical hit, then display a message letting 
            the users know. */
      if( critical_hit == 1.5 )
      {
            displayCriticalHit();
      }
      
      return (int) damage;
}
