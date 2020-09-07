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
const ll N = 3e5 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;


int main(){
    SPEED;
    int n;
    cin>>n;
    w(n){
        int x, k;cin>>x>>k;int Arr[x+1], Ans[x+1], ANS[x-k+1];
        for(int i=0; i<x; i++)cin>>Arr[i];
        stack<int> S;S.push(x-1);
        for(int i=x-2; i>=0; i--){
            while(Arr[i] > Arr[S.top()]){
                int temp = S.top();
                S.pop();
                Ans[temp] = S.empty()?x:S.top();
                if(S.empty())break;
            }
            S.push(i);
        }
        while(!S.empty()){
            int temp = S.top();
            S.pop();
            Ans[temp] = S.empty()?x:S.top();
        }
        int j = 0;
        for(int i=0; i<x-k+1; i++){
            while(j<i || Ans[j]<=i+k-1){
                j++;
            }
            ANS[i] = Arr[j];
        }
        for(int i=0; i<x-k+1; i++){
            cout<<ANS[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}