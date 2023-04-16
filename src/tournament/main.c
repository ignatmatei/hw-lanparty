#include "useful_stuff.h"
int main()
{
    int noOfTeams , i, j , x , newnr, nrOfTeamsToBeDeleted, val;
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
    newnr = findBiggestPow2(noOfTeams);
    nrOfTeamsToBeDeleted = noOfTeams - newnr;
    for(i = 0; i < nrOfTeamsToBeDeleted; i++)
    {
        val = findMinPoints(head);
        deleteTeam(&head, val);
    }
    int f = findMinPoints(head);
    printf("%d", f);
    return 0;
}
