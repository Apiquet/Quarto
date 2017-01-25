#include "fonction.h"
#include "couleur.h"
#include <string.h>


/********************************************************************************************************************
 * 
 * 
 *                            PIQUET Anthony / 3ETI / TP6 QUARTO
 * 
 * 
 *******************************************************************************************************************/



int main()
{
  partie();		//La fonction fait dérouler la partie grâce à des appels de divers fonctions crées
  couleur("0");    	//Je réinitialise les couleurs et la police d'écriture par défaut au cas où ça n'a pas été fait dans les fonctions précédentes car sinon l'utilisateur aura sa console qui s'affichera toujours avec la dernière police d'écriture (même si le jeux a été quitté) tant qu'il ne recroisera pas la fonction "couleur("0")"
  return 0;
  }