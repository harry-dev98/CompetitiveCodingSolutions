#include<iostream>
using namespace std;

int main(){
    long long t, r, g, b, w;
    bool r_, g_, b_, w_;
    cin>>t;
    while(t--){
        cin>>r>>g>>b>>w;
        r_ = r%2;
        g_ = g%2;
        b_ = b%2;
        w_ = w%2;
        int ans = r_+g_+b_;
        if(ans == 0){
            cout<<"YES\n";
        }
        else if(ans == 1){
            if(w_ == 0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(ans == 2){
            if(r>0 && b>0 && g>0 && w_==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"YES\n";
        }
    }
}   