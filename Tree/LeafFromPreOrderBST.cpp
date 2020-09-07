#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void printLeafNodes(int A[], int s, int e){
    if(s==e){
        return;
    }
    if(s+1==e){
        cout<<A[s]<<" ";
    }
    int root = A[s];
    int sep = upper_bound(A+s, A+e, root) - A;
    printLeafNodes(A, s+1, sep);
    printLeafNodes(A, sep, e);
}

int main(){
    SPEED;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        printLeafNodes(A, 0, n);
        cout<<"\n";
    }
}