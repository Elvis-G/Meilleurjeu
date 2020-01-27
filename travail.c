#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void SetColor(int ForgC) {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

// Structure Ennemies //

typedef struct Monstre Monstre_t;
struct Monstre
{
    int level;
    int pointdeviemax;
    int pointdevie;
    int attaque;
    int defense;
    int magie;
    int mp;
    int esquive;
    int exp;
};

// Structure Hero //

typedef struct LeHeros LeHeros_t;
struct LeHeros
{
    int level;
    int pointdeviemax;
    int pointdevie;
    int attaque;
    int defense;
    int magie;
    int mp;
    int exp;
    int expMax;
    int esquive;
};

// Structure Allies //

typedef struct Allies Allies_t;
struct Allies
{
    int level;
    int pointdeviemax;
    int pointdevie;
    int attaque;
    int defense;
    int magie;
    int mp;
    int exp;
    int expMax;
    int esquive;


};

typedef struct Capacites Capacites_t;
struct Capacites
{
    int degats;
    int coutMP;
    int cooldown;
    int tauxReussite;
    int tauxCritique;
};



int main (){

int jeu = 0;
int progression = 0;
int skillpoints = 60;

int coffre = 0;
int leHeal = 0;
int esquiveMonstre = 0;

int avancer = 0;

// Message de Début de Partie //
SetColor(15);
printf("%s\n\n", "");
printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       BIENVENUE CHER JOUEUR PREPARER VOUS A EMBARQUER       |");
printf("%s\n", "                           |     DANS UNE AVENTURE OU SEUL LA MORT Y METTRA UN TERME,    |");
printf("%s\n", "                           |                    ALORS BONNE CHANCE!!!                    |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(4000);

// Stats Base Hero //

SetColor(3);
LeHeros_t heros = {1, 250, 250, 0, 0, 0, 0, 0, 5, 0};
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s%d\n", "LEVEL : ", heros.level);
printf("%s%d\n", "Point de vie : ", heros.pointdevie);
printf("%s%d\n", "Attaque : ", heros.attaque);
printf("%s%d\n", "Defense : ", heros.defense);
printf("%s%d\n", "Magie : ", heros.magie);
printf("%s%d\n", "MP : ", heros.mp);
printf("%s%d\n", "Esquive : ", heros.esquive);
printf("%s%d%s%d\n", "Experience : ", heros.exp, "/", heros.expMax);
SetColor(15);

// Attribution des SkillPoints //

// SkillPoints Attaque //

printf("\n%s\n", "Comme vous pouvez le constatez, vos stats se trouvent toutes a 0");
printf("%s\n", "Vous allez donc devoir attribuer au total 60 points de competences, choissisez intelligement, il n'est pas possible de revenir en arriere");
printf("%s", "Attaque : ");
scanf("%d", &heros.attaque);
coffre = skillpoints;
skillpoints = skillpoints - heros.attaque;
while (skillpoints < 0){
  printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
  printf("\n%s", "Attaque : ");
  scanf("%d", &heros.attaque);
  skillpoints = coffre - heros.attaque;
}
printf("\n%s%d", "Points de competences restant : ", skillpoints);

// SkillPoints Defense //

printf("\n%s", "Defense : ");
scanf("%d", &heros.defense);
coffre = skillpoints;
skillpoints = skillpoints - heros.defense;
while (skillpoints < 0){
  printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
  printf("\n%s", "Defense : ");
  scanf("%d", &heros.defense);
  skillpoints = coffre - heros.defense;
}
printf("\n%s%d", "Points de competences restant : ", skillpoints);

// SkillPoints Magie //

printf("\n%s", "Magie : ");
scanf("%d", &heros.magie);
coffre = skillpoints;
skillpoints = skillpoints - heros.magie;
while (skillpoints < 0){
  printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
  printf("\n%s", "Magie : ");
  scanf("%d", &heros.magie);
  skillpoints = coffre - heros.magie;
}
printf("\n%s%d", "Points de competences restant : ", skillpoints);

// SkillPoints MP //

printf("\n%s", "MP : ");
scanf("%d", &heros.mp);
coffre = skillpoints;
skillpoints = skillpoints - heros.mp;
while (skillpoints < 0){
  printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
  printf("\n%s", "MP : ");
  scanf("%d", &heros.mp);
  skillpoints = coffre - heros.mp;
}
printf("\n%s%d", "Points de competences restant : ", skillpoints);

// SkillPoints Esquive //

printf("\n%s", "Esquive : ");
scanf("%d", &heros.esquive);
coffre = skillpoints;
skillpoints = skillpoints - heros.esquive;
while (skillpoints < 0){
  printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
  printf("\n%s", "Esquive : ");
  scanf("%d", &heros.esquive);
  skillpoints = coffre - heros.esquive;
}
printf("\n%s%d\n", "Points de competences restant : ", skillpoints);

// Affichage Hero et ses Stats //

printf("\n\n%s\n", "VOICI LA FICHE DE VOTRE PERSONNAGE ");

SetColor(3);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", heros.level);
printf("%s", "Point de vie : ");
printf("%d\n", heros.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", heros.attaque);
printf("%s", "Defense : ");
printf("%d\n", heros.defense);
printf("%s", "Magie : ");
printf("%d\n", heros.magie);
printf("%s", "MP : ");
printf("%d\n", heros.mp);
printf("%s", "Esquive : ");
printf("%d\n", heros.esquive);
printf("%s%d%s%d\n\n", "Experience : ", heros.exp, "/", heros.expMax);
SetColor(15);

Sleep(2000);

// Affichage Alliés et leur Stats //

printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       VOICI LES PERSONNAGES QUI VONT VOUS ACCOMPAGNER       |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(2000);

// Georges //

SetColor(4);
Allies_t georges ={1, 150, 150, 10, 5, 20, 20, 0, 5, 5};
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", georges.level);
printf("%s", "Point de vie : ");
printf("%d\n", georges.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", georges.attaque);
printf("%s", "Defense : ");
printf("%d\n", georges.defense);
printf("%s", "Magie : ");
printf("%d\n", georges.magie);
printf("%s", "MP : ");
printf("%d\n", georges.mp);
printf("%s", "Esquive : ");
printf("%d\n", georges.esquive);
printf("%s%d%s%d\n\n", "Experience : ", georges.exp, "/", georges.expMax);
SetColor(15);

Sleep(1000);

// David //

SetColor(14);
Allies_t david ={1, 400, 400, 10, 30, 5, 10, 0, 5, 5};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", david.level);
printf("%s", "Point de vie : ");
printf("%d\n", david.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", david.attaque);
printf("%s", "Defense : ");
printf("%d\n", david.defense);
printf("%s", "Magie : ");
printf("%d\n", david.magie);
printf("%s", "MP : ");
printf("%d\n", david.mp);
printf("%s", "Esquive : ");
printf("%d\n", david.esquive);
printf("%s%d%s%d\n\n", "Experience : ", david.exp, "/", david.expMax);
SetColor(15);

Sleep(1000);

// Bernard //

SetColor(2);
Allies_t bernard ={1, 180, 180, 25, 5, 5, 5, 0, 5, 15};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", bernard.level);
printf("%s", "Point de vie : ");
printf("%d\n", bernard.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", bernard.attaque);
printf("%s", "Defense : ");
printf("%d\n", bernard.defense);
printf("%s", "Magie : ");
printf("%d\n", bernard.magie);
printf("%s", "MP : ");
printf("%d\n", bernard.mp);
printf("%s", "Esquive : ");
printf("%d\n", bernard.esquive);
printf("%s%d%s%d\n\n", "Experience : ", bernard.exp, "/", bernard.expMax);
SetColor(15);

Sleep(1000);

// Daniel //

SetColor(5);
Allies_t daniel ={1, 300, 300, 15, 15, 10, 10, 0, 5, 10};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", daniel.level);
printf("%s", "Point de vie : ");
printf("%d\n", daniel.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", daniel.attaque);
printf("%s", "Defense : ");
printf("%d\n", daniel.defense);
printf("%s", "Magie : ");
printf("%d\n", daniel.magie);
printf("%s", "MP : ");
printf("%d\n", daniel.mp);
printf("%s", "Esquive : ");
printf("%d\n", daniel.esquive);
printf("%s%d%s%d\n\n", "Experience : ", daniel.exp, "/", daniel.expMax);
SetColor(15);

Sleep(1000);

// Accepter de rentrer dans la partie //

printf("\n%s\n", "Avant de vous presentez leurs capacites, notez sur un papier les stats de vos personnages, cela peut s'averer utile");
printf("\n%s\n", "Vous etes pret ? Si oui, entrer le numero [1] ");
while (avancer != 1){
scanf("%d", &avancer);
}
avancer = 0;

if (avancer == 1) {
printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |     VOICI LES CAPACITES DETAILLES DE CHAQUE PERSONNAGES     |");
printf("%s\n", "                           |_____________________________________________________________|");

}

// Présentation des attaques de chaque personnage //

// Attaque du Hero //

SetColor(3);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup d'epee [1]" "      | Cette attaque n'utilise pas de MP et ses degats seront bases en fonction de l'attaque de votre Personnage");
printf("%s\n", "Boule de Feu [2]" "     | Cette attaque utilise des MP et ses degats seront bases en fonction de la magie de votre Personnage");
printf("%s\n", "Repos [3]" "            | Cette attaque n'utilise pas de MP et permet de recuperer des points de vie, vous ne pourrez plus attaquer pendant 3 tours");
SetColor(15);

Capacites_t coupEpee ={1*heros.attaque, 0, 0, 100, 10};
Capacites_t bouleDeFeu ={1*heros.magie, 5, 0, 100, 10};
Capacites_t repos ={0, 0, 0, 90, 0};

Sleep(2000);

// Attaque de Georges //

SetColor(4);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup de Baguette [1]" " | Cette attaque n'utilise pas de MP et ses degats seront bases en fonction de l'attaque de Georges");
printf("%s\n", "Foudre [2]" "           | Cette attaque utilise des MP et ses degats seront bases en fonction de la magie de Georges");
printf("%s\n", "Soin [3]" "             | Cette attaque utilise des MP et permet de faire recuperer des points de vie au joueur cibler");
SetColor(15);

Capacites_t coupBaguette ={1*georges.attaque, 0, 0, 100, 10};
Capacites_t foudre ={1*georges.magie, 5, 0, 90, 10};
Capacites_t soin ={10*georges.magie, 10, 0, 90, 0};

Sleep(2000);

// Attaque de David //

SetColor(14);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup de Bouclier [1]" " | Cette attaque n'utilise pas de MP et ses degats seront bases en fonction de l'attaque de David");
printf("%s\n", "Coup Fatal [2]" "       | Cette attaque utilise des MP et permet de sonner l'adversaire, son taux de reussite est de 25%");
printf("%s\n", "Renforcement [3]" "     | Cette attaque n'utilise pas de MP et permet de faire augmenter la defense d'attaque du joueur viser");
SetColor(15);

Capacites_t coupBouclier ={1*david.attaque, 0, 0, 100, 10};
Capacites_t coupFatal ={0, 3, 0, 25, 0};
Capacites_t renforcement ={0, 0, 0, 100, 0};

Sleep(2000);

// Attaque de Bernard //

SetColor(2);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Slash [1]" "            | Cette attaque n'utilise pas de MP et ses dégats seront bases en fonction de l'attaque de Bernard");
printf("%s\n", "Double Lame [2]" "      | Cette attaque utilise des MP, elle permet d'effectuer plusieurs coups et ses degats seront bases en fonction de l'attaque de Bernard");
printf("%s\n", "Infection [3]" "        | Cette attaque n'utilise pas de MP et permet d'empoisonner l'adversaire, son taux de reussite est de 25%");
SetColor(15);

Capacites_t slash ={1*bernard.attaque, 0, 0, 90, 20};
Capacites_t doubleLame ={1*bernard.attaque, 5, 0, 100, 0};
Capacites_t infection ={2*bernard.level, 0, 0, 25, 0};

Sleep(2000);

// Attaque de Daniel //

SetColor(5);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Tranchant [1]" "        | Cette attaque n'utilise pas de MP et ses degats seront bases en fonction de l'attaque de Daniel");
printf("%s\n", "Blizzard [2]" "         | Cette attaque utilise des MP et ses degats seront bases en fonction de la magie de Daniel");
printf("%s\n", "Transcende [3]" "       | Cette attaque n'utilise pas de MP et permet d'augmenter l'esquive de Daniel, son taux de reussite est de 75%");
SetColor(15);

Capacites_t tranchant ={1*daniel.attaque, 0, 0, 90, 10};
Capacites_t blizzard ={1*daniel.level, 5, 0, 25, 0};
Capacites_t transcende ={0, 0, 0, 80, 0};

Sleep(2000);

// Accepter d'entrer dans la partie //

printf("\n\n%s\n", "De nouveau, notez sur un papier l'utilite des capacites de vos personnages, cela peut s'averer utile");
printf("\n%s\n", "Vous etes pret a ecrire votre histoire et partir affronter votre premier monstre ? Si oui, entrer le numero [1] ");
while (avancer != 1){
scanf("%d", &avancer);
}

Sleep(2000);
system("cls");

// la pregression permettra de créer une boucle par la suiten entrainant un changement au niveau des monstres
while (jeu == 0 && progression == 0 ) {

Monstre_t slime ={1, 150*slime.level, 150*slime.level, 5*slime.level, 10*slime.level, 5*slime.level, 5*slime.level, 5, 1*slime.level*2};
Capacites_t coupFlasque={1*slime.attaque, 0, 0, 90, 10};

Monstre_t gobelin ={1, 500*gobelin.level, 500*gobelin.level, 10*gobelin.level, 20*gobelin.level, 10*gobelin.level, 10, 5*gobelin.level*2};
Monstre_t orque ={1, 1200*orque.level, 1200*orque.level, 15*orque.level, 25*orque.level, 15*orque.level, 1, 12*orque.level*2};
Monstre_t phoenix ={1, 3000*phoenix.level, 3000*phoenix.level, 25*phoenix.level, 35*phoenix.level, 25*phoenix.level, 15, 23*phoenix.level*2};
Monstre_t dragon ={1, 7000*dragon.level, 7000*dragon.level, 50*dragon.level, 50*dragon.level, 50*dragon.level, 10, 40*dragon.level*2};

// Combat continue tant que Monstre en Vie //
while (slime.pointdevie >= 0)
{

printf("\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                             SLIME                           |");
printf("%s\n", "                           |_____________________________________________________________|");

// Présentation des stats du Slime //

// Spawn de Slime //

SetColor(8);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< SLIME >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", slime.level);
printf("%s", "Point de vie : ");
printf("%d\n", slime.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", slime.attaque);
printf("%s", "Defense : ");
printf("%d\n", slime.defense);
printf("%s", "Magie : ");
printf("%d\n", slime.magie);
printf("%s", "MP : ");
printf("%d\n", slime.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", slime.esquive);
SetColor(15);

Sleep(1000);

// Début du Combat //

printf("\n\n%s\n", " _____________________________________________________________ ");
printf("%s\n", "|                                                             |");
printf("%s\n", "|                        LE TOUR COMMENCE                     |");
printf("%s\n\n", "|_____________________________________________________________|");

// Si CoolDown //

SetColor(2);
if (infection.cooldown > 0){
infection.cooldown = infection.cooldown -1;
slime.pointdevie = slime.pointdevie - infection.degats/3 ;
    printf("\n%s%d%s\n", "Infection a infliger ", infection.degats/3, " de degats ");
    printf("%s\n\n", "---------------------------------------------------------------");
}
SetColor(15);

SetColor(5);
if (blizzard.cooldown > 0){
blizzard.cooldown = blizzard.cooldown -1;
slime.pointdevie = slime.pointdevie - blizzard.degats/3 ;
    printf("%s%d%s\n", "Le blizzard a infliger ", blizzard.degats/3, " de degats ");
    printf("%s\n\n", "---------------------------------------------------------------");
}
SetColor(15);

SetColor(3);
if (repos.cooldown == 2){
printf("%s\n", "Vous devez attendre 2 tours avant de pouvoir jouer");
} else if (repos.cooldown == 1) {
printf("%s\n", "Vous devez attendre 1 tours avant de pouvoir jouer");
}
SetColor(15);

SetColor(3);
if (repos.cooldown > 0){
repos.cooldown = repos.cooldown -1;
coffre = (rand() % (heros.pointdevie/4 - heros.pointdevie/8 + 1)) + heros.pointdevie/8;
heros.pointdevie = heros.pointdevie + coffre ;
printf("%s%d%s\n", "Vous avez recuperer ", coffre, " points de vie");
}
SetColor(15);

// VOS CHOIX + Info perso//

if (heros.pointdevie > 0 && slime.pointdevie > 0 && repos.cooldown == 0){
Sleep(1000);
SetColor(3);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", heros.level);
printf("%s", "Point de vie : ");
printf("%d\n", heros.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", heros.attaque);
printf("%s", "Defense : ");
printf("%d\n", heros.defense);
printf("%s", "Magie : ");
printf("%d\n", heros.magie);
printf("%s", "MP : ");
printf("%d\n", heros.mp);
printf("%s", "Esquive : ");
printf("%d\n", heros.esquive);
printf("%s%d%s%d\n\n", "Experience : ", heros.exp, "/", heros.expMax);


printf("\n%s\n\n", "***************** CHOISSISEZ VOTRE ATTAQUE ***************** ");
printf("%s\n", "Coup d'epee [1]" " ; Boule de Feu [2]" " ; Repos [3]");

// Permet de savoir si le monstre va esquiver l'attaque qui va suivre
esquiveMonstre = (rand() % (100 - 1 + 1)) + 1;
scanf("%d", &coffre);

// Si [1] //

if (coffre == 1 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - (coupEpee.degats - (slime.defense/2));
    printf("%s%d%s\n", "Vous avez infliger ", coupEpee.degats - (slime.defense/2), " de degats");
}
else if (coffre == 1 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [2] //

else if (coffre == 2 && heros.mp >= 5 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - bouleDeFeu.degats;
heros.mp = heros.mp - 5;
    printf("%s%d%s\n", "Vous avez infliger ", bouleDeFeu.degats, " de degats");
} else if (coffre == 2 && heros.mp < 5) {
    printf("%s\n", "vous n'avez pas assez de MP");
}
else if (coffre == 2 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [3] //

else if (coffre == 3) {
repos.cooldown = 3;
    printf("%s\n", "Vous rentrez en phase de repos, vous allez generer des points des vie chaque tour au cours de ce repos");
}

// Si [4 ou +] //

else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

// Choix d'attaque des Alliés //


// CHOIX DE GEORGES + INFO GEORGES//

if (georges.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(4);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", georges.level);
printf("%s", "Point de vie : ");
printf("%d\n", georges.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", georges.attaque);
printf("%s", "Defense : ");
printf("%d\n", georges.defense);
printf("%s", "Magie : ");
printf("%d\n", georges.magie);
printf("%s", "MP : ");
printf("%d\n", georges.mp);
printf("%s", "Esquive : ");
printf("%d\n", georges.esquive);
printf("%s%d%s%d\n\n", "Experience : ", georges.exp, "/", georges.expMax);


printf("\n%s\n\n", "***************** CHOISSISEZ L'ATTAQUE DE GEORGES ***************** ");
printf("%s\n", "Coup de Baguette [1]" " ; Foudre [2]" " ; Soin [3]");

esquiveMonstre = (rand() % (100 - 1 + 1)) + 1;
scanf("%d", &coffre);

// Si [1] //

if (coffre == 1 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - (coupBaguette.degats - slime.defense);
    printf("%s%d%s\n", "Georges a infliger ", coupBaguette.degats - (slime.defense/2), " de degats");
}
else if (coffre == 1 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [2] //

else if (coffre == 2 && georges.mp >= 5 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - foudre.degats;
georges.mp = georges.mp - 5;
    printf("%s%d%s\n", "Georges a infliger ", foudre.degats, " de degats");
}
else if (coffre == 2 && georges.mp < 5) {
    printf("%s\n", "Georges n'a pas assez de MP");
}
else if (coffre == 2 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [3] //

else if (coffre == 3 && georges.mp >= 10) {
georges.mp = georges.mp - 10;

// Choix de la personne à Soigner //

printf("\n%s\n", "Choissisez qui vous voulez soigner");
printf("%s\n", "Vous [1]" " ; Georges [2]" " ; David [3]" " ; Bernard [4]" " ; Daniel [5]");
scanf("%d", &coffre);
leHeal = (rand() % (soin.degats - soin.degats/2 + 1)) + soin.degats/2;

// Soigner Héro //

  if(coffre == 1) {
    heros.pointdevie = heros.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous vous etes soigner, vous redonnant ", leHeal, " points de vie");
  }

// Soigner Georges //

  else if (coffre == 2) {
    georges.pointdevie = georges.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Georges, lui redonnant ", leHeal, " points de vie");
  }

// Soigner David //

  else if (coffre == 3) {
    david.pointdevie = david.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner David, lui redonnant ", leHeal, " points de vie");
  }

// Soigner Bernard //

  else if (coffre == 4) {
    bernard.pointdevie = bernard.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Bernard, lui redonnant ", leHeal, " points de vie");
  }

// Soigner Daniel //

  else if (coffre == 5) {
    daniel.pointdevie = daniel.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Daniel, lui redonnant ", leHeal, " points de vie");
  }

// Si [6 ou +] //

  else if (coffre > 5) {
    printf("%s\n", "Vous avez rater votre attaque");
  }
}
else if (coffre == 3 && georges.mp < 10) {
    printf("%s\n", "Georges n'a pas assez de MP");
}

// Si [4 ou +] //

else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}


// CHOIX DE DAVID + INFO DAVID //

if (david.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(14);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", david.level);
printf("%s", "Point de vie : ");
printf("%d\n", david.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", david.attaque);
printf("%s", "Defense : ");
printf("%d\n", david.defense);
printf("%s", "Magie : ");
printf("%d\n", david.magie);
printf("%s", "MP : ");
printf("%d\n", david.mp);
printf("%s", "Esquive : ");
printf("%d\n", david.esquive);
printf("%s%d%s%d\n\n", "Experience : ", david.exp, "/", david.expMax);


printf("\n%s\n\n", "***************** CHOISSISEZ L'ATTAQUE DE DAVID ***************** ");
printf("%s\n", "Coup de Bouclier [1]" " ; Coup Fatal [2]" " ; Renforcement [3]");

esquiveMonstre = (rand() % (100 - 1 + 1)) + 1;
scanf("%d", &coffre);

// Si [1] //

if (coffre == 1 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - (coupBouclier.degats - (slime.defense/2));
    printf("%s%d%s\n", "David a infliger ", coupBouclier.degats - (slime.defense/2), " de degats");
}
else if (coffre == 1 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [2] //

else if (coffre == 2 && david.mp >= 3 && esquiveMonstre > slime.esquive) {
david.mp = david.mp - 3;
coffre = (rand() % (100 - 1 + 1)) + 1;
  if (coffre <= coupFatal.tauxReussite){
    printf("%s\n", "vous avez reussi votre coup fatal, le monstre est sonner");
    coupFatal.cooldown = 4;

  } else {
    printf("%s\n", "Le coup fatal a manquer");
  }
}
else if (coffre == 2 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}
else if (coffre == 3 && david.mp < 3) {
    printf("%s\n", "David n'a pas assez de MP");
}

// Si [3] //

else if (coffre == 3) {
  printf("\n%s\n", "Choissisez qui vous voulez renforcer");
  printf("%s\n", "Vous [1]" " ; Georges [2]" " ; David [3]" " ; Bernard [4]" " ; Daniel [5]");
  scanf("%d", &coffre);
    if(coffre == 1) {
      heros.defense = heros.defense*1.1;
      printf("%s%d", "Vous vous etes renforcer, votre defense est de ", heros.defense);
    } else if (coffre == 2) {
      georges.defense = georges.defense;
      printf("\n%s%d", "Vous avez renforcer Georges, sa defense est de ", georges.defense);
    } else if (coffre == 3) {
      david.defense = david.defense;
      printf("\n%s%d", "Vous avez renforcer Georges, sa defense est de ", david.defense);
    } else if (coffre == 4) {
      bernard.defense = bernard.defense;
      printf("\n%s%d", "Vous avez renforcer Georges, sa defense est de ", bernard.defense);
    } else if (coffre == 5) {
      daniel.defense = daniel.defense;
      printf("\n%s%d", "Vous avez renforcer Georges, sa defense est de ", daniel.defense);
    } else if (coffre > 5) {
      printf("%s\n", "Vous avez rater votre attaque");
    }

// Si [4 ou +] //

} else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}


// CHOIX DE BERNARD + INFO BERNARD //

if (bernard.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(2);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", bernard.level);
printf("%s", "Point de vie : ");
printf("%d\n", bernard.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", bernard.attaque);
printf("%s", "Defense : ");
printf("%d\n", bernard.defense);
printf("%s", "Magie : ");
printf("%d\n", bernard.magie);
printf("%s", "MP : ");
printf("%d\n", bernard.mp);
printf("%s", "Esquive : ");
printf("%d\n", bernard.esquive);
printf("%s%d%s%d\n\n", "Experience : ", bernard.exp, "/", bernard.expMax);


printf("\n%s\n\n", "***************** CHOISSISEZ L'ATTAQUE DE BERNARD ***************** ");
printf("%s\n", "Slash [1]" " ; Double Lame [2]" " ; Infection [3]");

esquiveMonstre = (rand() % (100 - 1 + 1)) + 1;
scanf("%d", &coffre);

// Si [1] //

if (coffre == 1 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - (slash.degats - (slime.defense/2));
    printf("%s%d%s\n", "Bernard a infliger ", slash.degats - (slime.defense/2), " de degats");
}
else if (coffre == 1 && esquiveMonstre <= slime.esquive) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [2] //

else if (coffre == 2 && bernard.mp >= 5 && esquiveMonstre > slime.esquive && doubleLame.cooldown == 0) {
slime.pointdevie = slime.pointdevie - (doubleLame.degats - (slime.defense/2));
    printf("%s%d%s\n", "Bernard a infliger ", doubleLame.degats - (slime.defense/2), " de degats");
bernard.mp = bernard.mp - 5;
doubleLame.cooldown = 4;
coffre = (rand() % (2 - 1 + 1)) + 1;
  if (coffre == 2) {
    slime.pointdevie = slime.pointdevie - (doubleLame.degats - (slime.defense/2));
        printf("%s%d%s\n", "Bernard a de nouveau infliger ", doubleLame.degats - (slime.defense/2), " de degats");
    coffre = (rand() % (4 - 1 + 1)) + 1;
    if (coffre == 4) {
      slime.pointdevie = slime.pointdevie - (doubleLame.degats - (slime.defense/2));
          printf("%s%d%s\n", "Bernard a encore infliger ", doubleLame.degats - (slime.defense/2), " de degats");
      coffre = (rand() % (10 - 1 + 1)) + 1;
      if (coffre == 10) {
        slime.pointdevie = slime.pointdevie - (doubleLame.degats - (slime.defense/2));
            printf("%s%d%s\n", "Bernard a infliger pour la quatrième fois ", doubleLame.degats - (slime.defense/2), " de degats");
      }
    }
  }
}
else if (coffre == 3 && bernard.mp < 5) {
    printf("%s\n", "Bernard n'a pas assez de MP");
}
else if (coffre == 2 && esquiveMonstre <= slime.esquive && doubleLame.cooldown == 0) {
      printf("%s\n", "le monstre a esquiver votre attaque");
}

else if (coffre == 2 && bernard.mp > 5 && doubleLame.cooldown == 2){
printf("%s\n", "Vous devez attendre 2 tours avant de pour l'utiliser a nouveau");
}

else if (coffre == 2 && bernard.mp > 5 && doubleLame.cooldown == 1) {
printf("%s\n", "Vous devez attendre 1 tours avant de pour l'utiliser a nouveau");
}

// Si [3] //

else if (coffre == 3 && esquiveMonstre > slime.esquive && infection.cooldown == 0) {
infection.cooldown = 4;
} else if (coffre == 3 && infection.cooldown == 2) {
printf("%s\n", "L'ennemi est encore infecter pendant 2 tours");
} else if (coffre == 3 && infection.cooldown == 1) {
printf("%s\n", "L'ennemi est encore infecter pendant 1 tours");
}
else if (coffre == 3 && esquiveMonstre <= slime.esquive && infection.cooldown == 0) {
    printf("%s\n", "le monstre a esquiver votre attaque");
}
// Si [4 ou +] //

else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

if (infection.cooldown > 0){
doubleLame.cooldown = doubleLame.cooldown -1;
}

// CHOIX DE DANIEL + INFO DANIEL //

if (daniel.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(5);

printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", daniel.level);
printf("%s", "Point de vie : ");
printf("%d\n", daniel.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", daniel.attaque);
printf("%s", "Defense : ");
printf("%d\n", daniel.defense);
printf("%s", "Magie : ");
printf("%d\n", daniel.magie);
printf("%s", "MP : ");
printf("%d\n", daniel.mp);
printf("%s", "Esquive : ");
printf("%d\n", daniel.esquive);
printf("%s%d%s%d\n\n", "Experience : ", daniel.exp, "/", daniel.expMax);


printf("\n%s\n\n", "***************** CHOISSISEZ L'ATTAQUE DE DANIEL ***************** ");
printf("%s\n", "Tranchant [1]" " ; Blizzard [2]" " ; Transcende [3]");

esquiveMonstre = (rand() % (100 - 1 + 1)) + 1;
scanf("%d", &coffre);

// Si [1] //

if (coffre == 1 && esquiveMonstre > slime.esquive) {
slime.pointdevie = slime.pointdevie - (tranchant.degats - (slime.defense/2));
    printf("%s%d%s\n", "Daniel a infliger ", tranchant.degats - (slime.defense/2), " de degats");
}
else if (coffre == 1 && esquiveMonstre <= slime.esquive) {
    printf("%s\n", "le monstre a esquiver votre attaque");
}

// Si [2] //

else if (coffre == 2 && daniel.mp >= 5 && esquiveMonstre > slime.esquive && blizzard.cooldown == 0) {
blizzard.cooldown = 4;
daniel.mp = daniel.mp - 5;
}
else if (coffre == 3 && daniel.mp < 5) {
    printf("%s\n", "Daniel n'a pas assez de MP");
}
else if (coffre == 2 && esquiveMonstre <= slime.esquive && blizzard.cooldown == 0) {
    printf("%s\n", "le monstre a esquiver votre attaque");
}

else if (coffre == 2 && daniel.mp > 5 && blizzard.cooldown == 2){
printf("%s\n", "L'ennemi est encore affecter par le blizzard pendant 2 tours");
}

else if (coffre == 2 && daniel.mp > 5 && blizzard.cooldown == 1) {
printf("%s\n", "L'ennemi est encore affecter par le blizzard pendant 1 tours");
}

// Si [3] //

else if (coffre == 3) {
  coffre = (rand() % (100 - 1 + 1)) + 1;
  if (coffre < transcende.tauxReussite) {
  daniel.esquive = daniel.esquive*1.2;
    printf("%s%d\n", "L'esquive de Daniel est maintenant de ", daniel.esquive);
  } else {
      printf("%s\n", "Vous avez rater votre attaque");
    }
}

// Si [4 ou +] //

else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

if (daniel.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);




// TOUR DU MONSTRE //

printf("\n\n%s\n\n", "***************** TOUR DU MONSTRE ***************** ");

coffre = (rand() % (2 - 1 + 1)) + 1;

// Si [1] //
SetColor(8);
if (coffre == 1 && coupFatal.cooldown == 0) {
  coffre = (rand() % (5 - 1 + 1)) + 1;
  if (coffre == 1) {
    heros.pointdevie = heros.pointdevie - (coupFlasque.degats - (heros.defense/2));
    printf("%s%d%s\n", "Le slime vous a infliger ", coupFlasque.degats - (heros.defense/2), " de degats ");
  } else if (coffre == 2){
    georges.pointdevie = georges.pointdevie - (coupFlasque.degats - (georges.defense/2));
    printf("%s%d%s\n", "Le slime a infliger ", coupFlasque.degats - (georges.defense/2), " de degats a Georges");
  } else if (coffre == 3){
    david.pointdevie = david.pointdevie - (coupFlasque.degats - (david.defense/2));
    printf("%s%d%s\n", "Le slime a infliger ", coupFlasque.degats - (david.defense/2), " de degats a David");
  } else if (coffre == 4){
    bernard.pointdevie = bernard.pointdevie - (coupFlasque.degats - (bernard.defense/2));
    printf("%s%d%s\n", "Le slime a infliger ", coupFlasque.degats - (bernard.defense/2), " de degats a Bernard");
  } else if (coffre == 5){
    georges.pointdevie = daniel.pointdevie - (coupFlasque.degats - (daniel.defense/2));
    printf("%s%d%s\n", "Le slime a infliger ", coupFlasque.degats - (daniel.defense/2), " de degats a Georges");
  }
} else if (coffre == 1 && coupFatal.cooldown > 0){
    printf("%s\n", "Le slime est sonner");
}
SetColor(15);
}

// Limite de PV Max pour Hero et Alliés //

if (heros.pointdevie > heros.pointdeviemax){
  heros.pointdevie = heros.pointdeviemax;
} else if (georges.pointdevie > georges.pointdeviemax) {
  georges.pointdevie = georges.pointdeviemax;
} else if (david.pointdevie > david.pointdeviemax) {
  david.pointdevie = david.pointdeviemax;
} else if (bernard.pointdevie > bernard.pointdeviemax) {
  bernard.pointdevie = bernard.pointdeviemax;
} else if (daniel.pointdevie > daniel.pointdeviemax) {
  daniel.pointdevie = daniel.pointdeviemax;
}

if (heros.pointdevie = heros.pointdeviemax){
  printf("Le Hero a ses Points de Vie Maximun\n");
}

// Regen par tour des MP du Hero et des Alliés //

heros.mp = heros.mp + heros.magie/5;
georges.mp = georges.mp + heros.magie/5;
david.mp = david.mp + heros.magie/5;
bernard.mp = bernard.mp + heros.magie/5;
daniel.mp = daniel.mp + heros.magie/5;

printf("\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                          FIN DU TOUR                        |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(4000);
system("cls");
// fin combat slime
}

// Gain d'expérience//

if (slime.pointdevie <= 0)
{
  heros.exp = heros.exp + 1;
  georges.exp = heros.exp + 1;
  david.exp = heros.exp + 1;
  bernard.exp = heros.exp + 1;
  daniel.exp = heros.exp + 1;

  printf("Le Hero et ses Alliés ont gagné 1 point d'experience");
  printf("Ils ont maintenant %d points d'expériences", heros.exp );
}

// Monter de Level des Heros,de ses alliés et du Slime //Monter des Points de Vie du Hero et du Slime //

if (heros.exp >= heros.expMax && georges.exp >= georges.expMax && daniel.exp >= daniel.expMax && bernard.exp >= bernard.expMax && david.exp >= david.expMax)
{
  heros.level = heros.level + 1;
  georges.level = georges.level + 1;
  david.level = david.level + 1;
  bernard.level = bernard.level + 1;
  daniel.level = daniel.level + 1;
  slime.level = slime.level + 1;
  skillpoints = 5;

// Monter des Points de Vie du Hero, de ses Alliés et du Slime //

  slime.pointdevie = slime.pointdevie * 1.1;
  heros.pointdevie = heros.pointdevie * 1.1;
  georges.pointdevie = georges.pointdevie * 1.1;
  david.pointdevie = david.pointdevie * 1.1;
  daniel.pointdevie = daniel.pointdevie * 1.1;
  bernard.pointdevie = bernard.pointdevie * 1.1;

  // Monter de l'exp necessaire pour level up //

    heros.expMax = heros.expMax * 1,8;
    georges.expMax = georges.expMax * 1,8;
    david.expMax = david.expMax * 1,8;
    daniel.expMax = daniel.expMax * 1,8;
    bernard.expMax = bernard.expMax * 1,8;

  printf("Le Hero et ses Allies ont gagne un Niveau\n");
  printf("Ils sont maintenant au Niveau %d et leur point de Vie ont augmenter\n", heros.level);

  printf("Attention, les Slimes sont maintenant plus fort\n");

}

if (skillpoints > 0) {
  printf("%s\n", "Vous venez de monter de niveau, vous avez donc 5 points de competences a attribuer, choissisez intelligement, il n'est pas possible de revenir en arriere");
  printf("%s", "Attaque : ");
  scanf("%d", &coffre);
  while (coffre > skillpoints){
    printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
    printf("\n%s", "Attaque : ");
    scanf("%d", &coffre);
  }
    heros.attaque = heros.attaque + coffre;
    skillpoints = skillpoints - coffre;

  printf("\n%s%d", "Points de competences restant : ", skillpoints);

  // SkillPoints Defense //

  printf("\n%s", "Defense : ");
  scanf("%d", &coffre);
  while (coffre > skillpoints){
    printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
    printf("\n%s", "Defense : ");
    scanf("%d", &coffre);
  }
    heros.defense = heros.defense + coffre;
    skillpoints = skillpoints - coffre;
  printf("\n%s%d", "Points de competences restant : ", skillpoints);

  // SkillPoints Magie //

  printf("\n%s", "Magie : ");
  scanf("%d", &coffre);
  while (coffre > skillpoints){
    printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
    printf("\n%s", "Magie : ");
    scanf("%d", &coffre);
  }
    heros.magie = heros.magie + coffre;
    skillpoints = skillpoints - coffre;
  printf("\n%s%d", "Points de competences restant : ", skillpoints);

  // SkillPoints MP //

  printf("\n%s", "MP : ");
  scanf("%d", &coffre);
  while (coffre > skillpoints){
    printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
    printf("\n%s", "MP : ");
    scanf("%d", &coffre);
  }
    heros.mp = heros.mp + coffre;
    skillpoints = skillpoints - coffre;
  printf("\n%s%d", "Points de competences restant : ", skillpoints);

  // SkillPoints Esquive //

  printf("\n%s", "Esquive : ");
  scanf("%d", &coffre);
  while (coffre > skillpoints){
    printf("\n%s", "Dis donc, vous avez utilisez plus de points de competences que vous en avez! Recommencez ");
    printf("\n%s", "Esquive : ");
    scanf("%d", &coffre);
  }
    heros.esquive = heros.esquive + coffre;
    skillpoints = skillpoints - coffre;
  printf("\n%s%d\n", "Points de competences restant : ", skillpoints);

  // Affichage Hero et ses Stats //

  printf("\n\n%s\n", "VOICI LA FICHE DE VOTRE PERSONNAGE MAINTENANT");

  SetColor(3);
  printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
  printf("%s", "LEVEL : ");
  printf("%d\n", heros.level);
  printf("%s", "Point de vie : ");
  printf("%d\n", heros.pointdevie);
  printf("%s", "Attaque : ");
  printf("%d\n", heros.attaque);
  printf("%s", "Defense : ");
  printf("%d\n", heros.defense);
  printf("%s", "Magie : ");
  printf("%d\n", heros.magie);
  printf("%s", "MP : ");
  printf("%d\n", heros.mp);
  printf("%s", "Esquive : ");
  printf("%d\n", heros.esquive);
  printf("%s%d%s%d\n\n", "Experience : ", heros.exp, "/", heros.expMax);
  SetColor(15);

  Sleep(2000);
}


if (slime.level == 5){
  progression = 2;
  printf("%s\n\n", "Bravo, vous avez completer la première phase du jeu, d'autres creatures seront a venir, merci de votre patience");
  jeu = 1;
  printf("\n%s\n", "                            _____________________________________________________________ ");
  printf("%s\n", "                           |                                                             |");
  printf("%s\n", "                           |                        FIN DE LA PHASE 1                    |");
  printf("%s\n", "                           |_____________________________________________________________|");
}

system("cls");

// FUTUR MONSTRES AJOUTÉS
// Gobelin Base Stats //
if (progression == 10000) {
SetColor(4);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< GOBELIN >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", gobelin.level);
printf("%s", "Point de vie : ");
printf("%d\n", gobelin.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", gobelin.attaque);
printf("%s", "Defense : ");
printf("%d\n", gobelin.defense);
printf("%s", "MP : ");
printf("%d\n", gobelin.mp);
printf("%s", "Esquive : ");
printf("%d\n", gobelin.esquive);

// Orgue Base Stats //

SetColor(1);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< ORQUE >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", orque.level);
printf("%s", "Point de vie : ");
printf("%d\n", orque.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", orque.attaque);
printf("%s", "Defense : ");
printf("%d\n", orque.defense);
printf("%s", "MP : ");
printf("%d\n", orque.mp);
printf("%s", "Esquive : ");
printf("%d\n", orque.esquive);

// Phoenix Base Stats //

SetColor(11);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< PHEONIX >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", phoenix.level);
printf("%s", "Point de vie : ");
printf("%d\n", phoenix.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", phoenix.attaque);
printf("%s", "Defense : ");
printf("%d\n", phoenix.defense);
printf("%s", "MP : ");
printf("%d\n", phoenix.mp);
printf("%s", "Esquive : ");
printf("%d\n", phoenix.esquive);

// Dragon Base Stats //

SetColor(10);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DRAGON >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", dragon.level);
printf("%s", "Point de vie : ");
printf("%d\n", dragon.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", dragon.attaque);
printf("%s", "Defense : ");
printf("%d\n", dragon.defense);
printf("%s", "MP : ");
printf("%d\n", dragon.mp);
printf("%s", "Esquive : ");
printf("%d\n", dragon.esquive);
}

// fin boucle combat
}




return 0;
// fin main
}
