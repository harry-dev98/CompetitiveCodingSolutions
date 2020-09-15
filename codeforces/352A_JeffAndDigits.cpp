#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> Cards(n);
    for(int& c: Cards)cin>>c;
    int f = 0, z = 0;
    for(int c: Cards){
        if(c == 5){
            f++;
        } else{
            z++;
        }
    }
    string ans = "";
    if(z == 0){
        cout<<-1<<"\n";
    }
    else{
        if(f/9 == 0){
            cout<<0<<"\n";
        } else{
            for(int i=0; i<9*(f/9); i++){
                ans += '5';
            }
            for(int i=0; i<z; i++){
                ans += '0';
            }
            cout<<ans<<"\n";

        }
    }
    return 0;
}