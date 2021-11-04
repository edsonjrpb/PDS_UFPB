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

	/*M�todo para Inicializar o valor das amostras*/
	void setAmostras_Reversas(std::vector<float> xn);

	/*M�todo para obter o valor das amostras*/
	std::vector<float> getAmostras_Reversas();

	/*M�todo de Implementa��o do Bit Reversal Algorithm*/
	std::vector<float> Reverter_Amostras(Amostras amostra);
	
	/*M�todo que imprime na tela sequ�ncia de amostra enviada como par�metro*/
	void MostrarAmostrasReversas(std::vector<float> xn_reversa);

};

