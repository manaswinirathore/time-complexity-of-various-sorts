#include "PES2UG19CS217_H.h"
int main()
{
    Graph*m = fl();
    Heap*s = crt(m->r);
    m = Dijkstra_Algo(m,s);
    Display(m);
}
Graph* fl(void)
{
    FILE*fil;
    fil=fopen("adjacencylist.txt","r");

    if (fil == NULL)
    {
        return NULL;
    }
    size_t s_ize = 1000;
    char* number = malloc(1000 * sizeof(char));
    int p_line=getline(&number,&s_ize,fil);
    Graph* m = init(atoi(number)+1);

    while((p_line = getline(&number,&s_ize,fil) != -1))
    {
        char* tkn = strtok(number, " ");
        int node = atoi(tkn);
        int weight,vertex;
        while (tkn != NULL)
        {
            // Get vertex token
            tkn = strtok(NULL," ");
            if (tkn == NULL)
                          break;
            vertex=atoi(tkn);
            tkn=strtok(NULL," ");
            if (tkn == NULL)
                           break;
            weight=atoi(tkn);
            m->graph[vertex] = ins(m->graph[vertex],node,weight);
        }
    }
    return m;
}
