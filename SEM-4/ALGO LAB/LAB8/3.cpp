#include <iostream>
#include <climits>
using namespace std;
const int n = 20;

void floydWarshall(int arr[n][n], int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                if (arr[j][i] == INT_MAX || arr[i][k] == INT_MAX) {
                    continue;
                }
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    cout << "\nAll pair shortest paths are" << endl;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << i << "--->" << j << " " << arr[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    int num;
    cout << "\nEnter the number of nodes" << endl;
    cin >> num;

    int arr[n][n];
    cout << "\nPopulate adjacency matrix, For infinity use '-2.1'" << endl;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            double temp;
            cin >> temp;
            if (temp == -2.1) {
                arr[i][j] = INT_MAX;
            } else {
                arr[i][j] = temp;
            }
        }
    }
    floydWarshall(arr, num);
    return 0;
}
