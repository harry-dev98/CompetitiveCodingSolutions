#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define N 9

bool getCord(int A[N][N], int &i, int &j){
    for(int a=0; a<N; a++){
        for(int b=0; b<N; b++){
            if(A[a][b] == 0){
                i = a;
                j = b;
                return true;
            }
        }
    }
    return false;
}

bool solveSoduko(int A[N][N], unordered_set<int> M[], unordered_set<int> M_C[], unordered_set<int> M_R[]){
    int i, j;
    if(!getCord(A, i, j)){
        return true;
    }
    
    for(int k=1; k<10; k++){
        if(M[(i/3)*3 + j/3].find(k) == M[(i/3)*3 + j/3].end() 
                    && M_C[j].find(k) == M_C[j].end() 
                    && M_R[i].find(k) == M_R[i].end())
        {
            A[i][j] = k;
            M[(i/3)*3 + j/3].insert(k);
            M_C[j].insert(k);
            M_R[i].insert(k);
            if(solveSoduko(A, M, M_C, M_R)){
                return true;
            }
            else{
                A[i][j] = 0;
                M[(i/3)*3 + j/3].erase(k);
                M_C[j].erase(k);
                M_R[i].erase(k);
            }
        }
    }
    return false;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int A[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                cin>>A[i][j];
        }
        unordered_set<int> M_C[N], M_R[N], M[N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(A[i][j] != 0){
                    M_R[i].insert(A[i][j]);
                    M_C[j].insert(A[i][j]);
                    M[(i/3)*3+ j/3].insert(A[i][j]);
                }
            }
        }
        // for(int i=0; i<N; i++){
        //     cout<<i<<" -> ";
        //     for(auto itr=M_R[i].begin(); itr!=M_R[i].end(); itr++){
        //         cout<<*itr<<" ";
        //     }
        //     cout<<endl;
        // }
        solveSoduko(A, M, M_C, M_R);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                cout<<A[i][j]<<" ";
        }
    cout<<"\n";
    }
}
