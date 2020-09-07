#include<bits/stdc++.h>
using namespace std;

int G[1001][1001]={};
int V, E;

int DFS(int cv, int visit[]){
    if(visit[cv]){
        return 0;
    }
    int area=1;
    visit[cv]=1;
    cout<<cv<<", ";
    for(int i=1; i<=V; i++){
        if(G[cv][i]==1){
            area+=DFS(i, visit);
        }
    }
    return area;
}

int main(){
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        int a,b;
        cin>>a>>b;
        G[a][b]=1;
    }
    int cv;
    cin>>cv;
    int visit[V+1]={};
    cout<<DFS(cv, visit)<<"\n";
    return 0;
}