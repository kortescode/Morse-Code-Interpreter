/************************
** Gestion des signaux **
************************/

#ifndef  SIGNAL_H_
# define SIGNAL_H_

/* Définition des type de signaux en morse */
typedef enum
{
  NONE,
  SHORT,
  LONG
} morseSignal;

/* Définition de notre tableau de signaux */
extern morseSignal* signals;

/* Définition de la position dans le tableau de signaux */
extern unsigned int signalsIndex;

/* Définition des fonctions */
void resetSignals(void);
void addSignal(morseSignal);
unsigned int getSignalsLength(void);

#endif /* !SIGNAL_H_ */
