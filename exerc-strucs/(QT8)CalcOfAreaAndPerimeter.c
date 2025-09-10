#include <stdio.h>

typedef  struct {
    float base;
    float height;
}Rectangle;

void area(float base, float height) {
    float area=base * height;
    printf("base * height: %.2f * %.2f\n",base,height);
    printf("total area is: %.2f\n",area);
}
void perimeter(float base, float height) {
    float perim = 2 * (base + height);
    printf("Perimeter is 2*(base+height): 2*(%.2f+%.2f)\n",base,height);
    printf("total perimeter is: %.2f",perim);
}
int main() {
    Rectangle r;

    printf("Enter the base value:");
    scanf("%f",&r.base);
    printf("Enter the height value:");
    scanf("%f",&r.height);
    area(r.base,r.height);
    perimeter(r.base,r.height);

    return 0;
}