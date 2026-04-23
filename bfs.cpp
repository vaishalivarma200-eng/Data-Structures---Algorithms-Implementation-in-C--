#include <iostream>
#include <string>
using namespace std;

string bfs_places[4] = {"Main Gate", "Classroom", "Lab", "Dorm Room"};
int bfs_graph[4][4] = {
    {0, 1, 1, 0}, 
    {1, 0, 0, 1}, 
    {1, 0, 0, 0}, 
    {0, 1, 0, 0}
};

void run_bfs(int start) {
    bool bfs_visited[4] = {false};
    int q[4], f = 0, r = 0; 
    
    q[r++] = start; 
    bfs_visited[start] = true;
    
    while(f < r) {
        int v = q[f++];
        cout << "Visiting: " << bfs_places[v] << "\n";
        
        for(int i = 0; i < 4; i++) {
            if(bfs_graph[v][i] == 1 && !bfs_visited[i]) {
                q[r++] = i; 
                bfs_visited[i] = true;
            }
        }
    }
}

int main() {
    cout << "--- Campus BFS Tour ---\n";
    run_bfs(0); 
    return 0;
}
