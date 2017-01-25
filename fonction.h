#ifndef __FONCTION__
#define __FONCTION__
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/********************************************************************************************************************
 * 
 * 
 *                            PIQUET Anthony / 3ETI / TP6 QUARTO
 * 
 * 
 *******************************************************************************************************************/



typedef struct Piece piece;
typedef struct Joueur joueur;

struct Joueur{
    char prenom[15];//Structure joueur contenant une chaine de caractère correspondant au prénom
};
struct Piece{
  int claire,ronde,haute,pleine; //1 pour oui, 0 pour non. Exemple: si Claire=0 c'est que la pièce est sombre, si ronde=1 elle est ronde sinon elle aurait été carrée
};

joueur creerunjoueur(joueur *p); 
//Deux appels de cette fonction dans le main() pour créer les deux joueurs
//Entrée: pointeur sur le joueur à créer ;
//Sortie : le joueur créé ;

void affichergenerique();
//La fonction a pour rôle d'afficher le générique (le nom du jeux ainsi que les règles)

void affichermodesjeux();
//La fonction affiche les différents modes de jeux possibles ainsi que des exemples en couleur pour que les joueurs comprennent bien les modes de jeux

int entrermodedejeux();
//La fonction permet aux joueurs d'entrer le numéro du mode de jeux auquel ils veulent jouer
//Sortie: le numéro du mode de jeux: 0,1,2 ou 3

void appeljoueur(int n,joueur J1, joueur J2);
//Cette fonction permet un affichage en console plus personnalisé car le joueur concerné par un appel (par exemple si on demande au joueur d'entrer le numéro de la pièce qu'il veut donner à son adversaire) va être interpellé par son prénom
//Entrées: n (le numéro aléatoire permettant de faire commencer un joueur alétoirement), J1,J2 les deux joueurs afin que la fonction connaisse les prénoms des joueurs

void affichernumeromodedejeux(int a);
//Cette fonction sera appelé à chaque tour pour rappeler aux joueurs en quel mode de jeux ils sont et donc ce qui est autorisé grâce à un affichage
//Entrée: a qui correspond au mode de jeux (0,1,2,3)

void afficherplateau(int P[16][6]); 
//Fonction pour afficher le plateau, 16 lignes et 6 colonnes, chaque ligne corresponds à un emplacement de pièces sur le plateau. Pour chaque ligne : 
    //1er colonnes : numéro de l'emplacement. 
    //Les 4 colonnes suivantes pour les caractéristiques de la pièce mise (soit 0 soit 1)
    //La dernière colonne sert à savoir à quel tour on a placé la pièce pour verification du quarto, 0 si aucune pièce n'est placée (On affiche seulement les 5 premières colonnes aux joueurs) ;
    //Si aucune pièce n'est présente on affiche par exemple pour l'emplacement 1: " 1 ----"
    // La fonction affiche également un descriptif pour mieux comprendre l'affichage
//Entrée: le plateau ;

void initialisertableau(piece T[]); 
//J'initialise le tableau de pièces initial contenant les 16 pièces ;
//Entrée : le tableau de pièces ;

int choixpiece(int i);
//Choix du numéro de pièce dans le tableau ;
//Entrée: i, i+1 étant la taille de la pioche car ce i correspond dans la partie à "16-i" avec i le numéro du tour
//Sortie : Renvoie le numéro de l'indice de la pièce voulu pour l'adversaire (Le tableau est affiché sur la console avec le numéro d'indice de chacune) ;
 
int affichertableaupiece(piece T[],int b);
//Affichage du tableau de pièce, b correspond à la longueur de celui-ci longueur que l'on décrémente à chaque tour car une pièce a été choisi. Pour cela on procède à l'appelle suivant dans le main() : « affichertableaupiece(T,16-i);
//Entrée : le tableau de pièces et sa taille ;
//Aucune sortie malgrè un int, ca permet juste de sortir de la fonction (avec un return 0;) lorsque toutes les pièces sont affichées pour éviter que la boucle aille inutilement jusqu'à 16 sans rien afficher

piece piecechoisieetsuppressiondanstableau(piece T[],int b);
//J'appelle « choixpiece() » dans cette fonction. La fonction stock alors la pièce voulue dans une variable de type pièce puis la supprime dans le tableau. Pour cela on déclare un pointeur de type pièce, on le fait pointer sur la pièce voulu puis on procède dans une boucle for jusqu'à la fin du tableau à : *p=*(p+1). b est la longueur du tableau, dans le main on met « piecechoisieetsuppressiondanstableau(T,16-i) » on « retire » donc une case au tableau à chaque tour pour que la boucle for n'aille pas inutilement jusque la fin à chaque tour. On return ensuite la pièce choisie pour son placement sur le plateau ;
//Entrées : le tableau de pièce et la longueur de celui-ci ;
//Sortie : on return la pièce choisie ;

int choixplacesurplateau();
//Demande au joueur où il veut placer sa pièce sur le plateau (le plateau est affiché avec un numéro à chaque emplacement) ;
//Sortie : le numéro de  l'emplacement ;

void placercaracteristiquepiecesurplateau(piece A, int P[16][6], int i);
//"choixplacesurplateau()" est appellée. Puis la fonction place les caractéristiques de la pièce choisie à l'emplacement voulu. 
//Elle ajoute le tour « i » en position P[][5] (invisible pour les jours car on ne l'affiche pas). i correspond au tour auquel a été posé la pièce pour la vérification du quarto
//Entrées : la pièce choisie, le plateau, le numéro du tour auquel la pièce a été choisi ;

int annoncerquarto();
//Fonction demandant si le joueur souhaite annoncer un quarto
//Sortie: 1 s'il en annonce un, 0 sinon

