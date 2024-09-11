#include<stdio.h>
#include"AdvancedC.h"

int main()
{
    int student,subject,id[10],total_marks[10][6],marks[10][6][4],i,j,k;
    int part=4;
    FILE *input;

    input=fopen("data.txt","r");
    if(input==NULL)
    {
        printf("File could not be opened\n\n");
        return 0;
    }
    fscanf(input,"%d",&student);
    fscanf(input,"%d",&subject);

    ThreeD_Array_Input(marks,id,student,subject,part,input);
    ThreeD_Array_Display(marks,id,student,subject,part);

    fclose(input);
    return 0;
}
