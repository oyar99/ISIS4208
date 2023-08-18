### Edmonds-Karp

Implementación de Edmonds-Karp para determinar cuanta agua se puede transportar en una
red de flujo desde un nodo fuente a un nodo destino.

C++ es un lenguaje multiplataforma en el sentido que se puede distribuir el código
fuente y compilar en distintos sistemas. Aunque los binarios no necesariamente se puedan
distribuir y ejecutar de la misma manera.

Las siguientes instrucciones explican como configurar el compilador GCC en distintas plataformas:

    - Windows: https://code.visualstudio.com/docs/cpp/config-mingw.
    - Linux: https://code.visualstudio.com/docs/cpp/config-linux
    - Mac: https://code.visualstudio.com/docs/cpp/config-clang-mac

Junto a este readme, se encuentra el código fuente en formato .cpp. Varios archivos X.in con distintos
ejemplos de grafos de entrada. Y varios archivo X.out que corresponden a la salida de X.in donde X es
un numero que representa una instancia del problema.

Adicionalmente, se adjunta un .exe que se puede distribuir en sistemas Windows.

## Como ejecutar el programa

1. Ejecutar el ejecutable (ejemplo: .exe) usando redirección de archivos.

    Ejemplo:
        1.exe < 1.in

    Notar que powershell no soporta el operador <, por lo que se recomienda usar el CMD en Windows.

    Opcionalmente se puede indicar un archivo de salida, de lo contrario la salida del algoritmo aparecerá en la terminal.

    Ejemplo:
        1.exe < 1.in > 1.out