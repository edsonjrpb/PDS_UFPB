#include "Transformada_Fourier.h"

/*CONSTRUTOR*/
Transformada_Fourier::Transformada_Fourier(){}

/*DESTRUTOR*/
Transformada_Fourier::~Transformada_Fourier(){}

/*MÉTODOS*/

/*Retorna o vetor com resultado da Transformada de Fourier*/
std::vector<std::complex<float>> Transformada_Fourier::getTransformada()
{
	return Xk;
}

/*Seta a transformada de fourier de uma amostra*/
void Transformada_Fourier::setTransformada_Xk(std::vector<std::complex<float>> Xk)
{
	this->Xk.clear();
	this->Xk = Xk;
}

/*Apresenta a transformada na forma complexa retangular*/
void Transformada_Fourier::mostrarTransformadaFourier(std::vector<std::complex<float>> Xk)
{
	int k{ 0 };//contador de índice do vetor
	std::cout << "\n\n\n*************** RESULTADO DA TRANSFORMADA ****************\n" << std::endl;
	
	for (std::vector<std::complex<float>>::iterator it = Xk.begin(); it != Xk.end(); ++k, ++it)//uso do iterator
	{
		std::cout << "Xk[" << k << "]: " << (*it).real() << " + j" << (*it).imag() << std::endl;
	}
	std::cout << "\n********************* FIM ***********************" << std::endl;

}

/*Apresenta a transformada na forma complexa polar*/
void Transformada_Fourier::mostrarTransformadaFourier_Polar(std::vector<std::complex<float>> Xk)
{
	int k{ 0 };//contador de índice do vetor
	std::cout << "\n\n\n*************** RESULTADO DA DFT (POLAR) ****************\n" << std::endl;
	
	for (std::vector<std::complex<float>>::iterator it = Xk.begin(); it != Xk.end(); ++k, ++it)//uso do iterator
	{
		std::cout << "Xk[" << k << "]: " << std::abs(*it) << " < " << (std::arg(*it)) * (180.0 / M_PI) << std::endl;
	}
	std::cout << "\n************************ FIM **************************" << std::endl;
}
