#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int G[MAX][MAX]={};
int E, V;

void BFS_iterative(int cv, int visited[]){
    queue<int> Q;
    
    for(Q.push(cv);!Q.empty();Q.pop()){
        int cv = Q.front();
        cout<<cv<<" ";
        visited[cv]=1;
        for(int i=1; i<=V; i++){
            if(G[cv][i]==1 && visited[i]==0){
                Q.push(i);
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
    int visited_[V+1]={};
    BFS_iterative(cv, visited_);
    return 0;
}
