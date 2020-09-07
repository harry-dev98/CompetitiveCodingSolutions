#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef struct node{
    map<char, node*> data;
    bool isEOW=false;
}* ptr;

ptr insert(ptr t, string s, int i=0){
    auto itr = t->data.find(s[i]);
    
    if(itr == t->data.end()){
        t->data[s[i]] = new node;
    }
    if(i != s.length()){
        t->data[s[i]] = insert(t->data[s[i]], s, i+1);
    }
    else{
        t->isEOW = true;
    }
    return t;
}

bool search(ptr t, string s, int i=0){
    if(t->isEOW && i==s.length()){
        return true;
    }
    auto itr = t->data.find(s[i]);
    if(itr == t->data.end()){
        return false;
    }
    return search(t->data[s[i]], s, i+1);
}

int main(){
    SPEED;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        string s;
        ptr T = new node;
        for(int i=0; i<x; i++){
            cin>>s;
            T = insert(T, s);
        }
        cin>>s;
        cout<<(search(T, s)?1:0)<<"\n";
    }
    return 0;
}