#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define p pair<int, pii>
#define se second
#define fi first

p ST[5000001];

void build(string str, int s, int e, int ind=0){
    if(e == s){
        if(str[s] == ')'){
            ST[ind].se.se=1;
            ST[ind].se.fi = 0;
            ST[ind].fi = 0;
        }
        else{
            ST[ind].se.fi=1;
            ST[ind].se.se=0;
            ST[ind].fi = 0;
        }
        return;
    }
    
    int mid = s+ (e-s)/2;
    build(str, s, mid, 2*ind+1);
    build(str, mid+1, e, 2*ind+2);
    int temp = min(ST[2*ind+1].se.fi, ST[2*ind+2].se.se);
    ST[ind].fi = ST[2*ind+1].fi + ST[2*ind+2].fi + 2 * temp;
    ST[ind].se.fi = ST[2*ind+1].se.fi + ST[2*ind+2].se.fi - temp; 
    ST[ind].se.se = ST[2*ind+1].se.se + ST[2*ind+2].se.se - temp; 
    return;
}

p query(int l, int r, int s, int e, int ind=0){
    if(r<s || e<l){
        return p(0, pii(0, 0));
    }
    if(l<=s && r>=e){
        return ST[ind];
    }
    int mid = s+ (e-s)/2;
    p q1 = query(l, r, s, mid, 2*ind+1);
    p q2 = query(l, r, mid+1, e, 2*ind+2);
    p q;
    int temp = min(q1.second.first, q2.second.second);
    q.first = q1.first + q2.first + 2*temp;
    q.second.first = q1.second.first + q2.second.first - temp;
    q.second.second = q1.second.second + q2.second.second - temp;
    return q;
}

string str;
int main(){
    SPEED;
    cin>>str;
    int q;
    int n = str.length();
    build(str, 0, n-1);
    cin>>q;
    int l,r;
    while(q--){
        cin>>l>>r;
        int ans = query(l-1,r-1,0,n-1).first;

        cout<<ans<<"\n";
    }
    return 0;
}

/*
())(())(())(  
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
*/