#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct Node{
    Node* ch[26];
    bool EOW = false;
};
typedef struct Node* PTR;

int search(PTR root, string s, int i=0){
    if(root->EOW && i==s.length()){
        return 1;
    }
    if(i>=s.length()){
        return 0;
    }
    int ind = s[i]-'a';
    if(root->ch[ind]==NULL){
        return 0;
    }
    return search(root->ch[ind], s, i+1);
    
}

PTR getNode(){
    PTR node = new Node;
    for(int i=0; i<26; i++)node->ch[i]=NULL;
    return node;
}

int main(){
    SPEED;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        string S[x];
        for(int i=0; i<x; i++)cin>>S[i];
        PTR root = getNode();
        for(int i=0; i<x; i++){
            PTR temp = root;
            int l = S[i].length();
            for(int j=0; j<l; j++){
                int ind = S[i][j] - 'a';
                // cout<<"adding "<<S[i][j]<<endl;
                if(temp->ch[ind] == NULL){
                    // cout<<"new node\n";
                    temp->ch[ind] = getNode();
                }
                temp = temp->ch[ind]; 
            }
            // cout<<"setting EOW for "<<S[i]<<endl;
            temp->EOW = true;
        }
        string s;cin>>s;
        cout<<search(root, s)<<endl;
        
    }
    return 0;
}