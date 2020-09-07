#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

char A[51][51];
int vis[51][51];
int X[] = {1, 1, 1, 0, 0, -1, -1, -1};
int Y[] = {0, 1, -1, 1, -1, 0, 1, -1};

bool valid(int i, int j, int n, int m, char ch){
    return (0<=i && i<n && 0<=j && j<m && vis[i][j]==0 && ch+1 == A[i][j]);
}

int DFS(int cv_x, int cv_y, int vis[51][51], int n, int m){
    vis[cv_x][cv_y] = 1;
    int local_mxx = 0;
    for(int i=0; i<8; i++){
        if(valid(cv_x+X[i], cv_y+Y[i], n, m, A[cv_x][cv_y])){
            local_mxx = max(local_mxx, DFS(cv_x+X[i], cv_y+Y[i], vis, n, m));
        }
    } 
    return 1+local_mxx;   
}

int main(){
    SPEED;
    int case_ = 0;
    while(true){
        case_++;
        int n, m;
        cin>>n>>m;
        if(n==0 || m==0){
            break;
        }
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>A[i][j];
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i][j] == 'A'){
                    mx = max(DFS(i, j, vis, n, m), mx);
                }
            }
        }
        cout<<"Case "<<case_<<": "<<mx<<"\n";

    }
    return 0;
}