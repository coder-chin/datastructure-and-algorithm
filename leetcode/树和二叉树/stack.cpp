#include<iostream>
#include<iomanip>
#include<stack>
#define Maxsize 1000 
#define ERROR 0
#define OK 1

using namespace std;
typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S) {
    S.base = new char[Maxsize];
    S.top = S.base;
    S.stacksize = Maxsize;
    return;
}

bool PushStack(SqStack &S,char e) {
    if(S.top-S.base==S.stacksize)
        return false;
    else {
        *S.top=e;
        S.top++;
        return true;
    }
}

void PopStack(SqStack &S,char &e) {
    if(S.top==S.base)
        exit(0);
    else
        e=*--S.top;
    return;
}

double GettopStack(SqStack &S) {
    if(S.top!=S.base)
    return *(S.top-1);
}

bool In(char &ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
        return true;
    else 
        return false;
}

char Precede(char c1,char c2) { 
    if((c1=='('&&c2==')')||(c1=='='&&c2=='='))   
        return '=';

    else if(c1=='('||c1=='='||c2=='('||(c1=='+'||c1=='-')&&(c2=='*'||c2=='/'))  
        return '<';

    else 
        return '>'; 
}

double Operate(double first, char t, double second) {//计算两数运算结果
    switch (t) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
    }
    return 0;
}

void EvaluateExpression(char &ch) {
    SqStack OPND,OPTR;
    char a,b,x,theta;
    InitStack(OPND);
    InitStack(OPTR);
    PushStack(OPTR,'=');
    cin>>ch;
    while(ch!='='||GettopStack(OPTR)!='='){
        if(!In(ch)){
        PushStack(OPND,ch);
        cin>>ch;
    }
    else
  switch(Precede(GettopStack(OPTR),ch)){
   case '<':
   PushStack(OPTR,ch);
   cin>>ch;
   break;
   case '>':
   PopStack(OPTR,theta);
   PopStack(OPND,b);
   PopStack(OPND,a);
   PushStack(OPND,Operate(a,theta,b));
   break;
   case '=':
   PopStack(OPTR,x);
   cin>>ch;
   break; 
  }
 }
 cout<<setiosflags(ios::fixed)<<setprecision<<GettopStack(OPND);
 return;
}

int main(){
    // SqStack S;
    // char ch,e,t;
    // double first;
    // double second;

    EvaluateExpression(ch);

    return 0;
} 