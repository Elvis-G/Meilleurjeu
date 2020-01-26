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


typedef struct Monstre Monstre_t;
struct Monstre
{
    int level;
    float pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;
};

typedef struct LeHeros LeHeros_t;
struct LeHeros
{

    int level;
    float pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;
    int exp;
};

typedef struct Allies Allies_t;
struct Allies
{
    int level;
    float pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;
    int exp;

    // Alchimiste , Necromancien, Paladin, Assassin
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
int experience = 0;
int skillpoints = 50;
int coffre = 0;

int progressionSlime = 1;
int expSlime = 1;

int avancer = 0;

while (jeu == 0) {
printf("%s\n\n", "");
printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       BIENVENUE CHER JOUEUR PREPARER VOUS A EMBARQUER       |");
printf("%s\n", "                           |     DANS UNE AVENTURE OU SEUL LA MORT Y METTRA UN TERME,    |");
printf("%s\n", "                           |                    ALORS BONNE CHANCE!!!                    |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(4000);

SetColor(3);

LeHeros_t heros = {1, 250, 0, 0, 0, 0, 0};


printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s%d\n", "LEVEL : ", heros.level);
printf("%s%d\n", "Point de vie : ", heros.pointdevie);
printf("%s%d\n", "Attaque : ", heros.attaque);
printf("%s%d\n", "Defense : ", heros.defense);
printf("%s%d\n", "MP : ", heros.mp);
printf("%s%d\n", "Esquive : ", heros.esquive);
printf("%s%d\n", "EXP : ", heros.exp);
SetColor(15);

printf("\n%s\n", "Comme vous pouvez le constatez, vos stats se trouvent toutes a 0");
printf("%s\n", "Vous allez donc devoir attribuer au total 50 points de competences, choissisez intelligement, il n'est pas possible de revenir en arriere");
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
printf("\n%s%d", "Points de competences restant : ", skillpoints);

printf("\n\n%s\n\n", "VOICI LA FICHE DE VOTRE PERSONNAGE ");

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
printf("%s", "MP : ");
printf("%d\n", heros.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", heros.esquive);
printf("%s", "EXP : ");
printf("%d\n\n", heros.exp);
SetColor(15);

Sleep(2000);

printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       VOICI LES PERSONNAGES QUI VONT VOUS ACCOMPAGNER       |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(2000);

SetColor(4);
Allies_t georges ={1, 150, 10, 5, 25, 10, 0};
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", georges.level);
printf("%s", "Point de vie : ");
printf("%d\n", georges.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", georges.attaque);
printf("%s", "Defense : ");
printf("%d\n", georges.defense);
printf("%s", "MP : ");
printf("%d\n", georges.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", georges.esquive);
printf("%s", "EXP : ");
printf("%d\n\n", georges.exp);
SetColor(15);

Sleep(1000);

SetColor(14);
Allies_t david ={1, 400, 5, 30, 10, 5, 0};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", david.level);
printf("%s", "Point de vie : ");
printf("%d\n", david.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", david.attaque);
printf("%s", "Defense : ");
printf("%d\n", david.defense);
printf("%s", "MP : ");
printf("%d\n", david.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", david.esquive);
printf("%s", "EXP : ");
printf("%d\n\n", david.exp);
SetColor(15);

Sleep(1000);

SetColor(2);
Allies_t bernard ={1, 180, 25, 5, 5, 10, 0};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", bernard.level);
printf("%s", "Point de vie : ");
printf("%d\n", bernard.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", bernard.attaque);
printf("%s", "Defense : ");
printf("%d\n", bernard.defense);
printf("%s", "MP : ");
printf("%d\n", bernard.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", bernard.esquive);
printf("%s", "EXP : ");
printf("%d\n\n", bernard.exp);
SetColor(15);

Sleep(1000);

SetColor(5);
Allies_t daniel ={1, 300, 15, 15, 10, 10, 0};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", georges.level);
printf("%s", "Point de vie : ");
printf("%d\n", georges.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", georges.attaque);
printf("%s", "Defense : ");
printf("%d\n", georges.defense);
printf("%s", "MP : ");
printf("%d\n", georges.mp);
printf("%s", "Esquive : ");
printf("%d\n\n", georges.esquive);
printf("%s", "EXP : ");
printf("%d\n\n", georges.exp);
SetColor(15);

Sleep(1000);

printf("\n%s\n", "Avant de vous presentez leurs capacites, notez sur un papier les stats de vos personnages, cela peut s'averer utile");
printf("\n%s\n", "Vous etes pret ? Si oui, entrer le numero -1- ");
while (avancer != 1){
scanf("%d", &avancer);
}

if (avancer == 1) {
printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |     VOICI LES CAPACITES DETAILLES DE CHAQUE PERSONNAGES     |");
printf("%s\n", "                           |_____________________________________________________________|");

}

SetColor(3);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Boule de Feu [1]");
printf("%s\n", "Coup d'épée [2]");
printf("%s\n", "Repos [3]");
SetColor(15);

Sleep(1000);

SetColor(4);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Boule de Feu [1]");
printf("%s\n", "Tonerre [2]");
printf("%s\n", "Soin [3]");
SetColor(15);

Sleep(1000);

SetColor(14);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Boule de Feu [1]");
printf("%s\n", "Tonerre [2]");
printf("%s\n", "Renforcement [3]");
SetColor(15);

Sleep(1000);

SetColor(2);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Boule de Feu [1]");
printf("%s\n", "Tonerre [2]");
printf("%s\n", "Renforcement [3]");
SetColor(15);

Sleep(1000);

SetColor(5);
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Boule de Feu [1]");
printf("%s\n", "Tonerre [2]");
printf("%s\n", "Renforcement [3]");
SetColor(15);

// Slime Base Stats //

SetColor(8);
Monstre_t slime ={1, 150*slime.level, 5*slime.level, 10*slime.level, 5*slime.level, 5*slime.level};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< SLIME >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", slime.level);
printf("%s", "Point de vie : ");
printf("%d\n", slime.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", slime.attaque);
printf("%s", "Defense : ");
printf("%d\n", slime.defense);
printf("%s", "MP : ");
printf("%d\n", slime.mp);
printf("%s", "Esquive : ");
printf("%d\n", slime.esquive);

// Gobelin Base Stats //

SetColor(4);
Monstre_t gobelin ={1, 200*gobelin.level, 10*gobelin.level, 20*gobelin.level, 10*gobelin.level, 10*gobelin.level};
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
Monstre_t orque ={1, 300*orque.level, 15*orque.level, 25*orque.level, 15*orque.level, 1*orque.level};
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

// Pheonix Base Stats //

SetColor(11);
Monstre_t pheonix ={1, 400*pheonix.level, 25*pheonix.level, 35*pheonix.level, 25*pheonix.level, 15*pheonix.level};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< PHEONIX >>>>>>>>>>>>>>>>> ");
printf("%s", "LEVEL : ");
printf("%d\n", pheonix.level);
printf("%s", "Point de vie : ");
printf("%d\n", pheonix.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", pheonix.attaque);
printf("%s", "Defense : ");
printf("%d\n", pheonix.defense);
printf("%s", "MP : ");
printf("%d\n", pheonix.mp);
printf("%s", "Esquive : ");
printf("%d\n", pheonix.esquive);

// Dragon Base Stats //

SetColor(10);
Monstre_t dragon ={1, 500*dragon.level, 50*dragon.level, 50*dragon.level, 50*dragon.level, 10*dragon.level};
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

// Gain d'expérience//

if (slime.pointdevie <= 0)
{
  heros.exp = heros.exp + 1;
  georges.exp = heros.exp + 1;
  david.exp = heros.exp + 1;
  bernard.exp = heros.exp + 1;
  daniel.exp = heros.exp + 1;

};

// Monter de Level //

if (heros.exp >= heros.exp + 5 && georges.exp >= georges.exp + 5 && daniel.exp >= daniel.exp + 5 && bernard.exp >= bernard.exp + 5 && david.exp >= david.exp + 5)
{
  heros.level = heros.level + 1;
  georges.level = georges.level + 1;
  david.level = david.level + 1;
  bernard.level = bernard.level + 1;
  daniel.level = daniel.level + 1;
  slime.level = slime.level + 1;
};

// Monter des PV Slime si Level up//

if (slime.level = slime.level + 1)
{
  slime.pointdevie = slime.pointdevie * 1.1;
};

// Monter des PV Heros si Level up//

if (heros.level = heros.level + 1)
{
heros.pointdevie = heros.pointdevie * 1.1;
};

// Monter des PV Allies si Level up//

if (georges.level = georges.level + 1)
{
georges.pointdevie = georges.pointdevie * 1.1;
};

if (david.level = david.level + 1)
{
david.pointdevie = david.pointdevie * 1.1;
};

if (daniel.level = daniel.level + 1)
{
daniel.pointdevie = daniel.pointdevie * 1.1;
};

if (bernard.level = bernard.level + 1)
{
bernard.pointdevie = bernard.pointdevie * 1.1;
};

SetColor(15);

Sleep(2000);
system("cls");

return 0;


}

}
