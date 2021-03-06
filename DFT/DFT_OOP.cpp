#define _USE_MATH_DEFINES
#include <math.h>
#include "DFT_OOP.h"

	/*CONSTUTOR*/

	DFT_OOP::DFT_OOP(){	};

	/*DESTRUTOR*/
	DFT_OOP::~DFT_OOP(){};

	/*M?TODOS*/
	/*M?todo para realiza??o do DFT - Discrete Fourier Transform*/
	std::vector<std::complex<double>> DFT_OOP::DFT(std::vector<double> xn)
	{
		std::vector<std::complex<double>> Xk;
		int N{ (int)xn.size() };
		int i{ 0 };

		/*std::cout << "\nEntre com a quantidade de pontos da DFT: ";
		std::cin >> N;*/

		for (int k = 0; k < N; ++k)
		{
			Xk.push_back(std::complex<double>::complex(0.0f, 0.0f));

			for (std::vector<double>::iterator it = xn.begin(); it != xn.end(); ++it, i++)
			{
				Xk[k] = std::complex<double>::complex(Xk[k].real() + (*it * cos(2 * M_PI * k * i / N)), Xk[k].imag() - (*it * sin(2 * M_PI * k * i / N)));

			}
		}
		this->setTransformada_Xk(Xk);
		
		return Xk;
	}

