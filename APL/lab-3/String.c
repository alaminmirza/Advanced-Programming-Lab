#include<stdio.h>
int main()
{
    //char p;
    char p[2][20];//in p[n] character type data we can store n-1 data,p[2]= How many string,p[20]=Length of string
    int i;
    for(i=1;i<=2;i++){
    scanf("%[^\n]\n%[^\n]",p[1],p[2]);
    //scanf("%[^\n]",p[2]);
    }
 /*for (i=1;i<=2;i++){
        gets(p[i]);
 }*/
    //p='*';
    //scanf("%c",&p);
    //scanf("%s",&p);
    //gets(p[1]);
    //gets(p[2]);
    //p=getchar();
    //printf("%c",p);
    //printf("%s\n%s",p[1],p[2]);
    printf("%s\n%s",p[1],p[2]);
}
