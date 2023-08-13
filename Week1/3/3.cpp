#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * Juan quiere invitar a sus amigos a conocer su nuevo apartamento. Sin embargo tiene la dificultad de que sus amigos
 * son algo conflictivos y entonces sabe que varias parejas de amigos se han peleado entre ellos. Debido a esto, tomó la
 * decisión de organizar dos reuniones. Diseñe un algoritmo que determine si es posible distribuir a los amigos de Juan en
 * dos grupos de tal manera que dentro de cada grupo no haya parejas de personas que se hayan peleado entre ellas.
 * 
 * Entrada:
 * 
 * Para el problema cada amigo de Juan estará enumerado del 1 al N.
 * 
 * La primera linea consta de un numero T indicando la cantidad de instancias del problema.
 * Luego por cada instancia, se tiene una primera linea con un numero N y R. Donde N indica el numero de amigos de Juan, 
 * y R indica el numero de parejas que se han peleado. Luego, siguen R lineas donde cada una consta de 2 números A y B, 
 * que significa que la persona A tuvo un conflicto con la persona B.
 * 
 * Salida:
 * 
 * Por cada instancia del problema se debe retornar "SI" si Juan puede invitar a todos sus amigos a su apartamento sin que haya personas
 * conflictivas en cada grupo. O "NO" en caso contrario.
 * 
 * Ejemplo:
 * 
 * 2
 * 6 5
 * 1 2
 * 2 3
 * 3 4
 * 3 5
 * 5 6
 * 5 5
 * 1 2
 * 1 3
 * 3 2
 * 3 4
 * 3 5
 * 
 * En este ejemplo tenemos dos instancias del problema.
 * 
 * La salida esperada para esta entrada seria:
 * 
 * "SI"
 * "NO"
 * 
 * Para el primer caso, podemos dividir el grupo asi: (1, 3, 6) y (2, 4, 5).
 * Para el segundo caso, no existe forma de dividir el grupo en 2. Pues entre los amigos (1, 2, 3) habrá uno que tendrá que quedar en un grupo con alguien
 * con quien ha peleado.
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
     * Lista adyacente para representar con un grafo las personas que han tenido peleas.
     * Es decir, una arista (U, V) significa que la persona U ha peleado con V, y por lo tanto
     * no pueden asistir a la misma reunion.
    */
    vector<unordered_set<int>> adj(N + 1, unordered_set<int>());

    for (int i = 0; i < R; ++i) {
        int u, v; cin >> u >> v;

        // U peleo con V
        // Grafo no dirigido
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // En este punto ya hemos construido el grafo no dirigido.

    // Haremos un procedimiento greedy: empezando en un nodo arbitrario, asignamos ese nodo a un grupo, y a los nodos adyacentes al otro grupo.
    // Si en algún momento, nos encontramos que ya habíamos asignado un nodo adyacente al grupo donde habría un conflicto, sabremos que no se puede
    // dividir el grupo de amigos en dos.
    // Complejidad: O(V + E)

    // Para asignar los nodos a un grupo, usaremos la técnica de graph coloring. 
    // Hash table para colorear los nodos del grafo. color[U] => 1 o color[U] => -2
    unordered_map<int, int> color;

    for (int u = 1; u <= N; ++u) {
        if (color.count(u) > 0) {
            continue;
        }

        queue<int> q;
        q.push(u);

        color[u] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int w: adj[v]) {
                if (color.count(w) > 0) {
                    // El nodo adyacente a v ya ha sido coloreado. Debemos revisar si son del mismo color - lo que indicaría que harían parte del mismo grupo,
                    // y por ende no se puede dividir el grupo de amigos en dos
                    if (color[w] == color[v]) {
                        return "NO";
                    }
                } else {
                    // El nodo adyacente no ha sido coloreado. Por lo que procederemos a colorearlo del color opuesto a color[v]
                    color[w] = ~color[v];

                    q.push(w);
                }
            }
        }
    }

    // En este punto el grafo ha sido coloreado de dos colores A y B tal que no existen dos nodos adyacentes del mismo color. Esta seria la forma en la que Juan
    // puede dividir su grupo de amigos para invitarlos a su apartamento de tal forma de que no hayan personas que hayan peleado en cada reunion.
    return "SI";
}