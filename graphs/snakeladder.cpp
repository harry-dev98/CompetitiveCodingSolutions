#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pll pair<long long ,long long >
#define ppll pair < pll , pll >
#define INF 1e18
#define eps 0.00001
#define le length
#define w(x) while(x--)
#define p(n1) cout << n1 << endl
#define rep(i , j , n) for(ll i = j ; i <= n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)
const ll N = 3e5 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;

int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        vector<int> adj[31];
        int x, y, z;
        cin>>x;
        for(int i=0; i<x; i++){
            cin>>y>>z;
            adj[y].push_back(z);
        }
        int vis[31];
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(1);
        for(auto itr:adj[1]){
            if(vis[itr]==0){
                Q.push(itr);
                vis[itr] = 1;
            }
        }
        Q.push(0);
        vis[1]=1;
        vis[0]=1;

        while(Q.size()>1){
            int top = Q.front();Q.pop();
            if(top==30){
                while(Q.front()>1){
                    Q.pop();
                }
                break;
            }
            if(top>0){
                for(int i=1; i<7; i++){
                    if(vis[top+i]==0 && (top+i)<31){
                        Q.push(top+i);
                        vis[top+i] = 1;
                        for(auto itr:adj[top+i]){
                            if(vis[itr]==0){
                                Q.push(itr);
                                vis[itr] = 1;
                            }
                        }
                    }
                }
                
            }
            else{
                if(!Q.empty())
                    Q.push(top-1);
            }
        }
        cout<<-1*Q.front()<<"\n";
        Q.pop();
    }
    return 0;
}