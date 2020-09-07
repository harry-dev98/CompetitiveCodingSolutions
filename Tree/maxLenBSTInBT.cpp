#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



int largestBst(Node *root);

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



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends

#define ppp pair<pair<int,int>, pair<int,int>>
#define fi first
#define se second

/*You are required to complete this method */
ppp _largestBst(Node *root){
	if(root==NULL){
	    return {{1, 0},{0,0}};
	}
    int d = root->data;
	ppp lst={{1,0},{d,d}}, rst={{1,0},{d,d}}; bool isBST = true;
	if(root->left != NULL){
	    lst = _largestBst(root->left);
	    isBST = isBST && (lst.se.se<root->data) && lst.fi.fi == 1;
	}
	if(root->right != NULL){
	    rst = _largestBst(root->right);
	    isBST = isBST && (rst.se.fi>root->data) && rst.fi.fi == 1;
	}
    int ans;
    if(isBST){
        ans = lst.fi.se + rst.fi.se + 1;
        
    }
    else{
        ans = max(lst.fi.se, rst.fi.se);
    }
    cout<<isBST<<" "<<lst.fi.se<<" "<<rst.fi.se<<" "<<ans<<" "<<root->data<<endl;
    
	return {{isBST,ans},{lst.se.fi, rst.se.se}};
}

int largestBst(Node *root){
    return _largestBst(root).fi.se;
}