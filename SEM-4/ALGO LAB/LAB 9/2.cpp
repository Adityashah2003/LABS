#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; 
int n = 4; 
int dist[4][4] = {{0, 10, 15, 20},
                  {10, 0, 35, 25},
                  {15, 35, 0, 30},
                  {20, 25, 30, 0}}; 

int visited = (1<<n) - 1; 
int arr[1<<16][16]; 

int tsp(int mask, int pos){
    if(mask == visited){
        return dist[pos][0];
    }
    if(arr[mask][pos] != -1){
        return arr[mask][pos];
    }
    int ans = INF;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            int new_ans = dist[pos][i] + tsp(mask | (1<<i), i);
            ans = min(ans, new_ans);
        }
    }
    return arr[mask][pos] = ans;
}
int main(){
    memset(arr, -1, sizeof(arr));
    cout<<"Minimum cost: "<<tsp(1,0)<<endl;
    return 0;
}
