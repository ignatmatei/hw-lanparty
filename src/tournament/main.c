#include "useful_stuff.h"
int main()
{
    Team *head;
    head = NULL;
    TeamData t1 , t2;
    t1.name="Andrei";
    t2.name ="Matei";
    t1.name = "Andreix";
    t1.noOfPlayers = 1;
    t2.noOfPlayers = 2;
    addTeamAtEnd(&head, t1);
    addTeamAtEnd(&head, t2);
    int i;
    for(i = 1; i <= 2; i++){
    printf("%s", head->data.name);
    head = head->next;
    }
    return 0;
}
