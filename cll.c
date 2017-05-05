//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:OPERATIONS ON CLL
#include<stdio.h>
struct node
{
int info;
struct node*next;
struct node*back;
}*ptr,*start,*prev,*cur,*now,*cur1;
int j=3;
void main(){
do{
int i,n,c,d;
printf("\n******MAIN MENU******");
printf("\n1:To Create\n2:To Display\n3:To Insert\n4:To Delete\n5:Exit\nEnter your choice:");
scanf("%d",&n);
switch(n){
 case 1: create();break;
 case 2: display();break;
 case 3:
        printf("\n1:insertion at begining\n2:insertion at end\n3:insertion at any position\n Enter your choice:");
        scanf("%d",&c);
        switch(c){ 
        case 1: insert_beg();break;
        case 2: insert_end();break;
        case 3: insert_pos();break;
        default:printf("wrong choice");break;
        };break;
 case 4:{
        printf("\n1:delete node from begining\n2:delete node from end\n3:delete node from any position\nEnter your choice:");
        scanf("%d",&d);
        switch(d){
        case 1: delete_beg();break;
        case 2: delete_end();break;
        case 3: delete_pos();break;
        default:printf("wrong choice");break;
        };break;
        }
 case 5:j=1;break;
 default:printf("wrong choice");break;
}
}
while(j>2);
}
void create(){
int n;
start=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data:");
scanf("%d",&start->info);
cur=start;
start->back=NULL;
do{
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL){
printf("insuficient space");
}
printf("enter the data:");
scanf("%d",&ptr->info);
cur->next=ptr;
ptr->back=cur;
cur=cur->next;
cur->next=start;
start->back=cur;
printf("\ndo you want to add more?\n1:yes\n2:no\nenter the choice:");
scanf("%d",&n);
}
while(n==1);
}

void display(){
cur=start;
  while(cur->next!=start){
  printf("%d->",cur->info);
  cur=cur->next;
  }
 printf("%d->\n",cur->info);
}
void insert_beg(){
 cur=start;  
 ptr=(struct node*)malloc(sizeof(struct node));
 if(ptr==NULL){ 
  printf("insuficient space");
 }

 printf("enter the data:");
 scanf("%d",&ptr->info);
 ptr->next=start;
 start->back=ptr; 
 now=start;
 while(now->next!=start){
  now=now->next;
 }
 ptr->back=now;
 now->next=ptr;
 start=ptr;
 display();  
}
void insert_end(){
cur=start;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL){ 
printf("insuficient space");
}

printf("enter the data:");
scanf("%d",&ptr->info);
   while(cur->next!=start){
   cur=cur->next;
   }
  cur->next=ptr;
  ptr->back=cur;
  ptr->next=start;
  start->back=ptr;
}
void insert_pos(){
cur=start;
int n;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL){ 
printf("insuficient space");
}

printf("enter the data before which we need to insert:");
scanf("%d",&n);
  while(cur->info!=n){
  prev=cur;
  cur=cur->next;
  }
       printf("enter the data to be inserted:");
       scanf("%d",&ptr->info);
       ptr->next=cur;
       cur->back=ptr; 
       prev->next=ptr;
       ptr->back=prev;
       display();

}
void delete_beg(){
 cur=start;
 now=start;
  while(now->next!=start){
  now=now->next;
 }

 if(start==NULL){
  printf("list is empty");
 }
 cur=cur->next;
 start=cur;
 start->back=now;
 now->next=start;
 display();
}
void delete_end(){
 cur=start;
 if(start==NULL){ 
  printf("list is empty");
 }
 else if(cur->next==start){
  printf("list is empty");
 }
else{
   while(cur->next!=start){
   prev=cur;  
   cur=cur->next;
   }
  prev->next=start;
  start->back=prev;
  cur->back=NULL;
  display();
}
}
void delete_pos(){
cur=start;
if(start==NULL){ 
  printf("list is empty");
 }

int n;
printf("enter the data to be deleted:");
scanf("%d",&n);
 while(cur->info!=n){
 prev=cur;
 cur=cur->next; 
 }
 cur->next=cur1;
 prev->next=cur1;
 cur1->back=prev;
 display(); 
}


