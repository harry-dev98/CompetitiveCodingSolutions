#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans="";
        stack<char>S;
        int x = 0; 
        int maxTill = 1;
        while(x<=s.length()){
            if(S.empty())S.push(s[x++]);
            else{
                if((S.top() == 'D' && s[x] == 'I')||(x>=s.length())){
                    int sze = S.size();
                    maxTill += sze;
                    if(S.top() == 'I'){
                        if(ans=="")ans+='1';
                        for(int i=maxTill-sze+1; i<=maxTill; i++){
                            ans += i + '0';
                        }
                        
                    }
                    else{
                        int temp=0;
                        while(S.top() == 'D'){
                            temp++;
                            S.pop();
                            if(S.empty())break;
                        }
                        if(ans=="")ans+='1';
                        for(int i=maxTill-sze+1; i<=maxTill-temp; i++){
                            ans += i + '0';
                        }
                        for(int i=maxTill; i>maxTill-temp; i--){
                            ans += i + '0';
                        }
                        if(temp>0){
                            ans = ans.substr(0, maxTill-temp-1)+ans.substr(maxTill-temp, ans.length())+ans[maxTill-temp-1];
                        }
                    }
                    while(!S.empty())S.pop();

                }
                else{
                    S.push(s[x++]);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}