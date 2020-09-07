#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int key = -1;
    node* ch[2];
}* PTR;

PTR getNode(){
    PTR tmp = new node;
    tmp->ch[0]=NULL;
    tmp->ch[1]=NULL;
    return tmp;
}

void insert(PTR root, int key){
    PTR temp = root;
    for(int i=32-1; i>=0; i--){
        bool setBit = (key & (1<<i));
        if(temp->ch[setBit] == NULL){
            temp->ch[setBit] = getNode();
        }
        temp = temp->ch[setBit];
    }
    temp->key = key;
    return;
}

void checkXOR(PTR root, int x, int &min_xored){
    for(int i=32-1; i>=0; i--){
        bool setBit = (x & (1<<i));
        if(root->ch[setBit] != NULL){
            root = root->ch[setBit];
        }
        else{
            root = root->ch[1-setBit];
        }
    }
    min_xored = min(min_xored, x ^ root->key);
    return;
}

int main(){
    int n;
    cin>>n; int A[n];
    PTR root = getNode();
    int min_xored=INT_LEAST32_MAX;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    insert(root, A[0]);
    for(int i=1; i<n; i++){
        // for min_xor pair we need to have minimum bit difference i.e.
        // min is for more similar binary expression
        checkXOR(root, A[i], min_xored);
        insert(root, A[i]);
    }
    cout<<min_xored<<"\n";
}