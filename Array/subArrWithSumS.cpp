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
    int t;
    cin>>t;
    w(t){
        int n, S;
        cin>>n>>S;
        li Arr[n+1];
        rep(i, 0, n-1){
            cin>>Arr[i];
        }
        li sum = 0;
        int s=0, e=0, f=0;
        rep(i, 0, n-1){
            sum+=Arr[e++];
            while(sum>S){
                sum -= Arr[s++];
            }
            if(sum==S){
                f=1;
                cout<<s+1<<" "<<e<<"\n";
                break;
            }
        }
    
        if(f==0){
            cout<<-1<<"\n";
        }
    }
    return 0;
}
