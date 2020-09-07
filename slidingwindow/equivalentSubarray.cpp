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
        int x;
        cin>>x;
        int A[x];
        for(int i=0; i<x; i++)cin>>A[i];
        unordered_set<int>S, s;
        for(int i=0; i<x; i++){
            S.insert(A[i]);
        }
        int k = S.size();
        int ans = 0;
        for(int j = k; j<=x; j++){
            s = {};
            for(int i=0; i<j; i++){
                s.insert(A[i]);
            }
            if(s.size()==k)ans++;
            for(int i=j; i<x-j+1; i++){
                    s.erase(A[i-j]);
                    s.insert(A[i]);
                    if(s.size()==k)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}