#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

#define fi first
#define se second
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

bool comp(pair<int, int>p, pair<int, int>o){
    if(p.fi == o.fi){
        return p.se > o.se;
    }
    return p.fi < o.fi;
}

int main(){
    int s, n, x, y;
    cin>>s>>n;
    pair<int, int> X[n];
    for(int i=0; i<n; i++){
        cin>>X[i].fi>>X[i].se;
    }
    sort(X, X+n, comp);
    bool a = true;
    for(int i=0; i<n; i++){
        if(s<=X[i].fi){
            a = false;
            break;
        }
        s += X[i].se;
    }
    cout<<(a?"YES":"NO")<<"\n";
    return 0;
}