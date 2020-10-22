#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>Size(n);
        for(int& b:Size)cin>>b;
        int mxSz = 0;
        int ansInd = -1;
        for(int itr=0; itr<n-1; itr++){
            if(Size[itr] > Size[itr+1]){
                if(mxSz < Size[itr]){
                    mxSz = Size[itr];
                    ansInd = itr;
                }
            } 
        }
        int mxSz2 = 0;
        int ansInd2 = -1;
        for(int itr=n-1; itr>0; itr--){
            if(Size[itr] > Size[itr-1]){
                if(mxSz2 < Size[itr]){
                    mxSz2 = Size[itr];
                    ansInd2 = itr;
                }
            } 
        }
        if(ansInd2 == -1 && ansInd == -1){
            cout<<-1<<"\n";
        } else if(ansInd == -1){
            cout<<ansInd2+1<<"\n";
        } else if(ansInd2 == -1){
            cout<<ansInd+1<<"\n";
        } else {
            if(mxSz > mxSz2)cout<<ansInd+1<<"\n";
            else cout<<ansInd2+1<<"\n";
        }
    }
    return 0;
}
