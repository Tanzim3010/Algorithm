#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printParens(vector<vector<int>> &s, int i, int j){
   if(i==j) {
    cout << "T" << j;
   } 
   else {
    cout << "(";
    printParens(s,i,s[i][j]);
    printParens(s,s[i][j]+1,j);
    cout << ")";
   }
}

void mcm(vector<int> &d){
    int n = d.size()-1;
    vector<vector<int>> M(n+1,vector<int>(n+1,0));
    vector<vector<int>> s(n+1,vector<int>(n+1,0));

    for(int len = 2; len <= n; len++){
        for(int i = 1; i<=n-len+1; i++){
            int j = i + len - 1;
            M[i][j] = INT_MAX;

            for(int k=i; k<j; k++){
                int q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];

                if(q<M[i][j]){
                    M[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications: " << M[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printParens(s, 1, n);
    cout << endl;
}

int main() {
    vector<int> d = {30,35,15,5,10,20,25}; 
    mcm(d);
    return 0;
}