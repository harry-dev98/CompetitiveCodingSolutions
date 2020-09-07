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
    //prime No's
    for(int i=2; i<10001; i++){
        if(A[i] == true){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}