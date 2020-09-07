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
#define MOD 1000000007
const int N = 3e5 + 5;
const int MAX = 3e5 + 5;
const int M = 1e6 + 5;


int DP[1025][101];

void clear(){
    memset(DP, -1, sizeof(DP));
    DP[0][0]=0;
}

lli getTotWays(vi Ts[], int n, int allSet, int mask = 0, int ts = 1){
    if(mask == allSet){
        return 1;
    }
    if(ts>100){
        return 0;
    }
    if(DP[mask][ts] != -1){
        return DP[mask][ts];
    }
    lli ways = getTotWays(Ts, n, allSet, mask, ts+1);
    for(auto p:Ts[ts]){
        p = (1<<p);
        if((mask & p)){
            continue;
        }
        else{
            ways += getTotWays(Ts, n, allSet, (mask|p), ts+1);
            ways %= MOD;
        }
    }
    DP[mask][ts] = ways;
    return ways;
}
int main(){
    SPEED;
    int t;
    cin>>t;
    w(t){
        int n, x;
        char c;
        cin>>n;
        vi Ts[101];
        clear();
        string temp, str; 
        getline(cin, str);  // to get rid of newline character 
        for (int i=0; i<n; i++){ 
            getline(cin, str); 
            stringstream ss(str); 
            // while there are words in the streamobject ss 
            while (ss >> temp){ 
                stringstream s; 
                s << temp; 
                s >> x; //cout<<x<<" ";
                // add the ith person in the list of cap if with id x 
                // cout<<Ts[x].size()<<", ";
                Ts[x].push_back(i); 
            } 
        } 
        int allSet = (1<<n)-1;
        cout<<getTotWays(Ts, n, allSet)<<"\n";
    }
    return 0;
}
