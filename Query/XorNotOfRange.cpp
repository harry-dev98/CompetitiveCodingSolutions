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
const ll N = 1e5 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;

ll ST[N];

ll build(ll A[], int s, int e, int ind=0){
    if(s==e){
        ST[ind] = A[s];
        return ST[ind];
    }
    int mid = (s+e)/2;
    ST[ind] = build(A, s, mid, 2*ind+1)^build(A, mid+1, e, 2*ind+2);
    return ST[ind];
}

ll Query(int s, int e, int qs, int qe, int ind=0){
    if(s>qe || e<qs){
        return 0;
    }
    if(qs<=s && e<=qe){
        return ST[ind];
    }
    int mid = (s+e)/2;
    return Query(s, mid, qs, qe, 2*ind+1) ^ Query(mid+1, e, qs, qe, 2*ind+2);
}

int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        int x, q; ll XOR = 0;
        cin>>x>>q; ll A[x];
        rep(i, 0, x-1)cin>>A[i];
        rep(i, 0, x-1)XOR ^= A[i];
        build(A, 0, x-1);
        int l, r;
        ll ans;
        rep(i, 0, q-1){
            cin>>l>>r;
            ans = XOR^Query(0, x-1, l-1, r-1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}