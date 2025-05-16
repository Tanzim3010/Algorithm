#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int grey = 1;
int black = 2;

int cycleCount = 0;
bool cycle = false;

void dfs_visit(int u,int parent,vector<vector<int>> &adj,vector<int> &color){
    color[u] = grey;
    cout << "Visiting node: " << u << endl;

    for(int v : adj[u]){
        if(color[v] == white){
            dfs_visit(v,u,adj,color);
        } 
        else if(v != parent) {
            cycleCount++;
            cycle = true;
            cout << "Cycle at edge: " << u << " -> " << v << endl;
        }
    }
    color[u] = black;
    cout << "finished node: " << u << endl;

}

void dfs(vector<vector<int>> &adj,int n){
    vector<int> color(n,white);
    

    for(int u=0; u<n; u++){
        if(color[u] == white){
            dfs_visit(u,-1,adj,color);
        }
    }
}

int main() {
    cout << boolalpha;  

    int n = 5;
    vector<vector<int>> adj(n);

    
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {2};
    adj[4] = {2};

    dfs(adj, n);

    cout << "Final cycle status: " << cycle << endl;

    return 0;
}

/*      

 0
/ \
1--2
  / \
  3  4


  
*/