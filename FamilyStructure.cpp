/*https://www.codingninjas.com/codestudio/problems/family-structure_981243?leftPanelTab=0*/

string solve(int n,long long int k){
    if(n==1 || k==1){
        return "Male";
    }
    long long temp=(k+1)/2;
    string ans=solve(n-1,temp);
    if(k==2*temp-1){
        return ans;
    }
    else{
        if(ans=="Female"){
            return "Male";
        }
        return "Female";
    }
}
string kthChildNthGeneration(int n, long long int k)
{
	// Write your code here	
   return solve(n,k);
}
