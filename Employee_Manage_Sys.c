// Employee Management System By Batch-7
// G-(08,10,29,31,59)
#include <stdio.h>
#include <conio.h>

// Define Employee structure
struct Employee
{
    int id, age;
    char name[50];
    char role[50];
    float salary;
};
// Global array and count
struct Employee emp[100];
int count = 0;

// Function to show all employees
void ShowEmployeesTable()
{
    if (count == 0)
    {
        printf("No Employee records are available:\n");
        return;
    }
    printf("\n:::All employees records:::");
    for (int i = 0; i < count; i++)
    {
        printf("\nEmployee:%d\n", i + 1);
        printf("Id:%d\n", emp[i].id);
        printf("Name:%s\n", emp[i].name);
        printf("Role:%s\n", emp[i].role);
        printf("salary:%2.f\n", emp[i].salary);
    }
}
//Function to Insert New Employee
void InsertNewEmployee()
{
    printf("\n:::Insert New Employee:::\n");
    printf("Enter Id:-");
    scanf("%d", &emp[count].id);
    printf("Enter Name:-");
    scanf("%s", &emp[count].name);
    printf("Enter Age:-");
    scanf("%d", &emp[count].age);
    printf("Enter Role:-");
    scanf("%s", &emp[count].role);
    printf("Enter Salary:-");
    scanf("%f", &emp[count].salary);
    count++;
    printf(":::Employee added successfully:::\n");
}
// void EditEmployeeData(){}

//Function to Remove Employee
void RemoveEmployee()
{
    int id, found = 0;
    printf(":::Remove Employee:::\n");
    printf("Enter employee ID to delete:\n");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (emp[i].id == id)
        {
            found = 1;
            for (int j = i; j < count - 1; j++)
            {
                emp[j] = emp[j + 1];
            }
            count--;
            printf("Employee id %d Deleted successfully:\n", id);
            break;
        }
    }
    if (!found)
    {
        printf("Employee ID not Found!!!\n");
    }
}

//Function to search a Specific Employee's Data
void SearchRecord()
{
    int id, found = 0;
    printf(":::Search Record:::\n");
    printf("Enter Employeee ID to Search Record:");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (emp[i].id == id)
        {
            found = 1;
            printf("\nEmployee:%d\n", i + 1);
            printf("Id:%d\n", emp[i].id);
            printf("Name:%s\n", emp[i].name);
            printf("Role:%s\n", emp[i].role);
            printf("salary:%2.f\n", emp[i].salary);
            break;
        }
    }
    if (!found)
    {
        printf("Employee ID not Found!!!\n");
    }
}

//Main Function
int main()
{
    int choice;
    {
        do
        {
            printf("::::Employee Management System (v1.0)::::\n");
            printf("1.Show Employees table:\n");
            printf("2.Insert New Employee:\n");
            // printf("3.Edit Employee Data:\n");
            printf("4.Remove Employee:\n");
            printf("5.Search Record\n");
            printf("6.Exit:\n");
            printf(":::Select your option from above:::");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                ShowEmployeesTable();
                break;
            case 2:
                InsertNewEmployee();
                break;
            // case 3:
            // EditEmployeeData();
            // break;
            case 4:
                RemoveEmployee();
                break;
            case 5:
                SearchRecord();
                break;
            case 6:
                printf("Exiting program::THANK YOU:\n");
                return 0;
            default:
                printf("Invalid input::Please Try Again!!!\n");
            }
        } while (1);
        return 0;
    }
}