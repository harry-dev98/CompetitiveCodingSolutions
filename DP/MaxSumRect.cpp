#include<bits/stdc++.h>
using namespace std;

#define inf 1<<30

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int A[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>A[i][j];
            }
        }
        int ColSum[n];
        int mxL=0, mxR=0, mxUp=0, mxDwn=0,mxRectSum=-1000001;
        for(int left = 0; left<m; left++){
            memset(ColSum, 0, sizeof(ColSum));
            for(int right=left; right<m; right++){
                for(int rw=0; rw<n; rw++){
                    ColSum[rw] += A[rw][right];
                    // cout<<ColSum[rw]<<" ";
                }
                // cout<<endl;
                int up=0, dwn=0, mxx=-1000001, mxxYet=0;
                for(int ind=0; ind<n; ind++){
                    if(ColSum[ind]+mxxYet>ColSum[ind]){
                        dwn = ind;
                        mxxYet += ColSum[ind];
                    }
                    else{
                        mxxYet = ColSum[ind];
                        up = dwn = ind;
                    }
                    // cout<<mxx<<" "<<mxxYet<<endl;
                    mxx = max(mxx, mxxYet);
                }
                if(mxx>mxRectSum){
                    mxUp = up;
                    mxDwn = dwn;
                    mxL = left;
                    mxR = right;
                    mxRectSum = mxx;
                }

            }
        }
        cout<<mxRectSum<<"\n";
    }
}