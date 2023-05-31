#include<iostream>
#include<stack>
using namespace std;

void DFS(int v,int visited[],int n,int a[][10])
{
    stack<int> Q;
    visited[v]=1;
    Q.push(v);

    while(!Q.empty())
    {
        int w;
        w=Q.top();
        Q.pop();
        for(int u=1;u<=n;u++)
        {
            if(a[w][u]==1 && visited[u]==0)
            {
                Q.push(u);
                visited[u]=1;
            }
        }
    }
}

void transpose(int a[][10],int n)
{
    int b[10][10];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}

int main()
{
    int a[10][10],n,m,x,p,q;
    cout<<"enter number of vertices- ";
    cin>>n;
    cout<<"enter number of edges- ";
    cin>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<"enter source- ";
        cin>>p;
        cout<<"enter destination- ";
        cin>>q;
        a[p][q]=1;
    }
    cout<<"the matrix is- \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }

    int vis1[n+1];
    for(int i=1;i<=n;i++)
        vis1[i]=0;

    int vis2[n+1];
    for(int i=1;i<=n;i++)
        vis2[i]=0;

    DFS(1,vis1,n,a);
    transpose(a,n);
    DFS(1,vis2,n,a);

    for(int i=1;i<=n;i++)
    {
        if((vis1[i]==0)&&(vis2[i]==0))
        {
            cout<<"graph not connected";
            return 0;
        }
    }
    cout<<"graph connected";
}
