#include <iostream>
#include <vector>
using namespace std;


int white = 0;
int grey = 1;
int black = 2;

int cycle = 0;
bool cycleCount = false;

void dfs_visit(int u,vector<vector<int>> &adj,vector<int> &color){
    color[u] = grey;
    cout << "Visiting node: " << u << endl;

    for(int v : adj[u]){
        if(color[v] == white) {
            dfs_visit(v,adj,color);
        }
        else if (color[v] == grey) {
            cycle++;
            cycleCount = true;
            cout << "Cycle at edge: " << u << " -> " << v  << endl;
        }
    }
    color[u] = black;
    cout << "finished node: " << u << endl;
}

void dfs(vector<vector<int>> &adj, int n){
    vector<int> color(n,white);

    for(int u=0; u<n; u++){
        if(color[u] == white){
            dfs_visit(u,adj,color);
        }
    }
}

int main() {
    int n = 7;
    vector<vector<int>> adj(n);

    
    adj[0] = {1, 2};     
    adj[1] = {2};         
    adj[2] = {3, 4};      
    adj[3] = {0};         
    adj[4] = {5};         
    adj[5] = {6};         
    adj[6] = {};   

    dfs(adj, n);

    return 0;
}