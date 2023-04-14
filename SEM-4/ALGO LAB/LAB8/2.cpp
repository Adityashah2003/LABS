#include<iostream>
#include<climits>

using namespace std;

void printOptimalParenthesis(int i, int j, int bracket[][100], char& name) {
    if (i == j) {
        cout << name;
        name++;
    }
    else {
        cout << "(";
        printOptimalParenthesis(i, bracket[i][j], bracket, name);
        printOptimalParenthesis(bracket[i][j] + 1, j, bracket, name);
        cout << ")";
    }
}

void matrixChainOrder(int p[], int n){
    int m[100][100];
    int bracket[100][100];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(1, n - 1, bracket, name);
    // cout << "\nMinimum Cost: " << m[1][n - 1] << endl;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    int p[n+1];
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    matrixChainOrder(p, n + 1);
    return 0;
}
