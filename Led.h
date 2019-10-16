/**********************
** Contrôle des LEDs **
**********************/

#ifndef  LED_H_
# define LED_H_

/* Définition des status des LEDs */
typedef enum
{
  OFF,
  GREEN,
  RED
} ledStatus;

/* Définition des fonctions */
void initLedPinMode(void);
void switchLed(ledStatus status);

#endif /* !LED_H_ */
