#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int emp_id;
    enum { FULL_TIME, CONTRACT } type;
    union {
        float salary;
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;
} Employee;

int main() {
    int n, i;
    float total_bill = 0, pay;
    Employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    emp = malloc(n * sizeof(Employee));

    if (emp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter name and employee ID: ");
        scanf("%19s %d",
              (emp + i)->name, &(emp + i)->emp_id);

        printf("Enter type (0-Full Time, 1-Contract): ");
        scanf("%d", (int *)&(emp + i)->type);

        if ((emp + i)->type == FULL_TIME) {
            printf("Enter monthly salary: ");
            scanf("%f", &(emp + i)->pay.salary);
        } else {
            printf("Enter hourly rate and hours worked: ");
            scanf("%f %d",
                  &(emp + i)->pay.contract_info.hourly_rate,
                  &(emp + i)->pay.contract_info.hours_worked);
        }
    }

    printf("\n--- EMPLOYEE PAYSLIPS ---\n");

    for (i = 0; i < n; i++) {
        if ((emp + i)->type == FULL_TIME)
            pay = (emp + i)->pay.salary;
        else
            pay = (emp + i)->pay.contract_info.hourly_rate *
                  (emp + i)->pay.contract_info.hours_worked;

        printf("\nName: %s\n", (emp + i)->name);
        printf("Employee ID: %d\n", (emp + i)->emp_id);
        printf("Total Pay: %.2f\n", pay);

        total_bill += pay;
    }

    printf("\nTotal Salary Bill: %.2f\n", total_bill);

    free(emp);
    return 0;
}
