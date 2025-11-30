# algoritmo-mis
Implementação do algoritmo exato para Conjunto Independente Máximo (MIS) em C++.

EXPLICAÇÃO DO CÓDIGO

Como o algoritmo funciona
1. Entrada do grafo

O programa lê:

n -> número de vértices
m -> número de arestas

Depois, monta a lista de adjacência (adj).

2. Representação dos conjuntos

currentSet -> conjunto sendo construído naquele momento
bestSet -> melhor solução encontrada até agora
bestSize -> tamanho do melhor conjunto até agora

3. Função principal: branchAndBound(int v)

Essa função tenta decidir para cada vértice v:

incluir ou não incluir
no conjunto independente.

A. Caso base

Quando v == n, todos os vértices foram considerados.
Se o currentSet for maior que o melhor encontrado -> atualiza bestSet.

B. Poda (Bound)
if (currentSet.size() + (n - v) <= bestSize)
    return;

Isso verifica se mesmo pegando todos os vértices restantes, não será possível superar o melhor conjunto já encontrado.

Se for impossível melhorar, abandona o ramo imediatamente.
Isso acelera MUITO a execução.

C. Verificar se pode incluir o vértice

Ele só pode ser incluído se não for vizinho de nenhum vértice já incluído:

bool canInclude = true;
for (int u : adj[v])
    if (find(currentSet.begin(), currentSet.end(), u) != currentSet.end())
        canInclude = false;

Se puder, tenta o ramo com v incluído.

D. Ramo sem incluir o vértice

Independente de incluir ou não, o algoritmo também tenta o caminho sem incluir:

branchAndBound(v + 1);

4. Saída

O programa imprime: o tamanho do MIS e os vértices que compõem esse conjunto

Complexidade

No pior caso, o MIS é um problema NP-difícil, então o algoritmo explora um espaço exponencial.
Mas o Branch and Bound reduz drasticamente o número de ramos explorados.

Complexidade pior caso:
O(2ⁿ)
Mas na prática -> bem mais rápido com a poda.

Exemplo de Execução

Entrada:

5 3
0 1
1 2
3 4


Saída:

Tamanho do Conjunto Independente Maximo: 3
Vertices: 0 2 3
