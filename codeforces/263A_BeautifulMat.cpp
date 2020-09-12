#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, z;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>z;
            if(z == 1){
                x = i;
                y = j;
            }
        }
    }
    cout<<abs(2-x) + abs(2-y)<<"\n";
    return 0;
}