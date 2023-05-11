#include "pch.h"
#include "useful_stuff.h"
int main()
{
    int noOfTeams, i, j, x, newnr, nrOfTeamsToBeDeleted;
    int* tasks;
    float val;
    char teamName[40], playerLastName[40], playerFirstName[40];
    char gol[1000];
    TeamData currTeam, t1, t2;
    PlayerData currPlayer;
    Team* head = NULL, * winnerStack = NULL, * loserStack = NULL;
    Player* currTeamPLayerHead;
    MatchData currMatch;
    Queue* q = NULL;
    Node* root = NULL, *currNode = NULL;
    Node* rootAVL = NULL;
    FILE* f;
    FILE* f1;
    FILE* fout;
    tasks = (int*)(malloc(5 * sizeof(int)));
    f = fopen("c.in", "r");
    fscanf(f, "%d %d %d %d %d", &tasks[0], &tasks[1], &tasks[2], &tasks[3], &tasks[4]);
    fclose(f);
    f1 = fopen("d.in", "r");
    fscanf(f1, "%d", &noOfTeams);
    if (tasks[0])
    {
        for (i = 0; i < noOfTeams; i++)
        {
            currTeam.totalPoints = 0;
            fscanf(f1, "%d ", &currTeam.noOfPlayers);
            fgets(teamName, 40, f1);
            strtok(teamName, "\r");
            strtok(teamName, "\n");
            currTeam.name = (char*)malloc(strlen(teamName) * sizeof(char) + 1);
            strcpy(currTeam.name, teamName);
            currTeamPLayerHead = NULL;
            for (j = 0; j < currTeam.noOfPlayers; j++)
            {
                fscanf(f1, "%s %s %d", playerLastName, playerFirstName, &currPlayer.points);
                strtok(playerLastName, "\r");
                strtok(playerFirstName, "\r");
                strtok(playerLastName, "\n");
                strtok(playerFirstName, "\n");
                currPlayer.lastName = (char*)malloc(strlen(playerLastName) * sizeof(char));
                currPlayer.firstName = (char*)malloc(strlen(playerFirstName) * sizeof(char));
                strcpy(currPlayer.lastName, playerLastName);
                strcpy(currPlayer.firstName, playerFirstName);
                addPlayerAtBeginning(&currTeamPLayerHead, currPlayer);
            }
            currTeam.listOfPlayers = currTeamPLayerHead;
            addTeamAtBeginning(&head, currTeam);
            calculateTotalPoints(head);
            fgets(gol, 10, f1);
        }
        fclose(f1);
        fout = fopen("r.out", "w");
        printList(head, fout);
    }
    if (tasks[1])
    {
        newnr = findBiggestPow2(noOfTeams);
        nrOfTeamsToBeDeleted = noOfTeams - newnr;
        for (i = 0; i < nrOfTeamsToBeDeleted; i++)
        {
            val = findMinPoints(head);
            deleteTeam(&head, val);
            printList(head,fout);
        }
    }
    if (tasks[2])
    {
        q = createQueue();
        i = 0;
        int currRound = 1;
        while (i < newnr)
        {
            if (i % 2 == 0)
            {
                t1 = head->data;
                t1.name = (char*)malloc(strlen(head->data.name) * sizeof(char));
                strcpy(t1.name, head->data.name);
            }
            else
            {
                t2 = head->data;
                t2.name = (char*)malloc(strlen(head->data.name) * sizeof(char));
                strcpy(t2.name, head->data.name);
                currMatch.team1 = t1;
                currMatch.team2 = t2;
                enQueue(q, currMatch);
            }
            head = head->next;
            i++;
        }
        while (newnr >= 2)
        {
            fprintf(fout,"\n");
            fprintf(fout,"--- ROUND NO.%d \n", currRound);
            while (!isQueueEmpty(q))
            {
                currMatch = deQueue(q);
                if (currMatch.team2.totalPoints > currMatch.team1.totalPoints || (currMatch.team2.totalPoints == currMatch.team1.totalPoints && strcmp(currMatch.team2.name,currMatch.team1.name) < 0))
                {
                    currMatch.team2.totalPoints++;
                    push(&winnerStack, currMatch.team2);
                    push(&loserStack, currMatch.team1);
                }
                else
                {
                    currMatch.team1.totalPoints++;
                    push(&winnerStack, currMatch.team1);
                    push(&loserStack, currMatch.team2);
                }
                fprintf(fout,"%s \t - \t %s \n", currMatch.team1.name, currMatch.team2.name);
            }
            q->rear = NULL;
            //printf("The losers of the round: \n");
            while (!isStackEmpty(loserStack))
            {
                t1 = pop(&loserStack);
                //printf("%s \n", t1.name);
            }
            i = 0;
            newnr /= 2;
            fprintf(fout,"\n");
            fprintf(fout,"WINNERS OF ROUND NO.%d \n",currRound);
            currRound++;
            while (i < newnr)
            {
                if (i % 2 == 0)
                {
                    t1 = pop(&winnerStack);
                    if (newnr == 8)
                    {
                        root = insert(root, t1);
                        //rootAVL = insertAVL(rootAVL, t1);
                    }
                    fprintf(fout,"%s \t - %.2f \n", t1.name,t1.totalPoints);
                }
                else
                {
                    t2 = pop(&winnerStack);
                    if (newnr == 8)
                    {
                        root = insert(root, t2);
                       // rootAVL = insertAVL(rootAVL, t2);
                    }
                    fprintf(fout,"%s \t - %.2f \n", t2.name,t2.totalPoints);
                    currMatch.team1 = t1;
                    currMatch.team2 = t2;
                    enQueue(q, currMatch);
                }
                i++;
            }
        }
    }
    if (tasks[3])
    {
        fprintf(fout,"\n");
        fprintf(fout,"TOP 8 TEAMS: \n");
        for (i = 0; i < 8; i++)
        {
            currNode = maxValueNode(root);
            fprintf(fout,"%s\t- %.2f \n", currNode->data.name,currNode->data.totalPoints);
            rootAVL = insertAVL(rootAVL, currNode->data);
            root = deleteNode(root, currNode->data);

        }

   }
    if (tasks[4])
    {
        fprintf(fout,"\n");
        fprintf(fout,"THE LEVEL 2 TEAMS ARE: \n");
        printNodesLevel2(rootAVL,fout);
    }
    return 0;
}
