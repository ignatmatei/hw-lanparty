#include "useful_stuff.h"

void addTeamAtBeginning(Team ** head, TeamData data)
{
   Team *newTeam = (Team*)malloc(sizeof(Team));
   newTeam->data = data;
   newTeam->next = *head;
   *head = newTeam;
}

void addTeamAtEnd(Team ** head, TeamData data)
{
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
