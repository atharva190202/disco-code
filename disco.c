#include <stdio.h>
void sort(int a[],int n){
    int i;
    int j;
    int t;
      for (i = 0; i < n; i++) {
        
        // iterates the array elements from index 1
        for (j = i + 1; j < n; j++) {
            
            // comparing the array elements, to set array
            // elements in descending order
            if (a[i] < a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main(int argc,char*argv[])
{
    //  printf("Hello World\n");
     //int input;
    // int in;
     FILE *fp;
     fp=fopen(argv[1],"r");
     printf("argv[0]%s\n",argv[0]);
     printf("argv[1]%s\n",argv[1]);
     printf("argv[2]%s\n",argv[2]);
     printf("argv[3]%s\n",argv[3]);
     
     if(fp==NULL){
        printf("file  not found");
     }
     //fscanf(fp,%d,);
    //  printf("The value of first element is");
    //  printf("%c\n",input);
    //   input=fgetc(fp);
    //   input=fgetc(fp);
    //   printf("The value of second element is");
    //  printf("%c\n",input);
    //   input=fgetc(fp);
    //   input=fgetc(fp);
    //   printf("The value of third element is");
    //  printf("%c\n",input);
     
     int nodes;
     fscanf(fp,"%d",&nodes);
    // printf("the no. of nodes present are");
    // printf("%d\n",nodes);
   

    int edges;
     fscanf(fp,"%d",&edges);
    //   printf("the no. of edges present are");
    // printf("%d\n",edges);
    // scanf("%d",&nodes);
    // scanf("%d",&edges);
    int arr[2*edges];
    for(int i=0;i<2*edges;i++){
       
        int ae;
        fscanf(fp,"%d",&ae);
        //scanf("%d",&ae);
        arr[i]=ae;
    }
    int mat[nodes][nodes];
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            mat[i][j]=0;
        }
    }
    for(int i=0;i<2*edges;i+=2){
       int a=arr[i];
       int b=arr[i+1];
       mat[a-1][b-1]++;
       mat[b-1][a-1]++;
    }
    int ans[nodes];
    for(int i=0;i<nodes;i++){
        int sum=0;
        for(int j=0;j<nodes;j++){
           sum+=mat[i][j];
        }
        ans[i]=sum;
    }
    for(int i=0;i<nodes;i++){
        printf("%d\n",ans[i]);
    }
    sort(ans,nodes);
    printf("the no. of nodes present are");
    printf("%d\n",nodes);
    for(int i=0;i<nodes;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}