#include<bits/stdc++.h>
using namespace std;

/*
    match Str1 to Str2 with least edits like delete replace insert
    1.Subprob : Str1[i:], Str2[j:] i.e. N*M
    2.Guess : we can guess to delete Str1[i] or insert Str2[j] at i in Str1
    or we can replace Str1[i] with Str2[j]
    3.Recurrence : cost for all is unity..else if Str1[i] == Str2[j] then cost
    is 0
    so DP[i,j]=min(1+min(DP[i-1,j], DP[i,j-1]), DP[i-1,j-1] +1 
    if Str[i]!=Str2[j] else +0)
    Here DP is 2d matrix and store the index to suffix of strings
    where i n j correspondes to Str1 and Str2 suffixes...
    4.Topological order : States aka the subprobs must be solved in bottom up
    hence starting from empty string.. here we just need two rows at any
    time.(Requires linear space)
    5.Actual Sol : DP[0,0]
*/

int editDistance(string x, string y){
    int lenx=x.length(), leny=y.length();
    int DP[lenx+1][leny+1]={0};

    for(int i=lenx; i>=0; i--){
        for(int j=leny; j>=0; j--){
            if(i==lenx){
                DP[i][j]=leny-j;
            }
            else if(j==leny){
                DP[i][j]=lenx-i;
            }
            else{
                if(x[i] == y[j]){
                    DP[i][j] = min(min(1+DP[i][j+1], 1+DP[i+1][j]), DP[i+1][j+1]);
                }
                else{
                    DP[i][j] = 1 + min(min(DP[i][j+1], DP[i+1][j]), DP[i+1][j+1]);
                }
                
            }
        }
    }
    for(int i=0; i<lenx; i++){
        for(int j=0; j<leny; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<"\n";
    }
    return DP[0][0];
}

int longestCommonSubSeq(string x, string y){
    int lenx=x.length(), leny=y.length();
    int DP[lenx+1][leny+1]={0};

    for(int i=lenx; i>=0; i--){
        for(int j=leny; j>=0; j--){
            if(i==lenx){
                DP[i][j]=0;
            }
            else if(j==leny){
                DP[i][j]=0;
            }
            else{
                if(x[i] == y[j]){
                    DP[i][j] = 1 + DP[i+1][j+1];
                }
                else{
                    DP[i][j] = max(max(DP[i][j+1], DP[i+1][j]), DP[i+1][j+1]);
                }
                
            }
        }
    }
    for(int i=0; i<lenx; i++){
        for(int j=0; j<leny; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<"\n";
    }
    return DP[0][0];
}


int main(){
    string x="ROSE", y="HORSE";
    cout<<editDistance(x, y)<<endl;
    cout<<longestCommonSubSeq(x, y)<<endl;
}