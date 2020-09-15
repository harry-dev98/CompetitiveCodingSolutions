#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> Time(n);
    for(int& t: Time)cin>>t;
    int mn = 1e9+7, ind=-1, repeated = 0;
    for(int i=0; i<n; i++){
        if(mn>Time[i]){
            mn = Time[i];
            ind = i+1;
            repeated = 0;
        }
        else if(mn == Time[i])repeated++;
    } 
    if(repeated == 0){
        cout<<ind<<"\n";
    }
    else{
        cout<<"Still Rozdil\n";
    }
    return 0;
}