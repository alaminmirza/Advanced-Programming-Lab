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
void display_student_tabulation(FILE*out,int st,int sb,char ccd[6][10],char ctl[6][100],float chr[6],int s_id[10],char s_nm[10][50],int s_marks[10][6][4],int pt)
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
            fprintf(out,"%d\t%d\t%d\t%d\n",s_marks[m][n][1],s_marks[m][n][2],s_marks[m][n][3],s_marks[m][n][4]);
        }
    }
}