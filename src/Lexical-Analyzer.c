#include <stdio.h> //entrada de texto libreria
#include <stdlib.h>

char palabrasReservadas[][50] ={ "leer", "imprimir", "cursor", "mientras", "repetir", "si", "sino", "hasta", "hacer", "finsi", "definir" };

int main() {

    FILE *pf;
    char arreglo[100]; // lectura de datos
    char ch;
    int temp;
    int indice = -1;
    int i;
    int Estado=0;
    int longitudArreglo = sizeof(palabrasReservadas)/sizeof(palabrasReservadas[0]);

    pf=fopen("archivoEntrada.txt", "r");

    if (pf==NULL) {
        printf("Error...archivo no encontrado\n");
        exit(1);
    }
    else
    {
        freopen("archivoSalida.txt", "w", stdout);
        printf("Los tokens encontrados en el texto son:\n");

        while ((ch=fgetc(pf))!=EOF) {
            if (ch>='A'&&ch<='Z') {
                temp=1;
                char tokens[]="<Tkn_mayuscula>\n";
                printf("%s", tokens);
            }
            else {
                while (!feof(pf)) {
                    fgets(arreglo, 100, pf);
                    for (i=0; i< longitudArreglo; i++) {
                        if (strcmp(palabrasReservadas[i], arreglo)== 0) {
                            printf("<Tkn_palabra_reservada>\n");
                            break;
                        }
                        else {
                            printf("Error");
                            break;

                        }
                    }
                }
            }
        }
    }
    return 0;
}