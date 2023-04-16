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
      currTeam.totalPoints = 0;
      fscanf(f1,"%d ",&currTeam.noOfPlayers);
      fgets(teamName,40,f1);
      strtok(teamName,"\r");
      strtok(teamName,"\n");
      currTeam.name = teamName;
      currTeamPLayerHead = NULL;
      for(j = 0; j < currTeam.noOfPlayers; j++)
      {
          fscanf(f1,"%s %s %d",playerLastName,playerFirstName,&currPlayer.points);
          currPlayer.lastName = playerLastName;
          currPlayer.firstName = playerFirstName;
          addPlayerAtBeginning(&currTeamPLayerHead,currPlayer);

      }
      currTeam.listOfPlayers = currTeamPLayerHead;
      addTeamAtBeginning(&head, currTeam);
      calculateTotalPoints(head);
      fgets(gol,10,f1);
    }
    printf("%s ! %d",head->data.name,head->data.totalPoints);
    return 0;
}
