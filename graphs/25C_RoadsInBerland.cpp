#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k, a, b, c;
    cin>>n;
    long long A[n][n];
    long long ans = 0;
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            cin>>A[i][j];
            if(i<j)
            ans+=A[i][j];
        }
    }
    cin>>k;
    for(long long i=0; i<k; i++){
        cin>>a>>b>>c; a--; b--;
        if(A[a][b] > c){
            ans += c - A[a][b];
            A[a][b] = c;
            A[b][a] = c;
            for(long long xx=0; xx<2; xx++){
                for(long long xy=0; xy<n; xy++){
                    for(long long xz=xy+1; xz<n; xz++){
                        if(A[xy][xz] > A[xy][a]+A[a][xz]){
                            ans -= A[xy][xz];
                            A[xy][xz] = A[xy][a] + A[a][xz];
                            A[xz][xy] = A[xy][xz];
                            ans += A[xy][xz];
                        }    
                    }
                }
                swap(a, b);
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}
