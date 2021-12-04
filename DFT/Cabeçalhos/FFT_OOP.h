#pragma once
#include "Amostras.h"
#include "Amostras_Reversa.h"
#include "Transformada_Fourier.h"

class FFT_OOP : public Transformada_Fourier
{
public:

	/*CONSTUTOR*/
	FFT_OOP();

	/*DESTRUTOR*/
	~FFT_OOP();

	/*MÉTODOS*/
	std::vector<std::complex<double>> FFT(std::vector<double> xn_reversa);
	std::vector<std::complex<double>> FFT(std::vector<std::complex<double>> &xn_reversa);

};