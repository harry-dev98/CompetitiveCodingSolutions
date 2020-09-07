#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int p, c;

typedef struct node {
    int data=-1;
    node* lc=NULL;
    node* rc=NULL;
}* PTR;

int _height(PTR t){
    if(t==NULL){
        return 0;
    }
    return 1 + max(_height(t->lc), _height(t->rc));
}

int getHeight(PTR t){
    if(t==NULL){
        return 0;
    }
    return _height(t->rc)-_height(t->lc);
}

PTR rightRot(PTR t){ 
    PTR temp = t->lc;
    t->lc = temp->rc;
    temp->rc = t;  
    return temp;
}

PTR leftRot(PTR t){
    PTR temp = t->rc;
    t->rc = temp->lc;
    temp->lc = t; 
    return temp;
}

PTR rightLeftRot(PTR t){
    PTR temp = t->rc;
    t->rc = temp->lc;
    temp->lc = t->rc->rc;
    t->rc->rc = temp;
    t = leftRot(t);
    return t;
}

PTR leftRightRot(PTR t){
    PTR temp = t->lc;
    t->lc = temp->rc;
    temp->rc = t->lc->lc;
    t->lc->lc = temp;
    t = rightRot(t);
    return t;
}

PTR insertAVL(PTR t, int k){
    if(t==NULL){
        PTR temp = new node;
        temp->data = k;
        p = 0;
        c = 0;
        return temp;
    }
    if(t->data>k){
        t->lc = insertAVL(t->lc, k);
    }
    else if(t->data<k){
        t->rc = insertAVL(t->rc, k);
    }
    else{
        p=0;c=0;
        return t;
    }
    p = getHeight(t);
        cout<<p<<c<<t->data<<"\n";
    if(abs(p)>1){
        if(p*c>=0){
            if(p<0){
                t = rightRot(t);
            }
            else{
                t = leftRot(t);
            }
        }
        else{
            if(p<0){
                t = leftRightRot(t);
            }
            else{
                t = rightLeftRot(t);
            }
        }
    }
    c = p;
    return t;
}

void inorder(PTR t){
    if(t==NULL){
        return;
    }
    cout<<t->data<<" ";
    inorder(t->lc);
    inorder(t->rc);
}

int main(){
    PTR T = NULL;
    int t, k;
    cin>>t;
    while(t--){
        cin>>k;
        T = insertAVL(T, k);
        inorder(T);
        cout<<"\n";
    }
}