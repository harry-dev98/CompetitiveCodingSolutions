#include<iostream>
#include<vector>
using namespace std;
#define pii pair<int, int>

int main(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    int A[n+1][m+1];
    vector<pii>Ans;
    int temp = y;
    while(temp<=m){
        Ans.push_back({x, temp});
        temp++;
    }
    temp = y-1;
    while(temp>0){
        Ans.push_back({x, temp});
        temp--;
    }
    temp = x+1;
    int f = 1;
    while(temp<=n){
        if(f==1){
            for(int i=1; i<=m; i++){
                Ans.push_back({temp, i});
            }
        }
        else{
            for(int i=m; i>0; i--){
                Ans.push_back({temp, i});
            }
        }
        temp++;
        f = 1-f;
    }
    temp = x-1;
    while(temp>0){
        if(f==1){
            for(int i=1; i<=m; i++){
                Ans.push_back({temp, i});
            }
        }
        else{
            for(int i=m; i>0; i--){
                Ans.push_back({temp, i});
            }
        }
        temp--;
        f = 1-f;
    }
    for(auto p:Ans){
        cout<<p.first<<" "<<p.second<<"\n";
    } 
    return 0;
}