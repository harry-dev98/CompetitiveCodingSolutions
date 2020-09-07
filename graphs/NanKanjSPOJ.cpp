#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j){
    return 0<=i && i<8 && j>=0 && j<8;
}

int main(){
    int t;
    cin>>t;
    int X[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int Y[] = {1, -1, 1, -1, 2, 2, -2, -2};
    string top, x, y;
    pair<string, int> p;
    while(t--){
        cin>>x>>y;
        int vis[8][8];
        memset(vis, 0, sizeof(vis));
        queue<pair<string, int>> Q;
        Q.push({x, 0});
        while(!Q.empty()){
            p = Q.front(); Q.pop();
            top = p.first;
            if(top == y){
                Q = {};
                cout<<p.second<<"\n";
            }

            int a = top[0]-'a';
            int b = top[1]-'1';
            vis[a][b]=1;
            for(int i=0; i<8; i++){
                int a_ = a+X[i];
                int b_ = b+Y[i];
                if(valid(a_, b_)){
                    if(vis[a_][b_]==0){
                        string s="";
                        s+=('a'+a_);
                        s+=('1'+b_);
                        Q.push({s, p.second+1});
                    }
                }            
            }
        }
    }
    return 0;
}