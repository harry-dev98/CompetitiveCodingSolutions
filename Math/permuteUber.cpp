#include<iostream>
using namespace std;

int main(){
    int ans = 0,n = 5;
    int _ = (n-1) * 24 * 23 * 22;

    for(int i=1; i<=25; i++){
        ans += _ * i;
    }
    cout<<ans<<"\n";
}