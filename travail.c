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
    int pointdeviemax;
    int pointdevie;
    int attaque;
    int defense;
    int magie;
    int mp;
    int esquive;
};

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
    int esquive;
};

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
int skillpoints = 60;

int coffre = 0;
int stockageHeros = 0;
int stockageGeorges = 0;
int stockageDavid = 0;
int stockageBernard = 0;
int stockageDaniel = 0;
int leHeal = 0;

int progressionSlime = 1;
int expSlime = 1;

int avancer = 0;


printf("%s\n\n", "");
printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |       BIENVENUE CHER JOUEUR PREPARER VOUS A EMBARQUER       |");
printf("%s\n", "                           |     DANS UNE AVENTURE OU SEUL LA MORT Y METTRA UN TERME,    |");
printf("%s\n", "                           |                    ALORS BONNE CHANCE!!!                    |");
printf("%s\n", "                           |_____________________________________________________________|");

Sleep(4000);

SetColor(3);
LeHeros_t heros = {1, 250, 250, 0, 0, 0, 0, 0};
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s%d\n", "LEVEL : ", heros.level);
printf("%s%d\n", "Point de vie : ", heros.pointdevie);
printf("%s%d\n", "Attaque : ", heros.attaque);
printf("%s%d\n", "Defense : ", heros.defense);
printf("%s%d\n", "Magie : ", heros.magie);
printf("%s%d\n", "MP : ", heros.mp);
printf("%s%d\n", "Esquive : ", heros.esquive);
SetColor(15);

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
printf("%s", "Magie : ");
printf("%d\n", heros.magie);
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
Allies_t georges ={1, 150, 150, 10, 5, 20, 20, 5};
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
printf("%d\n\n", georges.esquive);
SetColor(15);

Sleep(1000);

SetColor(14);
Allies_t david ={1, 400, 400, 10, 30, 5, 10, 5};
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
printf("%d\n\n", david.esquive);
SetColor(15);

Sleep(1000);

SetColor(2);
Allies_t bernard ={1, 180, 180, 25, 5, 5, 5, 15};
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
printf("%d\n\n", bernard.esquive);
SetColor(15);

Sleep(1000);

SetColor(5);
Allies_t daniel ={1, 300, 300, 15, 15, 10, 10, 10};
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
printf("%d\n\n", daniel.esquive);
SetColor(15);

Sleep(1000);

printf("\n%s\n", "Avant de vous presentez leurs capacites, notez sur un papier les stats de vos personnages, cela peut s'averer utile");
printf("\n%s\n", "Vous etes pret ? Si oui, entrer le numero -1- ");
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

SetColor(4);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup de Baguette [1]" " | Cette attaque n'utilise pas de MP et ses degats seront bases en fonction de l'attaque de Georges");
printf("%s\n", "Foudre [2]" "           | Cette attaque utilise des MP et ses dégats seront bases en fonction de la magie de Georges");
printf("%s\n", "Soin [3]" "             | Cette attaque utilise des MP et permet de faire recuperer des points de vie au joueur cibler");
SetColor(15);

Capacites_t coupBaguette ={1*georges.attaque, 0, 0, 100, 10};
Capacites_t foudre ={1*georges.magie, 5, 0, 90, 10};
Capacites_t soin ={10*georges.magie, 10, 0, 90, 0};

Sleep(2000);

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

SetColor(5);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Tranchant [1]" "        | Cette attaque n'utilise pas de MP et ses dégats seront bases en fonction de l'attaque de Daniel");
printf("%s\n", "Blizzard [2]" "         | Cette attaque utilise des MP et ses dégats seront bases en fonction de la magie de Daniel");
printf("%s\n", "Transcende [3]" "       | Cette attaque n'utilise pas de MP et permet d'augmenter l'esquive de Daniel, son taux de reussite est de 75%");
SetColor(15);

Capacites_t tranchant ={1*daniel.attaque, 0, 0, 90, 10};
Capacites_t blizzard ={1*daniel.level, 5, 0, 25, 0};
Capacites_t transcende ={0, 0, 0, 80, 0};

Sleep(2000);

printf("\n\n%s\n", "De nouveau, notez sur un papier l'utilite des capacites de vos personnages, cela peut s'averer utile");
printf("\n%s\n", "Vous etes pret a ecrire votre histoire et partir affronter votre premier monstre ? Si oui, entrer le numero -1- ");
while (avancer != 1){
scanf("%d", &avancer);
}

Sleep(2000);
system("cls");

Monstre_t slime ={1, 150*slime.level, 150*slime.level, 5*slime.level, 10*slime.level, 5*slime.level, 5*slime.level, 5*slime.level};

