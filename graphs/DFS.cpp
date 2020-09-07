#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int G[MAX][MAX]={};
int E, V;

void DFS_recc(int cv, int visited[]){
    for(int i=1; i<=V; i++){
        if(G[cv][i]==1 && visited[i]==0){
            cout<<i<<" ";
            visited[i]=1;
            DFS_recc(i, visited);
        }
    }
}

void DFS_iterative(int cv, int visited[]){
    stack<int> S;
    S.push(cv);
    while (!S.empty()){
        int cv = S.top();
        S.pop();
        cout<<cv<<" ";
        visited[cv]=1;
        for(int i=V; i>0; i--){
            if(G[cv][i]==1 && visited[i]==0){
                S.push(i);
            }
        }
    }
    
}

int main(){
    int cv;
    cin>>V>>E>>cv;
    for(int i=0; i<E; i++){
        int x,y;
        cin>>x>>y;
        G[x][y]=1;
        G[y][x]=1;
    }
    int visited[V+1]={};
    cout<<cv<<" ";
    visited[cv]=1;
    DFS_recc(cv, visited);
    cout<<"\n";
    int visited_[V+1]={};
    DFS_iterative(cv, visited_);
    return 0;
}
