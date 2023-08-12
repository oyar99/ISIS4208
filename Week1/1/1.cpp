#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <functional>
#include <assert.h>

using namespace std;

/*
 * La teoría de los seis grados de separación dice que una persona podría conocer a cualquier otra persona del mundo
 * siguiendo una cadena de personas que se conocen entre si de tamaño máximo 6. Suponiendo que si una persona
 * conoce a otra, entonces tienen una relación de amistad en la red social Facebook, diseñar un algoritmo lo más eficiente
 * posible, que reciba la base de datos de relaciones de amistad de esta red social y determine si la teoría de los seis
 * grados de separación se cumple.
 * 
 * Entrada:
 * 
 * Para el problema cada persona registrada en la red social estará enumerada del 1 al N.
 * 
 * La primera linea consta de un numero T indicando la cantidad de instancias del problema.
 * Luego por cada instancia, se tiene una primera linea con un numero N y R. Donde N indica el numero de personas
 * registradas en la red social, y R indica el numero de relaciones de amistad totales en la red social. Luego, siguen
 * R lineas donde cada una consta de 2 números A y B, que significa que la persona A tiene una relación de amistad con la persona B.
 * 
 * Salida:
 * 
 * Por cada instancia del problema se debe retornar "SI" si la teoría de los seis grados de separación se cumple. O "NO", en el caso contrario.
 * 
 * Ejemplo:
 * 
 * 2
 * 4 2
 * 1 2
 * 2 3
 * 2 1
 * 1 2
 * 
 * En este ejemplo tenemos dos instancias del problema.
 * 
 * 1. 4 personas están registradas en la red social y existen 2 amistades. 1 tiene una amistad con 2. 2 tiene una amistad con 3.
 * 2. 2 personas están registradas en la red social y existe 1 amistad. 1 es amigo de 2.
 * 
 * La salida esperada para esta entrada seria:
 * 
 * "NO"
 * "SI"
 * 
 * Para el primer caso, es imposible que alguien pueda conocer a la persona 4 ya que no es amigo de nadie.
 * Para el segundo caso, tanto 1 como 2 solo deben recorrer una cadena de longitud 1 para conocer a todos las demás.
 * 
*/

string solve();

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) cout << solve() << endl;
}

string solve() {
    int N, R; cin >> N >> R;

    /* 
     * Lista adyacente para representar con un grafo las relaciones de amistad en la red social.
     * Donde cada persona es un vértice y cada relación se representa con una arista.
    */
    vector<unordered_set<int>> adj(N + 1, unordered_set<int>());

    for (int i = 0; i < R; ++i) {
        int u, v; cin >> u >> v;

        // U es amigo de V
        // Grafo no dirigido
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // En este punto ya hemos construido el grafo no dirigido.

    // Haremos una búsqueda BFS a partir de cada nodo para determinar si a partir de algún nodo se debe recorrer mas de 6
    // niveles de profundidad para llegar a otro nodo.
    // Complejidad: O(V * (V + E))

    const int SEIS_GRADOS = 6;

    for (int u = 1; u <= N; ++u) {
        unordered_set<int> visited;
        unordered_map<int, int> depth;

        queue<int> q;
        q.push(u);

        visited.insert(u);
        depth[u] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (depth[v] > SEIS_GRADOS) {
                return "NO";
            }

            for (int w: adj[v]) {
                if (visited.count(w) <= 0) {
                    visited.insert(w);

                    q.push(w);
                    depth[w] = depth[v] + 1;
                }
            }
        }

        // Si no se visitaron todos los nodos, entonces no se cumple la teoría de los seis grados de separación
        if (visited.size() < N) {
            return "NO";
        }

        assert(visited.size() == N);
    }

    return "SI";
}