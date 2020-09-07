//  gave TLE

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define p pair<int, pii>
#define f first
#define se second

int st[1000001];

void buildTree(int s, int e, int ind=0){
    if(s==e){
    // cout<<"inddd"<<ind<<"index"<<s<<endl;
        st[ind] = 1;
        return;
    }
    int mid = (s+e)/2;
    buildTree(s, mid, 2*ind+1);
    buildTree(mid+1, e, 2*ind+2);
    st[ind] = st[2*ind+1] + st[2*ind+2];
}

void update(int pos, int s, int e, int ind=0){
    if(s==e){
        if(pos == s){
            // cout<<"inddd"<<ind<<endl;
            st[ind] = 0;
        }
        return;
    }
    int mid = (s+e)/2;
    // printf("%d %d %d %d\n",s,e,pos,mid);
    if(pos<=mid){
        update(pos, s, mid, 2*ind+1);
    }
    else{
        update(pos, mid+1, e, 2*ind+2);
    }
    st[ind] = st[2*ind+1] + st[2*ind+2];
}

int query(int s, int e, int l, int r, int ind=0){
    if(l>e || r<s){
        return 0;
    }
    if(l<=s && e<=r){
        return st[ind];
    }
    int mid = (s+e)/2;
    return query(s, mid, l, r, 2*ind+1)+query(mid+1, e, l, r, 2*ind+2);
}


int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++){
        cin>>arr[i];
    }
    int q, k;
    cin>>q;
    pii K[q];
    int I[q], J[q];
    int ans[q];
    for(int i=0; i<q; i++){
        cin>>I[i]>>J[i]>>K[i].f;
        K[i].se = i;
    }
    buildTree(0, t-1);
    sort(K, K+q);
    int ind;
    for(int i=0; i<q; i++){
        k = K[i].f;
        ind = K[i].se;
        for(int j=0; j<t; j++){
            if(arr[j]<=k){
                update(j, 0, t-1);
            }
        }
        ans[ind] = query(0, t-1, I[ind]-1, J[ind]-1);
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}