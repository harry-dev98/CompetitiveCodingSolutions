#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int p;
        map<int,int> M;
        for(int i=1; i<=k; i++){
            cin>>p;
            if(p!=-1){
                M[i] = p;
            }
        }
        int m = M.size();
        int DP[m+1][k+1];
        for(int i=0; i<=k; i++){
            DP[0][i] = 0;
        }
        for(int i=0; i<=m; i++){
            DP[i][0] = 0;
        }
        int i=1, kg, tmp;
        
        for(auto itr:M){
            kg = itr.first;
            p = itr.second;
            for(int j=1; j<=k; j++){
                if(i==1){
                    if(j>=kg){
                        DP[i][j] = (DP[i][j-kg]>=0)?DP[i][j-kg]+p:DP[i][j-kg];
                    }
                    else{
                        DP[i][j] = -1;
                    }
                }
                else{
                    if(j>=kg){
                        DP[i][j] = (DP[i][j-kg]==-1)?-1:min(DP[i][j-kg]+p, (DP[i-1][j]!=-1)?DP[i-1][j]:INT_MAX);
                    }
                    else{
                        DP[i][j] = DP[i-1][j];
                    }
                }
                
            }
            i++;
        }

        cout<<DP[m][k]<<"\n";
    }
    return 0;
}