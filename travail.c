#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


typedef struct Monstre Monstre_t;
struct Monstre
{
    int pointdevie;
    int attaque;
    int defense;
    int mp;
    int vitesse;
};

typedef struct LeHeros LeHeros_t;
struct LeHeros
{
    int level;
    int pointdevie;
    int attaque;
    int defense;
    int mp;
    int vitesse;
};

int main (){

int experience = 0;
int skillpoints = 50;
char* tableauMob[4];


LeHeros_t heros ={1, 250, 0, 0, 0, 0};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< LE HEROS >>>>>>>>>>>>>>>>> ");
printf("%s%d\n", "Level : ", heros.level);
printf("%s%d\n", "Point de vie : ", heros.pointdevie);
printf("%s%d\n", "Attaque : ", heros.attaque);
printf("%s%d\n", "Defense : ", heros.defense);
printf("%s%d\n", "MP : ", heros.mp);
printf("%s%d\n\n", "Vitesse : ", heros.vitesse);

printf("\n%s\n", "Vous avez la possibilite d'attribuer au total 50 points de competences, choissisez intelligement");
printf("%s%d", "Attaque : ", &heros.attaque);
skillpoints = skillpoints - heros.attaque;
printf("\n%s%d", "Points de competences restant : ", skillpoints);

printf("\n%s", "Defense : ");
scanf("%d", &heros.defense);
skillpoints = skillpoints - heros.defense;
printf("\n%s%d", "Points de competences restant : ", skillpoints);

printf("\n%s", "MP : ");
scanf("%d", &heros.mp);
skillpoints = skillpoints - heros.mp;
printf("\n%s", "Points de competences restant : ", skillpoints);

printf("\n%s", "Vitesse : ");
scanf("%d", &heros.vitesse);
skillpoints = skillpoints - heros.vitesse;
printf("\n%s%d", "Points de competences restant : ", skillpoints);

printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< LE HEROS >>>>>>>>>>>>>>>>> ");
printf("%s", "Level : ");
printf("%d\n", heros.level);
printf("%s", "Point de vie : ");
printf("%d\n", heros.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", heros.attaque);
printf("%s", "Defense : ");
printf("%d\n", heros.defense);
printf("%s", "MP : ");
printf("%d\n", heros.mp);
printf("%s", "Vitesse : ");
printf("%d\n\n", heros.vitesse);


Monstre_t slime ={20, 5, 10, 0, 5};
printf("\n%s\n\n", "<<<<<<<<<<<<<<<<< SLIME >>>>>>>>>>>>>>>>> ");
printf("%s", "Point de vie : ");
printf("%d\n", slime.pointdevie);
printf("%s", "Attaque : ");
printf("%d\n", slime.attaque);
printf("%s", "Defense : ");
printf("%d\n", slime.defense);
printf("%s", "MP : ");
printf("%d\n", slime.mp);
printf("%s", "Vitesse : ");
printf("%d\n", slime.vitesse);

tableauMob[0] = "bonjour";
tableauMob[1] = "Bonsoir";
tableauMob[2] = "Au revoir";
tableauMob[3] = "Adieu";
tableauMob[4] = "...";
printf("%s %s %s %s %s", tableauMob[0], tableauMob[1], tableauMob[2], tableauMob[3], tableauMob[4]);

return 0;
}
