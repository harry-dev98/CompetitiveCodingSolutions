#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

int V, E, x, y;
vi L[10001];

int getPossibleMV(int cv, bool visit[]){
    visit[cv]=true;
    for(auto itr=L[cv].begin(); itr != L[cv].end(); itr++){
        if(!visit[*itr]){
            getPossibleMV(*itr, visit);
        }
    }
    return cv;
}

bool checkMV(bool visit[]){
    for(int i=0; i<V; i++){
        if(!visit[i]){
            return false;
        }
    }
    return true;
}

int findMotherV(){
    bool visit[V]={false * V};
    int v;
    for(int i=0; i<V; i++){
        if(!visit[i]){
            v = getPossibleMV(i, visit);
        }
    }
    bool visit_[V] = {false * V};
    v = getPossibleMV(v, visit_);
    if(checkMV(visit_)){
        return v;
    }
    else{
        return -1;
    }
}

int main(){
    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>x>>y;
        L[x].pb(y);
    }
    int mv = findMotherV();
    cout<<mv<<"\n";
    return 0;
}
