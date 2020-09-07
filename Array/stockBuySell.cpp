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
#define pi pair<int,int>
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

pi getDays(int A[], int s, int n){
    int sell=s, buy=s, profit=0;
    for(int i=s+1; i<n; i++){
        // cout<<i<<" ";
        if((A[i]>A[sell])){
            profit = A[i]-A[buy];
            sell = i;
            // cout<<"sell changes\n";
        }
        else{
            if(sell == s){
                buy = i;
                sell = i;
                // cout<<"buy changes\n";
            }
            else{
                if(profit>0)
                return {buy, i};
            }
        }
    }
    if(profit>0)
    return {buy, n};
    else{
        return {-1,-1};
    }
}

int main(){
    SPEED;
    int t;
    cin>>t;
    w(t){
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        // for(int i=0; i<n; i++)cout<<A[i]<<" <- "<<i<<", ";
        int s = 0;
        while(s<n-1){
            pi ans = getDays(A, s, n);
            s = ans.se;
            if(s == -1){
                cout<<"No Profit";
                break;
            }
            else
            cout<<"("<<ans.fi<<" "<<ans.se-1<<") ";
        }
        cout<<"\n";
    }

    return 0;
}
