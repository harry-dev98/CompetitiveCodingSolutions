#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        int _ = 0, __ = y - x;
        for(int i=1; i<n; i++){
            if((y-x)%i == 0){
                _ = i;
                __ = (y-x)/i;
            }
        }
        int left = n - _ - 1;
        if(x/__ >= left){
            for(int i=0; i<=left; i++){
                cout<<x-i*__<<" ";
            }
            for(int i=1; i<=_; i++){
                cout<<x+i*__<<" ";
            }
        }
        else{
            int befX = (x-1)/__;
            for(int i=0; i<=befX; i++){
                cout<<x - i*__<<" ";
            }
            for(int i=1; i<=_; i++){
                cout<<x + i*__<<" ";
            }
            for(int i=1; i<=left-befX; i++){
                cout<<y+ i*__<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}