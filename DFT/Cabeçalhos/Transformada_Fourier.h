#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

class Transformada_Fourier
{
private:

	/*Vetor com variáveis complexas composta pelo resultado da transformada de Fourier*/
	std::vector<std::complex<double>> Xk;
	
public:

	/*CONSTRUTOR*/
	Transformada_Fourier();
	
	/*DESTRUTOR*/
	~Transformada_Fourier();
	
	/*MÉTODOS*/
	/*Retorna o vetor com resultado da Transformada de Fourier*/
	std::vector<std::complex<double>> getTransformada();
	
	/*Seta a transformada de fourier de uma amostra*/
	void setTransformada_Xk(std::vector<std::complex<double>> Xk);
	
	/*Apresenta a transformada na forma complexa retangular*/
	void mostrarTransformadaFourier(std::vector<std::complex<double>> Xk);
	
	/*Apresenta a transformada na forma complexa polar*/
	void mostrarTransformadaFourier_Polar(std::vector<std::complex<double>> Xk);

};

