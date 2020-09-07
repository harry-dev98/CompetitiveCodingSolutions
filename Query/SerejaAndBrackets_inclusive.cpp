#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define p pair<int, pii>

int T[10000]={};
int O[10000]={};
int C[10000]={};


void build(string str, int s, int e, int ind=0){
    if(e<s){
        return;
    }
    if(e == s){
        if(str[s] == ')'){
            C[ind]=1;
        }
        else{
            O[ind] = 1;
        }
        // cout<<s<<e<<endl;
        // cout<<ind<<"=> "<<T[ind]<<" "<<O[ind]<<" "<<C[ind]<<endl;
        return;
    }
    
    int mid = (s+e)/2;
    build(str, s, mid, 2*ind+1);
    build(str, mid+1, e, 2*ind+2);
    int temp = min(O[2*ind+1], C[2*ind+2]);
    T[ind] = T[2*ind+1] + T[2*ind+2] + 2 * temp;
    O[ind] = O[2*ind+1] + O[2*ind+2] - temp; 
    C[ind] = C[2*ind+1] + C[2*ind+2] - temp; 
    return;
}

p query(int l, int r, int s, int e, int ind=0){
    if(r<s || e<l){
        return p(0, pii(0, 0));
    }
    // printf("%d %d %d %d %d\n",l, r, s, e, ind);
    if(l<=s && e<=r){
        // printf("returning..(%d, %d) %d %d %d\n", s, e, T[ind], O[ind], C[ind]);
        return p(T[ind], pii(O[ind], C[ind]));
    }
    int mid = (s+e)/2;
    p q1 = query(l, r, s, mid, 2*ind+1);
    p q2 = query(l, r, mid+1, e, 2*ind+2);
    p q;
    int temp = min(q1.second.first, q2.second.second);
    q.first = q1.first + q2.first + 2*temp;
    q.second.first = q1.second.first + q2.second.first - temp;
    q.second.second = q1.second.second + q2.second.second - temp;
    // printf("returning..(%d, %d) %d %d %d\n",s, e, q.first, q.second.first, q.second.second);
    return q;
}

int main(){
    string str;
    SPEED;
    cin>>str;
    int q;
    int n = str.length();
    build(str, 0, n-1);
    // cout<<T[0]<<endl;
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