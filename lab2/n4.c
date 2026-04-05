#include <stdio.h>
#include <string.h>
struct Dat
{
    float dlina;
    float visota;
};

float area(float a,float b){
    return a*b;

}
float perimetr(float a,float b){
    return 2*(a+b);
}
int main(){
    struct Dat rect = {10.5, 5};
    printf("S=%f \n",area(rect.dlina,rect.visota));
    printf("P=%f",perimetr(rect.dlina,rect.visota));

    return 0;
}