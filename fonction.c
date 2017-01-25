#include "fonction.h"
#include "couleur.h" //bibliothèque permettant d'afficher des couleurs et des effets comme écrire en italique, gras, souligner, etc


/********************************************************************************************************************
 * 
 * 
 *                            PIQUET Anthony / 3ETI / TP6 QUARTO
 * 
 * 
 *******************************************************************************************************************/


joueur creerunjoueur(joueur *p) //La fonction crée un joueur en demandant de taper son prénom
{
  scanf("%s",(*p).prenom);              //Je fais entrer le prénom d'un joueur
  return *p;                            //Je retourne le joueur ainsi modifié
}
void affichergenerique() //Affichage du du generique, nom du jeux et règles
{
  couleur("33;3;5");                   //Je procède à un changement de couleur de l'écriture (jaune) et à la mise en italique (respectivement les codes 33 et 3)
  printf("Bienvenue dans le jeux du QUARTO !\n\n\n\n");
  couleur("0");
  couleur("4;3;1");
  printf("Présentation du jeux");
  couleur("0");
  couleur("3");
  printf(": Un plateau de jeux de 16 cases, 16 pièces différentes ayant chacune 4 caractéristiques:\n   - Claire ou foncée\n   - ronde ou carrée\n   - haute ou basse\n   - pleine ou creuse.\nEn début de partie, les pièces sont déposées à côté du plateau.\n");
  couleur("0");
  couleur("4;3;1");
  printf("But du jeux");
  couleur("0");
  couleur("3");
  printf(": Créer sur le plateau un alignement de 4 pièces ayant au moins une caractéristique en commun\n(cet alignement peut-être horizontal, vertical ou diagonal).\nLa partie est gagnée par le premier joueur qui annonce un '' QUARTO !'' valide.");     //Affichage du message en jaune et italique
  couleur("0");                       //Réinitialisation par défaut de la police d'écriture et de la couleur
}
void affichermodesjeux() //Affichage des modes de jeux possibles avec leur descriptif
{
	couleur("3");
        printf("\n\nVous avez quatre modes de jeux possibles:\n\n0: seuls les alignements sont prit en compte.\n1: quarto en petit carré autorisé.\n2: quarto en petit et grand carré autorisé (positions pour grand carré: 1,3,9,11/ 2,4,10,12/ 5,7,13,15/ 6,8,14,16). \n3: quarto en petit carré, grand carré et en grand carré retourné autorisé\n(positions pour grand carré retourné: 2,5,7,10 /3,6,8,11 /6,9,11,14 /7,10,12,15).\n\nExemple petit carré en vert, grand carré en jaune et grand carré retourné en bleu:\n\n");                 //Le texte s'affiche en italique
        couleur("0");                //Affichage des exemples (un petit caré, un grand et un grand retourné) pour que les joueurs se représentent bien les posibilités de quarto
        couleur("32;1");
        printf(" 1    2");
        couleur("0");
        printf("    3    4");
        couleur("33;1");
        printf("        1");
        couleur("0");
        printf("    2");
        couleur("33;1");
        printf("    3");
        couleur("0");
        printf("    4        1");
        couleur("34;1");
        printf("    2");
        couleur("0");
        printf("    3    4\n");
        couleur("32;1");
        printf(" 5    6");
        couleur("0");
        printf("    7    8        5    6    7    8");
        couleur("34;1");
        printf("        5");
        couleur("0");
        printf("    6");
        couleur("34;1");
        printf("    7");
        couleur("0");
        printf("    8\n 9   10   11   12");
        couleur("33;1");
        printf("        9");
        couleur("0");
        printf("   10");
        couleur("33;1");
        printf("   11");
        couleur("0");
        printf("   12        9");
        couleur("34;1");
        printf("   10");
        couleur("0");
        printf("   11   12\n13   14   15   16       13   14   15   16       13   14   15   16\n\n");
        couleur("3");
}
int entrermodedejeux() //La fonction demande d'entrer le mode de jeux dans lequel les joueurs veulent jouer
{
	int a;
	couleur("3");
        printf("En quel mode voulez-vous jouer? ");
        couleur("0");
	scanf("%d",&a);                                   //a servira a savoir en quel mode de jeux nous sommes lors de la vérification du quarto
        while(a!=0 && a!=1 && a!=2 && a!=3)               //Saisie protégée de a pour qu'il ne puisse valoir que 0, 1 ,2 ou 3
        {
            couleur("31");
            printf("Quatre modes de jeux possibles, de 0 à 3\n");      //J' affiche le message en rouge
            couleur("0");
            scanf("%d",&a);
        };
	return a;
}
void appeljoueur(int n,joueur J1, joueur J2) //La fonciton permet d'appeler le bon joueur au bon moment pour demande par exemple de choisir une pièce ou la poser
{
	if(n%2==0)                                        //% est le reste de la division donc si n%2=0 (Si n est pair) C'est J2 qui est appelé
        {
            printf("%s",J2.prenom);
        }
        else                                              //Sinon c'est J1
        {
            printf("%s",J1.prenom);
        }
}
void affichernumeromodedejeux(int a) //Affichage du numero du mode de jeux au dessus du plateau pour éviter que les joueurs oublie si la partie dure longtemps
{
  couleur("33;3;1");
  printf("Mode de jeux: %d",a);			//Affichage du mode de jeux auquel on est (0,1,2 ou 3) (En jaune italique et gras)
  couleur("0");
  couleur("33;3");
  if(a==0)
  {
    printf(" (Alignements seuls)\n");		//J' affiche alors pour chaque valeur possible de a, comment un quarto peut être réalisé
  }
  if(a==1)
  {
    printf(" (Alignements + petits carrés)\n");
  }
  if(a==2)
  {
    printf(" (Alignements + petits et grands carrés)\n");
  }
  if(a==3)
  {
    printf(" (Alignements + petits carrés + grands carrés + grands carrés retournés)\n");
  }
  couleur("0");
}
void afficherplateau(int P[16][6]) //affichage du plateau de jeux
{
  int i,j;
  couleur("35;4;3;1");              //La fonction couleur() permet de faire un affichage en couleur ou avec des effets (Ici 35=magenta, 4=souligné et 3=italique)
  printf("Plateau de jeux");        //J'affiche le message: Plateau de jeux
  couleur("0");                     //La fonction couleur("0") permet de remettre l'affichage en standard (blanc, sans italique, non souligné etc)
  couleur("35");
  printf(":");			    //J'ai enlevé l'italique et le souligné pour les 2 petits points
  couleur("0");
  printf("                                                            "); //Je me décale pour afficher le descriptif des références que je vais utiliser, à gauche du plateau
  couleur("35;4;3;1");
  printf("Descriptif référence");
  couleur("0");
  couleur("35;3");
  printf(":");
  couleur("0");
  printf("\n\n");		     //J'effectue deux retours à la ligne
  for(i=0;i<16;i++)		     //La boucle for va permettre d'afficher le plateau mais par la même occasion le descriptif des références car on l'affiche à gauche du plateau en console
  {
    couleur("3");                   //Affichage du descriptif des références en italique
    if(i==4) {printf("              - Sombre/Claire : 0/1\n\n                                                                                  - Carrée/Ronde  : 0/1\n");}
    if(i==8) {printf("\n                                                                                  - Petite/Haute  : 0/1\n \n");}
    if(i==12) {printf("              - Creuse/Pleine : 0/1\n \n \n");} //J' affiche le descriptif à droite du plateau de jeux grâce aux espaces
    //Les sauts de lignes à i=4, i=8 et i=12 sont dû au fait que je fais l'affichage du plateau soit 4 pièces par ligne, il faut donc revenir à la ligne tous les 4
    
    if(i<9) {printf(" ");}          //J'affiche le numéro de chaque emplacement donc pour faire un affichage droit nous devons ajouter un espace lorsque le numéro est inférieur à 10 pour le mettre au même niveau que les emplacements contenant deux chiffres comme 11, 12 etc
    couleur("0");
    if(P[i][5]==0)                  // P[i][5] contient le numéro de tour où la pièce a été placé sur l'emplacement i (0 si il n'y a aucune pièce) donc ce if traite le cas où aucune pièce n'a été placé sur cette emplacement
    {
        couleur("1");
	printf("       ");
	printf("%d  ",P[i][0]);                 //Affichage du numéro de l'emplacement en gras grâce à la fonction couleur("1")
        couleur("0");
        printf("----  ");                       //J'affiche donc par exemple pour l'emplacement 1 (s'il est vide) : 1 ----
        
    }
    else                                        //Si une pièce est présente à l'emplacement P[i]
    {
	printf("      ");
        couleur("1");
	printf(" %d ",P[i][0]);                //Affichage du numéro de l'emplacement en gras grâce à la fonction couleur("1")
        couleur("0");
        printf(":");
	for(j=1;j<5;j++)	               //J'affiche seulement la case 0 puis grâce à la boucle for les 1,2,3,4. La 5 n'est pas affiché car elle contient le numérodu tour auquel la pièce a été placé. Il n'y a donc pas d'utilité de l'afficher aux joueurs
	  {
            if(P[i][j]==0) {couleur("32");}    //Couleur spéciale pour le cas où la caractéristique est 0 (vert)
            if(P[i][j]==1) {couleur("33");}    //Couleur spéciale pour le cas où la caractéristique est 1 (jaune)
            
	    printf("%d",P[i][j]);              //Affichage des caractérisques de la pièce en binaire avec une couleur différentes pour 0 et 1 pour une reconnaissance plus facile des joueurs afin d'être plus attentif à un éventuel quarto
            couleur("0");
	  }
	printf("  ");
    }
  }
  printf("\n\n\n");
}
void initialisertableau(piece T[])	//initalisation des pieces
{
   /*T[0].ronde=0; T[0].claire=0; T[0].haute=0; T[0].pleine=0;   //piece carré,sombre,petite et creuse
   T[1].ronde=0; T[1].claire=0; T[1].haute=0; T[1].pleine=1;
   T[2].ronde=0; T[2].claire=0; T[2].haute=1; T[2].pleine=0;
   T[3].ronde=0; T[3].claire=0; T[3].haute=1; T[3].pleine=1;
   T[4].ronde=0; T[4].claire=1; T[4].haute=0; T[4].pleine=0;
   T[5].ronde=0; T[5].claire=1; T[5].haute=0; T[5].pleine=1;
   T[6].ronde=0; T[6].claire=1; T[6].haute=1; T[6].pleine=0;   
   T[7].ronde=0; T[7].claire=1; T[7].haute=1; T[7].pleine=1;
   T[8].ronde=1; T[8].claire=0; T[8].haute=0; T[8].pleine=0;
   T[9].ronde=1; T[9].claire=0; T[9].haute=0; T[9].pleine=1;
  T[10].ronde=1;T[10].claire=0;T[10].haute=1;T[10].pleine=0;
  T[11].ronde=1;T[11].claire=0;T[11].haute=1;T[11].pleine=1;
  T[12].ronde=1;T[12].claire=1;T[12].haute=0;T[12].pleine=0;
  T[13].ronde=1;T[13].claire=1;T[13].haute=0;T[13].pleine=1;
  T[14].ronde=1;T[14].claire=1;T[14].haute=1;T[14].pleine=0;
  T[15].ronde=1;T[15].claire=1;T[15].haute=1;T[15].pleine=1;*/   //pièce ronde,claire,haute et pleine
  
  ////////J AVAIS INITIALMENT DÉCLARER MA PIOCHE EN BRUT COMME CA MAIS J AI PREFERE FAIRE AVEC UNE BOUCLE FOR PAR LA SUITE. J AI LAISSÉ CETTE DÉCLARATION EN COMMENTAIRE AFIN DE MIEUX COMPREnDRE LA BOUCLE FOR QUI SUIT///////
   
  int i;
  for(i=0;i<16;i++)                                 //Déclaration du tableau de pièces à l'aide d'une boucle for
  {
      if(i<8) { T[i].ronde=0;}                      //Si i est inférieur à 8 je crée 8 pièces rondes
      else {T[i].ronde=1;}			    //pour i allant de 8 à 15 je crée 8 pièces carrées
      if(i<4 || ( i>7 && i<12 ) ) {T[i].claire=0;}  //Si i est inférieur à 4 ou compris entre 8 et 11, T[i].claire vaut 0 soit je crée 8 pièces sombres
      else {T[i].claire=1;}                         //Sinon T[i].claire vaut 1 je crée donc uassi 8 pièces claires
      if(i==0 || i==1 || i==4 || i==5 || i==8 || i==9 || i==12 || i==13) { T[i].haute=0;} //Je crée 8 pièces petites (deux pièces sur quatre)
      else { T[i].haute=1;}			    //Je crée 8 pièces haute
      if(i%2==0) {T[i].pleine=0;}		    //Je crée 8 pièces creuses (une pièce sur deux)
      else {T[i].pleine=1;}			    //Je crée 8 pièces pleines (une sur deux aussi donc)
  }
  //J'ai alors crée mon tableau en binaire de cette facon pour être sûr que toutes les combinaison possible de pièces sont présentes et qu'aucune ne se répette
}
int affichertableaupiece(piece T[],int b) //Entrées: Notre pioche et sa taille au moment de l'apel (dans le main(() on a "affichertableaupiece(T,16-i)" avec i le numéro du tour auquel on est
{
  int i,j;
  couleur("35;4;3;1");
  if(b!=1)                      //S'il reste plus d'une pièce dans la pioche on affiche le message suivant: Pièces disponibles (en magenta, souligné et en italique)
  {
  printf("Pièces disponibles");
  }
  else                          //Sinon on affiche: Dernière pièce disponible
  {
      printf("Dernière pièce disponible");
  }
  couleur("0");
  couleur("35;3");
  printf(":\n\n");              //J'enlève le soulignement pour les deux petits points en ne mettant pas le 4 dans la fonction couleur("")
  couleur("0");
  for(j=0;j<13;j++)             // Cette boucle est assez compliquée car on affiche sur une même ligne 2 caractéritiques de 4 pièces différentes à la suite
  {
    if(j==1) {j=4;}   		//Je procède à des sauts pour la valeurs de j. j vaut au premier tour 0, au deuxième 4 puis 8 puis 12
    if(j==5) {j=8;}
    if(j==9) {j=12;}
    for(i=0;i<4;i++)            //Cette boucle for permet d'afficher uniquement 4 numéros en ligne espacés allant de j+1 à j+4. Soit au premier passage 1,2,3,4, au second passage 5,6,7,8 puis 9,10,11,12 et enfin 13,14,15,16
    {
        couleur("1");
        if(i+j<b && i+j+1<10) {printf("%d                    ",i+j+1);}
        if(i+j<b && i+j+1>9) {printf("%d                   ",i+j+1);} //Dijonction de cas, si l'indice contient 1 ou 2 chiffres il faut ajuster un espace pour l'alignement
        couleur("0");
    }
    if(j<b) {printf("\n");}     //Je procède à un retour à la ligne tant qu'il reste des pièces à afficher sur la ligne suivante
    couleur("3");
    for(i=0;i<4;i++)            //Cette boucle permet d'afficher deux caractéristiques (si la pièce est claire ou sombre et ronde ou carré ) alignées séparées d'une virgules pour 4 pièces consécutives 
    {
	if(i+j<b)               //Je vérifie que la pièce que l'on va afficher fait toujours partie de la pioche
	{
	    if(T[i+j].claire==1) {printf("Claire, ");}    //J'affiche au premier passage (du for dépendant de j) si les pièces 1,2,3,4 sont claires ou sombres (au second les 5,6,7,8, etc)
	    else {printf("Sombre, ");}
	    if(T[i+j].ronde==1) {printf("Ronde        ");}//Puis rondes ou carrées
	    else {printf("Carrée       ");}
	}
    }
    if(j<b) {printf("\n");} 	//Je procède à un retour à la ligne tant qu'il reste des pièces à afficher sur la ligne suivante
    for(i=0;i<4;i++) 		//Cette boucle permet d'afficher deux caractéristiques (alignées séparées d'une virgules) pour 4 pièces consécutives 
    {
        if(i+j<b) 		//Je vérifie que la pièce que l'on va afficher fait toujours partie de la pioche
        {
            if(T[i+j].haute==1) {printf("Haute,  ");}       //J'affiche au premier passage (du for dépendant de j) si les pièces 1,2,3,4 sont hautes ou petites (au second les 5,6,7,8, etc)
            else {printf("Petite, ");}
            if(T[i+j].pleine==1) {printf("Pleine       ");} //Puis pleines ou creuses
            else {printf("Creuse       ");}
        }
    }
    
    if(j<b) {printf("\n");}             //Je procède à un retour à la ligne tant qu'il reste des pièces à afficher sur la ligne suivante
    couleur("0");
    for(i=0;i<4;i++)                    //Dans cette boucle for on affiche les références des pièces, par exemple pour la pièce 1 (sombre, carrée, petite, creuse): Ref: 0000, la dernière (claire,ronde,haute, pleine) Ref: 1111 car c'est la référence que l'on va afficher sur le plateau de jeux
    {
        if(i+j<b)                       //Je vérifie que la référence que l'on va afficher correspond à une pièce toujours présente dans la pioche
        {
            couleur("30");
            printf("(Ref: ");           //Affichage en noir
            couleur("1;3");
            printf("%d",T[i+j].claire); //Affichage en italique et gras des valeur. Pour cette ligne si la pièce est claire 1 si elle est sombre 0
            printf("%d", T[i+j].ronde);
            printf("%d", T[i+j].haute);
            printf("%d", T[i+j].pleine);
            couleur("0");
            couleur("30");
            printf(")          ");      //Je ferme la parenthèse de la même couleur que je l'ai ouverte (noir)
            couleur("0");
            
        }
    }
    
    if(4+j<b) {printf("\n\n");}         //Je vérifie qu'il y a des pièces à afficher au tour suivant avant de procéder aux retours à la ligne
    else			    	//Sinon pas besoin de faire tourner la boucle plus loin donc on sort de la fonction
    {
      printf("\n");
      return 0;
    }  
  }
  printf("\n");
  return 0;
}
 int choixpiece(int i) //pour choisir l'indice de la pièce que l'on veut donner à l'adversaire
{
   int n;
   couleur("36;3");
   printf(", choisissez le numero de pièce voulue pour votre adversaire: "); //Affichage du message en cyan et italique
   couleur("0");
   scanf("%d",&n);
   while((n>i+1) || (n<1))  //Saisie protégée de n, on ne veut pas n plus grand que i+1 ou plus petit que 1 car les indices devant les pièces de la pioches vont de 1 à i+1 (i+1 étant la taille de la pioche car dans le main() c'est la valeur de 16-i avec i le numéro du tour à laquel on se trouve soit au tour numéro 2 on a dans le main() 16-2=14 or il reste encore 15 pièces dans la pioche car nous sommes au début du tour 2 soit 15 pièces. On doit donc faire n>i+1
   {
       couleur("31");
       printf("Numero de piece non présent dans la pioche\n"); //Le message s'affiche en rouge pour interpeller le joueur qui a fait une mauvaise saisie
       couleur("0");
       scanf("%d",&n);
   };
   return n;                //Je retourne le numéro de la pièce choisie par la joueur
 }
