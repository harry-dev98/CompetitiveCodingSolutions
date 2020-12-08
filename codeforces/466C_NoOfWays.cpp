#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> Arr(n);
    for(int& a: Arr)cin>>a;
    int runningSum = 0;
    for(int& a: Arr){
        a += runningSum;
        runningSum = a;
    }
    int ans = 0;
    if(runningSum%3 == 0)cout<<"0\n";
    else{
        for(int i=1; i<n-1; i++){
            if(Arr[i] == runningSum/3){
                int low = i, high=n-1, mid;
                while(low <= high){
                    mid = low + (high - low)/2;
                    
                }
            }
        }
    }
}