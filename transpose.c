//NAME:VISHNUPRIYA.M
//AIM: WRITE A PROGRAM TO FIND TRANSPOSE OF A MATRIX
#include<stdio.h>
void spars(int A[20][20],int T[20][3],int r,int c){
  int i,j,k=1,t=0;
  T[0][0]=r,T[0][1]=c;
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      if(A[i][j]!=0){
       T[k][0]=i;
       T[k][1]=j;
       T[k][2]=A[i][j];
       k++,t++;
      }
    }
  }
 T[0][2]=t;
 printf("the array representation is given below\n");
 for(i=0;i<t+1;i++){
  for(j=0;j<3;j++){
   printf("%d\t",T[i][j]);
  }
 printf("\n");
 }
}
void trans(int T[20][3]){
 int i,j,k=1,Tp[20][3];
 Tp[0][0]=T[0][1];
 Tp[0][1]=T[0][0];
 Tp[0][2]=T[0][2];
 for(i=0;i<T[0][1];i++){
  for(j=1;j<=T[0][2];j++){
   if(T[j][1]==i){
    Tp[k][0]=T[j][1];
    Tp[k][1]=T[j][0];
    Tp[k][2]=T[j][2];
    k++;
   }  
  }
 }
 printf("the transpose is given below\n");
 for(i=0;i<=Tp[0][2];i++){
  for(j=0;j<3;j++){
  printf("%d\t",Tp[i][j]);
  }
  printf("\n");
 }
}
void main(){
int i,j,r, c,A[20][20],T[20][3];
printf("enter the no. of rows:");
scanf("%d",&r);
printf("enter the no.of clums:");
scanf("%d",&c);
printf("enter the elements \n");
 for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    scanf("%d",&A[i][j]);
   }
 }
spars(A,T,r,c);
trans(T);
} 
