#include<bits/stdc++.h>
using namespace std;

bool A[10001];

int main(){
    //Building seive
    memset(A, true, sizeof(A));
    for(int i=2; i<sqrt(10001); i++){
        if(A[i] == true){
            for(int j=i*i; j<10001; j+=i){
                A[j] = false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;

        //prime No's
        for(int i=2; i<n; i++){
            if(A[i] == true && A[n-i]==true){
                cout<<i<<" "<<n-i;
                break;
            }
        }
    cout<<"\n";
    }
    return 0;
}