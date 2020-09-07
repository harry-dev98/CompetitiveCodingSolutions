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

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        int size, sx, sy, ex, ey;
        cin>>size;
        int A[size][size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cin>>A[i][j];
                if(A[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                if(A[i][j]==2){
                    ex = i;
                    ey = j;
                }
            }
        }
        queue<pair<int,int>>Q;
        Q.push({sx, sy});
        bool ans = 0;
        while(!Q.empty()){
            pair<int,int> p = Q.front();Q.pop();
            for(int i=0; i<4; i++){
                int _ = p.fi + X[i];
                int __ = p.se + Y[i];
                if(_>=0 && _<size && __>=0 && __<size){
                    if(A[_][__] == 3){
                        Q.push({_, __});
                        A[_][__] = -3;
                    }
                    if(A[_][__] == 2){
                        ans = 1;
                        break;
                    }
                }
            }
        }
        cout<<(ans?1:0)<<"\n";
    }
    return 0;
}