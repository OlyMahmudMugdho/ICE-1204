#include <stdio.h>

float get_gpa(float mark)
{
    if (mark < 40)
    {
        return 0;
    }
    if (mark >= 40 && mark < 45)
    {
        return 2.00;
    }
    if (mark >= 45 && mark < 50)
    {
        return 2.25;
    }
    if (mark >= 50 && mark < 55)
    {
        return 2.50;
    }
    if (mark >= 55 && mark < 60)
    {
        return 2.75;
    }
    if (mark >= 60 && mark < 65)
    {
        return 3.00;
    }
    if (mark >= 65 && mark < 70)
    {
        return 3.25;
    }
    if (mark >= 70 && mark < 75)
    {
        return 3.50;
    }
    if (mark >= 75 && mark < 80)
    {
        return 3.75;
    }
    if (mark >= 80)
    {
        return 4.00;
    }
}

int main()
{
    int students_nums;
    int subject_nums;
    FILE *fptr;
    fptr = fopen("students.txt", "w");
    FILE *fptr_new;
    fptr_new = fopen("output.txt", "w+");

    printf("Enter the number of students : \n");
    scanf("%d", &students_nums);

    printf("Enter the number of subjects : \n");
    scanf("%d", &subject_nums);

    struct Student
    {
        char name[50];
        int roll;
        float marks[subject_nums];
        float total_marks;
        float gpa;
        float average;
    };

    struct Student student[students_nums];

    for (int i = 0; i < students_nums; i++)
    {
        float total = 0;

        printf("Enter student-%d name : \n", i + 1);
        
        scanf("%s", &student[i].name);

        printf("Enter the Roll of %s : \n", student[i].name);
        scanf("%d", &student[i].roll);

        for (int j = 0; j < subject_nums; j++)
        {
            printf("Enter the mark of subject-%d : \n", j + 1);
            scanf("%f", &student[i].marks[j]);
            total += student[i].marks[j];
        }

        student[i].total_marks = total;
        student[i].average = student[i].total_marks / subject_nums;
        student[i].gpa = get_gpa(student[i].average);

        fprintf(fptr, "Name : %s\nRoll : %d\nMarks : ", student[i].name, student[i].roll);

        for (int m = 0; m < subject_nums; m++)
        {
            fprintf(fptr, "%0.2f ", student[i].marks[m]);
        }
        fprintf(fptr_new, "Name : %s\nRoll : %d", student[i].name, student[i].roll);
        fprintf(fptr_new, "\nGPA : %0.2f\n", student[i].gpa);
        printf("\n");
    }

    fclose(fptr);
    fclose(fptr_new);

    FILE *readfptr;
    readfptr = fopen("output.txt","r");

    char c;
    while ((c = getc(readfptr)) != EOF)
    {
        printf("%c", c);
    }

    printf("\n");

    fclose(readfptr);
    return 0;

}
