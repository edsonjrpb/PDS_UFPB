#pragma once
#include "Amostras.h"
class Amostras_Reversa : public Amostras
{
private:

	/*Vetor de Amostras Reversas*/
	std::vector<float> xn_reversa;

public:

	/*CONSTRUTOR*/
	Amostras_Reversa();

	/*DESTRUTOR*/
	~Amostras_Reversa();

	/*Método para Inicializar o valor das amostras*/
	void setAmostras_Reversas(std::vector<float> xn);

	/*Método para obter o valor das amostras*/
	std::vector<float> getAmostras_Reversas();

	/*Método de Implementação do Bit Reversal Algorithm*/
	std::vector<float> Reverter_Amostras(Amostras amostra);
	
	/*Método que imprime na tela sequência de amostra enviada como parâmetro*/
	void MostrarAmostrasReversas(std::vector<float> xn_reversa);

};

