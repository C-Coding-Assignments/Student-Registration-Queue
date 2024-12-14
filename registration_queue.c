
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////
#define NAME_LEN 100
#define NETID_LEN 40

//structure definition for a student
struct student {
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
    double gpa;
    int attempts;
    struct student *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

//function prototype for help which prints the menu to the user
void help();
//function prototype for read which reads in information from the user for certain functions and for creating instances of student
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);
//function prototype for add_student which adds a student that the user creates to the linked list
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);
//function prototype for pop_student which removes the first student within the linked list
struct student * pop_student(struct student *registration);
//function prototype for list_students which prints all the students within the linked list
void list_students(struct student *registration);
//function prototype for list_gpa_min which prints the students within the linked list that have a gpa greater than or equal to the minimum gpa that the user enters
void list_gpa_min(struct student *registration, double gpa);
//function prototype for list_cop2510_min which prints the students within the linked list that have a greater COP 2510 letter grade greater than or equal to the minimum letter grade that the user enters
void list_cop2510_min(struct student *registration, int cop2510_grade);
//function prototype for clear_queue which clears the dynamically allocated memory
struct student * clear_queue(struct student *registration);

///////////////////
// main function //
///////////////////

int main() 
{
    //variable declarations and initalization
    char code;
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
    double gpa;
    int attempts;
    struct student *registration = NULL;

    //print the menu to the user
    help();
    printf("\n");

    //for loop which iterates until the user terminates the program
    for (;;) {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);

        //while loop which iterates until the user enters the new-line character
        while(getchar() != '\n'); /* skips to end of line */

        // run operation
        switch (code) {
            //scenario if the user enters an h    
            case 'h':
                help();
                break;
            //scenario if the user enters an a    
            case 'a':
                read(name, netid, &cop2510_grade, &gpa, &attempts);
                registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts);
                break;
            //scenario if the user enters a p    
            case 'p':
                registration = pop_student(registration);
                break;
            //scenario if the user enters a l
            case 'l':
                list_students(registration);
                break;
            //scenario if the user enters a g    
            case 'g':
                read(NULL, NULL, NULL, &gpa, NULL);
                list_gpa_min(registration, gpa);
                break;
            //scenario if the user enters a c
            case 'c':
                read(NULL, NULL, &cop2510_grade, NULL, NULL);
                list_cop2510_min(registration, cop2510_grade);
                break;
            //scenario if the user enters a q
            case 'q':
                registration = clear_queue(registration);
                return 0;
            //scenario if the user enters anything other than the letters above
            default:
                printf("Illegal operation code!\n");
        }
        printf("\n");
    }
}

//////////////////////////
// function definitions //
//////////////////////////

//function definition for help which prints the menu to the screen
void help() 
{
    printf("List of operation codes:\n");
    printf("\t'h' for help;\n");
    printf("\t'a' for adding a student to the queue;\n");
    printf("\t'p' for removing a student from the queue;\n");
    printf("\t'l' for listing all students in the queue;\n");
    printf("\t'g' for searching students with a minimum GPA;\n");
    printf("\t'c' for searching students with a minimum grade in COP2510;\n");
    printf("\t'q' to quit.\n");
}

//function definition for read which reads in information from the user for certain functions and for creating instances of student
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts)
{
    //checking if name is not NULL
    if (name != NULL) {
    printf("Enter the name of the student: ");
    scanf("%[^\n]", name);
    }
    //checking if netid is not NULL
    if (netid != NULL) {
    printf("Enter the NetID of the student: ");
    scanf("%s", netid);
    }
    //checking if cop2510_grade is not NULL
    if (cop2510_grade != NULL) {
    printf("Enter the COP2510 letter grade: ");
    scanf(" %c", cop2510_grade);
    }
    //checking if gpa is not NULL
    if (gpa != NULL) {
    printf("Enter the GPA: ");
    scanf("%lf", gpa);
    }
    //checking if attempts is not NULL
    if (attempts != NULL) {
    printf("Enter the number of previous attempts: ");
    scanf("%d", attempts);
    }
}   

//function definition for list_students which prints the students within the linked list
struct student *add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts)
{
    //creating a new student and allocating memory for it
    struct student *newStudent = malloc(sizeof(struct student));

    //checking if memory allocation was successful
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    //copying the input information into the new student
    strcpy(newStudent->name, name);
    strcpy(newStudent->netid, netid);
    newStudent->cop2510_grade = cop2510_grade;
    newStudent->gpa = gpa;
    newStudent->attempts = attempts;
    newStudent->next = NULL;

