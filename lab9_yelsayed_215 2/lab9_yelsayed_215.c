#include <stdio.h>
#include <stdlib.h>

void PM()
{
    printf("Enter your Choice:\n'i' - Insert data\n'u' - Update data\n's' - Search employee\n'p' - Print the database\n'q' - Quit\n");
}
int valid(char k)
{
    int coin = 0;

    if (k == 'i' || k == 'I' || k == 's' || k == 'S' || k == 'u' || k == 'U' || k == 'p' || k == 'P' || k == 'q' || k == 'q')
        coin++;

    if (k == 'q' || k == 'Q')
        coin = 3;

    return coin;
}

typedef struct
{
    int day;
    int year;
    int month;
} DOB;

typedef struct
{
    int ID;
    char firstName[30];
    char lastName[30];
    double salary;
    DOB birthday;

} employees;

main()
{
    int i, N = 3, count, tempID;
    int checkNum,num,j;
    employees *target;
    char kin[100], k;

    for (i = 0; i < N; i++)
    {
        target = malloc(sizeof(employees) * N);
    }
    if (target == NULL)
    {
        printf("Memeory not allocatied\n");
        exit(0);
    }
    PM();
    fgets(kin, 100, stdin);
    sscanf(kin, "%c", &k);
    checkNum = valid(k);
    while (checkNum == 0)
    {
        printf("ERROR %c not valid please re-enter choice\n", k);
        fgets(kin, 100, stdin);
        sscanf(kin, "%c", &k);
        checkNum = valid(k);
    }

    if (checkNum == 3)
    {
        free(target);
        exit(0);
    }

    while (checkNum != 3)
    {

        if (k == 'i' || k == 'I')
        {
            for (i = 0; i < N; i++)
            {
                if (target[i].ID == 0)
                {
                    printf("Enter ID\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%d", &tempID);
                        
                        for(j = 0; j < N; j++){
                            if(tempID == target[j].ID){

                                printf("Error! ID is already in the database\n");
                                break;
                            }
                            else{
                                target[i].ID = tempID;
                            }
                            break;
                        }
                        
                    printf("Enter First and Last Name\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%[^ ] %[^ ]", target[i].firstName, target[i].lastName);

                    printf("Enter salary\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%lf", &target[i].salary);

                    printf("Enter Birth Day\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%d", &target[i].birthday.day);
                    printf("Enter birth Month\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%d", &target[i].birthday.month);
                    printf("Enter Birth Year\n");
                    fgets(kin, 100, stdin);
                    sscanf(kin, "%d", &target[i].birthday.year);
                    count++;
                    if (count == N)
                    {
                        free(target);
                            N *= 2;
                            for(i = 0; i < N; i++){
                                target = malloc(sizeof(employees) * N);
                            }
                    }
                }
                
            }
        }





        if (k == 'p' || k == 'P')
        {
            printf("ID      Name       Date           Salary\n");
            for (i = 0; i < N; i++)
            {
            printf("%d      %s %s      %d/%d/%d      %.2f\n", target[i].ID, target[i].firstName, target[i].lastName, target[i].birthday.day, target[i].birthday.month, target[i].birthday.year, target[i].salary);
            }
       
        }

        if (k == 's' || k == 'S')
        {

            printf("Enter ID To search database\n");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &tempID);

            for (i = 0; i < N; i++)
            {
                if (target[i].ID == tempID)
                {
                    printf("\nID: %d\nFirst Name: %s\nLast Name: %sDOB: %d/%d/%d\nSalary: %.2f\n\n", target[i].ID, target[i].firstName, target[i].lastName, target[i].birthday.day, target[i].birthday.month, target[i].birthday.year, target[i].salary);
                }
                else{
                    printf("ID is not in Database\n");
                }
               
            }
        }




    if(k == 'u' || k == 'U'){

            printf("Enter ID To update database\n");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &tempID);


            for(i = 0; i < N; i++){
                 if (target[i].ID == tempID)
                {
                printf("1 - First Name\n2 - last Name\n3 - DOB\n4 - Salary\n5 - Do not update\n");
                fgets(kin,100,stdin);
                sscanf(kin,"%d",&num);

                switch (num)
            {

            case (1):
                printf("Enter First Name to update ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%s", &target[i].firstName);
                break;
            case (2):
                printf("Enter Last Name to update ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%s", &target[i].lastName);
                break;
            case (3):
                printf("Enter Birth Day to update ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &target[i].birthday.day);
                printf("Enter birth Monthto update ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &target[i].birthday.month);
                printf("Enter Birth Year\to update ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &target[i].birthday.year);
                break;
            case (4):
                printf("Enter Updated Salary for ID: %d: ", tempID);
                fgets(kin, 100, stdin);
                sscanf(kin, "%lf", &target[i].salary);
                break;
            defualt:
                printf("Option is not valid, try it again\n");

                break;
            

            }

                }
                else{
                    printf("ID Doesn't exist!!\n");
                }
            }

    }








        PM();
        fgets(kin, 100, stdin);
        sscanf(kin, "%c", &k);
        checkNum = valid(k);
        while (checkNum == 0)
        {
            printf("ERROR %c not valid please re-enter choice\n", k);
            fgets(kin, 100, stdin);
            sscanf(kin, "%c", &k);
            checkNum = valid(k);
        }
       

    }
    free(target);
    return 0;
}