piece piecechoisieetsuppressiondanstableau(piece T[],int b) //Je retourne la pièce voulue par le joueur et on la supprime de la pioche
{
   int n,i;
   n=choixpiece(b);   	    //n prend la valeur de l'indice de la pièce voulue
   piece A,*p;
   A=T[n-1];                //Je stock la pièce voulue dans une variable de type pièce que l'on retournera à la fin. Les indices sont affichés aux joueurs allant de 1 à 16 or dans les tableaux les indices vont de 0 à 15 donc je prends dans le tableau la pièce avec l'indice n-1
   p=&T[n-1];
   for(i=n-1;i<b;i++)       //Je procède dans cette boucle au décalage de toutes les pièces afin de supprimer la pièce qui a été choisie.
   {
     *p=*(p+1);             //Au premier tour p pointe sur la pièce choisie et prend alors la valeur de la pièce suivant. Ainsi de suite jusqu'à la fin de la pioche. La pièce est donc supprimée
     p++;
   }
   return A;                //Je retourne la pièce choisie
 }
 int choixplacesurplateau() //choix de l'indice de l'emplacement du plateau de jeux où le joueur veut mettre sa pièce
{
   int n;
   scanf("%d",&n);
   while ((n<1) || (n>16))  //Saisie protégée de n, on veut n compris entre 1 et 16
   {
       couleur("31");
       printf("Emplacement compris entre 1 et 16\n");//Le message s'affiche en rouge pour interpeller le joueur qui a fait une mauvaise saisie
       couleur("0");
       scanf("%d",&n);
   };
   return n;                //Je retourne l'emplacement souhaité sur le plateau par le joueur pour sa pièce
}
 void placercaracteristiquepiecesurplateau(piece A, int P[16][6], int i) //Je place les caractéristiques de la pièce sur le plateau de jeux
{
   int n;
   n=choixplacesurplateau(); //n prend la valeur de l'emplacement souhaité
   if(P[n-1][5]==0)          //Je vérifie grâce à ce if si l'emplacement est bien vide de toute pièce
   {
      P[n-1][1]=A.claire;    //Je place alors les divers caractéristiques sur le plateau
      P[n-1][2]=A.ronde;
      P[n-1][3]=A.haute;
      P[n-1][4]=A.pleine;
      P[n-1][5]=i;           //Je finis par inscrire le numéro du tour à laquel on a placé la pièce pour vérification du quarto
   }
   else                      //Si une pièce est déjà présente à l'emplacement voulu
   {
      couleur("31");
      printf("Dommage, l'emplacement est déjà prit. A quel emplacement voulez-vous mettre votre pièce?\n"); //J'affiche ce message en rouge pour interpeller
      couleur("0");
      placercaracteristiquepiecesurplateau(A,P,i); //Je rappelle alors cette même fonction pour redemander un emplacement au joueur
   }
}
int annoncerquarto()
{
   int r;
   couleur("36;3");
   printf(", voulez-vous annoncer un quarto? (1 pour oui, 0 pour non) ");
   couleur("0");
   scanf("%d",&r);                         //r est notre référence pour savoir si un quarto est annoncé (1 pour oui, 0 sinon)
   while((r!=1) && (r!=0))                 //Saisie protégée de r (On veut r=1 ou r=0) 
   {
         couleur("31");
         printf("Soit 0 soit 1\n");        //Le message s'affiche en rouge pour interpeler le joueur qui a fait une mauvaise saisie
         couleur("0");
         scanf("%d",&r);
   }
   return r;
}
int positionpourquatro() //Je demande ici un emplacement pour une des pièces participant au quarto
{
   int n;
   scanf("%d",&n);
   while((n<1) || (n>16))                            //Saisie protégée de n (on veut n compris entre 1 et 16)
   {
       couleur("31");
       printf("Emplacement compris entre 1 et 16\n");//Le message s'affiche en rouge pour interpeller le joueur qui a fait une mauvaise saisie
       couleur("0");
       scanf("%d",&n);
   }
   return n;              	  //Je retourne un numéro correspondant à un emplacement d'une des pièces participant au quarto
}
void triertableau(int T[],int n) //Je peux, grâce à cette fonction, trier dans l'ordre croissant un tableau d'entier de taille n
{
    int i,j,s;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(T[i]>T[j])   	//Je compare ici chaque case avec toutes les cases qui la suivent
            {
                s=T[i];     	//J'échange alors les cases si celle d'avant est plus grande que celle d'après
                T[i]=T[j];
                T[j]=s;
            }
        }
    }                       	// Le tableau est alors trié dans l'ordre croissant
}
int verificationcaracteristiquecommune(int P[16][6],int nu, int nd, int nt, int nq) //Je verifie grâce au plateau en parametre et des indices des emplacements si les 4 pièces ont une caractéristiques communes
{
    if(P[nu-1][1]==P[nd-1][1] && P[nd-1][1]==P[nt-1][1] && P[nt-1][1]==P[nq-1][1]) //Je vérifie si les pièces on leur première caractéristique en commun
      {
	return 1;               // Si oui on peut retourner 1 et donc sortir de la fonction
	
      }
      else                      //Sinon on va vérifier la deuxieme caracteristique
      {
	  if(P[nu-1][2]==P[nd-1][2] && P[nd-1][2]==P[nt-1][2] && P[nt-1][2]==P[nq-1][2]) //Je vérifie si les pièces on leur deuxième caractéristique en commun
	  {
	    return 1;          // Si oui on peut retourner 1 et donc sortir de la fonction
	    
	  }
	  else
	  {
	      if(P[nu-1][3]==P[nd-1][3] && P[nd-1][3]==P[nt-1][3] && P[nt-1][3]==P[nq-1][3]) //Je vérifie si les pièces on leur troisième caractéristique en commun
	      {
		    return 1;   // Si oui on peut retourner 1 et donc sortir de la fonction
		    
	      }
	      else
	      {
		  if(P[nu-1][4]==P[nd-1][4] && P[nd-1][4]==P[nt-1][4] && P[nt-1][4]==P[nq-1][4]) //Je vérifie si les pièces on leur quatrième caractéristique en commun
		  {
		      return 1; // Si oui on peut retourner 1 et donc sortir de la fonction
		      
		  }
	      }
	  }
      }
      return 0;                 // Si on arrive jusqu'ici c'est qu'aucune caractéristique n'est commune aux 4 pièces. On peut donc retourner 0
}
int alignement(int T[]) //Je procède aux vérifications pour tous les alignements possibles (le tableau contient les indices des positions des pièces participant au quatro rangées dans l'ordre croissant)
{
	int v=-1;
        v=verifierligne(T);			//v vaut 1 si les positions forment une ligne, 0 sinon
	if(v==0) {v=verifiercolonne(T);}	//v vaut 1 si les positions forment une colonne, 0 sinon
	if(v==0) {v=verifierdiag(T);}		//v vaut 1 si les positions forment une diagonal, 0 sinon
        return v;				//On retourne donc 1 si une alignement est vérifié, 0 sinon
}
int verifierligne(int T[]) //Fonction qui vérifie si les positions forment une ligne (le tableau contient les indices des positions des pièces participant au quatro rangées dans l'ordre croissant)
{
	int i;
	for(i=1;i<14;i++)
	{
	  if(i>1 && i<3) {i=5;}
	  if(i>5 && i<7) {i=9;}
	  if(i>9 && i<11) {i=13;} 	//Je procède à des sauts pour la valeur de i car on vérifie les lignes et chaque ligne possible commence soit pas 1 soit 5 soit 9 soit 13
	  if(T[0]==i)
	  {
	    if(T[1]!=i+1) {return 0;}	//Je vérifie ensuite que les positions se suivent pour former une ligne
	    if(T[2]!=i+2) {return 0;}
	    if(T[3]!=i+3) {return 0;}
	    return 1;			//Je retourne 1 que si toutes les positions se suivent, par exemple 1,2,3,4
	  }
	}
	return 0;			//Je retourne 0 si aucune ligne n'est vérifiée
  
}
int verifiercolonne(int T[]) //Fonction qui vérifie si les positions forment une colonne (le tableau contient les indices des positions des pièces participant au quatro rangées dans l'ordre croissant)
{
	int i;
	for(i=1;i<5;i++)		//Je vérifie les colonnes donc la première position est forcément une position de la première ligne (1,2,3 ou 4)
	{
	  if(T[0]==i)			//Je repère le moment où la première case du tableau est égal à une des positions de la première ligne
	  {
	    if(T[1]!=i+4) {return 0;}   //Pour vérifier un alignement en colonne les positions doivent être espacées de 4 cases comme par exemple les positions 1,5,9,13 sont alignées verticalement
	    if(T[2]!=i+8) {return 0;}
	    if(T[3]!=i+12) {return 0;}
	    return 1;                  //Je retourne 1 seulement si les cases sont alignées verticalement
	  }
	}
	return 0;                      //Je retourne ce 0 si la première case du tableau n'est pas comprise entre 1 et 4 soit qu'aucune colonne n'est vérifiée
  
}
int verifierdiag(int T[])   //Fonction qui vérifie si les positions forment une diagonal // Seulement deux cas 
{
	if(T[0]==1)                    //Meme principe que précédemment
        {
            if(T[1]!=6) {return 0;}
            if(T[2]!=11) { return 0; }
            if(T[3]!=16) { return 0;}
            return 1;
        }
        if(T[0]==4)
        {
            if(T[1]!=7) {return 0;}
            if(T[2]!=10) { return 0; }
            if(T[3]!=13) { return 0;}
            return 1;
        }
        return 0;
}
int verifiercarre(int T[])  //Je verifie si les pièces sont en petit carré (le tableau contient les indices des positions des pièces participant au quatro rangé dans l'ordre croissant)
{
    int i;
    for(i=1;i<12;i++)		//i n'a pas besoin d'aller après 11 car pour un carré la valeur de l'indice le plus petit ne peut pas être 12,13,14,15,16
    {
      if(i==4) {i=5;}
      if(i==8) {i=9;}
      if(i==12) {i=13;}		//Je procède à des sauts pour i car si un carré est possible, la valeur de l'indice le plus petit ne peut être 4,8,12
      if(T[0]==i)		//Si le plus petit indice est i (par exemple 2)
      {
	if(T[1]!=i+1) {return 0;}	//alors la seconde valeur sera i+1 soit la case à sa droite (3)
	if(T[2]!=i+4) {return 0;}	//puis la case sous la première soit i+4 (6)
	if(T[3]!=i+5) {return 0;}	//puis celle à droite de celle-ci soit i+5 (7)
	return 1;
      }
      
    }
    return 0;
}
int verifiergrandcarre(int T[])     //Je verifie si les positions forment un grand carré ou un petit (mode de jeux 2) (le tableau contient les indices des positions des pièces participant au quatro rangées dans l'ordre croissant)
{
    int v;
    v=verifiercarre(T);             //Si un petit carré est vérifié v vaut 1
    if(v==1)
    {
        return 1; 	            //Si v vaut 1 on peut retourner 1 car un petit carré est vérifié
    }
    //Sinon je vérifie si les positions forment un grand carré. La fonction marche de la même façon que les 2 précédentes
    if(T[0]==1) 	            //Si le premier indice est 1 on a plus que le choix du grand carré avec les positions 1,3,9,11
    {
        if(T[1]!=3) {return 0;}     //Si le deuxieme indices est différents de 3 alors que le premier est 1 alors un grand carré est impossible
        if(T[2]!=9) {return 0;}
        if(T[3]!=11) {return 0;}
        return 1;                   //Si on arrive ici c'est qu'on est en présence des indices 1,3,9,11 soit un grand carré. On peut retourner 1
    }
    if(T[0]==2)                     //LA suite est sur le même principe
    {
        if(T[1]!=4) {return 0;}
        if(T[2]!=10) {return 0;}
        if(T[3]!=12) {return 0;}
        return 1;
    }
    if(T[0]==5)
    {
        if(T[1]!=7) {return 0;}
        if(T[2]!=13) {return 0;}
        if(T[3]!=15) {return 0;}
        return 1;
    }
    if(T[0]==6)
    {
        if(T[1]!=8) {return 0;}
        if(T[2]!=14) {return 0;}
        if(T[3]!=16) {return 0;}
        return 1;
    }
    return 0;                       //Si on arrive ici c'est qu'aucun if n'est passé soit que le premier indice est autre que 1,2,5,6 donc un grand carré est impossible on retourne 0
}
int verifiercarreretourne(int T[])  //Je vérifie ici si les indices sont en petit carré,grand carré ou grand carré retourné (mode de jeux 3) (le tableau contient les indices des positions des pièces participant au quatro rangées dans l'ordre croissant)
{
    int v;
    v=verifiergrandcarre(T);        //Si un grand ou un petit carré est vérifié, v vaut 1, 0 sinon
    if(v==1)
    {
        return 1;                   //Si v vaut 1 on peut retourner 1 car un petit carré ou un grand est vérifié
    }
    //Sinon je vérifie si les positions forment un grand carré retourné. La fonction marche de la même façon que les précédentes
    if(T[0]==2) //Si le premier indice est 2 on a plus que le choix du grand carré retourné avec les positions 2,5,7,10
    {
        if(T[1]!=5) {return 0;}
        if(T[2]!=7) {return 0;}
        if(T[3]!=10) {return 0;}
        return 1;
    }
    if(T[0]==3)
    {
        if(T[1]!=6) {return 0;}
        if(T[2]!=8) {return 0;}
        if(T[3]!=11) {return 0;}
        return 1;
    }
    if(T[0]==6)
    {
        if(T[1]!=9) {return 0;}
        if(T[2]!=11) {return 0;}
        if(T[3]!=14) {return 0;}
        return 1;
    }
    if(T[0]==7)
    {
        if(T[1]!=10) {return 0;}
        if(T[2]!=12) {return 0;}
        if(T[3]!=15) {return 0;}
        return 1;
    }
    return 0;                               //Si on arrive ici c'est qu'aucun if n'est passé soit que le premier indice est autre que 2,3,6,7 donc un grand carré retourné est impossible on retourne 0
}
int verificationduquatro(int P[16][6], int i, int a) //Fonction vérifiant le quarto en appelant les fonctions précédentes
{
   int v, nu,nd,nt,nq;
   couleur("36;3");
   printf("Entrez les numéros de position des pièces qui participent au quarto\n(Si jamais vous entrez plusieurs fois la même position par erreur ou une case vide, entrez 4 positions et vous pourrez les retaper\nà nouveau)\n");
   couleur("0");
   nu=positionpourquatro();                 //On demande au joueur l'indice des 4 pièces participant à son quarto
   nd=positionpourquatro();
   nt=positionpourquatro();
   nq=positionpourquatro();
   do
   {
      while(nu==nd || nu==nt || nu==nq || nd==nt || nd==nq || nt==nq) //Saisie protégée des valeurs au cas où le joueur entre plusieurs fois la même position par erreur
      {
	    couleur("31");
	    printf("Vous avez entré plusieurs fois une même position. Entrez à nouveau les numéros de position des pièces qui participent au quarto\n");
	    couleur("0");
	    nu=positionpourquatro();            //Je demande à nouveau au joueur l'indice des 4 pièces participant à son quarto
	    nd=positionpourquatro();
	    nt=positionpourquatro();
	    nq=positionpourquatro();
      };
      while(P[nu-1][5]==0 || P[nd-1][5]==0 || P[nt-1][5]==0 || P[nq-1][5]==0) //Saisie protégée des valeurs au cas où le joueur entre une position vide par erreur
      {
	    couleur("31");
	    printf("Vous avez entré une ou plusieurs positions vides. Entrez à nouveau les numéros de position des pièces qui participent au quarto\n");
	    couleur("0");
	    nu=positionpourquatro();            //Je demande à nouveau au joueur l'indice des 4 pièces participant à son quarto
	    nd=positionpourquatro();
	    nt=positionpourquatro();
	    nq=positionpourquatro();
      };
   }while( (nu==nd || nu==nt || nu==nq || nd==nt || nd==nq || nt==nq) || (P[nu-1][5]==0 || P[nd-1][5]==0 || P[nt-1][5]==0 || P[nq-1][5]==0));
   //On ne continue que si le joueur a entré des numéros de position valide
   int T[4]={nu,nd,nt,nq};  //Je place ces indices dans un tableau
   triertableau(T,4);       //Je trie ce tableau dans l'ordre croissant
   couleur("31");
   /*if(P[nu-1][5]==0 || P[nd-1][5]==0 || P[nt-1][5]==0 || P[nq-1][5]==0) //Je vérifie que les indices correspondent à des emplacements occupés par des pièces
   {
       printf("Vous perdez car un ou plusieurs emplacements mentionnés sont vides\n");
       return 0; // Si ca n'est pas le cas on peut sortir de la fonction et retourner 0 pour signaler que le joueur à fait une mauvaise annonce de quarto
   }*/ 
   
   //Avec le if précédent je choisissais de faire perdre le joueur s'il tape une position vide sur le plateau par erreur au lieu de lui demander d'en entrer de nouvelles grâce au while précédent
   
   if(P[nu-1][5]<i-2 && P[nd-1][5]<i-2 && P[nt-1][5]<i-2 && P[nq-1][5]<i-2) //Je vérifie si la dernière pièce posée l'a été maximum 1 tour avant
   {
     printf("Vous perdez car la dernière pièce posée l'a été il y a plus d'un tour\n");
     return 0;                              // Si ca n'est pas le cas on peut sortir de la fonction et retourner 0 pour signaler que le joueur à fait une mauvaise annonce de quarto (pour l'affichage des demande de revanche, on demandera si le joueur qui a annoncé un mauvais quarto souhaite une revanche)
   }
   else
   {
     v=verificationcaracteristiquecommune(P, nu, nd, nt, nq); //Je regarde si les pièces ont au moins une caractéristique commune. Si c'est le cas v=1, 0 sinon
   }
   if(v==0)                                 //Si v vaut 0 les pièces n'ont pas de caractéritique commune donc pas besoin de vérifier les alignements ou carré on peut retourner 0 et afficher que l'annonceur de quarto perd
   {
       printf("Vous perdez car les pièces n'ont pas de caractéristique commune\n");
       return 0;                            // Si v vaut 0 c'est que les pièces n'ont pas de caractéristique commune on peut donc sortir de la fonction et retourner 0
   }
   v=alignement(T);                         // Si on arrive là c'est que v=1 donc une caractéristique est commune et que la dernière pièce a été posé il y maximum un tour. On vérifie donc l'alignement. v=1 si les pièces sont alignées, 0 sinon
   if(v==0 && a==0)                         //Si a=0 c'est qu'on est en mode de jeux 0 où seuls les alignement sont prit en compte. v=0 donc pas d'alignement. Le joueur a donc perdu
   {
       printf("Vous perdez car vous êtes en mode de jeux 0 et vos pièces ne sont pas alignées\n");
       return 0;                            //Seuls les alignements sont prit en compte et il n'y en a pas (car v=0) donc le quarto est faux. On peut sortir de la fonction et retourner 0
   }
   if(v==0 && a==1)                         //Si a=1 on est en mode de jeux 1 ce qui signifie que les petits carrés sont prit en compte pour le quarto
   {
       v=verifiercarre(T);                  //v=1 si les pièces sont en petit carré, 0 sinon
       if(v==0)
       {
            printf("Vous perdez car vous êtes en mode de jeux 1 et vos pièces sont ni alignées ni en petit carré\n");
            return 0;                       //Si on arrive ici c'est qu'on est en mode de jeux 1 et que les pièces sont ni alignées ni en carré on peut donc retourner 0 et sortir de la fonction
       }
   }
   if(v==0 && a==2)                         //Si a=2 on est en mode de jeux 2 ce qui signifie que les petits et grands carrés sont prit en compte pour le quarto
   {
        v=verifiergrandcarre(T);            //v=1 si un grand ou un petit carré est vérifié, 0 sinon
        if(v==0)
        {
            printf("Vous perdez car vous êtes en mode de jeux 2 et vos pièces sont ni alignées ni en petit ou grand carré\n");
            return 0;                       //Si on arrive ici c'est que les pièces sont ni alignées ni en carré on peut donc retourner 0 et sortir de la fonction
        }
   }
   if(v==0 && a==3)                         //Si a=3 on est en mode de jeux 3 ce qui signifie que les petits et grands carrés et grands carrés retournés sont prit en compte pour le quarto
   {
       v=verifiercarreretourne(T);          //v=1 si un petit carré un grand carré ou un grand carré retourné est vérifié, 0 sinon
       if(v==0)
       {
           printf("Vous perdez car vous êtes en mode de jeux 3 et vos pièces sont ni alignées, ni en quelconque carré (petit grand ou grand retourné)\n");
           return 0;
       }
   }
   if(v==1)				    //Si v =1 c'est que toutes les conditions pour réaliser un quarto sont vérifiées
   {
       couleur("36;3");
       printf("Vous gagnez!\n");            //J'affiche que l'annonceur de quarto gagne
       couleur("0");
       return 1;                            //Le quarto est validé on retourne donc 1 pour indiquer dans le main() que l'annonceur du quarto a gagné ce qui permettra de savoir que l'on demandera à l'autre joueur s'il veut une revanche
   }
   couleur("0");
   return 0;
}
int demandederevanche(int n,joueur J1,joueur J2,int w)
{
	int i;
	if(w==0)                               //Quarto erroné annoncé (w=0) on demande donc a l'annonceur de quarto s'il souhaite une revanche
        {
            couleur("35;3;1");
	    appeljoueur(n,J1,J2);
            couleur("0");
            couleur("35;3");
            printf(", votre annonce de quarto était erronée, voulez vous une revanche? (1 pour oui 0 pour non)\n");
            couleur("0");
            scanf("%d",&i);
            while(i!=0 && i!=1)                //Saisie protégée de i, i doit valoir 1 si le joueur souhaite une revanche, 0 sinon 
            {
                couleur("31");
                printf("Soit 0 soit 1\n");
                couleur("0");
                scanf("%d",&i);
            };
        }
        if(w==0 && i==1)                        //Quarto erroné annoncé (w=0) et où l'annonceur du quarto souhaite une revanche
        {
            couleur("35;3;1");
	    appeljoueur(n+1,J1,J2);
            couleur("0");
            couleur("35;3");
            printf(", acceptez vous la revanche? (1 pour oui 0 pour non)\n"); //On demande donc à l'autre joueur s'il accepte la revanche
            couleur("0");
            scanf("%d",&i);
            while(i!=0 && i!=1)                  //Saisie protégée de i, soit 1 soit 0 s"il souhaite rejouer ou non
            {
                couleur("31");
                printf("Soit 0 soit 1\n");       //Affichage du message en rouge pour interpeler le joueur qui a fait une mauvaise saisie
                couleur("0");
                scanf("%d",&i);
            };
        }
        if(w==1)                                //Un quarto juste annoncé (w=1) on demande donc au perdant s'il souhaite une revanche
        {
            couleur("35;1;3");
	    appeljoueur(n+1,J1,J2);
            couleur("0");
            couleur("35;3");
            printf(", vous avez perdu mais souhaitez vous une revanche? (1 pour oui 0 pour non)\n");
            couleur("0");
            scanf("%d",&i);
            while(i!=0 && i!=1)                 //Saisie protégée de i, i doit valoir 1 si le joueur souhaite une revanche, 0 sinon 
            {
                couleur("31");
                printf("Soit 0 soit 1\n");      //Affichage du message en rouge pour interpeler le joueur qui a fait une mauvaise saisie
                couleur("0");
                scanf("%d",&i);
            };
        }
        if(w==1 && i==1)                        //Un quarto juste (w=1) et où le perdant souhaite une revanche (i=1)  
        {
            couleur("35;1;3");
	    appeljoueur(n,J1,J2);
            couleur("0");
            couleur("35;3");
            printf(", acceptez vous la revanche? (1 pour oui 0 pour non)\n"); //On demande au joueur s'il accepte la revanche
            couleur("0");
            scanf("%d",&i);
            while(i!=0 && i!=1)                  //Saisie protégée de i (soit 0 soit 1)
            {
                couleur("31");
                printf("Soit 0 soit 1\n");       //Affichage du message en rouge pour interpeler le joueur qui a fait une mauvaise saisie
                couleur("0");
                scanf("%d",&i);
            };
        }
        return i;                                //i vaut 1 si les joueurs veulent rejouer, 0 sinon
}
 int egalitedemandersirejouer()
{
   int i;
   couleur("35;3");
   printf("\n\nEgalité ! Voulez-vous rejouer? (1 pour oui 0 pour non)\n"); //On annonce qu'il y a égalité et on demande si les joueurs veulent rejouer
   couleur("0");
   scanf("%d",&i);
   while(i!=0 && i!=1)                            //Saisie protégée de i (on veut soit 0 soit 1)
   {
         couleur("31");
         printf("Soit 1 soit 0");                 //Affichage du message en rouge pour interpeler le joueur qui a fait une mauvaise saisie
         couleur("0");
         scanf("%d",&i);
   }
   return i;                                      //i vaut 1 si les joueurs veulent rejouer, 0 sinon
}
 void partie()
{
      clrscr();               			  //La fonction "clrscr()" permet d'effacer la console et de mettre le curseur en haut à gauche
      affichergenerique();			  //J'affiche le generique de la partie (nom du jeux, règles
      piece T[16], A;  				  //Déclaration d'un tableau de structure piece (contenant 16 pièces) qui sera utilisé comme étant la pioche et d'une variable de type piece
      joueur J1, J2, *p;			  //Déclaration de deux joueur ainsi qu'un pointeur de type joueur (car pour chaque demande pour choisir une pièce ou la placer on appelera le joueur qui doit jouer par son prénom)
      int P[16][6];                               //Déclaration d'un tableau 2D de type int qui sera le plateau de jeux
      int i, r, a, n,w=-1,h,k;                    //Déclaration de 7 entiers
      p=&J1;  					  //Je vais chercher un faire entrer les noms des deux joueurs. On fait donc pointer le pointeur sur notre premier joueur
      couleur("35;3");
      printf("\n\n\nLe premier joueur à jouer sera tiré aléatoirement.");
      couleur("0");
      printf("\nEntrez le nom du joueur 1: ");
      J1=creerunjoueur(p);                         //Puis j'appelle la fonction creer un joueur avec le pointeur en paramètre
      printf("Entrez le nom du joueur 2: ");
      p=&J2;                                       //De même avec le deuxième joueur
      J2=creerunjoueur(p);
      do                                           //Je démarre une boucle DoWhile qui va servir à recommencer une partie si le perdant souhaite une revanche et si l'autre joueur l'accepte
      { 
	    for(h=0;h<16;h++)                      //Initialisation du plateau de jeux
	    {
		P[h][0]=h+1;                       //Je place un numéro devant chaque emplacement (de 1 à 16)
		for(k=0;k<5;k++)
		{
		    P[h][k+1]=0;                   //Je met tous les autres paramètres à 0
		}
	    }
	    i=0;                                   //i vaut 0, il servira à connaitre à quel tour nous sommes lors des appels des différentes fonctions
	    r=-1;                                  //r vaut -1, il servira à savoir si un quarto a été annoncé (il vaudra par la suite 1 si oui, 0 si non)
	    initialisertableau(T) ;                //J'initialise le tableau de pièces
	    affichermodesjeux();
	    a=entrermodedejeux();
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Saut de ligne afin qu'on ne voit que le jeux (plateau de jeux et pioche) sur la console 
	    srand(time(NULL));                     //Grâce à ces deux fonctions on fait prendre une valeur "aléatoire" à n afin que le premier joueur à jouer soit aléatoire
	    n=rand();
	    do                                     //Cette boucle DoWhile sert à faire défiler les tours jusqu'à ce qu'un quarto soit annoncé ou que toutes les pièces soient posées sur le plateau de jeux
	    {
		    
		    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Saut de ligne afin qu'on ne voit que le jeux (plateau de jeux et pioche) sur la console 
		    affichernumeromodedejeux(a);
		    afficherplateau(P);                       //Affichage du plateau de jeux
		    n++;                                      //J' augmente n de 1 afin de le faire passer de pair à impair ou inversement pour l'apel des joueurs
		    i++ ;                                     //J' augmente i de 1 car i est notre référence pour savoir à quel tour nous sommes
		    affichertableaupiece(T,16-i+1);           //J' affiche la pioche, 16-i+1 correspond à se taille, si nous sommes au début du deuxième tour, i vaut 2 et il doit y avoir 15 pièces de visibles
		    if(i>4)                                   //A partir du moment où il y a 4 pièces de placé sur le plateau un quarto est possible, on le demande à paritr du 4 eme tour
		    {
			couleur("36;1;3");
			appeljoueur(n,J1,J2);
			r=annoncerquarto();		      //r vaut 1 si le joueur annonce un quarto, 0 sinon
			couleur("0");
			if(r==1)                              // Si r=1 un quarto à été annoncé on le vérifie donc
			{
			    couleur("36;1;3");
			    appeljoueur(n,J1,J2);
			    couleur("0");
			    couleur("36");
			    printf(":");
			    couleur("0");
			    couleur("33;3");
			    printf(" QUAAAAARTO !!\n");
			    couleur("0");
			    w=verificationduquatro(P, i, a);    //Je vérifie alors le quarto (w=1 si le joueur gagne, 0 sinon)
			    
			}
		    }
		    if(r!=1)                                    //Si r est différent de 1 aucun quarto n'a été annoncé, on peut donc continuer la partie
		    {
			couleur("36;1;3");
			appeljoueur(n,J1,J2);
			couleur("0");
			A=piecechoisieetsuppressiondanstableau(T,16-i);     //Je demande au joueur quel pièce il veut donner à son adversaire et celle-ci se supprime de le pioche
			couleur("36;1;3");
			appeljoueur(n+1,J1,J2);
			couleur("0");
			couleur("36;3");
			printf(", à quel emplacement voulez-vous mettre votre pièce? ");
			couleur("0");
			placercaracteristiquepiecesurplateau(A, P, i);      //Puis je demande à l'autre joueur où il veut placer cette pièce
			
		    }
	    }while(i<16 && r!=1);                             //Je continue la partie tant qu'aucun quarto n'a été annoncé (r!=1) ou tant qu'il reste des pièces à placer sur le plateau de jeux (i<16)
	    if(i==16 && r!=1)                                         //Si i=16 on est sortie de la boucle de jeux or le dernier joueur à avoir posé une pièce sur le plateau souhaite peut-être annoncer un quarto
	    {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			afficherplateau(P);                   //J'affiche alors le plateau de jeux remplie
			printf("\n\n\n\n\n");
			couleur("36;1;3");
			appeljoueur(n+1,J1,J2);
			r=annoncerquarto();		      //r vaut 1 si le joueur annonce un quarto, 0 sinon
			couleur("0");
			if(r==1)
			{
			    couleur("36;1;3");
			    appeljoueur(n+1,J1,J2);
			    couleur("0");
			    couleur("36");
			    printf(":");
			    couleur("0");
			    couleur("33;3");
			    printf(" QUAAAAARTO !!\n\n"); 
			    couleur("0");
			    w=verificationduquatro(P, i, a);  //Vérification du quarto si le joueur en annonce un. w vaut 1 si le quarto est bon, 0 sinon
			    
			}
			n++;
	    }
	    if(i==16 && r==0)                                 //Cas où toutes les pièces ont été posé (i=16) mais où aucune quarto n'a été annoncé (r=0) il y a donc égalité      
	    {
		i=egalitedemandersirejouer();		      //On demande aux joueurs s'ils souhaitent faire une nouvelle partie. On recycle la variable i. i vaut 1 si les joueurs veulent rejouer, 0 sinon
	    }
	    else { i=demandederevanche(n,J1,J2,w); }	      //Sinon c'est que nous ne sommes pas allé jusqu'au 16eme tour donc qu'un joueur a annoncé un quarto. On demande alors au joueur perdant (soit celui qui a subit un quarto soit celui qui l'a annoncé s'il était faux) s'il souhaite une revanche et ensuite si l'autre l'accepte. i vaut 1 si les deux joueurs veulent rejouer, 0 sinon
      }while(i==1);
}