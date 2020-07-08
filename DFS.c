// input adjacency matrix
// also determines the connectivity

#include <stdio.h>
#include <stdlib.h>
int flag=1; //keeps track of number of visited vertices, can be used to check connectivity
int k=0; // indexing for the final dfs array
int n;
void DFS(int g[n][n],int i,int *visited,int *order)
{
    order[k++] = i+1;
    visited[i] = 1;
    for(int j=0;j<n;j++)
    {
        if(g[i][j]==1 && (!visited[j]))
        {
            flag++;
            DFS(g,j,visited,order);
        }
    }
}

void main() 
{
	printf("No of vertices\n");
	scanf("%d",&n);
	int graph[n][n];
	printf("Enter Adj. Matrix\n");
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        scanf("%d",&graph[i][j]);
	int *visited;
    visited = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        visited[i]=0;
    int *order;
    order = (int*)malloc(n*sizeof(int));
    int x;
    printf("Starting vertex index:\n"); // if node 1 then x=0
    scanf("%d",&x);
	DFS(graph,x,visited,order);
	for(int i=0;i<n;i++)
	    printf("%d ",order[i]);
	if(flag==n) printf("\nConnected\n");
	else printf("\nNOT Connected\n");
}
