
/*https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
   priority_queue<node*,vector<node*>,compare>mini;
    for(int i=0;i<k;i++){
    node *temp=new node(kArrays[i][0],i,0);  
        mini.push(temp);
    }
    vector<int>ans;
    while(mini.size()>0){
        node *temp=mini.top();
        ans.push_back(temp->data);
        mini.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<kArrays[i].size()){
            node* next=new node(kArrays[i][j+1],i,j+1);
            mini.push(next);
        }
    }
    return ans;
}
