#include<iostream>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        int64_t l, r, a, b, c, rem,rem_, m;
        cin>>l>>r>>m;
        for(int i=l; i<=r; i++){
            rem = m%i;
            rem_ = i-rem;
            if(rem == 0){
                cout<<i<<" "<<i<<" "<<i<<"\n";
                break;
            }
            else if(min(rem, rem_)<=(r-l)){
                if(rem_<=(r-l)){
                    cout<<i<<" "<<l<<" "<<l + rem_<<"\n";
                    break;
                }
                else{
                    cout<<i<<" "<<r<<" "<<r-rem<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}