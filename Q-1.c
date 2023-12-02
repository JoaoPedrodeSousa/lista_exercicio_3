#include <stdio.h>
#include <math.h>


int converterNumRomano(char numeroRomano) {
    if (numeroRomano == 'I'){
        return 1;
    }
    else if (numeroRomano == 'V'){
        return 5;
    }
    else if (numeroRomano == 'X'){
        return 10;
    }
    else if (numeroRomano == 'L'){
        return 50;
    }
    else if (numeroRomano == 'C'){
        return 100;
    }
    else if (numeroRomano == 'D'){
        return 500;
    }
    else if (numeroRomano == 'M'){
        return 1000;
    };
    
    return 0;
}

int converterNumRomanoParaDecimal(char *romano) {
    int resultado = 0;

    for (int i = 0; romano[i] != '\0'; i++) {
        if (converterNumRomano(romano[i]) < converterNumRomano(romano[i + 1])) {
            resultado -= converterNumRomano(romano[i]);
        } 
        else {
            resultado += converterNumRomano(romano[i]);
        }
    }

    return resultado;
}

int converterDecimalParaBinario(int decimal) {
    int binario = 0;
    int peso = 1;

    if (decimal == 0) {
        return 0;
    }

    while (decimal > 0) {
        binario += (decimal % 2) * peso;
        decimal = decimal / 2;
        peso *= 10;
    }
    
    return binario;
}

int converterBinarioParaHexadecimal(int binario) {
    int hexadecimal = 0, resto, i = 0;

    while (binario != 0) {
        resto = binario % 10;
        hexadecimal += resto * pow(2, i);
        binario /= 10;
        i++;
    }

    return hexadecimal;
}

int main() {
    char numeroRomano[20];
    
    scanf("%s", numeroRomano);

    int decimal = converterNumRomanoParaDecimal(numeroRomano);
    int binario = converterDecimalParaBinario(decimal);
    int hexadecimal = converterBinarioParaHexadecimal(binario);

    printf("%s na base 2: %d\n", numeroRomano,binario);
    printf("%s na base 10: %d\n",numeroRomano,decimal);
    printf("%s na base 16: %x\n",numeroRomano,hexadecimal);
    
    return 0;
}