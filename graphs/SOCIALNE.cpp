#include<bits/stdc++.h>
using namespace std;

const int N = 51;
const int inf = 1e9+9;
int G[N][N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t, m;
    cin>>t;
    string s;
    cin>>s;
    while(t--){
        m = s.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                G[i][j] = inf;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(s[j] == 'Y'){
                    G[i][j] = 1;
                }
            }
            if(t==0 && i == m-1)continue;
            cin>>s;
        } 
        int tmpmx, mx = 0, id = 0;
        for(int i=0; i<m; i++){
            tmpmx = 0;
            for(int j=0; j<m; j++){
                for(int k=0; k<m; k++){
                    if(G[i][k] == 1 && G[k][j]==1){
                        tmpmx += G[i][j]==0?1:0;
                    }    
                }
            }
            if(tmpmx>mx){
                mx = tmpmx;
                id = i;
            }
        }
        cout<<id<<" "<<mx<<"\n";
    }
    return 0;
}