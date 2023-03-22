#include <stdlib.h>
#include <stdio.h>

  struct Player{
  char* firstName;
  char* secondName;
  int points;
};

 struct Team{
 int noOfPlayers;
 int totalPoints;
 int totalPoints;
 int status;
 char* name;
 Player* listOfPlayers;
 struct Team* next;
};
typedef struct Team Team;
typedef struct Player Player;