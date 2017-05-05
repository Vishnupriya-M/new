//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:PALINDROME
#include<stdio.h>
  struct node
  {
  int info;
  struct node*next;
  struct node*back;
  }*ptr,*start,*prev,*cur;
 void pal(){
 int i,j;
 int A[20],B[20]; 
 cur=start;
  while(cur->next!=NULL){
  printf("%d->",cur->info);
  cur=cur->next;
  }
  printf("%d->\n",cur->info);
  cur=start;
  i=0;
    while(cur->next!=NULL){
      A[i]=cur->info;
      i++;
      cur=cur->next; 
   }
   A[i]=cur->info;
  for(j=0;j<=i;j++){
   printf("%d",A[j]);
   printf(" ");
  }
 printf("\n");
 i=0;
 while(cur->back!=NULL){
      B[i]=cur->info;
      i++;
      cur=cur->back;
   }
  B[i]=cur->info;
  for(j=0;j<=i;j++){
  printf("%d",B[j]);
  printf(" ");
  }
  int k=0;
  while(k<=i){
    if(A[k]==B[k]){
      k++;
    }
   else
    break;
  }
 if(k==i+1){
     printf("\n entered series is palindrom\n");
    }
   else
     printf("\n entered series is not a palindrom\n");
  }



 void main(){
  int n;
  start=(struct node*)malloc(sizeof(struct node));
  printf("\n enter the data:");
  scanf("%d",&start->info);
  cur=start;
  start->back=NULL;
  do{
   ptr=(struct node*)malloc(sizeof(struct node));
     if(ptr==NULL){
       printf("insufficient space");
     }
     printf("enter the data:");
     scanf("%d",&ptr->info);
     cur->next=ptr;
     ptr->back=cur;
     cur=cur->next;
     printf("\ndo you want to add more?\n1:yes\n2:no\nenter the choice:");
     scanf("%d",&n);
  }
  while(n==1);
  pal();
 }
 
