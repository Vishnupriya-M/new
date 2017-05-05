//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:MULTIPLICATION OF POLYNOMIALS
#include<stdio.h>
#include<stdlib.h>
struct node{
 int coeff;
 int exp;
 struct node *next;
}*c,*a,*b,*start,*cur,*d,*result,*tail,*ap,*bp,*temp,*term;
struct node*make_term(int co,int ex){
 term=(struct node*)malloc(sizeof(struct node));
 term->exp=ex;
 term->coeff=co;
 term->next=NULL;
 return term;
}
struct node*insert_term(int co,int ex,struct node*tail){
 temp=make_term(co,ex);
 temp->next=tail->next;
 tail->next=temp;
 return temp;
}
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
void polymult(struct node*a,struct node*b){
 int texp,tcoeff;
 result=tail=make_term(0,60);
 for(ap=a;ap!=NULL;ap=ap->next)
  for(bp=b;bp!=NULL;bp=bp->next){
   tail=result;
   tcoeff=ap->coeff*bp->coeff;
   texp=ap->exp+bp->exp;
   while(tail->next!=NULL&&tail->exp>texp){
    if((tail->next)->exp>=texp)
      tail=tail->next;
    else
      break;
   }
 if(tail->exp==texp)
   tail->coeff=tail->coeff+tcoeff;
 else if(tail->exp>texp)
   tail=insert_term(tcoeff,texp,tail);
}
tail=result;
result=result->next;
free(tail);
return result;
}
void main(){
printf("enter the first polynomial\n");
a=create();
display(a);
printf("enter the second polynomial\n");
b=create();
display(b);
polymult(a,b);
display(result);
}
