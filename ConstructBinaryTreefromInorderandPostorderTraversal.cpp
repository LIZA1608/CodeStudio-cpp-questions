/*https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106?leftPanelTab=0*/

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
int findpos(vector<int>in,int ele,int n){
    for(int i=0;i<n;i++){
        if(in[i]==ele){
            return i;
        }
    }
    return -1;
}
TreeNode<int>*solve(vector<int>post,vector<int>in,int &idx,int inorderstart,int inorderend,int n){
    if(inorderend<0 || inorderstart>inorderend){
        return NULL;
    }
    int curr=post[idx];
    idx--;
    TreeNode<int>*root=new TreeNode<int>(curr);
    int pos=findpos(in,curr,n);
    root->right=solve(post,in,idx,pos+1,inorderend,n);
    root->left=solve(post,in,idx,inorderstart,pos-1,n);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int idx=inOrder.size()-1; TreeNode<int>*ans=solve(postOrder,inOrder,idx,0,inOrder.size()-1,inOrder.size());
    return ans;
}
