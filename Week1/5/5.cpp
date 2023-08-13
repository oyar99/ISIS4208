#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * Una ciudad se diseño de tal modo que todas sus calles fueran de una sola vía. Con el paso del tiempo la cantidad de
 * habitantes de la ciudad creció y esto produjo grandes trancones en algunas de las vias debido a algunos desvíos
 * innecesarios que tienen que tomar los habitantes de la ciudad para poder llegar a sus trabajos. Por lo tanto, el alcalde
 * tomó la decisión de ampliar algunas vias para que puedan convertirse en doble via. Dado el mapa de la ciudad y el
 * costo de convertir cada via actual en doble via, determinar qué vias se deben convertir, de modo que se pueda transitar
 * de cualquier punto a cualquier punto de la ciudad por dobles vias y que el costo de la conversión sea el mínimo posible.
 * 
 * Entrada:
 * 
 * Para el problema cada punto de la ciudad estará enumerada del 1 al N.
 * 
 * La primera linea consta de un numero T indicando la cantidad de instancias del problema.
 * Luego por cada instancia, se tiene una primera linea con un numero N y R. Donde N indica el numero de puntos de la ciudad, 
 * y R indica el numero de calles. Luego, siguen R lineas donde cada una consta de 3 números U, V, y C,
 * lo que representa la calle de único sentido (U, V), y se indica que el costo de hacer (V, U) seria C.
 * 
 * Salida:
 * 
 * Por cada instancia del problema se debe retornar el numero de calles P que se deben convertir en doble via, seguido de P lineas,
 * donde cada una tiene la calle que seria doble via (U, V). Finalmente, se debe retornar otra linea con el costo de conversion, el cual
 * debe ser el mínimo posible siguiendo las especificaciones del problema.
 * 
 * Ejemplo:
 * 
 * 
 * 
*/

string solve();

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) cout << solve() << endl;
}

string solve() {
    int N, R; cin >> N >> R;

    
}