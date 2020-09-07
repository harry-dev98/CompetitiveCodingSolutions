#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n = s.size();
        priority_queue<int>pq;
        int ones = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                if(ones>0){
                    pq.push(ones);
                }
                ones = 0;
            }
        }
        if(ones>0)pq.push(ones);
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop(); 
            if(!pq.empty()){
                pq.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}