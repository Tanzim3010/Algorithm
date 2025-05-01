#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Initialize DP table
    vector<vector<int>> V(n + 1, vector<int>(W + 1, 0));

    // Build the table as per the algorithm
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                if (values[i - 1] + V[i - 1][w - weights[i - 1]] > V[i - 1][w]) {
                    V[i][w] = values[i - 1] + V[i - 1][w - weights[i - 1]];
                } else {
                    V[i][w] = V[i - 1][w];
                }
            } else {
                V[i][w] = V[i - 1][w];
            }
        }
    }

    return V[n][W]; // maximum value in knapsack
}

int main() {
    int n = 4;                   // Number of items
    int W = 8;                   // Max capacity
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values  = {3, 4, 5, 6};

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
