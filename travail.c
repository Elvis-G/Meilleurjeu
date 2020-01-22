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
    int pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;
};

typedef struct LeHeros LeHeros_t;
struct LeHeros
{
    char* nom;
    int level;
    int pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;
};

typedef struct Allies Allies_t;
struct Allies
{
    int level;
    int pointdevie;
    int attaque;
    int defense;
    int mp;
    int esquive;

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

int progression = 1;

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
LeHeros_t heros = {"Inconnu", 1, 250, 0, 0, 0, 0};
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s%d\n", "LEVEL : ", heros.level);
printf("%s%d\n", "Classe : ", heros.nom);
printf("%s%d\n", "Point de vie : ", heros.pointdevie);
printf("%s%d\n", "Attaque : ", heros.attaque);
printf("%s%d\n", "Defense : ", heros.defense);
printf("%s%d\n", "MP : ", heros.mp);
printf("%s%d\n", "Esquive : ", heros.esquive);
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
SetColor(15);

Sleep(2000);

printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       VOICI LES PERSONNAGES QUI VONT VOUS ACCOMPAGNER       |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(2000);

SetColor(4);
Allies_t georges ={1, 150, 10, 5, 25, 10};
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
SetColor(15);

Sleep(1000);

SetColor(14);
Allies_t david ={1, 400, 5, 30, 10, 5};
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
SetColor(15);

Sleep(1000);

SetColor(2);
Allies_t bernard ={1, 180, 25, 5, 5, 10};
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
SetColor(15);

Sleep(1000);

SetColor(5);
Allies_t daniel ={1, 300, 15, 15, 10, 10};
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


SetColor(8);
Monstre_t slime ={1*progression, 20*slime.level, 5*slime.level, 10*slime.level, 0*slime.level, 5*slime.level};
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
SetColor(15);

Sleep(2000);
system("cls");

return 0;


}

}
