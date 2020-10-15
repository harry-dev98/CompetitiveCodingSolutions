#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, needToGrow, needToFall, var;
    bool infectedAtBegin;
    cin>>t;
    while(t--){
        cin>>n>>x;
        needToFall = 0;
        needToGrow = 0;
        infectedAtBegin = 0;
        while(n--){
            cin>>var;
            if(var > x){
                needToFall += var - x;
            } else if(var < x) {
                needToGrow += x - var;
            } else{
                infectedAtBegin = 1;
            }
        } 
        if(needToFall == 0 && needToGrow == 0)cout<<0<<"\n";
        else if(needToFall == needToGrow || infectedAtBegin)cout<<1<<"\n";
        else {
            cout<<2<<"\n";
        }
    }
    return 0;
}