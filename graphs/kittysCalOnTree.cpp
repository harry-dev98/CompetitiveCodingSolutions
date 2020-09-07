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
const int MOD = 1e9+7;
const int MAX = 2e5 + 1;
const int M = 1e7 + 5;


int main(){
    SPEED;
    int n, q, x, y;

    cin>>n>>q;
    int G[n+1][n+1];
    vector<vector<lli>> dp(n+1, vector<lli>(n+1, M));
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        dp[x][y]=1;
        dp[y][x]=1;
        G[x][y]=1;
        G[y][x]=1;
    }
    for(int i=1; i<=n; i++){
        dp[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j]=dp[i][k]+dp[k][j];
            } 
        }
    }
    int a;
    for(int i=0; i<q; i++){
        cin>>a; int arr[a];
        for(int j=0; j<a; j++){
            cin>>arr[j];
        }
        lli ans=0;
        for(int j=0; j<a; j++){
            for(int k=j+1; k<a; k++){
                ans += arr[j] * arr[k] * dp[arr[j]][arr[k]]%MOD;
            }
        }
        ans = ans % MOD;
        cout<<ans<<"\n";
    }
    return 0;
}
