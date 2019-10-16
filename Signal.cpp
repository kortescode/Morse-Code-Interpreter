/************************
** Gestion des signaux **
************************/

#include "Arduino.h"
#include "Signal.h"

/* Déclaration de notre tableau de signaux */
morseSignal* signals;

/* Déclaration de la position dans le tableau de signaux */
unsigned int signalsIndex;

/* Fonction de réinitialisation du tableau de signaux */
void resetSignals(void)
{
  if (signals) // Si le tableau n'est pas vide
    free(signals); // On libère la mémoire

  signalsIndex = 0; // On réinitialise la position
  signals = NULL; // On réinitialise le tableau
}

/* Fonction de récupération de la taille du tableau de signaux */
unsigned int getSignalsLength(void)
{
  return signalsIndex; // On retourne simplement la position
}

/* Fonction d'ajout d'un signal dans le tableau de signaux */
void addSignal(morseSignal signal)
{
  signals = (morseSignal*)realloc(signals, (signalsIndex + 1) * sizeof(*signals)); // On agrandi la taille du tableau de signaux de 1
  signals[signalsIndex++] = signal; // On stocke le nouveau signal
}
