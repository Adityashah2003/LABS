#include<bits/stdc++.h>
using namespace std;
int n, W, w[100], p[100], maxProfit;
bool include[100], bestSet[100];

bool promising(int i, int profit, int weight) {
    int j, k;
    int totWeight;
    double bound;
    if (weight >= W) 
        return false;
    
    else {
        j = i + 1;
        bound = profit;
        totWeight = weight;
        while (j <= n && totWeight + w[j] <= W) {
            totWeight += w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if (k <= n) {
            bound += (W - totWeight) * (p[k] / w[k]);
        }
        return bound > maxProfit;
    }
}

void knapsack(int i, int profit, int weight) {
    if (weight <= W && profit > maxProfit) {
        maxProfit = profit;
        for (int j = 1; j <= n; j++) {
            bestSet[j] = include[j];
        }
    }
    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = false;
        knapsack(i + 1, profit, weight);
    }
}

int main() {
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;
    cout << "Enter the weights and profits of each item:" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> p[i];
    }
    knapsack(0, 0, 0);
    cout << "The optimal packing of the knapsack is: " << endl;
    for (int i = 1; i <= n; i++) {
        if (bestSet[i]) {
            cout << "Item " << i << endl;
        }
    }
    cout << "Total profit: " << maxProfit << endl;
    return 0;
}
