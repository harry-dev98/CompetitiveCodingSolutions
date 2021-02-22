#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> A(n);
        for(int& a: A)cin>>a;
        map<int, int> Cnt;
        for(int a: A){
            Cnt[a]++;
        }
        vector<int> _Cnt, pref;
        for(auto _: Cnt){
            _Cnt.push_back(_.second);
        }
        sort(_Cnt.begin(), _Cnt.end());
        int s = 0;
        for(int _: _Cnt){
            s+=_;
            pref.push_back(s);
        }
        int ans = INT_MAX, sz=_Cnt.size();
        for(int i=0; i<sz; i++){
            ans = min(ans, pref[sz-1] -((sz-i)* _Cnt[i]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}