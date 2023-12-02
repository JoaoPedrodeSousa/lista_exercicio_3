#include <stdio.h>
#include <math.h>


int main() {
    int numeroMeses;
    double aporte;
    double taxa;

    scanf("%d", &numeroMeses);
    scanf("%lf", &aporte);
    scanf("%lf", &taxa);

    if (numeroMeses < 1 || numeroMeses > 240 || aporte < 1 || aporte > 5000 || taxa < 0.01 || taxa > 0.2) {
        return 1;
    }

    double valorFinal = 0.0;
    for (int i = 1; i <= numeroMeses; i++) {
        valorFinal = ((valorFinal + aporte) * (1.0 + taxa));
        printf("Montante ao fim do mes %d R$ %.2f\n", i, valorFinal);
    }

    return 0;
}