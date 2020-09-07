#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int G[51][51]={};
int A[51][51]={};
int row[] = {-1, 0, 1};
int N, M;

bool isValidPos(int x, int y){
    return (x>=0) && (y>=0) && (x<N) && (y<M);
}

int _islands(int n, int m){
    // cout<<n<<m;
    A[n][m]=true;
    int x, y, ans=1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            x = n + row[i]; y = m + row[j];
            if(isValidPos(x,y)){
                if(G[x][y]==1 && A[x][y]!=1){
                    ans += _islands(x, y);
                }
            }
        }
    }
    return ans;
}

int largestIsland(){
    int max = 0, tmp_mx=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!A[i][j] && G[i][j]){
                tmp_mx = _islands(i, j);
                if(tmp_mx > max){
                    max = tmp_mx;
                }
            }
        }
    }
    return max;
}

int main(){
    SPEED;
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>G[i][j];
            }
        }
        cout<<largestIsland()<<"\n";
        memset(A, 0, sizeof(A));
    }
}