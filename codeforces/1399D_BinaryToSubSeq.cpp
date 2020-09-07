#include<iostream>
#include<stack>
using namespace std;

int main(){
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int seq=1, ans[n];
        stack<int> pos1, pos0;
        if(s[0] == '1'){
            pos1.push(seq);
        }
        else{
            pos0.push(seq);
        }
        ans[0] = seq;
        for(int i=1; i<n; i++){
            if(s[i] == '0'){
                if(pos1.empty()){
                    seq++;
                    pos0.push(seq);
                }
                else{
                    pos0.push(pos1.top());
                    pos1.pop();
                }
                ans[i] = pos0.top();
            }
            if(s[i] == '1'){
                if(pos0.empty()){
                    seq++;
                    pos1.push(seq);
                }
                else{
                    pos1.push(pos0.top());
                    pos0.pop();
                }
                ans[i] = pos1.top();
            }
        }
        cout<<pos1.size()+pos0.size()<<"\n";
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}