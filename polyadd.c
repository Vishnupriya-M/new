//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:POLYNOMIAL OPERATIONS
#include<stdio.h>
#include<stdlib.h>
struct node{
 int coeff;
 int exp;
 struct node *next;
}*c,*a,*b,*start,*cur,*d;
struct node *create()
{struct node *newnode=NULL,*cur=NULL,*start=NULL;
 int data,value,c;
 do
  {
  if(start==NULL)
   {
   start=(struct node*)malloc(sizeof(struct node));
   printf("Enter coefficient of first term\n");
   scanf("%d",&data);
   start->coeff=data;
   printf("Enter exponent of first term\n");
   scanf("%d",&value);
   start->exp=value;
   start->next=NULL;
   cur=start;
 }
   else{
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter coefficient\n");
  scanf("%d",&data);
  printf("Enter exponent\n");
  scanf("%d",&value);
  newnode->coeff=data;
  newnode->exp=value;
  newnode->next=NULL;
  cur->next=newnode;
  cur=newnode;
  }
  printf("Do you want to add more?\n1.yes\n2.no\n");
  scanf("%d",&c);
 }while(c==1);
 return start;
}
void display(start){
 struct node *cur=NULL;
 cur=start;
 while(cur->next!=NULL&&cur!=NULL){
  printf("%dx^%d+",cur->coeff,cur->exp);
  cur=cur->next;
 }
 if(cur!=NULL){
  printf("%dx^%d",cur->coeff,cur->exp);
  printf("\n");
 }
}
struct node *attach(int s,int e,struct node *k){
 struct node *n;
 n=(struct node*)malloc(sizeof(struct node));
 n->coeff=s;
 n->exp=e;
 n->next=NULL;
 k->next=NULL;
 return n;
} 
void polyadd(struct node*a,struct node*b){
 struct node*p,*q,*d,*c,*k;
 int x;
 p=a; 
 q=b;
 c=(struct node*)malloc(sizeof(struct node));
 d=c;
 while((p!=NULL)&&(q!=NULL)){
  if(p->exp==q->exp){
   x=(p->coeff)+(q->coeff);
     if(x!=0){
      d=attach(x,p->exp,d);
      q=q->next;
      p=p->next;
     }
  }
  else if((p->exp)< (q->exp)){
    d=attach(q->coeff,q->exp,d);
    q=q->next;
  }
  else{
   d=attach(p->coeff,p->exp,d);
   p=p->next;
  }
 }
while(p!=NULL){
  d=attach(p->coeff,p->exp,d);
  p=p->next;
 }
while(q!=NULL){
 d=attach(q->coeff,q->exp,d);
 q=q->next;
}
k=c;c=c->next;
return c;
}
void main(){
printf("enter the first polynomial:\n");
a=create();
display(a);
printf("enter the second polynomial:\n");
b=create();
display(b);
printf("resultant polynomial is\n");
polyadd(a,b);
display(c);
}
