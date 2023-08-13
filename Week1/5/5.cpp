#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>
#include <assert.h>

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
 * Se asume que el mapa de la ciudad no esta desconectado.
 * 
 * Para el problema cada punto de la ciudad estará enumerado del 1 al N.
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
 * 2
 * 4 4
 * 1 2 3
 * 2 3 4
 * 3 4 6
 * 4 1 1
 * 4 5
 * 1 2 3
 * 2 3 2
 * 3 1 5
 * 1 4 3
 * 3 4 6
 * 
 * En este ejemplo tenemos dos instancias del problema.
 * 
 * La salida esperada para esta entrada seria:
 * 
 * 3
 * 1 4
 * 1 2
 * 2 3
 * 8
 * 3
 * 1 2
 * 2 3
 * 1 4
 * 8
 * 
 * Las calles que se deben convertir en doble via se pueden retornar en cualquier orden.
 * 
*/

void solve();

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) solve();
}

void solve() {
    int N, R; cin >> N >> R;

    /* 
     * Lista adyacente para representar con un grafo el mapa de la ciudad.

     * Observación: Aunque el problema original sugiere que tratamos con un grafo
     * dirigido, data la naturaleza del problema vamos a tratarlo como un grafo
     * no dirigido con pesos. Es posible hacer esta abstracción pues el problema nos pide
     * que se pueda transitar de cualquier punto a cualquier punto de la ciudad por dobles vias, 
     * asi que vamos a ignorar la dirección de las vias y simplemente buscar las aristas que generan un MST (Minimum Spanning Tree).
    */
    vector<unordered_map<int, int>> adj(N + 1, unordered_map<int, int>());

    for (int i = 0; i < R; ++i) {
        int u, v; cin >> u >> v;
        int c; cin >> c;

        // UV es un candidato a ser una via de doble sentido - cuyo costo de conversion es C
        // Grafo no dirigido
        adj[u][v] = c;
        adj[v][u] = c;
    }

    // Comparador para determinar entre dos aristas UV y VW cual tiene mayor costo asociado a convertir la via en doble via
    auto cmp = [](const pair<pair<int, int>, int>& uv, const pair<pair<int, int>, int>& vw) {
        return uv.second > vw.second;
    };

    // Priority Queue - Binary Heap usado para poder retirar la arista menos costosa, al tiempo que podemos hacer inserciones nuevas de aristas
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cmp)> pq(cmp);

    vector<pair<int, int>> edges;
    edges.reserve(N - 1);

    unordered_set<int> vertices;
    
    int u = 1;
    int w = 0;

    vertices.insert(u);

    // Un árbol tiene N-1 aristas
    while (edges.size() < N - 1) {
        // Por cada arista UV - la insertamos en el Priority Queue
        for (const auto& edge: adj[u]) {
            if (vertices.count(edge.first) <= 0) {
                pq.push({ make_pair(u, edge.first), edge.second });
            }
        }

        // Sacamos del Priority Queue la arista de menor peso que conecta un vértice que aun no hace parte del árbol
        while (vertices.count(pq.top().first.second) > 0) {
            pq.pop();
        }

        auto edge = pq.top();
        pq.pop();

        // Incluimos esta arista en la respuesta
        edges.push_back(edge.first);
        // Incluimos el vértice V de la arista UV en los vertices que ya hacen parte del árbol
        vertices.insert(edge.first.second);

        w += edge.second;

        u = edge.first.second;
    }

    assert(edges.size() == N - 1);

    cout << N - 1 << endl;

    for (const auto& edge: edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    cout << w << endl;
}