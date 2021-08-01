class Solution {
    static class qentry {
        int v;
        int dist;// Distance of this vertex from source
    }
    static int minThrow(int N, int arr[]) {
        int n=30; //no of elements on board
        // create a 'move' array
        int []move = new int[n];
        for(int i=0;i<n;i++) {
            move[i] = -1;
        }
        for(int i=0;i<2*N;i+=2) {
            move[arr[i]-1] = arr[i+1]-1;
        }
        int []visited = new int[n];
        Queue<qentry> q = new LinkedList<>();
        qentry qe = new qentry();
        qe.v = 0;
        qe.dist = 0;
        visited[0] = 1;
        q.add(qe);

        // BFS
        while (!q.isEmpty()) {
            qe = q.remove();
            int v = qe.v;
            if (v == n - 1)
                break;

            // Dequeue the front vertex and enqueue its reachable vertices
            for (int j = v + 1; j <= (v + 6) && j < n; j++) {
                // If this cell is already visited, then ignore
                if (visited[j] == 0) {
                    // calculate its distance and mark it as visited
                    qentry a = new qentry();
                    a.dist = (qe.dist + 1);
                    visited[j] = 1;

                    // Check if there a snake or ladder at 'j' then tail of snake or top of ladder
                    // become the adjacent of 'i'
                    if (move[j] != -1)
                        a.v = move[j];
                    else
                        a.v = j;
                    q.add(a);
                }
            }
        }
      
        return qe.dist;
    }
}
