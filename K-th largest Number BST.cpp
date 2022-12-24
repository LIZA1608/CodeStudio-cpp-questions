/*https://www.codingninjas.com/codestudio/problems/k-th-largest-number_920438?leftPanelTab=0*/

int solve(TreeNode<int>* root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int right=solve(root->right,i,k);
    if(right!=-1){
        return right;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->left,i,k);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}
