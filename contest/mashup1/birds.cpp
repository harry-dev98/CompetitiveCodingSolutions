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
#define pli pair<long long ,int>
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
const int MAX = 3e5 + 5;
const int N = 1e4 + 1;
const int M = 1e3 + 1;

pli DP[N][M];

int main(){
    SPEED;
    lli n, W, B, X;
    cin>>n>>W>>B>>X;
    lli ans=0;
    lli Count[n], Cost[n];
    for(int i=0; i<n; i++){
        cin>>Count[i];
    }
    for(int i=0; i<n; i++){
        cin>>Cost[i];
    }
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<Count[i]; j++){
            if(i == 0){
                W -= Cost[i];
                DP[i][j].fi = W;
                DP[i][j].se = ++temp;
            }
            else{
                for(int )
            }
        }
        ans = max(ans, temp);
    }
    return 0;
}
