#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node* next;
}node;

typedef struct 
{
    int num_vertex;
    node** adj_lists;
}Graph_list;

Graph_list* create_graph_list(int vertex)
{
    Graph_list* graph=malloc(sizeof(Graph_list));
    graph->num_vertex=vertex;
    graph->adj_lists=malloc(sizeof(node*)*vertex);
    for(int i=0;i<vertex;i++){
        graph->adj_lists[i]=NULL;
    }
    return graph;
}

int add_edge_list(Graph_list* graph, int src, int des)
{
    node* new_node= malloc(sizeof(node));
    if(new_node==NULL){
        printf("memory not allocated ");
        exit(0);
    }
    new_node->vertex= des;
    new_node->next= graph->adj_lists[src];
    graph->adj_lists[src]= new_node;

    return 0;
}

int main() 
{
    int num_vertex = 5; 
    Graph_list* graph = create_graph_list(num_vertex);


    add_edge_list(graph, 0, 1);
    add_edge_list(graph, 0, 3);
    add_edge_list(graph, 1, 2);
    add_edge_list(graph, 1, 4);
    add_edge_list(graph, 3, 4);

    
    for (int i = 0; i < num_vertex; i++) {
        node* temp = graph->adj_lists[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
