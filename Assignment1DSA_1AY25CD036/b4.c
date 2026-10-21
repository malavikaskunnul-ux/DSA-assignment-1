#include <stdio.h>

typedef struct {
    int row, col, value;
} term;

void print_triples(term a[]) {
    int i;

    printf("Row\tCol\tValue\n");
    for (i = 0; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n",
               a[i].row, a[i].col, a[i].value);
}

void fast_transpose(term a[], term b[]) {
    int row_terms[100] = {0};
    int starting_pos[100];
    int i, j, num_cols = a[0].col;
    int num_terms = a[0].value;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    for (i = 1; i <= num_terms; i++)
        row_terms[a[i].col]++;

    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++)
        starting_pos[i] =
            starting_pos[i - 1] + row_terms[i - 1];

    printf("\nrow_terms[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", row_terms[i]);

    printf("\nstarting_pos[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", starting_pos[i]);

    printf("\n");

    for (i = 1; i <= num_terms; i++) {
        j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

int main() {
    int rows, cols, i, j, count = 0, value;
    term a[100], b[100];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    a[0].row = rows;
    a[0].col = cols;

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &value);

            if (value != 0) {
                count++;
                a[count].row = i;
                a[count].col = j;
                a[count].value = value;
            }
        }
    }

    a[0].value = count;

    printf("\nOriginal triples:\n");
    print_triples(a);

    fast_transpose(a, b);

    printf("\nTransposed triples:\n");
    print_triples(b);

    printf("\nTriples are in row-major order.\n");

    return 0;
}