while (jeu == 0) {
printf("\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                             SLIME                           |");
printf("%s\n", "                           |_____________________________________________________________|");

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

printf("\n\n%s\n\n", "********************* QUE LE COMBAT COMMENCE ********************* ");

SetColor(3);
if (repos.cooldown == 2){
printf("%s\n", "Vous devez attendre 2 tours avant de pouvoir jouer");
} else if (repos.cooldown == 1) {
printf("%s\n", "Vous devez attendre 1 tours avant de pouvoir jouer");
}
SetColor(15);

if (heros.pointdevie > 0 && slime.pointdevie > 0 && repos.cooldown == 0){
SetColor(3);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< VOUS >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup d'epee [1]" " ; Boule de Feu [2]" " ; Repos [3]");

scanf("%d", &coffre);
if (coffre == 1) {
slime.pointdevie = slime.pointdevie - (coupEpee.degats - (slime.defense/2));
} else if (coffre == 2) {
slime.pointdevie = slime.pointdevie - bouleDeFeu.degats;
} else if (coffre == 3) {
repos.cooldown = 4;
} else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

if (repos.cooldown > 0){
repos.cooldown = repos.cooldown -1;
}

printf("\n%s", "point de vie Slime : ");
printf("%d\n", slime.pointdevie);


if (georges.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(4);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< GEORGES >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup de Baguette [1]" " ; Foudre [2]" " ; Soin [3]");

scanf("%d", &coffre);
if (coffre == 1) {
slime.pointdevie = slime.pointdevie - (coupBaguette.degats - slime.defense);
} else if (coffre == 2) {
slime.pointdevie = slime.pointdevie - foudre.degats;
} else if (coffre == 3) {
printf("\n%s\n", "Choissisez qui vous voulez soigner");
printf("%s\n", "Vous [1]" " ; Georges [2]" " ; David [3]" " ; Bernard [4]" " ; Daniel [5]");
scanf("%d", &coffre);
leHeal = (rand() % (soin.degats - soin.degats/2 + 1)) + soin.degats/2;
  if(coffre == 1) {
    heros.pointdevie = heros.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous vous etes soigner, vous redonnant ", leHeal, " points de vie");
  } else if (coffre == 2) {
    georges.pointdevie = georges.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Georges, lui redonnant ", leHeal, " points de vie");
  } else if (coffre == 3) {
    david.pointdevie = david.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner David, lui redonnant ", leHeal, " points de vie");
  } else if (coffre == 4) {
    bernard.pointdevie = bernard.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Bernard, lui redonnant ", leHeal, " points de vie");
  } else if (coffre == 5) {
    daniel.pointdevie = daniel.pointdevie + leHeal;
    printf("%s%d%s\n", "Vous avez soigner Daniel, lui redonnant ", leHeal, " points de vie");
  } else if (coffre > 5) {
    printf("%s\n", "Vous avez rater votre attaque");
  }
} else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

if (david.pointdevie > 0 && slime.pointdevie > 0){
Sleep(2000);

SetColor(14);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DAVID >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Coup de Bouclier [1]" " ; Coup Fatal [2]" " ; Renforcement [3]");

scanf("%d", &coffre);
if (coffre == 1) {
slime.pointdevie = slime.pointdevie - (coupBouclier.degats - (slime.defense/2));
} else if (coffre == 2) {
coffre = (rand() % (100 - 1 + 1)) + 1;
  if (coffre <= coupFatal.tauxReussite){
    printf("%s\n", "vous avez reussi votre coup fatal, le monstre est sonner");
    coupFatal.cooldown = 4;
  } else {
    printf("%s\n", "Le coup fatal a manquer");
  }
} else if (coffre == 3) {
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
} else if (coffre > 3) {
printf("%s\n", "Vous avez rater votre attaque");
}
SetColor(15);
}

printf("\n%s", "point de vie Slime : ");
printf("%d\n", slime.pointdevie);
printf("\n%s", "Votre defense : ");
printf("%d\n", heros.defense);
printf("\n%s", "point de vie : ");
printf("%d\n", heros.pointdevie);

Sleep(2000);

SetColor(2);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< BERNARD >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Slash [1]" " ; Double Lame [2]" " ; Infection [3]");
SetColor(15);

Sleep(2000);

SetColor(5);
printf("\n\n%s\n\n", "<<<<<<<<<<<<<<<<< DANIEL >>>>>>>>>>>>>>>>> ");
printf("%s\n", "Tranchant [1]" " ; Blizzard [2]" " ; Transcende [3]");
SetColor(15);

Sleep(2000);


// Au cas où ils dépassent leur limite de pv
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

printf("\n%s", "point de vie : ");
printf("%d\n", heros.pointdevie);
}

return 0;
}
