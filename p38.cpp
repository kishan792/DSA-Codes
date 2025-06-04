#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> adjList[],int visited[],int start)
{
    cout<<start<<"\t";
    visited[start]  = 1;

    for(int i = 0;i<adjList[start].size();i++)
    {
        int neb = adjList[start][i];
        if(visited[neb]!=1)
        {
            dfs(adjList,visited,neb);
        }
    }
}
int main()
{
    int n,m;

    cout<<"Enter the number of vertex"<<endl;
    cin>>n;

    cout<<"Enter the num of edges"<<endl;
    cin>>m;

    vector<int> adjList[n+1];

    for(int i =0;i<m;i++)
    {
        int u,v;
        cout<<"enter u"<<endl;
        cin>>u;

        cout<<"enter v"<<endl;
        cin>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int visited[n+1] = {0};

    for(int i =1;i<=n;i++)
    {
        if(visited[i] !=1)
        {
            dfs(adjList,visited,i);
        }
    }
}