    //adding the new student to the end of the linked list   
    if (registration == NULL)
        return newStudent;

    //finding the last student in the linked list and adding instance to the list
    struct student *currentStudent = registration;    
    for (; currentStudent->next!= NULL; currentStudent = currentStudent->next);
    currentStudent->next = newStudent;

    return registration;
}

//function definition for pop_student which removes and prints the first student in the linked list
struct student *pop_student(struct student *registration)
{
    //checking if linked list has no elements
    if (registration == NULL)
        return registration;

    //removing the first student from the linked list
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name | NetID | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| %-20s | %-20s | %c | %1.1f | %8d |\n", registration->name, registration->netid, registration->cop2510_grade, registration->gpa, registration->attempts);
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    return registration->next;
}

//function definition for list_cop2510_min which prints the students with a given minimum grade in COP2510
void list_students(struct student *registration) 
{
    //checking if the linked list has at least one element    
    if (registration!= NULL)
    {
        //creating a new instance of student
        struct student *ptr = registration;

        printf("|----------------------|----------------------|---------|-----|----------|\n");
        printf("| Name | NetID | COP2510 | GPA | Attempts |\n");
        printf("|----------------------|----------------------|---------|-----|----------|\n");

        //iterating through linked list and printing each student
        for (; ptr != NULL; ptr = ptr->next)
        {
            printf("| %-20s | %-20s | %c | %1.1f | %8d |\n", ptr->name, ptr->netid, ptr->cop2510_grade, ptr->gpa, ptr->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
        }
    }
}

//function definition for list_gpa_min which prints the students with a given minimum GPA
void list_gpa_min(struct student *registration, double gpa) 
{
    //checking if the linked list has at least one item
    if (registration != NULL)
    {
        //creating a new instance of student
        struct student *ptr = registration;
        int count = 0;

        //counting how many students have earned the minimum GPA
        for (; ptr != NULL; ptr = ptr->next)
            //checking if the current student has earned the minimum GPA
            if (ptr->gpa >= gpa)
                count++;

        //reseting ptr
        ptr = registration;        

        //printing the students with the minimum GPA
        if (count > 0)
        {
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            printf("| Name | NetID | COP2510 | GPA | Attempts |\n");
            printf("|----------------------|----------------------|---------|-----|----------|\n");

            //for loop which iterates over the linked list
            for (; ptr != NULL; ptr = ptr->next)
                //selection statement which checks if the student earned the minimum GPA
                if (ptr->gpa >= gpa)
                {
                    printf("| %-20s | %-20s | %c | %1.1f | %8d |\n", ptr->name, ptr->netid, ptr->cop2510_grade, ptr->gpa, ptr->attempts);
                    printf("|----------------------|----------------------|---------|-----|----------|\n");
                }
        } 
    }
}

//function definition for list_cop2510_max which prints the students with a given maximum grade in COP2510
void list_cop2510_min(struct student *registration, int cop2510_grade) 
{
    //checking if the linked list has at least one item
    if (registration!= NULL)
    {
        //creating a new instance of student
        struct student *ptr = registration;
        int count = 0;

        //counting how many students have earned the minimum grade in COP2510
        for (; ptr != NULL; ptr = ptr->next)
            //checking if the student has earned the minimum grade in COP2510
            if (ptr->cop2510_grade <= cop2510_grade)
                count++;

        //reseting ptr    
        ptr = registration;           

        //selection statement which checks if at least one student has earned the minimum grade in COP2510 
        if (count > 0)
        {
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            printf("| Name | NetID | COP2510 | GPA | Attempts |\n");
            printf("|----------------------|----------------------|---------|-----|----------|\n");

            //for loop which iterates over the linked list
            for (; ptr != NULL; ptr = ptr->next)
                //selection statement which checks if the current student has earned the minimum grade
                if (ptr->cop2510_grade <= cop2510_grade)
                {
                    printf("| %-20s | %-20s | %c | %1.1f | %8d |\n", ptr->name, ptr->netid, ptr->cop2510_grade, ptr->gpa, ptr->attempts);
                    printf("|----------------------|----------------------|---------|-----|----------|\n");
                }
        }
    }
}

//function definition for list_attempts_max which prints the students with the maximum number of attempts
struct student * clear_queue(struct student *registration) 
{
    //freeing memory
    free(registration);

    return registration;
}
