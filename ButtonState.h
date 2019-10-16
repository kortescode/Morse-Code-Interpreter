/**********************
** Contrôle des LEDs **
**********************/

#ifndef  BUTTONSTATE_H_
# define BUTTONSTATE_H_

/* Définition des fonctions */
void manageNewlyPressedButton(void);
void manageNewlyUnpressedButton(void);
void manageContinuallyPressedButton(void);
void manageContinuallyUnpressedButton(void);

#endif /* !BUTTONSTATE_H_ */
