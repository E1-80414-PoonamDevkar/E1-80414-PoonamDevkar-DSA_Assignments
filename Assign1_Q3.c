#include <stdio.h>
#include <string.h>

struct Student 
{
    int rollno;
    char name[50];
    int marks;
};

// Function to perform bubble sort on the array of students
void bubbleSort(struct Student students[], int n);


int main() 
{
    struct Student students[10] =
     {
        {8001, "Poonam", 89},
        {8002, "Komal", 88},
        {8003, "Anu", 87},
        {8004, "Pranali", 70},
        {8005, "Pranita", 65},
        {8006, "Archana", 84},
        {8007, "Bhagya", 57},
        {8008, "Rutuja", 88},
        {8009, "Mira", 95},
        {8010, "Vrunda", 90}
    };

    int n = 10;

    printf("Unsorted List of Students:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Roll No: %d, Name: %s, Marks: %d\n", students[i].rollno, students[i].name, students[i].marks);
    }

    // Sort the students by marks
    bubbleSort(students, n);

    printf("\nSorted List of Students by Marks:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Roll No: %d, Name: %s, Marks: %d\n", students[i].rollno, students[i].name, students[i].marks);
    }

    return 0;
}

void bubbleSort(struct Student students[], int n)
{
    struct Student temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) 
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (students[j].marks > students[j + 1].marks) 
            {
                // Swap the two students
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == 0) 
        {
            break;
        }
    }
}
