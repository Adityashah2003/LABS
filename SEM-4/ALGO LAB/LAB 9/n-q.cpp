#include<bits/stdc++.h>
using namespace std;

void displayAllBoards(vector<vector<string>> &ans, int n){
    for(auto board: ans){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
bool isSafe(int col, int row, vector<string> &board, int n){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    row = duprow;
    col = dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0; row<n; row++){
        if(isSafe(col, row, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n; i++){//fills out each row of the board with empty "." string
        board[i] = s;
    }
    solve(0, board, ans, n);
    displayAllBoards(ans, n);
    return 0;
}