int positionpourquatro();
//Demande le numéro de l'emplacement d'une pièce faisant partie du quatro ;
//Sortie : Un entier correspondant à une place sur le plateau ;

void triertrableau(int T[], int n);
//Trie un tableau d'entiers (dans l'ordre croissant). Nous allons nous en servir pour trier les positions données par le joueur pour vérifier le quarto
//Entrée: tableau contenant la position des pièces sensées participer à un quarto

int verificationcaracteristiquecommune(int P[16][6],int nu, int nd, int nt, int nq);
//La fonction vérifie si les numéros de pièces passés en paramètre correspondent à des pièces ayant au moins une caractéristique en commun sur le plateau
//Entrées:  le plateau de jeux, les indices des pièces participant au quarto
//Sortie: 1 si au moins une caractérisque est commune aux quatre, 0 sinon

int verifierligne(int T[]);
//La fonction vérifie si les numéros dans le tableau correspondent aux indices de pièces qui sont en ligne sur le plateau de jeux
//Entrée: le tableau contenant les 4 positions de pièces sensées participer à un quarto
//Sortie: 1 si un alignement est vérifié, 0 sinon

int verifiercolonne(int T[]);
//La fonction vérifie si les numéros dans le tableau correspondent aux indices de pièces qui sont en colonne sur le plateau de jeux
//Entrée: le tableau contenant les 4 positions de pièces sensées participer à un quarto
//Sortie: 1 si un alignement est vérifié, 0 sinon

int verifierdiag(int T[]);
//La fonction vérifie si les numéros dans le tableau correspondent aux indices de pièces qui sont en diagonal sur le plateau de jeux
//Entrée: le tableau contenant les 4 positions de pièces sensées participer à un quarto
//Sortie: 1 si un alignement est vérifié, 0 sinon

int alignement(int T[]);
//Vérifie si les numéros présents dans le tableau correspondent à des indices de pièces alignées sur le plateau de jeux (en appelant les 3 fonctions précédentes)
//Entrée: Le tableau trié contenant les indices des pièces sensées participer au quarto
//Sortie: 1 si l'alignement est vérifié, 0 sinon

int verifiercarre(int T[]);
//Vérifie si les numéros présents dans le tableau correspondent à des indices de pièces en carré sur le plateau de jeux
//Entrée: Le tableau trié contenant les indices des pièces sensées participer au quarto
//Sortie: 1 si un carré est vérifié, 0 sinon

int verifiergrandcarre(int T[]);
//Verifie si lesnuméros présents dans le tableau correspondent à des indices de pièces en grand ou petit carré sur le plateau de jeux
//Entrée: Le tableau trié contenant les indices des pièces sensées participer au quarto
//Sortie: 1 si un grand ou un petit carré est vérifié, 0 sinon

int verifiercarreretourne(int T[]);
//Verifie si lesnuméros présents dans le tableau correspondent à des indices de pièces en grand ou petit carré ou en grand carré retourné sur le plateau de jeux
//Entrée: Le tableau trié contenant les indices des pièces sensées participer au quarto
//Sortie: 1 si un grand ou un petit carré ou un grand carré retourné est vérifié, 0 sinon

int verificationduquatro(int P[16][6], int i, int a);
//La fonction « positionpourquatro() » est appelé 4 fois pour connaitre l'emplacement des quatre pièces faisant parties du quatro. Grâce à « i » nous savons à quel tour nous sommes afin de vérifier si la dernière pièce posée a été posé maximum 1 tours avant. Si c'est le cas on vérifie si les pièces ont une caractéristique commune grâce à la fonction "verificationcaracteristiquecommune(P, nu,nd,nt,nq)". Si oui on appelle la fonction "alignement(T)" (après avoir mit nu,nd,nt et nq dans un tableau puis de l'avoir trié grâce à la fonction "triertableau(T)") pour vérifier si les pièces sont alignées. Puis si ça n'est pas le cas on vérifie la valeur de a passée en paramètre qui vaut soit 0 si le mode de jeux est en alignement seul, 1 si on autorise les quarto en petit carré, 2 en grand carré et 3 en grand carré retourné. En fonction de la valeur de a on vérifie donc les différents types de carré
//La fonction affiche si celui qui a annoncé le quarto gagne ou perd
//Entrées : le plateau, le numéro de tour au moment de l'annonce « quarto! », le mode de jeux (0 si on accepte seulement les alignements, 1 si les quarto en petit carré sont acceptés, 2 en grand carré et 3 en grand carré retourné)
//Sortie: 1 si l'annonce du quarto était correcte, 0 sinon (utilise pour demander qui veut une revanche sur qui)

int demandederevanche(int n,joueur J1,joueur J2,int w);
//Fonction appelée dans le main() dans le cas où un joueur a annoncé un quarto. Il demande au perdant s'il souhaite une revanche, et au gagnant s'il accepte
//Entrée: n (le nombre aléatoire permettant de savoir quel joueur appeler), J1 J2 les deux joueurs, w permettant de savoir si le quarto annoncé était bon ou mauvais (car s'il est mauvais on va demander à l'annonceur du quarto s'il souhaite une revanche car il a perdu, s'il était bon on va demande si l'autre joueur souhaite une revanche)
//Sortie: 1 si les joueurs veulent rejoueur, 0 sinon

int egalitedemandersirejouer();
//Fonction appelé dans le main() en cas d'égalité, elle demande aux joueurs s'ils veulent rejouer
//Sortie: 1 si les joueurs veulent rejoueur, 0 sinon

void partie();
//La fonction fait dérouler une partie grâce à divers appels des fonctions précédentes

#endif

