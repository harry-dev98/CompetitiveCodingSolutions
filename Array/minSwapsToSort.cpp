#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    int n;
    cin>>n;
    while(n--){
        int l, x;cin>>l;
        vector<pair<int,int>> V;
        for(int i=0; i<l; i++){
            cin>>x;
            V.push_back(make_pair(x, i));
        }
        sort(V.begin(), V.end());
        map<int,int> M;
        for(int i=0; i<l; i++){
            M[V[i].second] = i;
        }
        int vis[l];
        memset(vis, 0, sizeof(vis));
        int swaps = 0;
        int cycl = 0;
        for(int i=0; i<l; i++){
            int val = i;
            while(val != -1){
                if(vis[val]==1){
                    swaps += cycl-1;
                    cycl = 0;
                    val = -1;
                }
                else{
                    vis[val] = 1;
                    val = M[val];
                    cycl++;
                }
            }
        }
        cout<<swaps<<"\n";
    }
    return 0;
}