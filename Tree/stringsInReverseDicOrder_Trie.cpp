#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct node{
    bool EOW = false;
    string prefix="";
    node* ch[26]; 
};
typedef node* ptr;

ptr getNode(){
    ptr tmp = new node;
    for(int i=0; i<26; i++)tmp->ch[i] = NULL;
    return tmp;
}

void insert(ptr root, string s){
    for(int i=0; i<s.length(); i++){
        if(root->ch[s[i]-'a']==NULL){
            if(root->EOW){
                root->prefix = s.substr(0, i);
            }
            root->ch[s[i]-'a'] = getNode();
        }
        root = root->ch[s[i]-'a'];
    }
    root->EOW = true;
}

void print(ptr root){
    if(root->EOW){
        if(root->prefix == ""){
            cout<<"\n";
            return;
        }
        else{
            cout<<endl<<root->prefix;
        }
    }
    for(int i=25; i>=0; i--){
        if(root->ch[i] != NULL){
            char c = 'a' + i;
            cout<<c;
            print(root->ch[i]);
        }
    }
}

int main(){
    int n;
    ptr root = getNode();
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        insert(root, s);
    }
    print(root);
    return 0;
}