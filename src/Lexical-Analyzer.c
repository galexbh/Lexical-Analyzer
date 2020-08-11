#include <stdio.h> //entrada de texto libreria
#include <stdlib.h>

char palabrasReservadas[][50] ={ "leer", "imprimir", "cursor", "mientras", "repetir", "si", "sino", "hasta", "hacer"
, "finsi", "definir" };

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
                if (ch>='a'&&ch<='z') {
                    temp=2;
                    char tokens[]="<Tkn_minuscula>\n";
                    printf("%s", tokens);
                }
                else {
                    if (ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}') {//--
                        char tokens[]="<Tkn_caracter>\n";
                        printf("%s", tokens);
                    }
                    else {
                        if (ch>='0'&&ch<='9') {
                            temp=3;
                            char tokens[]="<Tkn_digito>\n";
                            printf("%s", tokens);
                        }
                        else {
                            if (ch=='+'||ch=='-'||ch=='*'||ch=='/') {
                                temp=4;
                                char tokens[]="<Tkn_operador>\n";
                                printf("%s", tokens);
                            }
                            else {
                                if (ch=='<'||ch=='>'||ch=='<'&&'='||ch=='>'&&'='||ch=='!'&&'='||ch=='='&&'=') {
                                    char tokens[]="<Tkn_operador_relacion>\n";
                                    printf("%s", tokens);
                                }
                                else {
                                    if (ch=='.') {
                                        char tokens[]="<Tkn_punto_decimal>\n";
                                        printf("%s", tokens);
                                    }
                                    else {
                                        if (ch==' ') {
                                            char tokens[]="       ";
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
                            }
                        }
                    }
                }

            }

        }
        fclose(stdout);
        fclose(pf);
    }
    return 0;

}