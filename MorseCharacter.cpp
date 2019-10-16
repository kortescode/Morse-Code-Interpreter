/************************************
** Gestion des caractères de morse **
************************************/

#include "MorseCharacter.h"

/* Initialisation du tableau des associations tableau de signaux / lettre */
static morseCharacter morseCharacters[] =
{
  { 'a', { SHORT, LONG } },
  { 'b', { LONG, SHORT, SHORT, SHORT } },
  { 'c', { LONG, SHORT, LONG, SHORT } },
  { 'd', { LONG, SHORT, SHORT } },
  { 'e', { SHORT } },
  { 'f', { SHORT, SHORT, LONG, SHORT } },
  { 'g', { LONG, LONG, SHORT } },
  { 'h', { SHORT, SHORT, SHORT, SHORT } },
  { 'i', { SHORT, SHORT } },
  { 'j', { SHORT, LONG, LONG, LONG } },
  { 'k', { LONG, SHORT, LONG } },
  { 'l', { SHORT, LONG, SHORT, SHORT} },
  { 'm', { LONG, LONG } },
  { 'n', { LONG, SHORT } },
  { 'o', { LONG, LONG, LONG } },
  { 'p', { SHORT, LONG, LONG, SHORT } },
  { 'q', { LONG, LONG, SHORT, LONG } },
  { 'r', { SHORT, LONG, SHORT } },
  { 's', { SHORT, SHORT, SHORT } },
  { 't', { LONG } },
  { 'u', { SHORT, SHORT, LONG } },
  { 'v', { SHORT, SHORT, SHORT, LONG } },
  { 'w', { SHORT, LONG, LONG } },
  { 'x', { LONG, SHORT, SHORT, LONG } },
  { 'y', { LONG, SHORT, LONG, LONG } },
  { 'z', { LONG, LONG, SHORT, SHORT } },
  { '0', { LONG, LONG, LONG, LONG, LONG } },
  { '1', { SHORT, LONG, LONG, LONG, LONG } },
  { '2', { SHORT, SHORT, LONG, LONG, LONG } },
  { '3', { SHORT, SHORT, SHORT, LONG, LONG } },
  { '4', { SHORT, SHORT, SHORT, SHORT, LONG } },
  { '5', { SHORT, SHORT, SHORT, SHORT, SHORT } },
  { '6', { LONG, SHORT, SHORT, SHORT, SHORT } },
  { '7', { LONG, LONG, SHORT, SHORT, SHORT } },
  { '8', { LONG, LONG, LONG, SHORT, SHORT } },
  { '9', { LONG, LONG, LONG, LONG, SHORT } },
  { '.', { SHORT, LONG, SHORT, LONG, SHORT, LONG } }
};

/* Fonction de récupération de la taille du tableau des associations */
unsigned int getMorseCharactersLength(void)
{
  return sizeof(morseCharacters) / sizeof(*morseCharacters); // On retourne la taille totale du tableau divisée par un de ses éléments
}

/* Fonction de récupération de la taille d'un des tableau de signaux du tableau des associations */
unsigned int getMorseCharacterSignalsLength(morseSignal* morseSignals)
{
  unsigned int n = 0;

  while (n < MORSECHARSIGNALS_LENGTH) // On parcourt la taille du tableau
  {
    if (morseSignals[n] == NONE) // Si le signal actuel n'est pas défini, on arrête
      break;
    ++n;
  }
  return n;
}

/* Fonction de récupération d'une lettre du tableau des associations en fonction de notre tableau de signaux */
char getMorseCharacter(void)
{
  unsigned int signalsLength = getSignalsLength(); // On récupère la taille de notre tableau de signaux

  for (unsigned int i = 0; i < getMorseCharactersLength(); ++i) // On parcourt le tableau des associations
  {
    if (signalsLength == getMorseCharacterSignalsLength(morseCharacters[i].signals)) // Si la taille de notre tableau de signaux est égale à la taille de celui de l'association
    {
      for (unsigned int j = 0; j < signalsLength; ++j) // On parcourt notre tableau de signaux et celui de l'association
      {
        if (signals[j] != morseCharacters[i].signals[j]) // Si les caractères sont différents
          break; // On passe à une autre association
        else if (j + 1 == signalsLength) // Si on est arrivé au bout des 2 tableaux
          return morseCharacters[i].character; // On retourne la lettre de l'association
      }
    }
  }
  return UNDEFINED_CHAR; // Sinon on retourne caractère non trouvé
}
