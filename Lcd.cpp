/****************************
** Contrôle de l’écran LCD **
****************************/

#include <LiquidCrystal.h>
#include "Lcd.h"
#include "MorseCharacter.h"

/* Initialisation de la librairie de l'écran LCD */
LiquidCrystal lcd(LCDRS, LCDENABLE, LCDD4, LCDD5, LCDD6, LCDD7);

/* Fonction d'initialisation de l'écran LCD */
void initLcd(void)
{
  lcd.begin(LCD_NUMCOLS, LCD_NUMROWS); // On définie le nombre de lignes et de colonnes de l'écran LCD
  lcd.print(MORSE_LINE); // On affiche le titre sur la 1ère ligne
  resetLcd(); // On réinitialise la 2ème ligne
}

/* Fonction de réinitialisation de la 2ème ligne l'écran LCD */
void resetLcd(void)
{
  lcd.setCursor(0, 1); // On place le curseur au début de la 2ème ligne
  lcd.print(BLANK_LINE); // On affiche une ligne vide
  lcd.setCursor(0, 1); // On replace le curseur au début de la 2ème ligne
}

/* Fonction d'affichage d'un caractère sur l'écran LCD */
void displayCharacterOnLcd(char character)
{
  static unsigned int cursorIndex = 0; // Postion horizontale

  if (character != UNDEFINED_CHAR) // Si le caractère n'est pas non trouvé
  {
    lcd.print(character); // On affiche le caractère
    ++cursorIndex; // On incrémente la position horizontale
  }

  if (cursorIndex == LCD_NUMCOLS) // Si la position horizontale est égale au nombre de colonne
  {
    resetLcd(); // On réinitialise la deuxième ligne
    cursorIndex = 0; // On réinitialise la position
  }
}
