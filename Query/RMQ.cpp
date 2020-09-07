#include<bits/stdc++.h>
using namespace std;



void _constructST(int st[], int arr[], int s, int e, int ind=0){
    // printf("%d, %d \n", s, e);
    if(s==e){
        st[ind] = arr[s];
        return;
    }
    if(s>e){
        return;
    }
    int mid = (s + e)/2;
    _constructST(st, arr, s, mid, 2*ind+1);
    _constructST(st, arr, mid+1, e, 2*ind+2);
    st[ind] = min(st[2*ind+1], st[2*ind+2]);
}

void constructST(int arr[],int n, int st[]){
  _constructST(st, arr, 0, n);

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

/* The functions returns the
 min element in the range
 from a and b */

int RMQ(int st[] , int n, int a, int b){
    return _RMQ(st, 0, n, a, b);
}

int main(){
    int arr[] = {1,2,3,4};
    int st[8];
    constructST(arr, 3, st);
    // for(int i=0; i<8; i++){
    //     cout<<st[i]<<endl;
    // }
    cout<<RMQ(st, 3, 2, 3)<<"\n";
}