#include <stdio.h>
#include <stdlib.h>
struct  queue
{
   int size;
   int f ;
   int r ;
   int * arr;
};
int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }else {
        return 0;
    }
}
int isfull(struct queue *q){
    if(q->r==q->size-1|| q->r+1==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q ,int val){
    if(isfull(q)){
        printf("queue is full !");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a;
    if(isempty(q)){
        printf("Queue is empty !\n");
        return 0;

    }else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=20;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
     
    int node;
    int i=6;
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
    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isempty(&q)){
        int node=dequeue(&q);
        for (int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}