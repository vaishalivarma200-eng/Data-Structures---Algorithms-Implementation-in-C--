#include <iostream>
#include <string>
using namespace std;

string dfs_places[3] = {"Dorm Room", "Library", "Cafeteria"};
int dfs_graph[3][3] = {
    {0, 1, 1}, 
    {1, 0, 0}, 
    {1, 0, 0}
}; 
bool dfs_visited[3] = {false};

void run_dfs(int v) {
    dfs_visited[v] = true;
    cout << "Exploring: " << dfs_places[v] << "\n";
    for(int i = 0; i < 3; i++) {
        if(dfs_graph[v][i] == 1 && !dfs_visited[i]) {
            run_dfs(i);
        }
    }
}

int main() {
    cout << "--- Campus DFS Tour ---\n";
    run_dfs(0); 
    return 0;
}
