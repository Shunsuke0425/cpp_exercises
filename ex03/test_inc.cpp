#include <cassert>
#include "inc.h"
int main(void) {
    double a = 1.0;
    inc(a); 
    assert(a == 2.0);
    inc(a); 
    assert(a == 3.0);

    a = 1.0;
    inc(&a); 
    assert(a == 2.0);
    inc(&a); 
    assert(a == 3.0);
    return 0;
}