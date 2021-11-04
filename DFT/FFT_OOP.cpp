#define _USE_MATH_DEFINES
#include <math.h>
#include "FFT_OOP.h"

/*CONSTUTOR*/
FFT_OOP::FFT_OOP() {};

/*DESTRUTOR*/
FFT_OOP::~FFT_OOP() {};

/*MÉTODOS*/
std::vector<std::complex<float>> FFT_OOP::FFT(std::vector<float> xn_reverso)
{
	std::vector<std::complex<float>> xn_reverso_complexo;

	for(std::vector<float>::iterator it = xn_reverso.begin(); it != xn_reverso.end(); ++it)
	{
		xn_reverso_complexo.push_back(*it);
	}

	std::vector<std::complex<float>> transformada = this->FFT(xn_reverso_complexo);
	
	this->setTransformada_Xk(transformada);

	return this->getTransformada();

};
std::vector<std::complex<float>> FFT_OOP::FFT(std::vector<std::complex<float>>& xn_reversa_complex)
{
	unsigned int tam_amostra_complexa{ xn_reversa_complex.size() };
	std::vector<std::complex<float>> Xk(tam_amostra_complexa);
	std::vector<std::complex<float>> ANi(tam_amostra_complexa / 2);
	std::vector<std::complex<float>> ANf(tam_amostra_complexa / 2);

	if (tam_amostra_complexa == 1) return std::vector<std::complex<float>>(1, xn_reversa_complex[0]);

	/*Carregando os Twiddle Factors*/
	std::vector<std::complex<float>> Wn(tam_amostra_complexa);
	for (int i = 0; i < tam_amostra_complexa; i++) {
		float alpha = (float)(2.0f * M_PI * i / tam_amostra_complexa); //verificar se valor é realmente negativo ou não
		Wn[i] = std::complex<float>(std::cos(alpha), std::sin(alpha));
	}
	
	/*Divide os coeficientes pela metade*/
	for (int i = 0; i < tam_amostra_complexa / 2; i++) 
	{

		// metade inicial dos coeficientes
		ANi[i] = xn_reversa_complex[i];
	
		// metade final dos coeficientes
		ANf[i] = xn_reversa_complex[i + (tam_amostra_complexa/2)];
	}

	// chamada recursiva para a metade inicial dos coeficientes
	std::vector<std::complex<float>> Xk_temp_i{ FFT(ANi) };

	// chamada recursiva para a metade final dos coeficientes
	std::vector<std::complex<float>> Xk_temp_f{ FFT(ANf) };
		
	for (int i = 0; i < tam_amostra_complexa / 2; i++) {
		Xk[i] = Xk_temp_i[i] + Wn[i] * Xk_temp_f[i];
		Xk[i + tam_amostra_complexa / 2] = Xk_temp_i[i] - Wn[i] * Xk_temp_f[i];
	}
	return Xk;
}


