#include "CDummy.h"
#include "cdummy/CDversion.h"
#include <stdio.h>

void hello(void) {
    printf("Hello, World!\n");
}

int do_something() {
    printf("This library is version %d.%d\n", CDUMMY_VERSION_MAJOR, CDUMMY_VERSION_MINOR);
    return 0;
}
