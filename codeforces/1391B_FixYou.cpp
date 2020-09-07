#include<iostream>
#include<unordered_set>
using namespace std;

#define pii pair<int, int>

char A[109][109];
bool Vis[109][109];
int P[10009];
int Sz[10009];
int Mx[10009];

int coordton(int i, int j, int m){
    return i*m + j;
}

void make_set(int a){
    P[a] = a;
    Sz[a] = 1;
    Mx[a] = a;
}

int find_set(int a){
    if(P[a] == a){
        return a;
    }
    P[a] = find_set(P[a]);
    return P[a];
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Sz[a] < Sz[b]){
            swap(a, b);
        }
        P[b] = a;
        Sz[a] += Sz[b];
        Mx[a] = max(Mx[a], b);
        return true;
    }
    return false;
}

void dfs(int i, int j, int n, int m){
    Vis[i][j] = 1;
    int lst = coordton(i, j, m);
    if(A[i][j] == 'D' && i != n-1){
        union_set(lst, coordton(i+1, j, m));
        if(Vis[i+1][j] == 0){
            dfs(i+1, j, n, m);
        }
    }
    else if(A[i][j] == 'R' && j != m-1){
        union_set(lst, coordton(i, j+1, m));
        if(Vis[i][j+1] == 0){
            dfs(i, j+1, n, m);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, x;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>A[i][j];    
            }
        }
        x = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                Vis[i][j] = 0;
                make_set(x++);      
            }
        }
        unordered_set<int>S;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(Vis[i][j] == 0){
                    dfs(i, j, n, m);
                }
            }
        }
        for(int i=0; i<m*n; i++){
            int _ = find_set(i);
            if(Mx[_] != -1 && Mx[_] != m*n-1){
                S.insert(Mx[_]);
            }
        }
        cout<<S.size()<<"\n";
    }
    return 0;
}