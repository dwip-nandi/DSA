#include<bits/stdc++.h>
using namespace std;
int minDistance(vector<int>&vertex,vector<bool>&visited,int n){
    int mn =INT_MAX, min_index=n;

    for(int v=0;v<n;v++){
        if(!visited[v] && vertex[v]<mn){
            mn = vertex[v];
            min_index=v;
        }
    }
    return min_index;
}
void printPath(vector<int>&pre,int des){
    if(pre[des]==-1)return ;

    printPath(pre,pre[des]);
    cout<<"->"<<char('A'+des);
}
int dijkstra(vector<vector<int>> &graph,int src,int des){
    int n =graph.size();
    vector<int>vertex(n,INT_MAX);
    vector<bool>Visited(n,false);
    vector<int>pre(n,-1);
    vertex[src]=0;
    for(int i=0;i<n-1;i++){
        int u = minDistance(vertex,Visited,n);
        visited[u]=true;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v] && vertex[v]!=INT_MAX vertex[u]+graph[u][v]<vertex[v]){
                vertex[v]=vertex[u]+graph[u][v];
                pre[v]=u;
            }
        }

    }
    cout<<"Shortest Path from"<<char('A'+src)<<"to"<<char('A'+des)<<':'<<char('A'+src);
    printPath(pre,des);
    cout<<endl;
}
int main(){
    cout<<"Enter the number of VErtix : ";
    int n; cin>>n;
    cout<<"Enter the vertixes : "<<endl;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cin>>v[i][j];
        }
    }

    cout<<"Enter the Source : ";
    char s; cin>>s;
    int src = s -'A';
    cout<<"Enter the destination :";
    char d; cin>>d;
    int des = d-'A';

    dijkstra(v,src,des);
}