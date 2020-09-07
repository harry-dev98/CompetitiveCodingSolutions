#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef struct node{
    int key = -1;
    node* ch[2];
}* ptr;

ptr getNode(){
    ptr temp = new node;
    temp->ch[0] = NULL;
    temp->ch[1] = NULL;
    return temp;
}

void insertTrie(ptr root, int X){
    for(int i=31; i>=0; i--){
        bool currBit = (X & (1<<i));
        if(root->ch[currBit] == NULL){
            root->ch[currBit] = getNode();
        }
        root = root->ch[currBit];
    }
    root->key = X;
    return;
}

int minXOR(ptr root, int X){
    for(int i=31; i>=0; i--){
        bool curBit = (X & (i<<i));
        if(root->ch[curBit] != NULL){
            root = root->ch[curBit];
        }
        else{
            root = root->ch[1-curBit];
        }
    }
    return X^root->key;
}

int main(){
    SPEED;
    ptr root = getNode();
    insertTrie(root, 0);
    int X=0, q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        if(n==1){
            int x;
            cin>>x;
            insertTrie(root, X^x);
        }
        else if(n == 2){
            int x;
            cin>>x;
            X = X ^ x;
        }
        else{
            cout<<minXOR(root, X)<<"\n";
        }
    }
}