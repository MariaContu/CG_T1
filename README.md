# CG_T1
Repositório referente ao desenvolvimento do primeiro trabalho da cadeira de Computação Gráfica.

## Objetivo
Desenvolver um programa que avalie algoritmos de inclusão de pontos em polígonos de um diagrama de Voronoi, usando OpenGL.

## O Que deve ser construido?
O programa deve gerar um ponto que se move sobre o diagrama e, à cada movimento, deve ser informado em qual dos polígonos do conjunto o ponto está localizado.

Para cada polígono deve ser gerado um envelope. Sugere-se utilizar a estrutura da classe Envelope.

## Métodos de Inclusão De Pontos em Polígonos

Inicialmente o teste deve ser feito para verificar se o ponto ainda está no mesmo polígono que estava antes do último movimento. Se estiver, nenhum outro teste deve ser feito. Como os polígonos são todos convexos, o teste deve ser realizado com o algoritmo de inclusão de pontos 
em polígonos convexos. Como saída, deve ser informado quantas vezes a função ProdVetorial foi chamada.


Quando se detectar que o ponto saiu do polígono, o programa deve determinar qual o novo polígono contém o ponto através de três algoritmos:

• Inclusão de pontos em polígonos côncavos: O teste de inclusão deve ser realizado somente com os polígonos cujos envelopes cruzarem a linha horizontal usada para o teste.Neste caso, deve ser contabilizado o número de vezes que a função HaIntersecao foi 
chamada.

• Inclusão de pontos em polígonos convexos: O teste de inclusão deve ser realizado somente com os polígonos cujos envelopes contiverem o ponto. Neste caso, devem ser contabilizados o número de vezes que a função ProdVetorial for chamada;

• Inclusão de pontos em polígonos convexos utilizando a informação de vizinhança disponível no Diagrama de Voronoi: o novo polígono deve ser determinado testando qual aresta foi o “cruzada” quando o ponto saiu do polígono. Deve ser contabilizado o número de vezes que a função ProdVetorial foi chamada.