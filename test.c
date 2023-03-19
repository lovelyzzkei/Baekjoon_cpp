#include <stdio.h>

typedef struct point 
{
    int xPos;
    int yPos;
    struct point* ptr;
} Point;

void SwapPoint(Point* p1, Point* p2)
{
    Point tmp;
    tmp = *p1;
    p1->xPos = p2->xPos;
    p1->yPos = p2->yPos;

    p2->xPos = tmp.xPos;
    p2->yPos = tmp.yPos;
}

int main(void)
{
    Point p1 = {2, 4};
    Point p2 = {5, 7};
    Point p3 = {3, 3};
    Point pos2;

    SwapPoint(&p1, &p2);

    printf("%d %d %d %d\n", p1.xPos, p1.yPos, p2.xPos, p2.yPos);
    

    p1.ptr = &p2;
    p2.ptr = &p3;
    p3.ptr = &p1;

    printf("Connection between [%d, %d] and [%d, %d] \n", p1.xPos, p1.yPos, p1.ptr->xPos, p1.ptr->yPos);

    return 0;
}