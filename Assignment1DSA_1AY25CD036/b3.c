#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
    polynomial c;
    int i, max;

    max = (a.degree > b.degree) ? a.degree : b.degree;
    c.degree = max;

    for (i = 0; i <= max; i++) {
        float x = (i >= max - a.degree) ?
                  a.coef[i - (max - a.degree)] : 0;
        float y = (i >= max - b.degree) ?
                  b.coef[i - (max - b.degree)] : 0;

        c.coef[i] = x + y;
    }

    while (c.degree > 0 && c.coef[0] == 0) {
        for (i = 0; i < c.degree; i++)
            c.coef[i] = c.coef[i + 1];
        c.degree--;
    }

    return c;
}

void display(polynomial p) {
    int i, exp, first = 1;

    for (i = 0; i <= p.degree; i++) {
        exp = p.degree - i;

        if (p.coef[i] == 0)
            continue;

        if (!first)
            printf(p.coef[i] > 0 ? " + " : " - ");
        else if (p.coef[i] < 0)
            printf("-");

        float value = (p.coef[i] < 0) ? -p.coef[i] : p.coef[i];

        if (exp == 0 || value != 1)
            printf("%g", value);

        if (exp > 0) {
            printf("x");
            if (exp > 1)
                printf("^%d", exp);
        }

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main() {
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    c = add(a, b);

    printf("First polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    printf("Sum: ");
    display(c);

    return 0;
}
