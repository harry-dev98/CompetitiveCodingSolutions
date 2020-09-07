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
    int n, x, y;
    cin>>n;
    w(n){
        cin>>x>>y;
        int DP[x+1][y+1];
        memset(DP, 0, sizeof(DP));
        for(int i=0;i<=x;i++){
            DP[i][0] = 0;
            DP[0][i] = 0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1; j<=y; j++){
                if(i==1&&j==1){
                    DP[i][j] = 1;
                    continue;
                }
                DP[i][j] = DP[i-1][j]+DP[i][j-1];
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1; j<=y; j++){
                cout<<DP[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<DP[x][y]<<"\n";
    }
    return 0;
}