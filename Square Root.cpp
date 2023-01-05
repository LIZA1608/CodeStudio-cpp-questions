
/*https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0*/


#include <bits/stdc++.h> 

 int sqrtN(long long int N)
{
    if(N<2){
        return N;
    }
    long long int s=0;
   long long  int e=N;
   long long  int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s<=e){
     
        if(mid==(N/mid)){
            return mid;
        }
        if(mid<(N/mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
