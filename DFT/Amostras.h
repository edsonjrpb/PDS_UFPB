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

	/*Método para Inicializar o vetor Amostras*/
	void setAmostras(std::vector<float> xn);
	
	/*Método para Inicializar o vetor Amostras*/
	std::vector<float> getAmostras();

	/*Método para obteção de amostras do sinal de forma digitada*/
	std::vector<float> ObterAmostras_EntradaDigitada();

	/*Método para obteção de amostras do sinal de forma randômica*/
	std::vector<float> ObterAmostras_EntradaRandomica();

	/*Método para obteção de amostras do sinal de arquivo externo*/
	std::vector<float> ObterAmostras_EntradaArquivoExterno();

	/*Imprimir ou Gravar Amostras*/
	void GravarAmostrasDiscretas_ArquivoExterno(std::vector<float> xn);
	
	/*Método que imprime na tela sequência de amostra enviada como parâmetro*/
	void MostrarAmostras(std::vector<float> xn);

	/*Cria o efeito de preenchimento do vetor com zero "Zero-Padding" até uma pontência de 2* - usado para FFT*/
	void ZeroPadding();

	/*Verificar se a quantidade de amostras é múltiplo de 2* - usado para FFT*/
	bool isPotenciaDeDois();
};
