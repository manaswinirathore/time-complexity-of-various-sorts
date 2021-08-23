#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Node
{
    int i_d,wt,dee,prev;
    struct Node* nxt;
}Node;

typedef struct Head
{
    Node* hd;
    int prev,dee;
}Head;

typedef struct Graph
{
    int r;
    Head* graph;
}Graph;
typedef struct Heap1
{
    int r;
    Node*heap;
}Heap;
typedef struct Path
{
    Node* hd;
    int dee;
} Path;

typedef struct Paths
{
    int r;
    Path* p_aths;
}Paths;

Graph* init(int s_ize);
Graph* fl(void);
Graph* Dijkstra_Algo(Graph* m, Heap* s);
Head ins(Head hd, int i_d, int wt);
Heap* crt(int s_ize);
Heap* del(Heap* s, int* delete);
Heap* updt(Heap* s);
Heap* dist_updt(Heap* s, int i_d, int dee);
Node* ins_pt(Node* hd, int i_d);
void Display(Graph* m);
int* reset_graph(int* array, int s_ize);

