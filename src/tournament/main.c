#include "useful_stuff.h"
int main()
{
    int noOfTeams , i, j , x , newnr, nrOfTeamsToBeDeleted;
    float val;
    char teamName[40],playerLastName[40],playerFirstName[40];
    char gol[1000];
    TeamData currTeam , t1 , t2;
    PlayerData currPlayer;
    Team *head = NULL;
    Player *currTeamPLayerHead;
    MatchData currMatch;
    Queue *q;
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
      currTeam.name = (char*)malloc(strlen(teamName) * sizeof(char));
      strcpy(currTeam.name,teamName);
      currTeamPLayerHead = NULL;
      for(j = 0; j < currTeam.noOfPlayers; j++)
      {
          fscanf(f1,"%s %s %d",playerLastName,playerFirstName,&currPlayer.points);
          /*currPlayer.lastName = playerLastName;
          currPlayer.firstName = playerFirstName;*/
          strtok(playerLastName,"\r");
          strtok(playerFirstName,"\r");
          strtok(playerLastName,"\n");
          strtok(playerFirstName,"\n");
          currPlayer.lastName = (char*)malloc(strlen(playerLastName) * sizeof(char));
          currPlayer.firstName = (char*)malloc(strlen(playerFirstName) * sizeof(char));
          strcpy(currPlayer.lastName,playerLastName);
          strcpy(currPlayer.firstName,playerFirstName);
          addPlayerAtBeginning(&currTeamPLayerHead,currPlayer);

      }
      currTeam.listOfPlayers = currTeamPLayerHead;
      addTeamAtBeginning(&head, currTeam);
      calculateTotalPoints(head);
      fgets(gol,10,f1);
    }
    fclose(f1);
    printList(head);
    newnr = findBiggestPow2(noOfTeams);
    nrOfTeamsToBeDeleted = noOfTeams - newnr;
    for(i = 0; i < nrOfTeamsToBeDeleted; i++)
    {
        val = findMinPoints(head);
        deleteTeam(&head, val);
        printList(head);
    }
    q = createQueue();
    i = 0;
    while(i < newnr)
    {
      if(i%2 == 0)
      {
          t1 = head->data;
          t1.name = (char*)malloc(strlen(head->data.name) * sizeof(char));
          strcpy(t1.name,head->data.name);

      }
      else
      {
          t2 = head->data;
          t2.name = (char*)malloc(strlen(head->data.name) * sizeof(char));
          strcpy(t2.name,head->data.name);
          currMatch.team1 = t1;
          currMatch.team2 = t2;
          enQueue(q,currMatch);
      }
      head = head->next;
      i++;
    }
    for(i = 0; i < newnr / 2; i++)
    {
        currMatch = deQueue(q);
        printf("%s \t %s \n",currMatch.team1.name,currMatch.team2.name);
    }
    return 0;
}
