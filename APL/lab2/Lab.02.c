#include<stdio.h>
#include"AdvancedC.h"

 int main()
 {
     int student,subject,id[10],total_marks[10][2],marks[10][2][4],i,j,k;
     int part=4;

     printf("student= ");
     scanf("%d",&student);

     printf("subject= ");
     scanf("%d",& subject);

     ThreeD_Array_Input(marks,id,student,subject,part);
     ThreeD_Array_Display(marks,id,student,subject,part);

     return 0;
 }





