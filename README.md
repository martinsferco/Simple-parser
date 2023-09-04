# Simple-parser
En este Trabajo Práctico final de la materia R212 - Estructura de Datos y Algoritmos I, se nos propuso realizar un analizador
sintáctico o parser. \
Dado un archivo con lı́neas de caracteres del abecedario (pudiendo
ser minúsculas o mayúsculas, o una mezcla entre ellas), se encarga de colocar espacios
de manera que la frase resultante esté formada por palabras aceptadas. Dichas palabras
aceptadas se encuentran en un diccionario de palabras válidas. Además, el analizador
sintáctico se encargará de devolvernos una separación de palabras que maximice en cada
paso, el tamaño de las mismas.
En el caso de que nos encontremos en un punto donde no es posible formar ninguna
palabra válida, se saltea uno o más caracteres (que ahora consideraremos como errores)
para continuar con el análisis del resto de la frase.

---

Los comandos que daremos a continuación, debemos ejecutarlos en el directorio raíz del proyecto. 

## Compilacion del programa

Para compilar el programa:

    make

Si se quiere compilar con opciones de depurado

    make debug=yes

Si se quieren compilar los test

    make test

Para eliminar todos los archivos objeto generados por la compilación

    make clean

## Ejecucion del programa
Para ejecutar el programa de parseo:

    ./parser diccionario entrada resultado

Donde:
1. **diccionario**: ruta del archivo *.txt* que contiene las palabras validas. 
2. **entrada**: ruta del archivo que vamos a parsear.
3. **resultado**: ruta del archivo donde vamos a guardar el resultado del parseo.

Un ejemplo sería:

    ./parser dictionaries/small_dictionary.txt testdata/prueba.txt result.txt
  
Para ejecutar los test del programa, simplemente ejecutamos:

    ./test

---