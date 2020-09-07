#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int V, E;
stack<int> S;

void TopoSort(int cv, int visit[], int done[]){
    if(visit[cv]){
        cout<<"Not a DAG!!\n";
        return;
    }
    if(done[cv]) return;
    visit[cv]=1;
    for(auto itr=adj[cv].begin();itr!=adj[cv].end();itr++){
        if(!visit[*itr]) TopoSort(*itr, visit, done);
    }
    visit[cv]=0;
    done[cv]=1;
    S.push(cv);
}


int main(){
    cin>>V>>E;
    int a,b;
    for(int i=1; i<=E; i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int visit[V+1]={}, done[V+1]={};
    for(int i=1; i<=V; i++){
        if(!done[i]) TopoSort(i, visit, done);
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}