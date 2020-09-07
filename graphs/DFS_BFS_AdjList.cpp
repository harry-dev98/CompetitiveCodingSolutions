#include<bits/stdc++.h>
using namespace std;

// assumed that the graph is directed... 

vector<int> adj[1001];
int V, E;

void DFS(int cv, int v[]){
    stack<int> S;
    S.push(cv);
    while(!S.empty()){
        cv = S.top();
        cout<<cv<<" ";
        S.pop();
        for(auto i=adj[cv].rbegin(); i!=adj[cv].rend(); i++){
            if(v[*i]==0){
                v[*i]==1;
                S.push(*i);
            }
        }
    }
}

void BFS(int cv, int v[]){
    queue<int> Q;
    for(Q.push(cv);!Q.empty();Q.pop()){
        cv = Q.front();
        cout<<cv<<" ";
        for(auto i=adj[cv].begin();i!=adj[cv].end();i++){
            if(v[*i]==0){
                Q.push(*i);
            }
        }
    }
}

int main(){
    int cv;
    cin>>V>>E>>cv;
    for(int i=1; i<=E; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int v[V+1]={};
    int v_[V+1]={};
    DFS(cv, v);
    cout<<"\n";
    BFS(cv, v_);
    return 0;
}