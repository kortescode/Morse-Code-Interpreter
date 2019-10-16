/**********************
** Base du programme **
**********************/

#include "Lcd.h"
#include "Led.h"
#include "Time.h"
#include "Button.h"
#include "ButtonState.h"

/* Fonction de paramétrage du programme */
void setup(void)
{
  initLedPinMode(); // On initialise les pins digitaux des LEDs
  initButtonPinMode(); // On initialise le pin digital du bouton
  initLcd(); // On initialise l'écran LCD

  resetSignals(); // On initialise notre tableaux de signaux
  resetTime(); // On initialise le temps à partir de maintenant
}

/* Fonction de boucle du programme */
void loop(void)
{
  static bool isButtonPreviouslyPressed; // Le bouton était-il pressé pendant la dernière boucle
  static bool isButtonCurrentlyPressed; // Le bouton est-il pressé actuellement

  isButtonPreviouslyPressed = isButtonCurrentlyPressed; // On met la valeur actuelle dans celle de la dernière boucle
  isButtonCurrentlyPressed = isButtonPressed(); // On récupère la valeur actuelle

  if (isButtonCurrentlyPressed) // Si le bouton est pressé
  {
    if (isButtonPreviouslyPressed) // Si il l'était aussi avant
      manageContinuallyPressedButton();
    else // Si il ne l'était pas avant
      manageNewlyPressedButton();
  }
  else // Si le bouton n'est pas pressé
  {
    if (!isButtonPreviouslyPressed) // Si il ne l'était pas non plus avant
      manageContinuallyUnpressedButton();
    else // Si il l'était avant
      manageNewlyUnpressedButton();
  }
}
