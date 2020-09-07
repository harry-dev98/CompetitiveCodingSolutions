#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int LIS(int A[], int n){
    int DP[n+10], lis=1;
    for(int i=0; i<n; i++)DP[i]=1;
    long long sign;
    for(int i=0; i<n; i++){
        sign = A[i]/abs(A[i]);
        for(int j=i; j<n; j++){
            long long _ = A[j]/abs(A[j]); 
            if(_*sign < 0 && abs(A[j])>abs(A[i])){
                DP[j] = max(DP[i]+1, DP[j]);
                lis = max(DP[j], lis);
            }
        }
    }
    return lis;
}

int main(){
    int n;
    cin>>n;
    
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    cout<<LIS(A, n)<<"\n";
    return 0;
}