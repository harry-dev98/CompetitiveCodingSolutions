#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    if(b<m*a){
        cout<<(b * (n/m)) + min(b, a * (n%m))<<"\n";
    }
    else{
        cout<<n * a<<"\n";
    }
    return 0;
}