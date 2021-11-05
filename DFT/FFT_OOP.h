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
	//~FFT_OOP();

	/*MÉTODOS*/
	std::vector<std::complex<float>> FFT(std::vector<float> xn_reversa);
	std::vector<std::complex<float>> FFT(std::vector<std::complex<float>> &xn_reversa);

};