#include <iostream>
#include "mycode.h"
using namespace std;

int main()
{
    matrix m(2);
    matrix n(2);
    matrix c;
    m.display();
    n.display();
    c=m+n;
    //c.display();
    // c=m*n;
    c.display();
    return 0;
}
