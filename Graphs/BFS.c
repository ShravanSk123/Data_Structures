// input adjacency matrix

#include <stdio.h>
int k=0; // indexing for the final bfs array
int n;
int f=0,r=-1; //queue front and rear
void BFS(int g[n][n],int i,int *visited,int *order,int *queue)
{
    if(f>r) return;
    visited[i]=1;
    order[k++] = i+1;
    for(int j=0;j<n;j++)
    {
        if(g[i][j]==1 && visited[j]==0)
        {
            visited[j]=1;
            queue[++r]=j+1;
        }
    }
    f++;
    BFS(g,queue[f]-1,visited,order,queue);
}

void main() 
{
	printf("No of vertices\n");
	scanf("%d",&n);
	int graph[n][n],queue[n];
	printf("Enter Adj. Matrix\n");
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        scanf("%d",&graph[i][j]);
	int visited[n];
    for(int i=0;i<n;i++)
    {
        queue[i]=0;
        visited[i]=0;
    }
    int order[n];
    int x;
    printf("Starting vertex(Naming starts with 1,2,3...)\n");
    scanf("%d",&x);
    queue[++r]=x;
	BFS(graph,x-1,visited,order,queue);
	for(int i=0;i<n;i++)
	    printf("%d ",order[i]);
}
