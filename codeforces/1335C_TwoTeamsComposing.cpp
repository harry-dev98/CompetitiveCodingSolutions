#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> Skills(n);
        for(int& _: Skills)cin>>_;
        map<int, int> MappedSkills;
        for(int _: Skills){
            MappedSkills[_]++;
        }
        int mx = 0;
        for(auto _: MappedSkills){
            mx = max(mx, _.second);
        }
        cout<<max(min((int)MappedSkills.size(), mx-1), min((int)(MappedSkills.size()-1), mx))<<"\n";
    }
    return 0;
}