#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, k, d0, d1;
    cin>>t;
    while(t--){
        cin>>k>>d0>>d1;
        long long runningSum = d0+d1;
        long long dig = 2, currDig=(d1+d0)%10;
        while(currDig != 0 && currDig!=2 && dig<k){
            runningSum += currDig;
            currDig = runningSum%10;
            dig++;
        }
        if(currDig == 0){

        } else {
            long long leftDig = k - dig;
            runningSum += (leftDig/4) * (2+4+8+6);
            long long leftOver = leftDig%4;
            if(leftOver == 1)runningSum+=2;
            else if(leftOver == 2)runningSum+=(2+4);
            else if(leftOver == 3)runningSum+=(2+4+8);
        }
        if(runningSum%3 == 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}