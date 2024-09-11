#include<stdio.h>
#include"CSE_106.h"

int main(void)
{
    //Veriable Delaration Part
    int i, j, k, std_id[10], std_marks[10][6][4], part, total_marks[10][6], sub, std;
    char std_name[10][50], letter_grade[10][6][4], ccode[6][10], ctitle[6][100];
    float grade_point[10][6], choure[6], sgpa[10];
    FILE *input, *output;

    //File Management Part

    input = fopen("data.txt","r");
    output = fopen("output.txt","w");
    if(input==NULL && output==NULL)
    {
        printf("\n file not found \n");
        return 0;
    }

    //No.of student & Subject entry Part

    fscanf(input,"%d,%d",&std,&sub);

    //Subject information entry

    input_subject_information(input,sub,ccode,ctitle,choure);

    //Student information entry part

    part=4;
    input_student_information(input,std,sub,std_id,std_name,std_marks,part);

    //student wise information Display part

    display_student_tabulation(output,std,sub,ccode,ctitle,choure,std_id,std_name,std_marks,part);
}