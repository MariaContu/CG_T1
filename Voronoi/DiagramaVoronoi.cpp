//
//  DiagramaVoronoi.cpp
//  OpenGLTest
//
//  Created by Márcio Sarroglia Pinho on 23/08/23.
//  Copyright © 2023 Márcio Sarroglia Pinho. All rights reserved.
//

#include "DiagramaVoronoi.h"
#include "Envelope.h"

ifstream input;            // ofstream arq;

Voronoi::Voronoi()
{

}
Poligono Voronoi::LeUmPoligono()
{
    Poligono P;
    unsigned int qtdVertices;
    input >> qtdVertices;  // arq << qtdVertices
    for (int i=0; i< qtdVertices; i++)
    {
        double x,y;
        // Le um ponto
        input >> x >> y;
        Ponto(x, y).imprime();
        if(!input)
        {
            cout << "Fim inesperado da linha." << endl;
            break;
        }
        P.insereVertice(Ponto(x,y));
    }
    cout << "Poligono lido com sucesso!" << endl;
    return P;
}

void Voronoi::LePoligonos(const char *nome)
{
    input.open(nome, ios::in); //arq.open(nome, ios::out);
    if (!input)
    {
        cout << "Erro ao abrir " << nome << ". " << endl;
        exit(0);
    }
    string S;

    input >> qtdDePoligonos;
    cout << "qtdDePoligonos:" << qtdDePoligonos << endl;
    Ponto A, B;
    Diagrama[0] = LeUmPoligono();
    Diagrama[0].obtemLimites(Min, Max);// obtem o envelope do poligono
    for (int i=1; i< qtdDePoligonos; i++)
    {
        Diagrama[i] = LeUmPoligono();
        Diagrama[i].obtemLimites(A, B); // obtem o envelope do poligono

        Min = ObtemMinimo (A, Min);
        Max = ObtemMaximo (B, Max);
    }
    cout << "Lista de Poligonos lida com sucesso!" << endl;

}
Poligono Voronoi::getPoligono(int i)
{
    if (i >= qtdDePoligonos)
    {
        cout << "Nro de Poligono Inexistente" << endl;
        return Diagrama[0];
    }
    return Diagrama[i];
}
unsigned int Voronoi::getNPoligonos()
{
    return qtdDePoligonos;
}
void Voronoi::obtemLimites(Ponto &min, Ponto &max)
{
    min = this->Min;
    max = this->Max;
}

void Voronoi::obtemVizinhosDasArestas()
{
    for (int i = 0; i < this->getNPoligonos(); i++) {
        Poligono poli1 = this->getPoligono(i);
        Poligono poli2 = this->getPoligono((i + 1) % this->getNPoligonos());

        for (int j = 0; j < poli1.getNVertices(); j++) {
            Ponto p1a = poli1.getVertice(j);
            Ponto p1b = poli1.getVertice((j + 1) % poli1.getNVertices());

            for (int k = 0; k < poli2.getNVertices(); k++) {
                Ponto p2a = poli2.getVertice(k);
                Ponto p2b = poli2.getVertice((k + 1) % poli2.getNVertices());

                if (p1a == p2b && p1b == p2a) {
                    poli1.addVizinho(poli2);
                    poli2.addVizinho(poli1);
                }
            }
        }
    }
}
