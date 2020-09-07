#include<iostream>
using namespace std;

int main(){
    int t, n, r, a, b, c;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        cin>>n;
        int A[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
                }
            }
        }
        cin>>r;
        a = 0;
        for(int i=0; i<r; i++){
            cin>>b>>c;
            b--;c--;
            a += A[b][c];
        }
        cout<<"Case #"<<tt<<": "<<a<<"\n";
    }
    return 0;
}