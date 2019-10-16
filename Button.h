/***********************
** Contrôle du bouton **
***********************/

#ifndef  BUTTON_H_
# define BUTTON_H_

# include "Signal.h"

/* Définition des fonctions */
void initButtonPinMode(void);
bool isButtonPressed(void);
morseSignal getButtonSignal(void);

#endif /* !BUTTON_H_ */
