#include <stdio.h>
#include <string.h>
struct students{
    int roll;
    char name[50];
    float marks1;
    float marks2;
    float marks3;
    float total;
    float avg;

};
void cal_avg__tot(struct students *s);
void filter(struct students *p,int n);
void sorting(struct students *t,int n);
int main(){
    int n;
    printf("enter no of students->");
    scanf("%d",&n);
    struct students students[n];
     for(int i=0;i<n;i++){

         printf("enter details of student %d\n",i+1);
        printf("enter roll  number\n");
         scanf("%d",&students[i].roll);

        printf("enter name of the student\n");
          scanf("%s",students[i].name);

        printf("enter marks of sub1\n");
         scanf("%f",&students[i].marks1);

        printf("enter marks of sub2\n");
         scanf("%f",&students[i].marks2);

        printf("enter marks of sub3\n");
         scanf("%f",&students[i].marks3);
         
         cal_avg__tot(&students[i]);

     }
printf("------------------------------------------------------------------");
    printf("<--displaying all records-->");
  printf("------------------------------------------------------------------");

    for(int i=0;i<n;i++){
        printf("\nroll-> %d || name-> %s || marks1-> %.2f || marks2-> %.2f || marks3-> %.2f || total-> %.2f || avarage-> %.2f\n",students[i].roll,students[i].name,students[i].marks1,students[i].marks2,students[i].marks3,students[i].total,students[i].avg);    
        
    }
printf("------------------------------------------------------------------");
    filter(&students[0],n);
  printf("------------------------------------------------------------------");
  printf("\n");
  printf("------------------------------------------------------------------");
printf("\n<--sorting records according to name-->\n");
  printf("------------------------------------------------------------------");
printf("<--records after sorting-->\n");
  printf("------------------------------------------------------------------");
sorting(&students[0],n); 
  for(int i=0;i<n;i++){
        printf("\nroll-> %d || name-> %s || marks1-> %.2f || marks2-> %.2f || marks3-> %.2f || total-> %.2f || avarage-> %.2f\n",students[i].roll,students[i].name,students[i].marks1,students[i].marks2,students[i].marks3,students[i].total,students[i].avg);    
        
    }


    
}
void cal_avg__tot(struct students *s)
{
    s->total = s->marks1 + s->marks2 + s->marks3;
    s->avg = s->total/3;
}

void filter(struct students *p,int n){
    printf("<--displaying filtered names-->");
    int found = 0;
    for (int i = 0; i < n; i++) {
       
        char first_char = p[i].name[0];
        
        if ((first_char == 'A' || first_char == 'a' || first_char == 'B' || first_char == 'b') 
            && p[i].avg > 80.0) {
            printf("\nRoll No: %d || Name: %s || Average: %.2f\n", 
                   p[i].roll, p[i].name, p[i].avg);
            found = 1;
        }
    }
    
    if (found ==0) {
        printf("\nNo students match this specific criteria\n");
    
}
}
void sorting(struct students *t,int n){

    struct students temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(strcmp(t[j].name,t[j+1].name) >0){
                temp = t[j];
                t[j] = t[j+1];
                t[j+1]= temp;
                
            }   
        }   
    }

printf("<--sorting sucessful-->");
    
}
