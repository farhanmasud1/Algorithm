#include <stdio.h>
#include <stdlib.h>
int Bellman_Ford(int G[20][20], int V, int E, int edge[20][2]) //function to find shortest path
{
    int i,u,v,k,distance[20],parent[20],S,flag=1; //declaring variables
    for(i=0; i<V; i++)
        distance[i] = 100000, parent[i] = -1 ; //initializing distance and parent
    printf("Enter source: ");
    scanf("%d",&S); //taking source as input
    distance[S-1]=0 ; //initializing distance of source to 0
    for(i=0; i<V-1; i++)
    {
        for(k=0; k<E; k++) //loop to find shortest path
        {
            u = edge[k][0], v = edge[k][1] ; //taking edge
            if(distance[u]+G[u][v] < distance[v]) //checking if distance of u + weight of edge is less than distance of v
            {
                distance[v] = distance[u] + G[u][v], parent[v]=u ; //updating distance and parent
            }

        }
    }
    for(k=0; k<E; k++) //loop to check if negative weight cycle exists
    {
        u = edge[k][0], v = edge[k][1] ; //taking edge
        if(distance[u]+G[u][v] < distance[v]) //checking if distance of u + weight of edge is less than distance of v
            flag = 0 ; //if yes then negative weight cycle exists
    }
    if(flag) //if no negative weight cycle exists
        for(i=0; i<V; i++)
            printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1); //printing shortest path

    return flag; //returning flag
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0; //declaring variables
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V); //taking no. of vertices as input
    printf("Enter graph in matrix form:\n");
    for(i=0; i<V; i++) //taking graph as input
    {
        for(j=0; j<V; j++)
        {
            scanf("%d",&G[i][j]); //taking input
            if(G[i][j]!=0) //if weight of edge is not 0
            {
                edge[k][0]=i,edge[k++][1]=j; //storing edge
            }

        }
    }


    if(Bellman_Ford(G,V,k,edge)) //calling function
    {
        printf("\nNo negative weight cycle\n");
    }

    else
    {
        printf("\nNegative weight cycle exists\n"); //if negative weight cycle exists
    }

    return 0;
}
