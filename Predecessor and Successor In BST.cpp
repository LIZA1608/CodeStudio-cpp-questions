/*https://www.codingninjas.com/codestudio/problems/predecessor-and-successor_920476?leftPanelTab=0*/

int findpred(binaryTreeNode* root,int key){
   int pred=-1;
    while(root!=NULL){
        if(root->data>=key){
            root=root->left;
        }
        else{
            pred=root->data;
            root=root->right;  
        }
}
      return pred;
}
    int findsuc(binaryTreeNode* root,int key){
    int succ=-1;
    while(root!=NULL){
        if(root->data<=key){
            root=root->right;
        }
        else{
            succ=root->data;
            root=root->left;  
        }
    }
         return succ;
    }
vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	vector<int> ans;
      int a=findpred(root,key);
    ans.push_back(a);
    int b=findsuc(root,key);
    ans.push_back(b);
    return ans;
}
