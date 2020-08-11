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
                break;
            case 'm'://Minusculas
                if(estado==0||estado==1) 
                {
                estado=1;  
                }
                if(estado==2){
                    estado=5;
                }
                break;
            case 'M'://Mayusculas
                if(estado==0||estado==70) 
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
                if(estado==1||estado==0)
                {
                    strcat(imprimir,res);
                    estado=0;
                }
                break;
            case 'v':
                if(estado==5){
                    strcat(res,"variable>");
                    strcat(imprimir,res);
                    memset(cadena,0,sizeof cadena);
                    contador=0;
                    estado=0;
                }
                break;
            case 'o':
                if(estado==6){
                    strcat(imprimir,res);
                    memset(cadena,0,sizeof cadena);
                    contador=0;
                    estado=0;
                }
            case 'l':
                if(estado==6){
                    strcat(imprimir,res);
                    memset(cadena,0,sizeof cadena);
                    contador=0;
                    estado=0;
                }
                break;
            case 'u':
                strcat(imprimir,"<Tkn_numero>");
                memset(cadena,0,sizeof cadena);
                contador=0;
                estado=0;
                break;
            case '{':
                if(estado==0){
                    strcat(imprimir,"<Tkn_inicio_bloque>");
                }
            case '}':
                if(estado==0){
                    strcat(imprimir,"<Tkn_fin_bloque>");
                }
                break;
            case '(':
                if(estado==0){
                    strcat(imprimir,"<Tkn_inicio_parentesis>");
                }
                break;
            case ')':
                if(estado==0){
                    strcat(imprimir,"<Tkn_fin_parentesis>");
                }
                break;
            case '"':
                if(estado==0){
                    strcat(imprimir,"<Tkn_cadena>");
                }
            default:
                estado=6;
                break;
        }
        //FIN DEL SWITCH
        //DECISIONES
        
    }

    printf("%s",imprimir);
    fclose(ptfile);
    ptfile=NULL;


    ptfile=fopen("archivo_salida.mem","w");
    fwrite(imprimir,1,strlen(imprimir) ,ptfile);
    fclose(ptfile);
    return 0;
}
