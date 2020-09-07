#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long int a, b, c;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        a = b = c = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a') a += a + 1;
            else if(s[i] == 'b') b += a + b;
            else c += c + b;
        }
        cout<<c<<"\n";
    }
    return 0;
}