# Descrição do programa:

**-** Programa criado com o intuito de fixar conceitos de ***Árvore Binária***, uso de `struct` na linguagem C, ***recursividade*** e ***alocação dinâmica de memória***.

**-** A ideia principal consiste na criação de indivíduos e na atribuição de tipos sanguíneos herdados, onde a relação parental é construída mesmo quando 
o programa atinge o caso base — isto é, quando não há mais “parentes” para os quais os ponteiros possam apontar. Nesse caso, utiliza-se a função 
`random_allele` para simular uma geração inicial “ancestral”.

**-** Por se tratar de um modelo simplificado, a seleção do tipo sanguíneo herdado ocorre por meio da escolha aleatória entre os dois alelos de cada progenitor.
Não são consideradas outras possibilidades mais complexas, como dominância genética, fator Rh ou probabilidades reais envolvidas na herança biológica.

**-** A construção da árvore ocorre de forma recursiva, onde os indivíduos são criados a partir das gerações mais antigas até as mais recentes, permitindo que 
os alelos sejam atribuídos corretamente no retorno das chamadas.
