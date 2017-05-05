//NAME:VISHNUPRIYA.M
//ROLL NO:64
//PROGRAM:PRGRM PERFORMS COVERTION OF INFIX EXPRESSION TO POSTFIX AND EVALUATION OF THE EXPRESSION
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 50
int top=-1;
float res;
int ch;
 char s[MAX];
 int i,j=0;
char stack[MAX];
char stack1[MAX];
char post[MAX];
int prio(char c){
 if(c=='^')
   return 3;
 else if(c=='*'||c=='/')
   return 2;
 else if(c=='+'||c=='-')
   return 1;
 else 
   return 0;
}
push(char p){
if(top==MAX)
 printf("stack is full");
else{
top++;
stack[top]=p;
}
}
push1(int p){
 int top1;
if(top1==MAX)
 printf("stack is full");
else{
top1++;
stack1[top1]=p;
}
}

char pop(){
char item;
if(top==-1)
  printf("stack is empty");
  else{ 
 item=stack[top];
 top=top-1;
 }
return item;
}
int pop1(){
int item;
 int top1;
if(top1==-1)
  printf("stack is empty");
  else{ 
 item=stack1[top1];
 top1=top1-1;
 }
return item;
}

void postfix(char s[MAX]){
 int i=0;
 int length;
 char symbol;
 char opr;
 length=strlen(s);
 while(i<length){
   symbol=s[i];
   switch(symbol){
   case '(':push(symbol);break;
   case ')':opr=pop();
            while(opr!='('){
              post[j]=opr;
              j++;
              opr=pop();
            }break;
   case '+': while(prio(stack[top])>=prio(symbol)){
          opr=pop();
          post[j]=opr;
          j++;
        }
        push(symbol);
        break;

   case '-': while(prio(stack[top])>=prio(symbol)){
          opr=pop();
          post[j]=opr;
          j++;
        }
        push(symbol);
        break;

   case '*': while(prio(stack[top])>=prio(symbol)){
            opr=pop();
            post[j]=opr;
            j++;
        }
        push(symbol);
        break;

   case '/': while(prio(stack[top])>=prio(symbol)){
            opr=pop();
            post[j]=opr;
            j++;
        }
        push(symbol);
        break;

   case '^':
          while(prio(stack[top])>=prio(symbol)){
          opr=pop();
           post[j]=opr;
           j++;
        }
        push(symbol);
        break;
  default:post[j++]=symbol;break;

   }
  i++;
}
while(top>-1){
  opr=pop();
  post[j++]=opr;
}
post[j++]='\0';
printf("%s",post);

}
float eval(char post[MAX]){
 int m=0,l=0;int post1[MAX];
 float op1,op2,res;
 char ch;
 while(post[m]!='\0'){
  if(isalpha(post[m])){
  printf("\nenter the value of %c:",post[m]);
  scanf("%f",&post1[l]);   
  l++;
  }
  m++;
 }
 post1[l]='\0';
 printf("the evaluated result is given by\n");
 int k=0;
 while(post1[k]!='\0'){
  ch=post1[k];
  if (isalpha(post1[k])){
    push1(post1[k]);
   k++;
  }
  else{
  op1=pop1();
  op2=pop1();
  switch(ch){
   case '+':push1(op1+op2);break;
   case '-':push1(op1-op2);break;
   case '*':push1(op1*op2);break;
// case '^':push1(pow(op1,op2));break;
   case '/':push1(op1/op2);break;
  }
  k++;
  }
  }res=pop1();
  return res;
}
void main(){
 top=-1;
 printf("\nEnter a valid infix expression:");
 scanf("%s",&s);
 printf("postfix expression is given by\n"); 
 postfix(s);
 eval(post);
 printf("%f",res);
}
