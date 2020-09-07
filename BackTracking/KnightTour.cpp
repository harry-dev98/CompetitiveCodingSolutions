#include<bits/stdc++.h>
using namespace std;

#define N 6
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int isSafe(int x, int y, int sol[N][N]) { 
    return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1); 
} 

bool _util(int x, int y, int move, int X[], int Y[], int sol[N][N]){
    int new_x, new_y;
    if(move == N*N){
        return true;
    }
    for(int i=0; i<8; i++){
        new_x = x + X[i];
        new_y = y + Y[i];
        if(isSafe(new_x, new_y, sol)){
            sol[new_x][new_y] = move;
            if(_util(new_x, new_y, move+1, X, Y, sol)==true){
                return true;
            }
            else{
                sol[new_x][new_y] = -1;
            }
        }
    }
    return false;
}

void printAns(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

void knightTour(){
    int sol[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sol[i][j] = -1;
    int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
    sol[0][0] = 0;
    if(_util(0, 0, 1, x, y, sol)==false){
        cout<<"Not Possible\n";
    }
    else{
        printAns(sol);
    }
}

int main(){
    knightTour();
    return 0;
}