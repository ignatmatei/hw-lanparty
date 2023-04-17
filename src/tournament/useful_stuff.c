#include "useful_stuff.h"
void printList(Team *head)
{
    int i;
    printf("head of list \n");
    while(head != NULL)
    {
        printf("%s \n", head->data.name);
        head = head ->next;
    }
    printf("end of list \n");
}

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
  t->data.totalPoints /= t->data.noOfPlayers;
}
float findMinPoints(Team *head)
{
    int i;
    float min = head->data.totalPoints;
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
void deleteTeam (Team **head, float points)
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
void push(Team ** top, TeamData data)
{

}
void deleteList(Team **head)
{
  Team * headcopy;
  while(*head != NULL)
  {
      headcopy = (*head)->next;
      free((*head)->data.name);
      free(*head);
      *head = headcopy;
  }
  *head = NULL;
}

Queue *createQueue()
{
    Queue *q;
    q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) return NULL;
    q->front  = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, MatchData data)
{
    Match *newMatch = (Match*)malloc(sizeof(Match));
    newMatch->data = data;
    newMatch->next = NULL;
    if(q->rear == NULL) q->rear = newMatch;
    else
    {
        (q->rear)->next = newMatch;
        (q->rear) = newMatch;
    }
    if(q->front == NULL)
        q->front = q->rear;
}
 int isQueueEmpty(Queue *q)
 {
     return(q->front == NULL);
 }
MatchData deQueue(Queue *q)
{
 Match *aux;
 MatchData data;
 if(isQueueEmpty(q)) return;
 aux = q->front;
 data = aux->data;
 q->front = (q->front)->next;
 free(aux);
 return data;
}

