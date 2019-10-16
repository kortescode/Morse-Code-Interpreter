/*********************
** Gestion du temps **
*********************/

#include "Arduino.h"
#include "Time.h"

/* Déclaration du temps passé */
unsigned long time;

/* Fonction de réinitialisation du temps */
void resetTime(void)
{
  time = millis(); // On récupère la valeur du nombre de millisecondes passé depuis le démarrage du programme
}

/* Fonction de récupération du temps passé depuis la dernière réinitialisation */
unsigned long getElapsedTime(void)
{
  return millis() - time; // On retourne la différence entre le nombre de millisecondes passé depuis le démarrage du programme et celui stocké
}
