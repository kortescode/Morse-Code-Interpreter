/********************************
** Gestion des états du bouton **
********************************/

#include "Lcd.h"
#include "Led.h"
#include "Time.h"
#include "Button.h"
#include "MorseCharacter.h"

/* Fonction de management d'une nouvelle pression sur le bouton */
void manageNewlyPressedButton(void)
{
  switchLed(GREEN); // On allume la LED verte
  resetTime(); // On réinitialise le temps à partir de maintenant
}

/* Fonction de management d'un nouveau relâchement du bouton */
void manageNewlyUnpressedButton(void)
{
  addSignal(getButtonSignal()); // On ajoute le signal produit à notre tableau de signaux
  switchLed(OFF); // On éteind les LEDs
  resetTime(); // On réinitialise le temps à partir de maintenant
}

/* Fonction de management d'une continuation de pression sur le bouton */
void manageContinuallyPressedButton(void)
{
  switchLed((getElapsedTime() < LONGPRESS_DELAY) ? GREEN : RED); // On allume la LED correspondante au type de pression sur le bouton
}

/* Fonction de management d'une continuation de relâchement du bouton */
void manageContinuallyUnpressedButton(void)
{
  if (getElapsedTime() >= NOPRESS_DELAY) // Si le temps écoulé est supérieur à celui défini
  {
    displayCharacterOnLcd(getMorseCharacter()); // On essaye de trouver et d'afficher la lettre produite avec les signaux
    resetSignals(); // On réinitialise notre tableaux de signaux
    resetTime(); // On réinitialise le temps à partir de maintenant
  } 
}
