#include "useful_stuff.h"

void printList(Team* head)
{
    int i;
    printf("head of list \n");
    while (head != NULL)
    {
        printf("%s \n", head->data.name);
        head = head->next;
    }
    printf("end of list \n");
}

void addTeamAtBeginning(Team** head, TeamData data) {
    Team* newTeam = (Team*)malloc(sizeof(Team));
    newTeam->data = data;
    newTeam->next = *head;
    *head = newTeam;
}

void addTeamAtEnd(Team** head, TeamData data) {
    if (*head == NULL) {
        addTeamAtBeginning(&*head, data);
    }
    else {
        Team* aux = *head;
        Team* newTeam = (Team*)malloc(sizeof(Team));
        newTeam->data = data;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newTeam;
        newTeam->next = NULL;
    }
}
void addPlayerAtBeginning(Player** head, PlayerData data) {
    Player* newPlayer = (Player*)(malloc(sizeof(Player)));
    newPlayer->data = data;
    newPlayer->next = *head;
    *head = newPlayer;
}
void calculateTotalPoints(Team* t)
{
    int i;
    for (i = 0; i < t->data.noOfPlayers; i++)
    {
        t->data.totalPoints += t->data.listOfPlayers->data.points;
        t->data.listOfPlayers = t->data.listOfPlayers->next;
    }
    t->data.totalPoints /= t->data.noOfPlayers;
}
float findMinPoints(Team* head)
{
    int i;
    float min = head->data.totalPoints;
    while (head != NULL)
    {
        if (min > head->data.totalPoints)
            min = head->data.totalPoints;
        head = head->next;
    }
    return min;
}
int findBiggestPow2(int n)
{
    int a = 2;
    while (a <= n)
        a *= 2;
    a /= 2;
    return a;
}
void deleteTeam(Team** head, float points)
{
    if (*head == NULL) return;
    Team* headcopy = *head;
    if (headcopy->data.totalPoints == points)
    {
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    Team* prev = *head;
    while (headcopy != NULL)
    {
        if (headcopy->data.totalPoints != points)
        {
            prev = headcopy;
            headcopy = headcopy->next;
        }
        else
        {
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
    }
}
void push(Team** top, TeamData data)
{
    Team* newTeam = (Team*)malloc(sizeof(Team));
    if (newTeam == NULL) {
        printf("!!!!!!!!!!!!!");
        return;
    }
    newTeam->data = data;
    newTeam->next = *top;
    *top = newTeam;
}
int isStackEmpty(Team* top)
{
    return top == NULL;
}
TeamData pop(Team** top)
{
    Team* temp = *top;
    TeamData aux = temp->data;
    *top = (*top)->next;
    free(temp);
    return aux;
}
void deleteStack(Team** top)
{
    Team* temp;
    while (!isStackEmpty((*top)))
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
void deleteList(Team** head)
{
    Team* headcopy;
    while (*head != NULL)
    {
        headcopy = (*head)->next;
        free((*head)->data.name);
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}

Queue* createQueue()
{
    Queue* q;
    q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enQueue(Queue* q, MatchData data)
{
    Match* newMatch = (Match*)malloc(sizeof(Match));
    newMatch->data = data;
    newMatch->next = NULL;
    if (q->rear == NULL) q->rear = newMatch;
    else
    {
        (q->rear)->next = newMatch;
        (q->rear) = newMatch;
    }
    if (q->front == NULL)
        q->front = q->rear;
}
int isQueueEmpty(Queue* q)
{
 //   if (q->front == NULL)
        return q->front == NULL;

    //if (strcmp(q->front->data.team2.name, q->rear->data.team2.name) ==0)
    //{
    //    printf("este egat");
    //    q->front->next == NULL;
    //}

    //return q->front == NULL;
}
MatchData deQueue(Queue* q)
{
    Match*  aux = q->front;
    MatchData data = aux->data;
    q->front = (q->front)->next;;
    free(aux);
    return data;
}

void deleteQueue(Queue *q)
{
    Match *aux;
    while(!isQueueEmpty(q))
    {
        aux = q->front;
        q->front = q->front->next;
        free(aux);
    }
    free(q);
}

Node* newNode(TeamData data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

Node* insert(Node* node, TeamData key)
{
    if (node == NULL)
        return newNode(key);
    if (key.totalPoints < node->data.totalPoints)
        node->left = insert(node->left, key);
    if (key.totalPoints > node->data.totalPoints)
        node->right = insert(node->right, key);
    if (key.totalPoints == node->data.totalPoints && strcmp(key.name, node->data.name) < 0)
        node->left = insert(node->left, key);
    if(key.totalPoints == node->data.totalPoints && strcmp(key.name, node->data.name) > 0)
        node->right = insert(node->right, key);
    return node;

}

Node* minValueNode(Node* node)
{
    Node* aux = node;
    while (aux->left != NULL)
        aux = aux->left;
    return aux;
}

Node* deleteNode(Node* root, TeamData key)
{
    if (root == NULL) return root;
    if (key.totalPoints < root->data.totalPoints)
        root->left = deleteNode(root->left, key);
    if (key.totalPoints > root->data.totalPoints)
        root->right = deleteNode(root->right, key);
    if(key.totalPoints == root->data.totalPoints && strcmp(key.name, root->data.name) < 0)
        root->left = deleteNode(root->left, key);
    if (key.totalPoints == root->data.totalPoints && strcmp(key.name, root->data.name) > 0)
        root->right = deleteNode(root->right, key);
    if (key.totalPoints == root->data.totalPoints && strcmp(key.name, root->data.name) == 0)
    {
        if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else
            if (root->right == NULL){
                Node* temp = root;
                root = root->left;
                free(temp);
                return root;

         }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;

}
