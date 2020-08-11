/*
   ! Lexical-Analyzer
   * It receives a text document as input and produces an output composed of tokens.
   @authors galexbh | jmanzanaresm | Yillian88 | yensy95 | angelgonzalardon
   @version 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    
    //Declaracioness
    char * tipos_datos[][3]={"entero","decimal","cadena"};
    char palabras_reservadas[][11]={"definir","hasta","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
	char operador_relacional[][6]={"<",">","==","!=","<=",">="};

    int estado=0; //ESTADO INICIAL
    int contador=0;
    char cadena[20]="",res[30]="<Tkn_";
    
    //Respuesta a Imprimir en Array
    char imprimir[1000]="";
    
    printf("--------------ANALIZADOR LEXICO EN C--------------\n");
    //Abriendo Archivo Externo
    FILE *ptfile;
    char caracter;

    printf("%s",imprimir);
    fclose(ptfile);
    ptfile=NULL;

    ptfile=fopen("input_file.mem","r");
    if(ptfile==NULL){
        fputs("error",stderr);
        exit(1);
    }

   ///Estados o Patrones

    

    ///Casos
        switch (caracter){
            case 'n':
            if (estado==1 || estado==2 || estado==0)
            {
                estado=3;  //Estado de Numero entrante
            }

    ptfile=fopen("output_file.mem","w");
    fwrite(imprimir,1,strlen(imprimir) ,ptfile);
    fclose(ptfile);
    return 0;
}