#define _USE_MATH_DEFINES
#include <math.h>
#include "DFT_OOP.h"

	/*CONSTUTOR*/

	DFT_OOP::DFT_OOP(){	};

	/*DESTRUTOR*/
	DFT_OOP::~DFT_OOP(){};

	/*MÉTODOS*/
	/*Método para realização do DFT - Discrete Fourier Transform*/
	std::vector<std::complex<float>> DFT_OOP::DFT(std::vector<float> xn)
	{
		std::vector<std::complex<float>> Xk;
		int N{ (int)xn.size() };
		int i{ 0 };

		/*std::cout << "\nEntre com a quantidade de pontos da DFT: ";
		std::cin >> N;*/

		for (int k = 0; k < N; ++k)
		{
			Xk.push_back(std::complex<float>::complex(0.0f, 0.0f));

			for (std::vector<float>::iterator it = xn.begin(); it != xn.end(); ++it, i++)
			{
				Xk[k] = std::complex<float>::complex(Xk[k].real() + (float)(*it * cos(2 * M_PI * k * i / N)), Xk[k].imag() - (float)(*it * sin(2 * M_PI * k * i / N)));

			}
		}
		this->setTransformada_Xk(Xk);
		
		return Xk;
	}

