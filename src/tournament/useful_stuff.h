#include <stdio.h>
#include <stdlib.h>

struct PlayerData{
 char *firstName;
  char *secondName;
  int points;
};
struct TeamData{
  char *name;
  int noOfPlayers;
 int totalPoints;
 int status;

 struct Player *listOfPlayers;
};

struct Player{
  struct PlayerData data;
  struct  Player *next;
};

 struct Team{
 struct TeamData data;
 struct Team* next;
};

typedef struct Team Team;
typedef struct Player Player;
typedef struct PlayerData PlayerData;
typedef struct TeamData  TeamData;

void addTeamAtBeginning(Team **, TeamData);
void addTeamAtEnd(Team **, TeamData);

