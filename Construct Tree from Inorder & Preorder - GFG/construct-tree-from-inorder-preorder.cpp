// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int> mp;
    Node* f(int &cur,int s,int e,int pre[],int in[]){
        
        if(s>e){
            cur--;
            return NULL;   
        }
            
        Node* node = new Node(pre[cur]);
        
        int pos = mp[pre[cur]];
        
        cur++;
        node->left = f(cur,s,pos-1,pre,in);
        cur++;
        node->right = f(cur,pos+1,e,pre,in);
        
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int cur=0;
        mp.clear();
        for(int i=0; i<n; i++){
            mp[in[i]] = i;
        }
        return f(cur,0,n-1,pre,in);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends