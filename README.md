# DistributionCenter
## 1. Introdução
A proposta do trabalho é determinar o contingente mínimo de ligas metálicas
necessárias para atender a uma determinada demanda de um Centro de
Distribuição. A partir da demanda e um conjunto de tamanhos de ligas
disponíveis, o objetivo é encontrar a combinação mais eficiente para o
comprimento efetivo da proposta. <br>
Ademais, vale ressaltar que cada fábrica produz ligas metálicas em diferentes
tamanhos(expressos em metros) e os clientes realizam solicitações de ligas com
base em sua necessidade específica. Assim, o papel desempenhado pelo centro
de distribuição é efetuar a separação das encomendas de cada cliente, a fim de
que sejam despachadas posteriormente pelas transportadoras.<br>
Com vistas a aprimorar a eficiência do processo, tanto em termos de tempo
quanto de recursos, é desejável minimizar o número de ligas metálicas utilizadas
para atender a uma determinada demanda, levando em consideração os
tamanhos disponíveis no estoque.<br>
Para ilustrar essa questão, suponha que um cliente solicite 40 metros de
ligas, e o centro de distribuição disponha de ligas nos seguintes tamanhos: [1, 5,
10, 20, 25]. Nesse caso, a quantidade mínima de ligas que poderia ser utilizada
para atender a essa demanda específica seria de 2.<br>
## 2. Modelagem
O algoritmo apresentado modela a solução de um problema de otimização na
distribuição de ligas metálicas em um centro de distribuição. O objetivo é
determinar o número mínimo de ligas necessárias para atender a uma
determinada demanda, considerando os tamanhos disponíveis das ligas.
A modelagem da solução é feita da seguinte forma:<br>
1. Leitura do número de casos de teste: O algoritmo lê do usuário a
quantidade de casos de teste que serão realizados.
2. Loop dos casos de teste: Para cada caso de teste, o algoritmo realiza
as seguintes etapas:<br>
a. Leitura dos tamanhos de ligas disponíveis: O algoritmo lê do
usuário os tamanhos das ligas disponíveis e armazena-os em
um vetor.<br>
b. Chamada da função `minimumLigas`: O algoritmo chama a
função `minimumLigas` passando a demanda e o vetor de
tamanhos de ligas disponíveis como parâmetros. Essa função
implementa um algoritmo de programação dinâmica para
determinar o número mínimo de ligas necessárias.<br>
c. Impressão dos resultados: O número mínimo de ligas calculado
pela função `minimumLigas` é armazenado em um vetor de
saída e após o loop dos casos de teste, o algoritmo imprime os
resultados.<br>
A função `minimumLigas` implementa o algoritmo de programação dinâmica
para resolver o problema. Ela utiliza um vetor para armazenar o número mínimo
de ligas para cada quantidade de demanda. O caso base é definido como zero,
pois não é necessário nenhuma liga para atender uma demanda de valor zero.
O algoritmo percorre todas as possibilidades de tamanhos de ligas 
disponíveis e, para cada tamanho que seja menor ou igual à demanda atual,
verifica se é possível reduzir o problema para uma demanda menor e se isso
resulta em um número menor de ligas necessárias. Caso seja possível reduzir o
problema e o número de ligas obtido seja menor do que o armazenado no vetor, o
valor é atualizado. Após percorrer todas as possibilidades, a função retorna o
valor armazenado no vetor correspondente à demanda total.<br>
## 3. Análise de Complexidade e NP-Completude
### Complexidade do Algoritmo
A complexidade do algoritmo é determinada pelo número de iterações
necessárias para calcular o número mínimo de ligas.<br>
O algoritmo tem complexidade polinomial de tempo O(N*M), onde N
é a quantidade de demanda e M é o número de tamanhos de ligas
disponíveis. Isso ocorre porque, para cada valor de quantidade, é
necessário percorrer os tamanhos disponíveis em busca da solução ótima.<br>
### Demonstração da NP-Completude:
Em primeiro lugar, é importante destacar que o problema das ligas
metálicas pode ser formulado como um problema de otimização, portanto,
é um problema de decisão, onde se pergunta se existe uma solução que
satisfaça uma certa restrição para uma dada entrada.<br>
Podemos fazer uma redução polinomial e mostrar que o problema das
ligas metálicas é, pelo menos, tão difícil quanto o Problema da Mochila
(Knapsack). Essa redução consiste em mapear uma instância do problemada Mochila para uma instância equivalente do problema das ligas
metálicas. Para cada item da mochila, criamos uma liga metálica de
tamanho correspondente ao valor do item e definimos a demanda como a
capacidade máxima da mochila.Dessa forma, a solução para o problema
das ligas metálicas corresponde à solução para o problema da Mochila.<br>
Portanto, como o problema das ligas metálicas pode ser reduzido ao
problema da Mochila, que é NP-completo, concluímos que o problema das
ligas metálicas também é NP-completo.<br>
### Conclusão:
Com base na análise da complexidade do algoritmo e na
demonstração da NP-completude do problema das ligas metálicas,
podemos concluir que o algoritmo proposto resolve o problema de forma
eficiente, utilizando programação dinâmica. No entanto, devido à natureza
NP-completa do problema, não é possível encontrar uma solução ótima em
tempo polinomial, especialmente quando o tamanho da entrada aumenta.<br>
Portanto, é importante considerar estratégias adicionais para lidar com
instâncias de maior porte.
