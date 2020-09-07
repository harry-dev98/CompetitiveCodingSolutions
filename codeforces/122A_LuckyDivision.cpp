#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool ans=false;
    unordered_set<int>S = {4,7};
    for(int j=2; j<=n; j++){
        bool isL = true;
        int i = j;
        while(i){
            int x = i%10;
            if(S.find(x) == S.end()){
                isL = false;
                break;
            }
            i/=10;
        }
        if(isL){
            if(n%j==0){
                ans=true;
                break;
            }
        }
    }
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}