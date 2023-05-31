#include<iostream>
using namespace std;

int knapsack(int weight[], int profit[], int n, int C)
{
    int dp[n+1][C+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weight[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + profit[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int max_profit = dp[n][C];
    cout << "\nThe max profit achievable is " << max_profit << endl;
    cout << "Selected items: ";
    int i = n, j = C;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            cout << i-1 << " ";
            j -= weight[i-1];
        }
        i--;
    }
    cout << endl;
    return max_profit;
}

int main(){
    int n, cap;
    cout << "\nEnter the number of items: ";
    cin >> n;
    int weight[n], profit[n];
    cout << "\nEnter the weight and profit for every item: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> profit[i];
    cout << "\nEnter the capacity: ";
    cin >> cap;
    knapsack(weight, profit, n, cap);
    return 0;
}
