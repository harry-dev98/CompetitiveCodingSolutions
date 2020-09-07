#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
    cout<<root->data<<" ";
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	
	root=correctBST(root);

	inorder(temp,root);

	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0\n";
	}
	}
    return 0;
}// } Driver Code Ends


Node* getPredecessor(Node* root){
    int x = root->data;
    root = root->left;
    while(root->right != NULL && root->right->data != x){//cout<<"ok\n";
        root = root->right;
    }
    return root;
}


void visit(Node* root, Node* &pr, Node* &fi, Node* &se, Node* &th){
    if(pr == NULL){
        pr = root;
    }
    cout<<root->data<<" "<<pr->data<<", ";
    if(root->data<pr->data){
        if(fi == NULL){
            fi = pr;
            se = root;
            // cout<<"fi "<<fi->data<<endl;
        }
        else{
            th = root;
            // cout<<"th "<<th->data<<endl;
        }
    }
    pr = root;
}

struct Node *correctBST( struct Node* root){
    struct Node* fi=NULL;
    struct Node* se=NULL;
    struct Node* th=NULL;
    struct Node* pr = NULL;
    Node* r = root;
    while(root != NULL){//cout<<"asda\n";
        if(root->left != NULL){
            Node* pred = getPredecessor(root);
            if(pred->right == NULL){
                pred->right = root;
                root = root->left;
            }
            else{
                pred->right = NULL;
                visit(root, pr, fi, se, th);
                root = root->right;
            }
        }
        else{
            visit(root, pr, fi, se, th);
            root = root->right;
        }
    
    }
    int a = fi->data;
    fi->data = (th==NULL)? se->data: th->data;
    if(th == NULL){
        se->data = a;
    }
    else{
        th->data = a;
    }
    cout<<"swap "<<fi->data<<", "<<((th!=NULL)?th->data:se->data)<<endl;
    return r;
}
