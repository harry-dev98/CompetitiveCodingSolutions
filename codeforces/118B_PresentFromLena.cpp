#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n; 
    char pic[2*n+1][2*n+1];
    memset(pic, '-', sizeof(pic));
    int row = 0;
    int col;
    for(int i=0; i<=n; i++){
        col = 0;
        for(int j=0; j<n-i; j++){
            pic[row][col] = ' ';
            col++;
        }
        for(int k=0; k<=i; k++){
            pic[row][col] = '0' + k;
            col++;
        }
        for(int k=i-1; k>=0; k--){
            pic[row][col] = '0' + k;
            col++;
        }
        row++;
    }   
    for(int i=n-1; i>=0; i--){
        col = 0;
        for(int j=0; j<n-i; j++){
            pic[row][col] = ' ';
            col++;
        }
        for(int k=0; k<=i; k++){
            pic[row][col] = '0' + k;
            col++;
        }
        for(int k=i-1; k>=0; k--){
            pic[row][col] = '0' + k;
            col++;
        }
        row++;
    }

    for(int i=0; i<2*n+1; i++){
        for(int j=0; j<2*n+1; j++){
            if(pic[i][j] == '-')break;
            cout<<pic[i][j];
            if(j != 2*n){
                if(pic[i][j+1] != '-')cout<<" ";
            } 
        }
        cout<<"\n";   
    }
    return 0;
}