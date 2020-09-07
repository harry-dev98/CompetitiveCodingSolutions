#include <bits/stdc++.h>
using namespace std;
int *constructST(int a[],int n){
    int *tree = new int[n<<1];
    for (int i=0; i<n; i++) tree[n+i] = a[i];
    for (int i=n-1; i>=0; i--) tree[i] = min(tree[i<<1], tree[(i<<1)+1]);
    return tree;
}

int query(int *t, int n, int l, int r) {
    int minimum = INT_MAX;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l & 1) minimum = min(minimum, t[l++]);
        if (r & 1) minimum = min(minimum, t[--r]);
    }
    return minimum;
}
int _RMQ(int st[], int s, int e, int l, int r, int ind=0){
    if(s>r || e<l){
        return 100001;
    }
    if(l<=s && e<=r){
        return st[ind];
    }
    int mid = (s+e)/2;
    int m = _RMQ(st, s, mid, l, r, 2*ind+1);
    int n = _RMQ(st, mid+1, e, l, r, 2*ind+2);
    // cout<<s<<e<<m<<" "<<n<<"\n";
    return min(m,n);
}

int RMQ(int st[] , int n, int l, int r){
    // return _RMQ(st, 0, n, a, b);
    return query(st, n, l, r+1);
}


int main(){
    int arr[] = {1,2,3,4};

    int *st = constructST(arr, 4);
    for(int i=0; i<8; i++){
        cout<<st[i]<<endl;
    }
    cout<<RMQ(st, 4, 2, 3)<<"\n";
}