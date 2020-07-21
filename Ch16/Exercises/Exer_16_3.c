#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GET_X(A, R) ((R)*(cos(A)))
#define GET_Y(A, R) ((R)*(sin(A)))
#define PI 3.1415926535

typedef struct {
    double r;
    double A;
} polar_coordinates;

typedef struct {
    double x;
    double y;
} X_Y_coordinates;

X_Y_coordinates* transformation(polar_coordinates *coor);

int main(void)
{
    polar_coordinates* test = (polar_coordinates *)malloc(sizeof(polar_coordinates));
    test->A = PI / 3;
    test->r = 5;
    X_Y_coordinates* result = transformation(test);
    printf("%lf %lf\n", result->x, result->y);

    return 0;
}

X_Y_coordinates* transformation(polar_coordinates *coor)
{
    X_Y_coordinates* result = (X_Y_coordinates *)malloc(sizeof(X_Y_coordinates));
    result->x = GET_X(coor->A, coor->r);
    result->y = GET_Y(coor->A, coor->r);
    return result;
}