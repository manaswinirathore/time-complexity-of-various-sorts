#include "PES2UG19CS217_H.h"
Graph* init(int s_ize)
{
    Graph*m=(Graph*)malloc(sizeof(Graph));

    m->r=s_ize;
    m->graph=malloc(s_ize * sizeof(Node));
    for (int i=0;i<s_ize;++i)
    {
        m->graph[i].hd=NULL;
        m->graph[i].prev=0;
        m->graph[i].dee=INT_MAX;
    }
    return m;
}

Head ins(Head hd, int i_d, int wt)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->i_d = i_d;
    new_node->wt = wt;
    new_node->nxt = NULL;
    new_node->dee = INT_MAX;
    new_node->prev = 0;
    if (hd.hd == NULL)
                hd.hd = new_node;
    else
    {
        Node*x = hd.hd;
        while (x->nxt != NULL)
        {
            x = x->nxt;
        }
        x->nxt = new_node;
    }
    return hd;
}


Heap* crt(int s_ize)
{
    Heap*s = (Heap*)malloc(sizeof(Heap));
    s->r = s_ize - 1;

    s->heap=malloc((s->r + 1) * sizeof(Node));

    for (int i = 0; i < s->r; ++i)
    {
        s->heap[i].i_d = i + 1;
        s->heap[i].dee = INT_MAX;
        s->heap[i].prev = 0;
    }
    return s;
}

Heap* del(Heap* s, int* delete)
{
    *delete = s->heap[0].i_d;

    for (int i = 0; i < (s->r - 1); ++i)
    {
        s->heap[i] = s->heap[i + 1];
    }
    s->r--;
    return s;
}

Heap* updt(Heap* s)
{
    Node x;
    for (int i = 0; i < s->r - 1; ++i)
    {
        int num_swaps = 0;
        
        for (int j = 0; j < (s->r - i - 1); ++j)
        {
            if (s->heap[j].dee > s->heap[j + 1].dee)
            {
                x = s->heap[j];
                s->heap[j] = s->heap[j + 1];
                s->heap[j + 1] = x;
                num_swaps++;
            }
        }
        if (num_swaps == 0)
                    break;
    }
    return s;
}

Heap* dist_updt(Heap* s, int i_d, int dee)
{
    for (int i = 0; i < s->r;++i)
    {
        if (s->heap[i].i_d == i_d)
        {
            s->heap[i].dee = dee;
            break;
        }
    }

    s = updt(s);
    return s;
}

Graph* Dijkstra_Algo(Graph* m, Heap* s)
{
    int source= m->r - 1;
    s->heap[s->r - 1].dee = 0;
    m->graph[s->heap[s->r - 1].i_d].dee = 0;
    s = updt(s);
    int vertex[m->r];
    for (int i = 1; i < m->r;++i)
    {
        vertex[i] = 0;
    }
    vertex[m->r - 1] = 1;
    int delete;
    Node* r;

    for (int i = 1; i < (m->r - 1);++i)
    {
        s = del(s,&delete);
        vertex[delete] = 1;
        Node*x=m->graph[delete].hd;
        while (x != NULL)
        {
            if ((m->graph[delete].dee + x->wt) < (m->graph[x->i_d].dee))
            {
                m->graph[x->i_d].dee = m->graph[delete].dee + x->wt;
                s = dist_updt(s, x->i_d, m->graph[x->i_d].dee);
                m->graph[x->i_d].prev = delete;
            }
            x = x->nxt;
        }
    }
    return m;
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
Node* ins_pt(Node* hd, int i_d)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->i_d = i_d;
    new_node->nxt = NULL;
    if (hd == NULL)
               hd=new_node;
    else
    {
        Node* x = hd;
        while(x->nxt != NULL)
        {
            x = x->nxt;
        }
        x->nxt = new_node;
    }
    return hd;
}

int* reset_graph(int* array,int s_ize)
{
     array[s_ize] = 0;
     return array;
}

void Display(Graph* m)
{
    Paths* p_ath = malloc(sizeof(Paths));
    p_ath->p_aths = malloc((m->r - 1) * sizeof(Node));
    int source=m->r-1;
    int* array = malloc(source * sizeof(int));

    for (int i = 1; i < source; ++i)
    {
        if (m->graph[i].prev != 0)
        {
            Node* new_node = malloc(sizeof(Node));
            new_node->i_d = i;
            new_node->nxt = NULL;
            p_ath->p_aths[i].hd = new_node;
        }
        else
            p_ath->p_aths[i].hd = NULL;
    }

    for (int i=1; i < source; ++i)
    {
        int prev = m->graph[i].prev,j=0,k=0;
        for(int l=1;l<source;++l)
        {
            array = reset_graph(array,l);
        }
        if (prev != 0)
        {
            while (prev != source)
            {
                array[j] = prev;
                j++;
                prev=m->graph[prev].prev;
            }
            array[j] = prev;
        }
        while (k <= j && (array[j]==source))
        {
            p_ath->p_aths[i].hd = ins_pt(p_ath->p_aths[i].hd,array[k]);
            k++;
        }
    }
    Node*x;

    for (int i = 1; i < source; ++i)
    {
        x = p_ath->p_aths[i].hd;
        if (x == NULL)
               printf("%d No Path\n",i);
        else
        {
            printf("%d ",i);

            while (x != NULL)
            {
                printf("%d ",x->i_d);
                x = x->nxt;
            }
            printf("%d\n",m->graph[i].dee);
        }
    }
}
