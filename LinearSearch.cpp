#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pint pair<long long ,long long >
#define ppint pair < pint , pint >
#define INF 1e18
#define eps 0.00001
#define le length
#define w(x) while(x--)
#define p(n1) cout << n1 << endl
#define rep(i , j , n) for(int i = j ; i <= n ; i++)
#define per(i , j , n) for(int i = j ; i >= n ; i--)
#define lp(i,a,b) for(int i=a; i<b; i++)
#define lli long long int
#define li long int
#define uli unsigned long int
#define ulli unsigned long long int
#define dbl double
#define sfi(x) scanf("%d", &x)
#define pfi(x) printf("%d\n", x)
#define pf(x) printf("%s\n", x)
#define vi vector<int>
#define vli vector<long int>
#define w(x) while(x--)
const int N = 3e5 + 5;
const int MAX = 3e5 + 5;
const int M = 1e6 + 5;


int main(){
    SPEED;
    int t, n, k, ans, val;
    sfi(t);
    w(t){
        ans = -1;
        sfi(n);sfi(k);
        rep(i, 0, n-1){
            sfi(val);
            if(val == k && ans == -1){
                ans = i+1;
                cout<<ans<<"\n";
                // break;
            }
        }
        if(ans == -1){
            cout<< ans<<"\n";
        }
    }
    return 0;
}
