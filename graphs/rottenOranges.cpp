#include<bits/stdc++.h>
using namespace std;

int G[101][101];

int timeToRot(int n, int m){
    queue<pair<int,int>> Q;
    int C=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(G[i][j] == 2){
                Q.push({i,j});
            }
            if(G[i][j] != 0){
                C++;
            }
        }
    }
    int ans;
    int c=0;
    pair<int, int> p;
    Q.push({-1, 0});
    while(!Q.empty()){
        p = Q.front();
        int i = p.first;
        int j = p.second;
        Q.pop();
        if(i == -1){
            if(!Q.empty()){
                Q.push({-1, j+1});
            }
            else{
                ans = j;
                break;
            }
            continue;
        }
        c++;
        if(G[i][j+1] == 1){
            Q.push({1,j+1});
            G[i][j+1] = -1;
        }
        if(G[i][j-1] == 1){
            Q.push({i, j-1});
            G[i][j-1] = -1;
        }
        if(G[i+1][j] == 1){
            Q.push({i+1, j});
            G[i+1][j] = -1;
        }
        if(G[i-1][j] == 1){
            Q.push({i-1, j});
            G[i-1][j] = -1;
        }
    }
    if(c == C){
        return ans;
    }
    else return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(G, -1, sizeof(G));
        int n, m;
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>G[i][j];
            }
        }
        cout<<timeToRot(n, m)<<"\n";
    }
    return 0;
}