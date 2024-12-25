#include <stdio.h>

typedef struct
{
    char name[30];
    int age;
    float salary;
} Employee;

int main()
{
    FILE *fp;
    Employee e1 = {"John Doe", 30, 50000.5};

    // Ghi struct vào file
    fp = fopen("employee.dat", "wb");
    // fwrite(&e1, sizeof(Employee), 1, fp);
    Employee employees[3] = {
        {"Alice", 25, 45000},
        {"Bob", 28, 48000},
        {"Charlie", 32, 55000}};
    fwrite(employees, sizeof(Employee), 3, fp);
    fclose(fp);

    // Đọc struct từ file
    Employee e2;
    fp = fopen("employee.dat", "rb");
    //fread(&e2, sizeof(Employee), 1, fp);
    Employee e;
    while (fread(&e, sizeof(Employee), 1, fp))
    {
        printf("Name: %s, Age: %d, Salary: %.2f\n", e.name, e.age, e.salary);
    }

    fclose(fp);

    // In dữ liệu đọc được
    //printf("Name: %s\nAge: %d\nSalary: %.2f\n", e2.name, e2.age, e2.salary);

    return 0;
}
