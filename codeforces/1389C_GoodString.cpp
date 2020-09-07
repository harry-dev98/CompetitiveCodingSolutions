#include<iostream>
#include<vector>
using namespace std;

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int helper(const string& s, int i, int j){
    int tmp = 0;
    for(auto c:s){
        if(i == c-'0'){    
            ++tmp;
            swap(i, j);
        }
    }
    if(i!=j && tmp%2==1){
        tmp--;
    }
    return tmp;
}

int main(){
    speed;
    int t, n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                ans = max(helper(s, i, j), ans);
            }
        }  
        cout<<int(s.size()) - ans<<"\n";
    }
    return 0;
}