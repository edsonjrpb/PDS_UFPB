#include "Amostras_Reversa.h"

/*CONSTRUTOR*/
Amostras_Reversa::Amostras_Reversa()
{
	
	//this->setAmostras_Reversas(this->Reverter_Amostras(xn.getAmostras()));
}

/*DESTRUTOR*/
Amostras_Reversa::~Amostras_Reversa() {}


/*MÉTODOS*/

/*Método para Inicializar o valor das amostras*/
void Amostras_Reversa::setAmostras_Reversas(std::vector<float> xn_reversa)
{
	this->xn_reversa.clear();
	this->xn_reversa = xn_reversa;
}

/*Método para obter o valor das amostras*/
std::vector<float> Amostras_Reversa::getAmostras_Reversas()
{
	return this->xn_reversa;
}

/*Método de Implementação do Bit Reversal Algorithm*/
std::vector<float> Amostras_Reversa::Reverter_Amostras(Amostras xn)
{
	if (!xn.isPotenciaDeDois()) std::cout << "reversão incompactível";
	
	std::vector<int> index_reversa;
	std::vector<float> amostras_reversas;
	int N{ (int)pow(2,log2(xn.getAmostras().size())) };
	int bits{ (int)log2(xn.getAmostras().size()) };
		
	for (int i = 0; i < N; i++)
	{
		int valbitrev{ i };
		int nrev{ 0 };
		int B{ 1 << bits };
		int counter{ bits - 1 };
		nrev = valbitrev;
		for (valbitrev >>= 1; valbitrev; valbitrev >>= 1)
		{
			nrev <<= 1;
			nrev |= valbitrev & 1;
			counter--;
		}
		nrev <<= counter;
		nrev &= B - 1;
		index_reversa.push_back(nrev);
	}
	for (int i=0; i < (int)xn.getAmostras().size(); ++i)
	{
		amostras_reversas.push_back(xn.getAmostras().at(index_reversa.at(i)));
	}
	
	return amostras_reversas;
}

/*Método que imprime na tela sequência de amostra reversa enviada como parâmetro*/
void Amostras_Reversa::MostrarAmostrasReversas(std::vector<float> xn_reversa)
{
	unsigned int i{ 0 };

	std::cout << "\n\n\n************ AMOSTRAS DO SINAL REVERTIDOS *************" << std::endl;
	for (std::vector<float>::iterator it = xn_reversa.begin(); it != xn_reversa.end(); ++it, ++i)
	{
		std::cout << "\nxn[" << i << "]: " << *it;
	}
	std::cout << "\n\n\n********************** FIM ***********************" << std::endl;
}
