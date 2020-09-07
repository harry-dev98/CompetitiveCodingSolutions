#include<iostream>
#include<unordered_set>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int A[n], B[m];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        for(int i=0; i<m; i++){
            cin>>B[i];
        }
        unordered_set<int> S(A, A+n);
         bool ans = false;
        for(int i=0; i<m; i++){
            if(S.find(B[i]) != S.end()){
                cout<<"YES\n";
                cout<<1<<" "<<B[i]<<"\n";
                ans = true;
                break;
            }
        }
        if(!ans){
            cout<<"NO\n";
        }
    }
    return 0;
}