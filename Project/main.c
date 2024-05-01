#include <stdio.h>
#include <stdlib.h>

struct student{
    char *names;
    int id;
    float total_grade;
    int age;
    char *gender;
    char *password;
};
int main()
{
    struct student students[]=
    {
        {"Ahmed",1111,100,20,"male","12"},
        {"Hana",1112,90,19,"female","23"},
        {"Maged",1113,85,21,"male","34"},
    };
    int num_students= sizeof(students)/sizeof(students[0]);
    int n, x;
    int iD;
    printf("1.admin mode\n");
    printf("2.user mode\n");
    printf("Please choose your mode:");
    scanf("%d",&n);
    if(n==1)
    {
        int password = 1234;
        int pass;
        printf("Please enter your password: ");
        scanf("%d",&pass);
        int y=2;
        while(y!=0||pass==password)
        {
            if(pass==password)
            {
                printf("1.add student record\n");
                printf("2.remove student record\n");
                printf("3.view student record\n");
                printf("4.view all records\n");
                printf("5.edit admin password\n");
                printf("6.edit student grade\n");
                printf("Please choose: ");
                scanf("%d",&x);
                break;
            }
            else
            {
                printf("Your password incorrect\nPlease try again\n");
                printf("Enter your password: ");
                scanf("%d",&pass);
                --y;
            }
        }
        if(y==0&&pass!=password)
        {
            printf("You have exceeded the maximum attempts\nPlease try in another time");
        }
        switch(x)
        {
            case 1:
                printf("Please enter the student information\n");
                struct student New;
                char *Name;
                printf("Name: ");
                scanf("%s",&New.names);
                printf("ID: ");
                scanf("%d",&New.id);
                int check(int id)
                {
                    for(int i=0; i<num_students; i++)
                    {
                        if(New.id==students[i].id)
                        {
                            printf("Invalid id\nBecause the ID was used before");
                            return 0;
                        }
                    }
                    return 1;
                }
                if(check(New.id)==1)
                {
                    printf("Total grade: ");
                    scanf("%f",&New.total_grade);
                    printf("Age: ");
                    scanf("%d",&New.age);
                    printf("Gender: ");
                    scanf("%s",&New.gender);
                    printf("Password: ");
                    scanf("%s",&New.password);
                    students[num_students++]=New;
                    printf("Students was added");
                }
                break;
            case 2:
                printf("Enter the ID: ");
                scanf("%d",&iD);
                int removing(int id)
                {
                    for(int i=0; i<num_students; i++)
                    {
                        if(iD==students[i].id)
                        {
                            return 1;
                        }
                    }
                    printf("The removing is rejected\nThe id doesn't exist");
                    return 0;
                }
                if(removing(iD)==1)
                {
                    for(int i=0 ; i<num_students-1 ; i++)
                    {
                        students[i]=students[i+1];
                    }
                    num_students--;
                    printf("The student is removed successfully");
                }
                break;
            case 3:
                printf("Enter the ID: ");
                scanf("%d",&iD);
                for (int i=0 ; i<num_students ; i++)
                {
                    if(iD==students[i].id)
                    {
                        printf("name: %s\n",students[i].names);
                        printf("total grades: %.2f\n",students[i].total_grade);
                        printf("age: %d\n",students[i].age);
                        printf("Gender: %s\n",students[i].gender);
                    }
                }
                break;
            case 4:
                for (int i=0 ; i<num_students ; i++)
                {
                        printf("name: %s\n",students[i].names);
                        printf("total grades: %.2f\n",students[i].total_grade);
                        printf("age: %d\n",students[i].age);
                        printf("Gender: %s\n",students[i].gender);
                }
                break;
            case 5:
                printf("Enter the current password: ");
                int Password;
                scanf("%d",&Password);
                if(Password==password)
                {
                    int new_pass;
                    printf("Enter new password: ");
                    scanf("%d",&new_pass);
                    password = new_pass;
                    printf("The new password is: %d",password);
                }
                else
                    printf("Incorrect password");
                break;
            case 6:
                printf("Enter the ID: ");
                scanf("%d",&iD);
                int found=0;
                int change(int i)
                {
                    for(int i=0; i<num_students; i++)
                    {
                        if(iD==students[i].id)
                        {
                            found++;
                            float grades;
                            printf("Enter the new grade: ");
                            scanf("%f",&grades);
                            students[i].total_grade=grades;
                            printf("The new grade= %.2f",students[i].total_grade);
                        }
                    }
                }
                change(iD);
                if(found==0)
                    printf("Incorrect ID");
                    break;
            default:
                printf("Invalid choice");
                break;
        }
    }
    else if(n==2)
    {
        printf("Enter your ID: ");
        scanf("%d",&iD);
        char stu_pass[20];
        printf("Enter your password: ");
        scanf("%s",stu_pass);
        int wonder(int iD,char *stu_pass,struct student students[],int num_students)
        {
            for(int i=0; i<num_students ; i++)
            {
                if(iD == students[i].id && strcmp(stu_pass, students[i].password)==0)
                {
                    printf("Welcome %s\n",students[i].names);
                    return 1;
                }
            }
            return 0;
        }
        if(wonder(iD,stu_pass,students,num_students)==1)
        {
            printf("1.View your record\n");
            printf("2.Edit your password\n");
            printf("3.Edit your name\n");
            printf("Enter your choice: ");
            scanf("%d",&x);
            switch(x)
            {
                case 1:
                    printf("Enter your ID: ");
                    int ID;
                    scanf("%d",&ID);
                    for(int i=0; i<num_students ; i++)
                    {
                       if(ID == students[i].id)
                       {
                           printf("name: %s\n",students[i].names);
                            printf("total grades: %.2f\n",students[i].total_grade);
                            printf("age: %d\n",students[i].age);
                            printf("Gender: %s\n",students[i].gender);
                       }
                    }
                    break;
                case 2:
                    printf("Enter your ID: ");
                    int I;
                    scanf("%d",&I);
                    for(int i=0; i<num_students ; i++)
                    {
                       if(I == students[i].id)
                       {
                           char PASS[20];
                           printf("Enter your new password: ");
                           scanf("%s",PASS);
                           students[i].password=(char*)malloc(strlen(PASS)+1);
                           strcpy(students[i].password,PASS);
                           printf("The password changed successfully");
                           free(students[i].password);
                       }
                    }
                    break;
                case 3:
                    printf("Enter your ID: ");
                    int d;
                    scanf("%d",&d);
                    for(int i=0; i<num_students ; i++)
                    {
                       if(d == students[i].id)
                       {
                           char NAME[20];
                           printf("Enter your new name: ");
                           scanf("%s",NAME);
                           students[i].names=(char*)malloc(strlen(NAME)+1);
                           strcpy(students[i].names,NAME);
                           printf("The name changed successfully");
                           free(students[i].names);
                       }
                    }
                    break;
                default:
                    printf("Invalid choice");
                    break;
            }
        }
        else
        {
            printf("wrong ID or password");
        }
    }
    else
    printf("Invalid choice");
    return 0;
}
