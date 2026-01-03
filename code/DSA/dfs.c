#include <stdio.h>
#include <stdlib.h>
//they are written upper then main function to make them global varible
int node;
int i=6;//i mean index
int visited[7]={0,0,0,0,0,0,0};//this are the index or nodes
int a[7][7]={
{0,1,1,1,0,0,0},//this is for 1 visited node or index 
{1,0,0,1,0,0,0},// second go on up to last index 
{1,0,0,1,1,0,0},// visited row is columns for 2d matrix.
{1,1,1,0,1,0,0},//it  show that which visited node or index are join with other nodes.
{0,0,1,1,0,1,1},
{0,0,0,0,1,0,0},
{0,0,0,0,1,0,0}//this is a last node or index because we only visited 7 node.
};
void dfs(int i){
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<7;j++){
         if(a[i][j]==1 && !visited[j]){
            dfs(j);
         }
    }
}
int main(){
   
   dfs(3);
   
   
    return 0;
}