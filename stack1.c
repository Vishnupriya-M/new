//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:OPERATIONS ON A STACK

#include<stdio.h>
int stack[30];
int top;
void main(){
 int n,j=0;
 printf("\n MAIN MENU");
 do{
 printf("\n1:to create\n2:to insert\n 3:to delete\n4:to display the last added element\n5:display\n6:exit");
 printf("\nenter the option:");
 scanf("%d",&n); 
 switch(n){
 case 1:create();break;
 case 2:push();break;
 case 3:pop();break;
 case 4:peep();break;
 case 5:display();break;
 case 6:j=1;break;
 default:printf("\nwrong choice");
 }
}
while(j==0);
}
void display(){
 int i;
 for(i=0;i<=top;i++){
  printf("%d\n",stack[i]);
 }
}
void create(){
 int n,i;
 printf("enter the no of elements:");
 scanf("%d",&n);
 printf("enter the elements\n");
 for(i=0;i<n;i++){
  scanf("%d",&stack[i]);
 }
 top=n-1;
 for(i=0;i<n;i++){ 
  printf("%d\n",stack[i]);
 }
}

void push(){
 int i;
 if (top>29)
  printf("stack is full");
 else{
  top=top+1;
  printf("enter the element to be inserted:");
  scanf("%d",&stack[top]);
  for(i=0;i<=top;i++){
   printf("%d\n",stack[i]);
 } 
}
}
void pop(){
 int item;
 if(top<0)
  printf("deletion not possible/list is empty");
 else{
  item=stack[top];
  top=top-1;
  display();
 }
}
void peep(){
 printf("%d",stack[top]);
}

