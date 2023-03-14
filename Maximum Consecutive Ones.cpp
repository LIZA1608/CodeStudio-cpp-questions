/*https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_892994?leftPanelTab=0*/

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i,j=0;
    for(i=0;i<n;i++){
        if(arr[i]==0){
            k--;
        }
        if(k<0 && arr[j++]==0){
            k++;
        }
    }
    return i-j;
}
