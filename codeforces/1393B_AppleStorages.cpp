#include<iostream>
using namespace std;
const int MXN = 1e5+9;
int A[MXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pair2=0, pair4=0, n, _, q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>_;
        pair2 -= A[_]/2;
        pair4 -= A[_]/4;
        A[_]++;
        pair2 += A[_]/2;
        pair4 += A[_]/4;
    }
    cin>>q;
    char c;
    for(int i=0; i<q; i++){
        cin>>c>>_;
        pair2 -= A[_]/2;
        pair4 -= A[_]/4;
        if(c=='-')A[_]--;
        else A[_]++;
        pair2 += A[_]/2;
        pair4 += A[_]/4;
        if(pair2>=4 && pair4>=1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}