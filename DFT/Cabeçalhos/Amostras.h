#pragma once
#include <vector>
#include <complex>
#include <iostream>
#include <fstream>
#include <string>

class Amostras {

private:
	
	/*Vetor de Amostras*/
	std::vector<double> xn;
		
protected:

public:
	
	/*CONSTRUTOR*/
	Amostras();
	Amostras(std::vector<double> xn);


	/*DESTRUTOR*/
	~Amostras();

	/*M�todo para Inicializar o vetor Amostras*/
	void setAmostras(std::vector<double> xn);
	
	/*M�todo para Inicializar o vetor Amostras*/
	std::vector<double> getAmostras();

	/*M�todo para obte��o de amostras do sinal de forma digitada*/
	std::vector<double> ObterAmostras_EntradaDigitada();

	/*M�todo para obte��o de amostras do sinal de forma rand�mica*/
	std::vector<double> ObterAmostras_EntradaRandomica();

	/*M�todo para obte��o de amostras do sinal de arquivo externo*/
	std::vector<double> ObterAmostras_EntradaArquivoExterno();

	/*Imprimir ou Gravar Amostras*/
	void GravarAmostrasDiscretas_ArquivoExterno(std::vector<double> xn);
	
	/*M�todo que imprime na tela sequ�ncia de amostra enviada como par�metro*/
	void MostrarAmostras(std::vector<double> xn);

	/*Cria o efeito de preenchimento do vetor com zero "Zero-Padding" at� uma pont�ncia de 2* - usado para FFT*/
	void ZeroPadding();

	/*Verificar se a quantidade de amostras � m�ltiplo de 2* - usado para FFT*/
	bool isPotenciaDeDois();
};
