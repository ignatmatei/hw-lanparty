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
int findMinPoints(Team *head)
{
    int i;
    int min = head->data.totalPoints;
    while(head != NULL)
    {
        if(min > head->data.totalPoints)
            min = head->data.totalPoints;
        head = head->next;
    }
  return min;
}
int findBiggestPow2(int n)
{
    int a = 2;
    while(a <= n)
        a *= 2;
    a /= 2;
    return a;
}
void deleteTeam (Team **head, int points)
{
    if(*head == NULL) return;
    Team *headcopy = *head;
    if(headcopy->data.totalPoints == points)
    {
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    Team *prev = *head;
    while(headcopy != NULL)
    {
        if(headcopy->data.totalPoints != points)
        {
            prev = headcopy;
            headcopy = headcopy ->next;
        }
        else
        {
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
    }
}
