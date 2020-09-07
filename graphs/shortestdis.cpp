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


int N[] = {1, -1, 0, 0};
int M[] = {0, 0, 1, -1};

int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        int X, Y, x, y;
        cin>>X>>Y;
        int A[X][Y];
        for(int i=0; i<X; i++)for(int j=0; j<Y; j++)cin>>A[i][j];
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){
                cout<<A[i][j];
            }
            cout<<"\n";
        }
        cin>>x>>y;
        queue<pair<int,int>>Q;
        Q.push({0,0});
        Q.push({-1, -1});
        int ans = 0;
        while(!Q.empty()){
            pair<int,int> p = Q.front();
            Q.pop();
            if(p.fi==x && p.se==y)break;
            if(p.fi == -1 && p.se == -1){
                ans++;
                if(!Q.empty()){
                    Q.push({-1,-1});
                }
                continue;
            }
            for(int i=0; i<4; i++){
                int x_ = p.fi + N[i];
                int y_ = p.se + M[i];
                if(x_>=0 && x_<X && y_>=0 && y_<Y){
                    if(A[x_][y_] == 1){
                        Q.push({x_, y_});
                        A[x_][y_] = -1;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}