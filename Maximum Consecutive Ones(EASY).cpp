/*https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_3843993?leftPanelTab=0*/

import java.util.* ;
import java.io.*; 
public class Solution {
	public static int consecutiveOnes(int n, int[] arr) {
		// Write your code here.
		int c=0,maxi=0;
		for(int i=0;i<n;i++){
			if(arr[i]!=0){
				c++;
				maxi=Math.max(maxi,c);
			}
			else{
				c=0;
			}
		}
		return maxi;
	}
}
