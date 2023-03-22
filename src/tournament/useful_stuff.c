#include "useful_stuff.h"

Team* addAllofTheStuffInONeFunction(){
    FILE* f1;
    f1 = fopen("date.in","r");
    int i , n=getw(f1),no1 = getw(f1);
    Team* head;
    head = (Team*)malloc(sizeof(Team));
    head->next = NULL;
    head->listOfPlayers  = (Player*)malloc(no1 * sizeof(Player));
    for(i = 0; i < no1; i++)
     {

     }
    return head;
}
//  stopAtspace()
// {

// }
