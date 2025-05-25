#include <iostream>
#include <vector>
using namespace std;

void lcs(string x,string y){
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1; i <=m; i++){
        for(int j = 1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << "Length of lcs: " << dp[m][n] << endl;


    string lcs1 = "";
    int i = m, j = n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            lcs1 = x[i-1] + lcs1;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }
    cout << "LCS: " << lcs1 << endl;
}

int main(){
    string x = "Store";
    string y = "Strongest";
    lcs(x,y);
    return 0;
}