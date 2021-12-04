#pragma once
#include "Amostras.h"
class Amostras_Reversa : public Amostras
{
private:

	/*Vetor de Amostras Reversas*/
	std::vector<double> xn_reversa;

public:

	/*CONSTRUTOR*/
	Amostras_Reversa();

	/*DESTRUTOR*/
	~Amostras_Reversa();

	/*Método para Inicializar o valor das amostras*/
	void setAmostras_Reversas(std::vector<double> xn);

	/*Método para obter o valor das amostras*/
	std::vector<double> getAmostras_Reversas();

	/*Método de Implementação do Bit Reversal Algorithm*/
	std::vector<double> Reverter_Amostras(Amostras amostra);
	
	/*Método que imprime na tela sequência de amostra enviada como parâmetro*/
	void MostrarAmostrasReversas(std::vector<double> xn_reversa);

};

