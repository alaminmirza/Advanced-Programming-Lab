#include<stdio.h>
#include"AdvancedC.h"

int main()
{
    int sid[10];
    int student,subject,id[10],i,j;
    char code[7][10],name[7][100],title[7][100];
    float cr[7];
    FILE *input;

    input=fopen("data.txt","r");
    if(input==NULL)
    {
        printf("File could not be opened\n\n");
        return 0;
    }
    fscanf(input,"%d",&student);
    fscanf(input,"%d",&subject);

    sub(subject,code,title,cr,input);
    sub_out(subject,code,title,cr);

    printf("\n\n");

    stu(student,sid,name,input);
    //stu_out(student,sid,name);
    for(j=1; j<=student; j++)
    {
        printf("%d\t",sid[j]);
        printf("%s\n",name[j]);
    }
/*
    ThreeD_Array_Input(marks,id,student,subject,part,input);
    ThreeD_Array_Display(marks,id,student,subject,part);
*/
    fclose(input);
    return 0;
}
