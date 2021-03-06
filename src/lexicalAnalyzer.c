/*
   ! Lexical-Analyzer
   * It receives a text document as input and produces an output composed of tokens.
   @authors galexbh | jmanzanaresm | Yillian88 | yensy95 | angelgonzalardon
   @version 1.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    //Declaracioness
    char * tipos_datos[][3]={ "entero", "decimal", "cadena" };
    char palabras_reservadas[][11]={ "definir", "hasta", "mientras", "repetir", "si", "hacer", "finsi", "sino", "leer", "imprimir", "cursor" };
    char operador_relacional[][6]={ "<", ">", "==", "!=", "<=", ">=" };

    int estado=0; //ESTADO INICIAL
    int contador=0;
    char cadena[20]="", res[30]="<Tkn_";

    //Respuesta a Imprimir en Array
    char imprimir[1000]="";

    printf("--------------ANALIZADOR LEXICO EN C--------------\n");
    //Abriendo Archivo Externo
    FILE *ptfile; 
    char caracter;

    ptfile=fopen("input_file.mem", "r"); // Abrir el archivo en modo lectura.
    if (ptfile==NULL) {
        fputs("error", stderr);
        exit(1);
    }
    while ((caracter=fgetc(ptfile))!=EOF) { //Mientras caracter sea distinto al final del archivo

        if (caracter != ' ') {
            cadena[contador]=caracter;
            contador++;

            //FILTRAR letra(Mayuscula o Minuscula) o numero 
            if (caracter >= 'a' && caracter <= 'z') {
                caracter='m'; //Minusculas
            }
            else if (caracter >= 'A' && caracter <= 'Z') {
                caracter='M'; //Mayusculas
            }
            else if (caracter >= '0' && caracter <= '9') {
                caracter='n'; //Estado de Numero entrante
            }
        }
    else {
        strcpy(res, "<Tkn_"); //char *strcpy ( char *destino, const char *origen );
                              
        if (estado==5) {
            caracter='v'; //Estado de Variable
        }            
        else if (estado!=6) {
                //Busqueda de Palabra reservada
                for (int i=0;i<=(sizeof(palabras_reservadas)/sizeof(palabras_reservadas[0]));i++) {
                    if (strcmp(cadena, palabras_reservadas[i])==0)
                    {
                        caracter='p'; // Estado palabras reservadas
                        strcat(res, cadena); //añade una cadena a otra pasándole dos punteros a los bloques de memoria reservados. 
                        strcat(res, ">\n");
                    }
                }
                memset(cadena, 0, sizeof cadena); //C *memset(void *str, int c, size_t n)
                                        //copia el caracter 0 (NULL - ASCII) (un char sin signo) a los primeros n caracteres de la cadena.
                contador=0;
            }
            if (estado==6) {
                for (int i=0;i<=(sizeof(operador_relacional)/sizeof(operador_relacional[0]));i++) {
                    if (strcmp(cadena, operador_relacional[i])==0) { //Compara la cadena con el operador relacional
                        caracter='o';
                        strcat(res, "operador_relacional");
                        strcat(res, ">\n");
                    }
                }
                memset(cadena, 0, sizeof cadena);
                contador=0;
            }
            if (estado==3) {
                caracter='u'; //Estado de números
            }
        }

        /*Estados o Patrones*/

   /*Casos*/

        switch (caracter) {

        case 'n':
            if (estado==1 || estado==2 || estado==0)
            {
                estado=3;  //Estado de Numero entrante
            }
            break;
        case 'm':          //Minusculas
            if (estado==0||estado==1)
            {
                estado=1;
            }
            if (estado==2) {
                estado=5;
            }
            break;
        case 'M':          //Mayusculas
            if (estado==0||estado==70)
            {
                estado=2;
            }
            break;
        case '.':
            if (estado==3 ||estado==1)
            {
                estado=4;  //estado Punto Decimal
            }
            break;
        case 'p':
            if (estado==1||estado==0)
            {
                strcat(imprimir, res); //Estado palabras reservadas
                estado=0;
            }
            break;
        case 'v':
            if (estado==5) {
                strcat(res, "variable>\n");
                strcat(imprimir, res);
                memset(cadena, 0, sizeof cadena);
                contador=0;
                estado=0;
            }
            break;
        case 'o':
            if (estado==6) {
                strcat(imprimir, res);
                memset(cadena, 0, sizeof cadena);
                contador=0;
                estado=0;
            }
        case 'l':
            if (estado==6) {
                strcat(imprimir, res);
                memset(cadena, 0, sizeof cadena);
                contador=0;
                estado=0;
            }
            break;
        case 'u':
            strcat(imprimir, "<Tkn_numero>\n");
            memset(cadena, 0, sizeof cadena);
            contador=0;
            estado=0;
            break;
        case '{':
            if (estado==0) {
                strcat(imprimir, "<Tkn_inicio_bloque>\n");
            }
            break;
        case '}':
            if (estado==0) {
                strcat(imprimir, "<Tkn_fin_bloque>\n");
            }
            break;
        case '(':
            if (estado==0) {
                strcat(imprimir, "<Tkn_inicio_parentesis>\n");
            }
            break;
        case ')':
            if (estado==0) {
                strcat(imprimir, "<Tkn_fin_parentesis>\n");
            }
            break;
        case '"':
            if (estado==0) {
                strcat(imprimir, "<Tkn_cadena>\n");
            }
            break;
        default:
            estado=6;
            break;
        }
        
    } // Repetir iteración

    /* Imprimir por consola */

    printf("%s", imprimir);
    fclose(ptfile); // Cerramos el archivo de modo lectura
    ptfile=NULL; // Limpiar buffer

    /* Abrir archivo en modo escritura */

    ptfile=fopen("output.mem", "w"); 
    fwrite(imprimir, 1, strlen(imprimir), ptfile);
    fclose(ptfile);

    return 0;
}
