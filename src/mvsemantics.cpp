#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
int *ptr = new int[10,0];
int *ptr1 = new int [10];
ptr[2]=5;
std::copy(ptr,ptr+5,ptr1);

cout<<ptr1[2];

return 1;
}
