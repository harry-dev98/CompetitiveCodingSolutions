#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pi pair<int,int>

void buildST(int A[], pi ST[], int n, int l, int r, int ind=0){
    if(l == r-1){
        ST[ind].first = ST[ind].second = A[l];
        return;
    }
    int mid = (l+r)/2;
    buildST(A, ST, n, l, mid, 2*ind+1);
    buildST(A, ST, n, mid, r, 2*ind+2);
    ST[ind].first = ST[2*ind+1].first + ST[2*ind+2].first;
    ST[ind].second = max(ST[2*ind+1].second, ST[2*ind+1].first + ST[2*ind+2].second);
}

pi getSum(pi ST[], int n, int ql, int qr, int l, int r, int ind=0){
    if(qr <= l || ql >= r){
        return {0, -1000000};
    }
    if(ql <= l && r <= qr){
        return ST[ind];
    }
    int mid = (l+r)/2;
    if(ql>=mid){
        return getSum(ST, n, ql, qr, mid, r, 2*ind+2);
    }
    if(qr<=mid){
        return getSum(ST, n, ql, qr, l, mid, 2*ind+1);
    }
    pi x = getSum(ST, n, ql, qr, l, mid, 2*ind+1);
    pi y = getSum(ST, n, ql, qr, mid, r, 2*ind+2);
    pi ans = {x.first+y.first, max(x.second, x.first+y.second)};
    return ans;
}

int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int A[n]; pi ST[2*n+2];
        for(int i=0; i<n; i++)cin>>A[i];
        buildST(A, ST, n, 0, n);
        int l,r;
        for(int i=0; i<q; i++){
            cin>>l>>r;
            cout<<getSum(ST, n, l, r, 0, n).second<<" ";
        }
       cout<<"\n";
    }
    return 0;
}