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

    int m,n;
    fprintf(output,"students=%d\nsubjects=%d\n",std,sub);
    for(n=1;n<=sub;n++)
    {
      fprintf(output,"\n%s\t%.2f\t%s\n",ccode[n],choure[n],ctitle[n]);
    }
    for (m=1;m<=std;m++)
    {
        fprintf(output,"\n%d\t%s\n",std_id[m],std_name[m]);
        for(n=1;n<=sub;n++)
        {
            fprintf(output,"%d\t%d\t%d\t%d\t%d\t%.2f\t%s\n",std_marks[m][n][1],std_marks[m][n][2],std_marks[m][n][3],std_marks[m][n][4],total_marks[m][n],grade_point[m][n],letter_grade[m][n]);
        }
        fprintf(output,"%.2f\n",sgpa[m]);
    }

}
