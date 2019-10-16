/****************************
** Contrôle de l’écran LCD **
****************************/

#ifndef  LCD_H_
# define LCD_H_

/* Définition des nombres de lignes et de colonnes de l'écran LCD */
# define LCD_NUMROWS 2
# define LCD_NUMCOLS 16

/* Définition des chaînes de caractères à afficher */
# define MORSE_LINE  "Listening morse"
# define BLANK_LINE  "                "

/* Définition des index des pins digitaux des éléments */
typedef enum
{
  BUTTON    = 2,
  GREENLED  = 3,
  REDLED    = 4,
  LCDRS     = 8,
  LCDENABLE = 9,
  LCDD4     = 10,
  LCDD5     = 11,
  LCDD6     = 12,
  LCDD7     = 13
} pinIndex;

/* Définition des fonctions */
void initLcd(void);
void resetLcd(void);
void displayCharacterOnLcd(char character);

#endif /* !LCD_H_ */
