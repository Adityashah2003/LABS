#include <bits/stdc++.h>
using namespace std;

static bool comp(double p1, double p2) {
    return p1 > p2;
}

double fracKnapsack(int weight[], int value[], int n, int maxCap) {
    double density[n];
    for (int i = 0; i < n; i++) {
        density[i] = value[i] / (weight[i] + 0.0);
    }
    sort(density, density + n, comp);

    int i = 0, Cap = 0;
    double totalValue = 0.0;
    while (i < n && Cap + weight[i] <= maxCap) {
        int j;
        for (j = 0; j < n; j++) {
            if (density[i] == value[j] / (weight[j] + 0.0)) {
                break;
            }
        }
        totalValue += value[j];
        Cap += weight[j];
        i++;
    }
    if (i < n) {
        int j;
        for (j = 0; j < n; j++) {
            if (density[i] == value[j] / (weight[j] + 0.0)) {
                break;
            }
        }
        totalValue += (maxCap - Cap) * (value[j] / (weight[j] + 0.0));
    }
    return totalValue;
}

int main() {
    int n;
    cout << "Enter the no. of weights: ";
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> value[i];
    }
    cout << "Enter max weight: ";
    int maxi;
    cin >> maxi;

    double x = fracKnapsack(weight, value, n, maxi);
    cout << x;
    return 0;
}
