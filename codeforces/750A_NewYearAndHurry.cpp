#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin>>n>>t; 
    t = 240-t;
    int ans, sum=0;
    for(int i=1; i<=n; i++){
        sum+=5*i;
        ans = i;
        if(sum>t){
            ans--;
            break;
        }
    }

    cout<<ans<<"\n";
    return 0;
}