#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)val[i] / (float)wt[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(val[i], val[j]);
                swap(wt[i], wt[j]);
            }
        }
    }
    int total_val = 0;
    int total_wt = 0;
    for (int i = 0; i < n; i++) {
        if (total_wt + wt[i] <= W) {
            total_wt += wt[i];
            total_val += val[i];
        }
    }
    return total_val;
}
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Maximum value in Knapsack: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
