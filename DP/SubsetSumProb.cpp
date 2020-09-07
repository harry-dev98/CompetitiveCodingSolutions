    #include<bits/stdc++.h>
    using namespace std;

    int DP[1005][1005];
    int SubsetSumTopDown(int A[], int n, int S){
        for(int i=0; i<=n; i++){
            DP[i][0] = true;
        }
        for(int i=1; i<=S; i++){
            DP[0][S] = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=S; j++){
                if(j >= A[i-1])
                    DP[i][j] = DP[i-1][j] || DP[i-1][j-A[i-1]];
                else
                    DP[i][j] = DP[i-1][j];
            }
        }
        return DP[n][S];
    }

    int main(){
        int t;
        cin>>t;
        while(t--){
            int n,S=0;cin>>n;
            int A[n];
            for(int i=0; i<n; i++){
                cin>>A[i];
                S+=A[i];
            }
            if(S%2 == 0){
                cout<<(SubsetSumTopDown(A, n, S/2)?"YES":"NO");
                cout<<"\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }