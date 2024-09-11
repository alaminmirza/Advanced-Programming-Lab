#include<stdio.h>
#include"CSE_106.h"
#include<string.h>

int main(void)
{
    //Veriable Delaration Part
    int i, j, k, std_id[10], std_marks[10][6][4], part, total_marks[10][6], sub, std;
    char std_name[10][50], letter_grade[10][7][4], ccode[6][10], ctitle[6][100];
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

    //Subject wise total marks calculation

    student_subjectwise_totalmarks_calculation(std,sub,part,std_marks,total_marks);

    //Grade point calculation

    studentwise_gradepoint_calculation(std,sub,total_marks,grade_point);

    //student wise letter grade calculation
    studentwise_lettergrade_calculation(std,sub,total_marks,letter_grade);

    //student wise SGPA calculation

    studentwise_SGPA_calculation(std,sub,grade_point,choure,sgpa);

    //student wise information Display part

    for(i=1;i<=std;i++){
    for(j=1;j<=sub;j++){
        printf("%s\n",letter_grade[i][j]);
        }
        printf("\n\n");}

    display_student_tabulation(output,std,sub,ccode,ctitle,choure,std_id,std_name,std_marks,part,total_marks,grade_point,letter_grade,sgpa);
}
