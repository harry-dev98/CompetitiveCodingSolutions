#include<bits/stdc++.h>
using namespace std;

int X[] = {1, -1, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A[3][3], B[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>A[i][j];
            B[i][j] = 0;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int _=0; _<5; _++){
                if(i+X[_] < 3 && i+X[_] >= 0 && j+Y[_] < 3 && j+Y[_] >= 0){
                    B[i+X[_]][j+Y[_]] += A[i][j];
                }
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<1 - (B[i][j]%2);
        }
        cout<<"\n";
    }    
    return 0;
}