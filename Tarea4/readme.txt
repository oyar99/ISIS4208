### Huffman y Shannon-Fano

Implementación de códigos de Shannon-Fano y Huffman para comprimir texto.

Las implementaciones fueron probadas con Python 3.9. Por lo que se recomienda
instalar esa version para ejecutar los scripts. Ver: https://www.python.org/downloads/release/python-390/

Junto a este readme, se encuentra el código fuente en formato .py, y un archivo input.txt con ejemplo del texto a comprimir.

## Como ejecutar el programa

1. Validar que Python y la version correspondiente este instalado correctamente ejecutando el siguiente comando

    python --version

2. Ejecutar el código de Shannon-Fano. Para el texto de entrada, se puede usar cualquier otra ruta de un archivo de texto que use codificación UTF-8

    python .\Tarea4ShannonFano.py "input.txt"

3. Ejecutar el código de Huffman. Para el texto de entrada, se puede usar cualquier otra ruta de un archivo de texto que use codificación UTF-8

    python .\Tarea4Huffman.py "input.txt"

La salida de los programas reporta la codificación a usar para el texto/alfabeto dado teniendo en cuenta la frecuencia de cada
carácter. De igual manera se reporta el numero de bits esperado, la entropía en el peor de los casos, y el numero total de bits necesarios para guardar el texto dado.