#include "wuerfel.h"
#include "quadrat.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double k;
    if (scanf("%lf", &k) < 1)
    {
	fprintf(stderr, "Falsche Parameter Eingabe!\n");
	return 1;
    }

    double f = oberflaeche(k);
    double v = volumen(k);

    printf("Kantenlaenge: %f\nOberflaeche %f\nVoluemen %f\n", k, f, v);

    return 0;
}
