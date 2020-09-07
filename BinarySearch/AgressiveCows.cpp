#include<iostream>
#include<algorithm>
using namespace std;

bool reqCondtSatisfied(const int A[], const int& n, const int& mid, const int& c){
    int tot = 0;
    int i = 0, j = 0;
    while(i<n){
        tot++;
        while(A[i] - A[j] < mid && i<n){
            i++;
        }
        j = i;
    }
    return tot>=c;
}

int BinarySearch(int A[], int n, int c){
    int l=0, r=1e9;
    int mid;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(reqCondtSatisfied(A, n, mid, c)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    return l;
}

int main(){
    int t, n, c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        sort(A, A+n);
        cout<<BinarySearch(A, n, c)<<"\n";
    }
    return 0;
}