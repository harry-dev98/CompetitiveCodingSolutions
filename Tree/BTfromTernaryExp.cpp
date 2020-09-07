#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char ch){
        data = ch;
        left=NULL;
        right=NULL;
    }
};

Node* _util(Node* root, string str, int &i){
    root = new Node(str[i++]);
    if(i == str.length()){
        return root;
    }
    if(str[i] == '?'){
        root->left = _util(root->left, str, ++i);
        root->right = _util(root->right, str, ++i);
    }
    else if(str[i]==':'){
        return root;
    }
    return root;
}

Node* convertExpression(string str, int i){
    Node* root = NULL;
    return _util(root, str, i);
}

void printT(Node* T){
    if(T==NULL){
        return;
    }
    cout<<T->data<<" ";
    printT(T->left);
    printT(T->right);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        Node* root=convertExpression(str, 0);
        printT(root);
        cout<<"\n";
    }
}