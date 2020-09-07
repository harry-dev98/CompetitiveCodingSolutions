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
const ll N = 1e6 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;

ll A[N];
stack<ll> S;
ll mxx;

int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        int x;
        ll tmp;
        cin>>x;
        rep(i, 0, x-1)cin>>A[i];
        mxx = 0;
        S.push(0);
        rep(i, 1, x-1){
            while(A[S.top()]>A[i]){
                tmp = S.top();
                S.pop();
                cout<<mxx<<" -- ";
                if(S.empty())cout<<A[tmp]*(i)<<endl;
                else cout<<A[tmp]*(i-S.top()-1)<<endl;
                mxx = max(mxx, (S.empty())?A[tmp]*(i):A[tmp]*(i-S.top()-1));
                if(S.empty())break;
            }
            S.push(i);
        } 
        while(!S.empty()){
            tmp = S.top();S.pop();
            cout<<tmp<<" "<<mxx<<" -- -- ";
            if(S.empty())cout<<A[tmp]*(tmp+1)<<endl;
            else cout<<A[tmp]*(tmp-S.top())<<endl;
            mxx = max(mxx, (S.empty())?(A[tmp]*(x)):A[tmp]*(x-S.top()-1));
        }
        cout<<mxx<<"\n";  
    }
    return 0;
}