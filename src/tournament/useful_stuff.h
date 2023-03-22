#include <stdlib.h>
#include <stdio.h>

typedef struct Player{
  char* FirstName;
  char* SecondName;
  int Points;
  struct Player* next;
};

typedef struct Team{
 int NoOfPlayers;
 int TotalPoints;
 struct Player* HeadPlayer;
 int TotalPoints;
 int status;
 struct Team* next;
};
