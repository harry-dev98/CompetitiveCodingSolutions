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
#define pi pair<int, int>
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
    // SPEED;
    int n;
    cin>>n;
    w(n){
        int x; cin>>x;
        int A[x], ans[x];
        for(int i=0; i<x; i++)cin>>A[i];
        stack<pi> S;
        S.push(mp(x-1, 1));
        for(int i=x-2; i>=0; i--){
            cout<<A[S.top().fi]<<" "<<S.top().se<<" "<<A[i]<<endl;
            if(A[S.top().fi]>A[i]){
                cout<<"doog\n";
                pi tmp = {i, 1};
                S.push(tmp);
            }
            else{
                cout<<"here\n";
                while(A[S.top().fi]<A[i]){
                    pi tmp = S.top();S.pop();
                    ans[tmp.fi] = tmp.se;
                    if(S.empty()){
                        break;
                    }
                    S.top().se += tmp.se;
                }
                S.push({i, 1});
            }
        }
        while(true){
            pi tmp = S.top();S.pop();
            ans[tmp.fi] = tmp.se;
            if(S.empty()){
                break;
            }
            S.top().se += tmp.se;
        }
        for(int i=0; i<x; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}