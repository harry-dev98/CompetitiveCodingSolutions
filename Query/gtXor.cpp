#include<bits/stdc++.h>
using namespace std;

int st[1000001];

int _gtXor(int s, int e, int l, int r, int ind=0){
    if(l>e || r<s){
        return 0;
    }
    if(l<=s && e<=r){
        return st[ind];
    }
    int mid = (s+e)/2;
    int n = _gtXor(s, mid, l, r, 2*ind+1);
    int m = _gtXor(mid+1, e, l, r, 2*ind+2);
    return n ^ m;
}

void buildTree(int arr[], int s, int e, int ind=0){
    // cout<<s<<e<<endl;
    if(s==e){
        st[ind] = arr[s];
        return;
    }
    if(s>e){
        return;
    }
    int mid = (s+e)/2;
    buildTree(arr, s, mid, 2*ind+1);
    buildTree(arr, mid+1, e, 2*ind+2);
    st[ind] = st[2*ind+1]^st[2*ind+2];
    // printf("%d %d %d\n", st[ind], s, e);
}


int gtXor(int arr[], int n,int a,int b)
{
    buildTree(arr, 0, n-1);
    return _gtXor(0, n-1, a, b);
    // return 0;
}

int main(){
    int arr[] = {1,3,5,7,9,11};
    cout<<gtXor(arr, 6, 1, 3)<<"\n";
}