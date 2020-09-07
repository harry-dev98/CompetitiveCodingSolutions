#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
int partition(int in[], int x, int s, int e){
    for(int i=s; i<e; i++){
        if(in[i] == x){
            
            return i;
        }
    }
    return -1;
    
}  

Node *_build(int in[], int post[], int s, int e, int &rt){
    if(s+1 == e){
        rt--;
        return new Node(in[s]);
    }
    if(s >= e){
        return NULL;
    }
    int ind = partition(in, post[rt--], s, e);
    Node* root = new Node(in[ind]);
    root->right = _build(in, post, ind+1, e, rt);
    root->left = _build(in, post, s, ind, rt);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int rt = n-1;
    return _build(in, post, 0, n, rt);
}
