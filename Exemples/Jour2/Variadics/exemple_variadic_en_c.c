#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double max( int nb_vals, double x0, ... ) {
    int index;
    va_list args;
    double valmax = x0;
    va_start(args, x0);
    for (index=0; index<nb_vals-1; ++index) {
        double xi = va_arg(args,double);
        valmax = (valmax < xi ? xi : valmax);
    }
    va_end(args);
    return valmax;
}

int main() {
    double val = max(6, -1., 3., 4., 2., -7., 0.);
    printf("La valeur maximale trouvee est : %lg\n", val);
    return EXIT_SUCCESS;
}