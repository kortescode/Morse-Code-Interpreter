/*********************
** Gestion du temps **
*********************/

#ifndef  TIME_H_
# define TIME_H_

/* Définition du temps d'attente d'un appui long sur le button (en ms) */
# define LONGPRESS_DELAY 500

/* Définition du temps d'attente sans appui sur le button (en ms)  */
# define NOPRESS_DELAY   1000

/* Définition du temps passé */
extern unsigned long time;

/* Définition des fonctions */
void resetTime(void);
unsigned long getElapsedTime(void);

#endif /* !TIME_H_ */
