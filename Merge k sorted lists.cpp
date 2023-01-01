/*https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/


/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<queue>
class compare{
    public:
    bool operator()(Node<int>*a,Node<int>*b){
        return (a->data>b->data);
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare>mini;
    int k=listArray.size();
if(k==0){
    return NULL;
}
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            mini.push(listArray[i]); 
        }
    }
    Node<int>*head=NULL;
    Node<int>*tail=NULL;
    while(mini.size()>0){
        Node<int>* temp=mini.top();
        mini.pop();
          if(temp->next!=NULL){
                mini.push(temp->next);
          }
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
             tail=temp;
        }
    }
    return head;
}
