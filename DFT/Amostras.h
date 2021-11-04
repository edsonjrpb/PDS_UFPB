#pragma once
#include <vector>
#include <complex>
#include <iostream>
#include <fstream>
#include <string>

class Amostras {

private:
	
	/*Vetor de Amostras*/
	std::vector<float> xn;
		
protected:

public:
	
	/*CONSTRUTOR*/
	Amostras();
	Amostras(std::vector<float> xn);


	/*DESTRUTOR*/
	~Amostras();

	/*M�todo para Inicializar o vetor Amostras*/
	void setAmostras(std::vector<float> xn);
	
	/*M�todo para Inicializar o vetor Amostras*/
	std::vector<float> getAmostras();

	/*M�todo para obte��o de amostras do sinal de forma digitada*/
	std::vector<float> ObterAmostras_EntradaDigitada();

	/*M�todo para obte��o de amostras do sinal de forma rand�mica*/
	std::vector<float> ObterAmostras_EntradaRandomica();

	/*M�todo para obte��o de amostras do sinal de arquivo externo*/
	std::vector<float> ObterAmostras_EntradaArquivoExterno();

	/*Imprimir ou Gravar Amostras*/
	void GravarAmostrasDiscretas_ArquivoExterno(std::vector<float> xn);
	
	/*M�todo que imprime na tela sequ�ncia de amostra enviada como par�metro*/
	void MostrarAmostras(std::vector<float> xn);

	/*Cria o efeito de preenchimento do vetor com zero "Zero-Padding" at� uma pont�ncia de 2* - usado para FFT*/
	void ZeroPadding();

	/*Verificar se a quantidade de amostras � m�ltiplo de 2* - usado para FFT*/
	bool isPotenciaDeDois();
};
