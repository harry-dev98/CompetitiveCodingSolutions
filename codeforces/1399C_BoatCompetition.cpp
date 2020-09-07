#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        unordered_map<int, int>M;
        unordered_set<int>S, S_;
        for(int i=0; i<n; i++){
            M[A[i]]++;
            S.insert(A[i]);
        }
        int _, tmp, ans = 0;
        for(int i=1; i<=100; i++){
            tmp = 0;
            S_ = S;
            for(auto j:S){
                if(S_.find(j) == S_.end())continue;
                _ = (i - j);
                _ = _>0?_:0;
                auto itr = S_.find(_);
                if(itr != S_.end()){
                    if(j == _){
                        tmp += min(M[j], M[_])/2;
                    }
                    else{
                        tmp += min(M[j], M[_]);
                    }
                    S_.erase(j);
                    S_.erase(_);
                } 
            }
            ans = max(ans, tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}