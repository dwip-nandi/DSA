#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int visit[100000];
void toDFS(int node){
    visit[node]=1;
    cout<<node<<"->";

    for(int i=0;i<v[node].size();i++){
        int child = v[node][i];
        if(visit[child]==0){
            toDFS(child);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    toDFS(1);

}