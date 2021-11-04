#pragma once
#include "Amostras.h"
#include "Transformada_Fourier.h"

class DFT_OOP : public Transformada_Fourier
{
public:

	/*CONSTUTOR*/
	DFT_OOP();

	/*DESTRUTOR*/
	~DFT_OOP();
	
	/*MÉTODOS*/
	std::vector<std::complex<float>> DFT(std::vector<float> xn);

};

