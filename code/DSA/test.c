#include <stdio.h>
#include <stdlib.h>

int main(){
    int *temp=(int*)malloc((12+1)*sizeof(int));
    printf("%d",temp[1]);
    
    return 0;
}