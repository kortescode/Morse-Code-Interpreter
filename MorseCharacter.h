/************************************
** Gestion des caractères de morse **
************************************/

#ifndef  MORSECHARACTER_H_
# define MORSECHARACTER_H_

# include "Signal.h"

/* Définition du caractère non trouvé */
# define UNDEFINED_CHAR -1

/* Définition de la taille maximale d'un tableau de signaux */
# define MORSECHARSIGNALS_LENGTH 7

/* Définition de la structure d'association tableau de signaux / lettre */
typedef struct
{
  unsigned char character;
  morseSignal   signals[MORSECHARSIGNALS_LENGTH];
} morseCharacter;

/* Définition des fonctions */
char getMorseCharacter(void);
unsigned int getMorseCharactersLength(void);
unsigned int getMorseCharacterSignalsLength(morseSignal*);

#endif /* !MORSECHARACTER_H_ */
