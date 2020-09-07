#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define vi vector<int> 
#define eb emplace_back
#define pi pair<int,int>
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
        int x, split;cin>>x;
        int A[x];
        vi V;
        rep(i, 0, x-1)cin>>A[i];
        stack<pi> S;S.push({0,x-1});
        while(!S.empty()){
            pi tmp = S.top();S.pop();
            if(tmp.fi == tmp.se){
                // V.pb(A[tmp.fi]);
                cout<<A[tmp.fi]<<" ";
            }
            else{
                S.push({tmp.fi, tmp.fi});
                split =  upper_bound(A+tmp.fi+1, A+tmp.se+1, A[tmp.fi]) - (A);
                cout<<split<<endl;
                if(split<=tmp.se)
                S.push({split, tmp.se});
                if(tmp.fi != split-1)
                    S.push({tmp.fi+1, split-1});
            }
        }
        
        cout<<"\n";
    }

    return 0;
}