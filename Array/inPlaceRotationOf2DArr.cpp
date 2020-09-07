#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n; int A[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(i != j){
                    int temp = A[i][j];
                    A[i][j] = A[j][i];
                    A[j][i] = temp;
                }

            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                int temp = A[i][j];
                A[i][j] = A[i][n-1-j];
                A[i][n-1-j] = temp;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<A[i][j]<<" ";
            }cout<<"\n";
        }
    }
}