//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// } Driver Code Ends
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    
    // Return the root of the generated BST
    vector<int>ans;
    void fit(Node*root,int x)
    {
        if(!root)
        {
            Node*temp = new Node(x);
            root= temp;
            return;
            
        }
        
        if(root->data > x)
        {
            if(!(root->left))
            {
                root->left = new Node(x);
                return;
            }
            else
            fit(root->left,x);
        }
        else
        {
            if(!(root->right))
            {
                root->right = new Node(x);
                return;
            }
            else
            fit(root->right,x);
        }
    }
    Node *formbst(vector<int>&ans)
    {
        Node*head = new Node(ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            fit(head,ans[i]);
        }
        return head;
    }
    void help(Node*root)
    {
        if(!root)
        return ; 
        ans.push_back(root->data);
        help(root->left);
        help(root->right);
    }
    Node *binaryTreeToBST (Node *root)
    {
        
        help(root);
        Node*head = formbst(ans);
       
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends