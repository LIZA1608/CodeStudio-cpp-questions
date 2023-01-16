/*https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
   for(int i=0;i<arr[0].length();i++){
       char ch=arr[0][i];
       
       bool match=true;
       for(int j=1;j<n;j++){
           if(arr[j].size()<i||ch!=arr[j][i]){
               match=false;
               break;
           }
       }
       if(match==false){
           break;
       }
       else{
           ans.push_back(ch);
       }
   }
    return ans;
}


