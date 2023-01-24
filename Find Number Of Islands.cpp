/*https://www.codingninjas.com/codestudio/problems/find-number-of-islands_630512?leftPanelTab=0*/


#include<bits/stdc++.h>
void bfs(int row,int col,int **arr, vector<vector<int>>&vis,int n,int m){
queue<pair<int,int>>q;
q.push({row,col});
vis[row][col]=1;
while(!q.empty()){
   int row=q.front().first;
   int col=q.front().second;
   q.pop();
   for(int delrow=-1;delrow<=1;delrow++){
      for(int delcol=-1;delcol<=1;delcol++){
         int nrow=row+delrow;
         int ncol=col+delcol;
         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
         arr[nrow][ncol]==1 && !vis[nrow][ncol]){
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
         }
      }
   }
}
}
int getTotalIslands(int** arr, int n, int m)
{
   int c=0;
   vector<vector<int>>vis(n,vector<int>(m));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(!vis[i][j] && arr[i][j]==1){
            c++;
            bfs(i,j,arr,vis,n,m);
         }
      }
   }
   return c;
}
