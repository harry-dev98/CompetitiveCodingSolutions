#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int l = str.length();
    bool ans = false;
    for(int i=0; i<l; i++){
        if(ans == true)break;
        if(str[i] == '0'){
            ans = true;
            cout<<"YES\n0\n";break;
        }
        if(str[i] == '8'){
            ans = true;
            cout<<"YES\n8\n";break;
        }
        for(int j=i+1; j<l; j++){
            if(ans == true)break;
            int i_ = str[i] - '0';
                int j_ = str[j] - '0';
                int _ = (i_*10+j_);
                if(_%8==0){
                    ans = true;
                    cout<<"YES\n"<<_<<"\n";break;
                }  
            for(int k=j+1; k<l; k++){
                int i_ = str[i] - '0';
                int j_ = str[j] - '0';
                int k_ = str[k] - '0';
                int _ = (i_*100+j_*10+k_);
                if(_%8==0){
                    ans = true;
                    cout<<"YES\n"<<_<<"\n";break;
                }   
            }
        }
    }
    if(!ans)cout<<"NO\n";
    return 0;
}