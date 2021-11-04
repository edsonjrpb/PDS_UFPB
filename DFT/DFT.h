#pragma once
#include <vector>
#include <complex>
#include "Transformada_Fourier.h"

/*Função DFT - Discrete Fourier Transform*/
std::vector<std::complex<float>> DFT(std::vector<float> xn);


void MostrarDFT(std::vector<std::complex<float>> Xk);
void MostrarDFT_Polar(std::vector<std::complex<float>> Xk);