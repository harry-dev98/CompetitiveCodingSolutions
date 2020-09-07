#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int INF = 1000000009;
int getLIS(int A[], int n, vector<int>& LIS){
    int I[n+1];
    for(int i=0; i<n+1; i++)I[i] = INF;
    I[0] *= -1;
    int DP[n+1];
    int ptr, lis = 0;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i])-I;
        I[ptr] = A[i];
        DP[i] = ptr;
        lis = max(lis, ptr);
    }
    for(int i=n-1; i>=0; i--){
        if(DP[i] == lis){
            ptr = i;
            break;
        }
    }
    LIS.push_back(A[ptr]);
    for(int i=ptr-1; i>=0; i--){
        if(A[i] < A[ptr] && DP[i]+1 == DP[ptr]){
            ptr = i;
            LIS.push_back(A[ptr]);
        }
    }
    reverse(LIS.begin(), LIS.end());
    return lis;
}

int main(){
    int n = 10;
    int A[] = {8, 1, 9, 8, 3, 4, 6, 1, 5, 2};
    vector<int>LIS;
    int lis = getLIS(A, n, LIS);
    cout<<lis<<"\n";
    for(auto e:LIS)cout<<e<<" ";
    cout<<"\n";
    return 0;
}