/***********************
** Contrôle du bouton **
***********************/

#include "Arduino.h"
#include "Lcd.h"
#include "Time.h"
#include "Button.h"

/* Fonction d'initialisation du pin digital du bouton */
void initButtonPinMode(void)
{
  pinMode(BUTTON, INPUT); // On met le pin digital du bouton dans un état de haute impédance
}

/* Fonction pour savoir si le bouton est-il pressé */
bool isButtonPressed(void)
{
  return (digitalRead(BUTTON) == LOW); // Le pin digital du bouton a t'il un voltage inférieur à 1.5 Volt
}

/* Fonction de récupération du type de signal en morse en fonction du temps de pression sur le bouton */
morseSignal getButtonSignal(void)
{
  return (getElapsedTime() >= LONGPRESS_DELAY) ? LONG : SHORT; // On retourne le type de pression en fonction du temps défini
}
