#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/' ||c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
void infixToPostfix(char *exp)
{
    int len=strlen(exp);
    char stack[len],result[len+1];
    int j=0,i,top=-1;
    
    for(i=0;i<len;i++)
    {
        char c=exp[i];
        
        if(isalnum(c))
        result[j++]=c;
        
        else if(c=='(')
        stack[++top]='(';
        
        else if(c==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
            result[j++]=stack[top--];
            }
            if(top!=-1 &&stack[top]=='(' )
            top--;
        }
        else
        {
            while(top!=-1 && prec(c)<=prec(stack[top]))
            result[j++]=stack[top--];
            stack[++top]=c;
        }
    }
        while(top!=-1)
        result[j++]=stack[top--];
        
        result[j]='\0';
        printf("The postfix expression:");
        printf("%s\n",result);
}
int main()
{
    char exp[50];
    printf("Enter the infix expression:");
    scanf("%s",exp);
    infixToPostfix(exp);
    return 0;
}
