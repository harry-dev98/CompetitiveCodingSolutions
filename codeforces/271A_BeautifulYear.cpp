#include<bits/stdc++.h>
using namespace std;

bool check(int i){
    int _[10];
    memset(_, 0, sizeof(_));
    while(i){
        int __ = i%10;
        if(_[__]){
            return false;
        }
        _[__]++;
        i /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(true){
        n++;
        if(check(n)){
            cout<<n<<"\n";
            break;
        }
    }
    return 0;
}