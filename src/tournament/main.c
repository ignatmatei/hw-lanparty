#include "useful_stuff.h"
int main()
{
    int noOfTeams , i, j , x;
    char teamName[40],playerLastName[40],playerFirstName[40];
    char gol[1000];
    TeamData currTeam;
    PlayerData currPlayer;
    Team *head = NULL;
    Player *currTeamPLayerHead;
    FILE *f1;
    f1 = fopen("d.in","r");
    fscanf(f1,"%d",&noOfTeams);
    for(i = 0; i < noOfTeams; i++)
    {
      fscanf(f1,"%d ",&currTeam.noOfPlayers);
      /*printf("%d",currTeam.noOfPlayers);*/
      fgets(teamName,40,f1);
      currTeam.name = teamName;
      /*printf("%s",currTeam.name);*/
      currTeamPLayerHead = NULL;
      for(j = 0; j < currTeam.noOfPlayers; j++)
      {
          fscanf(f1,"%s %s %d",playerLastName,playerFirstName,&currPlayer.points);
          currPlayer.lastName = playerLastName;
          currPlayer.firstName = playerFirstName;
          addPlayerAtBeginning(&currTeamPLayerHead,currPlayer);
          /*printf("%s %s",currTeamPLayerHead->data.lastName,currTeamPLayerHead->data.firstName);*/

      }
      currTeam.listOfPlayers = currTeamPLayerHead;
      addTeamAtBeginning(&head, currTeam);
      fgets(gol,10,f1);
    }
    printf("%s",head->data.name);
    return 0;
}
