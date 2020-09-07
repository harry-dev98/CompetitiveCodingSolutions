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

void bfs(int s, vi L[], bool visit[], int v){
    queue<int> Q;
    Q.push(s);
    visit[s]=true;
    while(!Q.empty()){
        s = Q.front();Q.pop();
        cout<<s<<" ";
        for(auto itr=L[s].begin(); itr!=L[s].end(); itr++){
            if(!visit[*itr]){
                Q.push(*itr);
                visit[*itr]=true;
            }
        }
    }
}


int main(){
    SPEED;
    int t, v, e, x, y;
    cin>>t;
    w(t){
        cin>>v>>e;
        vi L[v];
        rep(i, 1, e){
            cin>>x>>y;
            L[x].pb(y);
            L[y].pb(x);
        }
        bool visit[v];
        bfs(0, L, visit, v);
        cout<<"\n";
    }
    return 0;
}
