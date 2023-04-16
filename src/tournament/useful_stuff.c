#include "useful_stuff.h"

void addTeamAtBeginning(Team ** head, TeamData data){
   Team *newTeam = (Team*)malloc(sizeof(Team));
   newTeam->data = data;
   newTeam->next = *head;
   *head = newTeam;
}

void addTeamAtEnd(Team ** head, TeamData data){
   if(*head == NULL){
    addTeamAtBeginning(&*head, data);
   }
   else{
        Team *aux = *head;
   Team *newTeam = (Team*)malloc(sizeof(Team));
   newTeam->data = data;
      while(aux->next != NULL)
        aux = aux->next;
      aux->next = newTeam;
      newTeam->next = NULL;
   }
}
void addPlayerAtBeginning(Player ** head, PlayerData data){
  Player *newPlayer = (Player*)(malloc(sizeof(Player)));
  newPlayer->data = data;
  newPlayer->next = *head;
  *head = newPlayer;
}
void calculateTotalPoints(Team *t)
{
  int i;
  for(i = 0; i < t->data.noOfPlayers; i++)
  {
      t->data.totalPoints += t->data.listOfPlayers->data.points;
      t->data.listOfPlayers = t->data.listOfPlayers->next;
  }
}
int findMinPoints(Team *head, int nr)
{
    int i;
    int min = head->data.totalPoints;
    for(i = 0; i < nr; i++)
    {
        if(head->data.totalPoints < min)
            min = head->data.totalPoints;
     head = head->next;
    }
  return min;
}
