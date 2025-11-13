//write a program to create stduent database using array and structure read atleast.
// Apply sorting technique . ✅
// buble sort on prn asd , name dsn .✅
//selection marks descending order✅
// insertion on name descsnding order✅
#include <stdio.h>
#include <string.h>
#include <ctype.h>

 struct STUDENT {
    char name[50];
    int marks;
    int day, month, year;
    int prn;
    int div;
    int address[100];

 };


void displayStudent(struct STUDENT student[] , int n) {
    printf("\nName             Marks    DoB            PRN   Div   Address\n");
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s            |  ", student[i].name);
        printf("%d    |  ", student[i].marks);
        printf("%02d/%02d/%04d| ", student[i].day, student[i].month, student[i].year);
        printf("%d  |  ", student[i].prn);
         printf("%d |  ", student[i].div);
        printf("%s\n", student[i].address);
    }
 }



void reader(struct STUDENT student[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", student[i].name);
        printf("Marks: ");
        scanf("%d", &student[i].marks);
        printf("Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &student[i].day, &student[i].month, &student[i].year);
        printf("PRN: ");
        scanf("%d", &student[i].prn);
        printf("Division: ");
        scanf("%d", &student[i].div);
         printf("Enter address: ");
        scanf(" %[^\n]", student[i].address);
    }
     printf("\nDetails of Students:\n");
    displayStudent(student ,n);

}

void bubbleprn(struct STUDENT student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (student[j].prn > student[j + 1].prn) {
                struct STUDENT temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
     printf("\nStudents prn asd:\n");
    displayStudent(student ,n);
}

void bubblediv(struct STUDENT student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (student[j].div > student[j + 1].div) {
                struct STUDENT temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
     printf("\nStudents marks asd:\n");
    displayStudent(student ,n);
}

void bubblename(struct STUDENT student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(student[j].name, student[j + 1].name) < 0) {
                struct STUDENT temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    printf("\nStudent names asd:\n");
    displayStudent(student ,n);
}

void selectionmark(struct STUDENT student[], int n) {
    for (int i = 0; i < n - 2; i++) {
        int rep = i;
        for (int j = i + 1; j < n; j++) {
            if (student[j].marks > student[rep].marks) {
                rep = j;
            }
        }
        if (rep != i) {
            struct STUDENT temp = student[i];
            student[i] = student[rep];
            student[rep] = temp;
        }
    }
    printf("\nStudents marks dsn:\n");
    displayStudent(student ,n);
}

void insertionname(struct STUDENT student[], int n) {
    for (int i = 1; i < n; i++) {
        struct STUDENT key = student[i];
        int j = i - 1;
        while (j >= 0 && strcmp(student[j].name, key.name) < 0) {
            student[j + 1] = student[j];
            j--;
        }
        student[j + 1] = key;
    }
    printf("\nStudents names dsn:\n");
    displayStudent(student ,n);    
}

 int main (){

    int n,option;
    char conin ,conout;

    printf("Enter the number of Students: ");
    scanf("%d", &n);

    struct STUDENT student[n];

    reader(student, n);
do {
    printf("\n\nwhich sording do you want?\n");
    printf("1. Sort by bubble PRN (ascending)\n");
    printf("2. Sort by bubble Division (ascending)\n");
    printf("3. Sort by bubble Name (ascending)\n");
    printf("4. Sort by selection Marks (descending)\n");
    printf("5. Sort by insertion Name (descending)\n");
    printf("Enter your c1: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
           bubbleprn(student , n);
        break;

        case 2:
           bubblediv(student , n);
        break;

        case 3:
           bubblename(student , n);
        break;

        case 4:
           selectionmark(student , n);
        break;

        case 5:
          insertionname(student , n);
        break;

    default:
         printf("INVALID INPUT (╬▔皿▔)╯");
        break;
    }
   
    printf("Do you want to countinue sorting?(y/n)");
    scanf(" %c",&conin);
    conin = toupper(conin);
    } while (conin != 'N');
    

    return 0;
}

