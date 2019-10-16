/**********************
** Contrôle des LEDs **
**********************/

#include "Arduino.h"
#include "Lcd.h"
#include "Led.h"

/* Fonction d'initialisation des pins digitaux des LEDs */
void initLedPinMode(void)
{
  pinMode(GREENLED, OUTPUT); // On met le pin digital de la LED verte dans un état de basse impédance
  pinMode(REDLED, OUTPUT); // On met le pin digital de la LED rouge dans un état de basse impédance
}

/* Fonction d'allumage / extinction des LEDs */
void switchLed(ledStatus status)
{
  digitalWrite(GREENLED, (status == GREEN)); // On passe le voltage de la LED verte à 5 Volt si le status est correspondant à celle-ci, sinon on le passe à 0 Volt
  digitalWrite(REDLED, (status == RED)); // On passe le voltage de la LED rouge à 5 Volt si le status est correspondant à celle-ci, sinon on le passe à 0 Volt
}
