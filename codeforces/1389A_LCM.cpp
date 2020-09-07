#include<iostream>
using namespace std;

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    speed;
    long long t, l, r, x, y;
    cin>>t;
    while(t--){
        cin>>l>>r;
        x = l; y = r;
        while(y) {
            x %= y;
            swap(x, y);
        }
        long long hcf = x;
        long long lcm = (l * r)/hcf;
        
        if(l == 1 || r == 1 || r%l == 0 || lcm <= r){
            cout<<l<<" "<<r;
        }
        else if(2*l < r){
            cout<<l<<" "<<2*l;
        }
        else{
            cout<<-1<<" "<<-1;
        }
    cout<<"\n";
    }
    return 0;
}