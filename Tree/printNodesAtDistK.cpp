// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void printkdistanceNodeDown(Node *root, int k);

int printkdistanceNode(Node* root, int target , int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        printkdistanceNode(head, target, k);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

int Target; 

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
unordered_set<int> M;
void printkdistanceNodeDown(Node *root, int k, vector<int> &A){
    if(root==NULL)return;
    if(M.find(root->data) != M.end())return;
    if(k == 0 && M.find(root->data) == M.end()){
        A.push_back(root->data);
        return;
    }
     printkdistanceNodeDown(root->left, k-1, A);
    printkdistanceNodeDown(root->right, k-1, A);
}

void _push(Node* root, stack<pair<int, Node*>> &S){
    while(root!=NULL){
        S.push({1,root});
        root = root->left;
    }
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
int printkdistanceNode(Node* root, int target , int k){
    Target = target;
    M.clear();
    vector<int> A;
    int ans=-1;
    stack<pair<int,Node*>> S;
    _push(root, S);
    Node* tmp;
    while(!S.empty()){
        if(S.top().first == 2)S.pop();
        else{
            tmp = S.top().second;
            if(tmp->data == target){
                ans = 1;
                while(!S.empty()){
                    if(k>0){
                        tmp = S.top().second;
                        printkdistanceNodeDown(tmp, k--, A);
                        M.insert(tmp->data);
                    }
                    else if(k==0){
                        A.push_back(S.top().second->data);
                        k--;
                    }
                    else{
                        k--;
                    }
                    S.pop();
                }
            }
            else{
                S.top().first++;
                _push(tmp->right, S);
            }
        }
    }
    sort(A.begin(), A.end());
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    return ans;
}