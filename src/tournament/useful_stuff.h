#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PlayerData {
    char* firstName;
    char* lastName;
    int points;
};
struct TeamData {
    char* name;
    int noOfPlayers;
    float totalPoints;
    int status;

    struct Player* listOfPlayers;
};

struct Player {
    struct PlayerData data;
    struct  Player* next;
};

struct Team {
    struct TeamData data;
    struct Team* next;
};
struct MatchData
{
    struct TeamData team1;
    struct TeamData team2;
};
struct Match
{
    struct MatchData data;
    struct Match* next;
};
struct Q
{
    struct Match* front, * rear;
};
struct N
{
    struct TeamData data;
    int height;
    struct N* left;
    struct N* right;
};
typedef struct Team Team;
typedef struct Player Player;
typedef struct PlayerData PlayerData;
typedef struct TeamData  TeamData;
typedef struct MatchData MatchData;
typedef struct Q Queue;
typedef struct Match Match;
typedef struct N Node;
void addTeamAtBeginning(Team**, TeamData);
void addTeamAtEnd(Team**, TeamData);
float findMinPoints(Team*);
void addPlayerAtBeginning(Player**, PlayerData);
int findBiggestPow2(int);
void deleteTeam(Team**, float);
void printList(Team*);
void deleteList(Team**);
Queue* createQueue();
void enQueue(Queue*, MatchData);
int isQueueEmpty(Queue*);
MatchData deQueue(Queue*);
void calculateTotalPoints(Team*);
void push(Team**, TeamData);
int isStackEmpty(Team*);
TeamData pop(Team**);
void deleteStack(Team**);
void deleteQueue(Queue*);
Node* newNode(TeamData);
Node* insert(Node*, TeamData);
Node* minValueNode(Node*);
Node* deleteNode(Node*, TeamData);
void inorder(Node*);
Node* maxValueNode(Node*);
