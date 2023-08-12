### Ejercicios de grafos

Solución a los 5 problemas de algoritmos de grafos propuestos para la semana #1 de ISIS4208.

Para cada problema enumerado del 1 al 5 existe una carpeta que contiene:

    - Código fuente en c++ con extension .cpp, debidamente documentado, donde se explica como funciona la entrada y salida de los datos.
    - .in: Archivo que contiene un ejemplo de la entrada para el algoritmo
    - .out: Archivo que contiene la salida del algoritmo para la entrada de los datos en el archivo .in
    - .exe: Ejecutable del código fuente

Para ejecutar el código se debe de configurar el compilador GCC. Ver https://code.visualstudio.com/docs/cpp/config-mingw. 
Y luego seguir los siguientes pasos

1. Opcionalmente compilar el código y generar un ejecutable nuevo.

    Ejemplo:
        g++ 1.cpp -o 1.exe

2. Ejecutar el archivo .exe usando redirección de archivos.

    Ejemplo: 
        1.exe < 1.in

    Notar que powershell no soporta el operador <, por lo que se recomienda usar el CMD en Windows.

    Opcionalmente se puede indicar un archivo de salida, de lo contrario la salida del algoritmo aparecerá en la terminal.

    Ejemplo:
        1.exe > 1.in > 1.out