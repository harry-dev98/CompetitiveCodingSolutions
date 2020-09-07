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
const int M = 1e2+1;

void FloydWarshal(int G[M][M], int Ans[M][M], int V){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                    Ans[j][k] = (Ans[j][i] + Ans[i][k]) < Ans[j][k] ? Ans[j][i] + Ans[i][k] : Ans[j][k];
            }
        }
    }
}

void printAns(int Ans[M][M], int V){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(Ans[i][j]<MAX||Ans[i][j]==0){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
    }
}

int main(){
    SPEED;
    int t;
    cin>>t;
    w(t){
        int V;
        cin>>V;
        int G[M][M];
        int A[M][M];
        rep(i, 0 , V-1){
            rep(j, 0, V-1){
                cin>>G[i][j];
            }
        }
        rep(i, 0 , V-1){
            rep(j, 0, V-1){
                if(i==j){
                    A[i][j] = 0;
                }
                else{
                    if(G[i][j]==0){
                        A[i][j]=MAX;
                    }
                    else{
                        A[i][j] = G[i][j];
                    }
                }
            }
        }
        FloydWarshal(G, A, V);
        printAns(A, V);
        cout<<"\n";
    }
    return 0;
}
