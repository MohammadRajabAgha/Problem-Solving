#include<iostream>
using namespace std;
short sum(short a, short z)
{
    return a * z;
}
int main() {

    short* result = new short;//heap

    *result = sum(5, 5);

    printf(" result = %d \n", *result);
    printf(" Address of result (Stack) = %p \n", &result);
    printf(" Heap Address stored in result = %p \n", result);

    delete result;

    return 0;
}