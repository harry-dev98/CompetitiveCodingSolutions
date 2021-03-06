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
    // SPEED;
    int n;
    cin>>n;
    w(n){
        string s;cin>>s;
        stack<char> S;
        int i = 0;
        bool ans=true;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch =='[' || ch == '{'){
                S.push(ch);
            }
            else{
                if(S.empty()){
                    ans=false; break;
                }
                if(S.top() == '{' && ch != '}'){
                    ans = false;break;
                }
                else if(S.top() == '[' && ch != ']'){
                    ans = false;break;
                }
                else if(S.top() == '(' && ch != ')'){
                    ans = false;break;
                }
                S.pop();
            }
        }
        
        if(ans && S.empty()){
            cout<<"balanced\n";
        }
        else{
            cout<<"not balanced\n";
        }
    }
    return 0;
}