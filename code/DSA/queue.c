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
    
    return 0;
}