#include <stdio.h>
void input_subject_information(FILE*in,int sb,char ccd[6][10],char ctl[6][100],float chr[6])
{
    int m;
    for(m=1;m<=sb;m++)
    {
        fscanf(in,"%[^,],%[^,],%f",&ccd[m],&ctl[m],&chr[m]);
    }
}
void input_student_information(FILE*in, int st, int sb, int s_id[10], char s_nm[10][50], int s_marks[10][6][4], int pt)
{
    int m,n;
    for(m=1;m<=st;m++)
    {
        fscanf(in,"%d,%[^\n]",&s_id[m],s_nm[m]);
        for(n=1;n<=sb;n++)
        {
            fscanf(in,"%d,%d,%d,%d",&s_marks[m][n][1],&s_marks[m][n][2],&s_marks[m][n][3],&s_marks[m][n][4]);
        }
    }
}
void student_subjectwise_totalmarks_calculation(int st,int sb,int pt,int s_marks[10][6][4],int t_marks[10][6])
{
    int i,j,k,temp;
    for(i=1;i<=st;i++)
    {
        for(j=1;j<=sb;j++)
        {
            temp=0;
            for(k=1;k<=pt;k++)
            {
                temp=temp+s_marks[i][j][k];
            }
            t_marks[i][j]=temp;
        }
    }
}
void studentwise_gradepoint_calculation(int st,int sb,int t_marks[10][6],float g_point[10][6])
{
    int i,j;
    for(i=1;i<=st;i++)
    {
        for(j=1;j<=sb;j++)
        {
            if(t_marks[i][j]>=80){
                g_point[i][j]=4.00;
            }
            else if(t_marks[i][j]>=75){
                g_point[i][j]=3.75;
            }
            else if(t_marks[i][j]>=70){
                g_point[i][j]=3.50;
            }
            else if(t_marks[i][j]>=65){
                g_point[i][j]=3.25;
            }
            else if(t_marks[i][j]>=60){
                g_point[i][j]=3.00;
            }
            else if(t_marks[i][j]>=55){
                g_point[i][j]=2.75;
            }
            else if(t_marks[i][j]>=50){
                g_point[i][j]=2.50;
            }
            else if(t_marks[i][j]>=45){
                g_point[i][j]=2.25;
            }
            else if(t_marks[i][j]>=40){
                g_point[i][j]=2.00;
            }
            else{
                g_point[i][j]=0;
            }
        }
    }
}
void studentwise_lettergrade_calculation(int st,int sb,int t_marks[10][6],char l_grade[10][7][4])
{
    int i,j;
    for(i=1;i<=st;i++)
    {
        for(j=1;j<=sb;j++)
        {
            if(t_marks[i][j]>=80){
                strcpy(l_grade[i][j],"A+");
                //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=75){
                 strcpy(l_grade[i][j],"A");
                 //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=70){
                 strcpy(l_grade[i][j],"A-");
                 //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=65){
                strcpy(l_grade[i][j],"B+");
                //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=60){
                 strcpy(l_grade[i][j],"B");
                 //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=55){
                strcpy(l_grade[i][j],"B-");
                //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=50){
               strcpy(l_grade[i][j],"C+");
               //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=45){
                strcpy(l_grade[i][j],"C");
                //printf("%s\n",l_grade[i][j]);
            }
            else if(t_marks[i][j]>=40){
                strcpy(l_grade[i][j],"D");
                //printf("%s\n",l_grade[i][j]);
            }
            else{
               strcpy(l_grade[i][j],"F");
               //printf("%s\n",l_grade[i][j]);
            }
        }
        //printf("\n\n");
    }

}
void studentwise_SGPA_calculation(int st,int sb,float g_point[10][6],float cr[6],float sg[10])
{
    float a,b;
    int i,j;
    for(i=1;i<=st;i++)
    {
        a=0;
        b=0;
        for(j=1;j<=sb;j++)
        {
            a=a+g_point[i][j]*cr[j];
            b=b+cr[j];
        }
        sg[i]=a/b;
    }
}
void display_student_tabulation(FILE*out,int st,int sb,char ccd[6][10],char ctl[6][100],float chr[6],int s_id[10],char s_nm[10][50],int s_marks[10][6][4],int pt,int t_marks[10][6],float g_point[10][6],int l_grade[10][7][4],float sg[10])
{
    int m,n;
    fprintf(out,"students=%d\nsubjects=%d\n",st,sb);
    for(n=1;n<=sb;n++)
    {
      fprintf(out,"\n%s\t%.2f\t%s\n",ccd[n],chr[n],ctl[n]);
    }
    for (m=1;m<=st;m++)
    {
        fprintf(out,"\n%d\t%s\n",s_id[m],s_nm[m]);
        for(n=1;n<=sb;n++)
        {
            fprintf(out,"%d\t%d\t%d\t%d\t%d\t%.2f\t%s\n",s_marks[m][n][1],s_marks[m][n][2],s_marks[m][n][3],s_marks[m][n][4],t_marks[m][n],g_point[m][n],l_grade[m][n]);
        }
        fprintf(out,"%.2f\n",sg[m]);
    }


}

