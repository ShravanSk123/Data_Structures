import java.io.*;
import java.util.*;

class Graph{
    int V; //number of vertices
    LinkedList<Integer> adj[];
    
    Graph(int v){  //not a default constructor
        V = v; //initializing
        adj = new LinkedList[v];
        // create...
        for(int i=0;i<v;i++){
            adj[i] = new LinkedList();
        }
    }
    
    //add edges
    void addEdge(int v,int w){ // w to be added
        adj[v].add(w);
    }
    
    // s is starting vertex(source)
    // BFS traversal
    
    void BFS(int s){
        boolean []visited = new boolean[V]; // create visited list for all vertices
        // if vertex is visited mark as 'true'
        
        LinkedList<Integer> queue = new LinkedList<Integer>(); //use LL class as queue(since bfs)
        //mark starting vertex as visited and add to queue
        visited[s] = true;
        queue.add(s);
        
        //BFS algorithm
        while(queue.size()!=0){
            s = queue.poll(); // removes first element, store in s
            //print it
            System.out.print(s+" ");
            //use Iterator class to get adjacent vertices
            Iterator<Integer> i = adj[s].listIterator();
            while(i.hasNext()){
                int n = i.next();
                if(visited[n] == false){
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }
    //main 
    public static void main (String[] args) {
        Scanner s = new Scanner(System.in);
        Graph g = new Graph(4);
        g.addEdge(0,1);
        g.addEdge(0,2); 
        g.addEdge(1,2); 
        g.addEdge(2,0); 
        g.addEdge(2,3); 
        g.addEdge(3,3);
        int k;
        System.out.println("Enter the starting vertex/ source");
        k = s.nextInt();
        
        System.out.print("BFS Traversal is ");
        
        g.BFS(k);
    }
}
