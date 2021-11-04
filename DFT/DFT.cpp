/*Aluno: Edson Pereira de Castilho Junior
  UFPB - Universidade Federal da Paraíba
  Mestrado em Engenharia Elétrica
*/
#define _USE_MATH_DEFINES
#include "DFT.h"
#include <math.h>
#include <iostream>


using namespace std;

/*Função calula DFT recebendo como argumento as amostras do sinal discreto no tempo e o tamanho da amostra
* Devolve Array contento os número complexos resultados da DFT

Last Modified: 2021.10.11
*/
std::vector<std::complex<float>> DFT(std::vector<float> xn)
{
	std::vector<std::complex<float>> Xk;
	int N{ 0 };
	
	cout << "\nEntre com a quantidade de pontos da DFT: ";
	cin >> N;

	for (int k = 0; k < N; ++k)
	{
		Xk.push_back(std::complex<float>::complex(0.0f, 0.0f));
		
		for (unsigned n = 0; n < xn.size(); ++n)
		{
			Xk[k] = std::complex<float>::complex((float)(Xk[k].real() + (xn.at(n) * cos(2 * M_PI * k * n / N))), (float)(Xk[k].imag() - (xn.at(n) * sin(2 * M_PI * k * n / N))));
		}
	}
	return Xk;
}

void MostrarDFT(std::vector<std::complex<float>> Xk) 
{
	cout << "\n\n\n*************** RESULTADO DA DFT ****************\n" << endl;
	for (unsigned k = 0; k < Xk.size(); ++k)
	{
		cout << "Xk[" << k << "]: " << Xk[k].real() << " + j" << Xk[k].imag() << endl;
	}
	cout << "\n********************* FIM ***********************" << endl;
}

void MostrarDFT_Polar(std::vector<std::complex<float>> Xk)
{
	cout << "\n\n\n*************** RESULTADO DA DFT (POLAR) ****************\n" << endl;
	for (unsigned k = 0; k < Xk.size(); ++k)
	{
		cout << "Xk[" << k << "]: " << std::abs(Xk[k]) << " < " << (std::arg(Xk[k]))*(180.0/M_PI) << endl;
	}
	cout << "\n************************ FIM **************************" << endl;
}


