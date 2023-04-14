//krushkal's

#include<bits/stdc++.h>
using namespace std;

#define v 6
#define infinity 5000
int parent[v];

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void union1(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void krushkals(int cost[][v]){
    int mincost = 0;

    for(int i=0; i<v; i++){
        parent[i] = i;
    }

    int edge_count = 0;
    cout<<"Edges selected and corresponding cost"<<":"<<endl;
    while(edge_count<v-1){
        int min = infinity, a=-1, b=-1;
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(find(i)!=find(j) && cost[i][j]<min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a,b);
        cout<<"("<<a+1<<","<<b+1<<")"<<"\t\t"<<min<<endl;
        edge_count++;
        mincost+=min;
    }
    cout<<"Minimum cost="<<mincost;
}

int main(){
    int cost[][v] = {
        { infinity, 6,1,5,infinity,infinity },
        { 6,infinity,5, infinity, 3, infinity },
        { 1,5,infinity, 5,6,4 },
        { 5,infinity, 5,infinity,infinity,2 },
        { infinity, 3,6,infinity,infinity,6 },
        { infinity, infinity, 4,2,6,infinity },
    };

    krushkals(cost);

    return 0;
}
