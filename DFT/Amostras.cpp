#include "Amostras.h"

/*CONSTRUTOR*/
Amostras::Amostras()
{
	this->xn.clear();
}

Amostras::Amostras(std::vector<float> xn)
{
	this->xn.clear();
	this->xn = xn;
}

/*DESTRUTOR*/
Amostras::~Amostras() 
{
	this->xn.clear();
}

/*MÉTODOS*/

/*Método para inicializar o vetor Amostras*/
void Amostras::setAmostras(std::vector<float> xn)
{
	this->xn.clear();
	this->xn = xn;
}

/*Método para obter o vetor Amostras*/
std::vector<float> Amostras::getAmostras() 
{
	return this->xn;
}

/*Método para obteção de amostras do sinal de forma digitada*/
std::vector<float> Amostras::ObterAmostras_EntradaDigitada()
{
	setlocale(LC_ALL, "portuguese");
	float amostra{ 0.0f };
	std::vector<float> xn;
	
	do {
		std::cout << "\nEntre com o valor da amostra (entre 0 para finalizar): ";
		std::cin >> amostra;
		if(amostra!=0) xn.push_back(amostra);
	} while (amostra);
	
	this->setAmostras(xn);

	return xn;
}

/*Método para obteção de amostras do sinal de forma randômica*/
std::vector<float> Amostras::ObterAmostras_EntradaRandomica()
{
	int amostras{ 0 };
	std::vector<float> xn;
	
	srand((unsigned int)time(0));
	
	std::cout << "\n\nInforme a quantidade de amostras desejadas: ";
	std::cin >> amostras;
	
	for (int i = 0; i < amostras; ++i)
	{
		xn.push_back((2.0f * rand() / RAND_MAX) - 1.0f);
	}
	
	this->xn = xn;

	return xn;
}

/*Método para obteção de amostras do sinal de arquivo externo*/
std::vector<float> Amostras::ObterAmostras_EntradaArquivoExterno()
{
	std::string endereco{ NULL };
	std::string entrada{ NULL };
	std::vector<std::string> amostras_string;
	std::vector<float> xn;
	
	std::cout << "\nDigite o endereço do arquivo onde se encontram as amostras: ";
	std::cin >> endereco;
	
	std::ifstream file(endereco);

	while(file >> entrada)
	{
		if ((char)entrada.front() != 'x' && (char)entrada.front() != 'X') amostras_string.push_back(entrada);
	}
	
	float f{ 0.0f };
	
	for (std::vector<std::string>::iterator it = amostras_string.begin(); it != amostras_string.end(); ++it)
	{
		std::istringstream valores(*it);
		valores >> f;
		xn.push_back(f);
	}

	this->setAmostras(xn);
	
	return xn;
}

/*Método para gravação de amostras em arquivo externo*/
void Amostras::GravarAmostrasDiscretas_ArquivoExterno(std::vector<float> xn)
{
	std::ofstream arquivo;
	int i{ 0 };
	std::string nome_arquivo{ NULL };

	std::cout << "\nDigite o nome do arquivo que deseja salvar a amostras: ";
	std::cin >> nome_arquivo;
	arquivo.open(nome_arquivo + ".txt");
	

	for (std::vector<float>::iterator it = xn.begin(); it != xn.end(); ++it, ++i)
	{
		arquivo.open("Amostras.txt", std::ios::app);
		arquivo << "\nxn[" << i << "]: " << *it;
		arquivo.close();
	}

	arquivo.close();
	
	this->xn.clear();
	this->xn = xn;

}

/*Método que imprime na tela sequência de amostra enviada como parâmetro*/
void Amostras::MostrarAmostras(std::vector<float> xn)
{
	unsigned int i{ 0 };
	
	std::cout << "\n\n\n*************** AMOSTRAS DO SINAL ****************" << std::endl;
	for(std::vector<float>::iterator it = xn.begin(); it != xn.end(); ++it, ++i)
	{
		std::cout << "\nxn[" << i << "]: " << *it;
	}
	std::cout << "\n\n\n********************** FIM ***********************" << std::endl;
}

/*Verificar se a quantidade de amostras é múltiplo de 2* - usado para FFT*/
bool Amostras::isPotenciaDeDois()
{
	return (Amostras::getAmostras().size() & (Amostras::getAmostras().size() - 1)) ? false : true;
}

/*Cria o efeito de preenchimento do vetor com zero "Zero-Padding" até uma pontência de 2* - usado para FFT*/
void Amostras::ZeroPadding()
{
	
	if (Amostras::isPotenciaDeDois())
	{
		/*std::cout << "O Zero-Padding não é aplicada a amostras pois a mesma já é uma potência de dois" << std::endl;*/
		return;
	}
	else
	{
		std::vector<float> xn{ this->getAmostras() };
		int proximaPotencia{ (int)ceil(log2(xn.size())) };
		
		int deficit{ (int)pow(2,proximaPotencia) - (int)xn.size() };
				
		auto it = xn.end();
		xn.insert(it, deficit, 0.0f);
		this->setAmostras(xn);
	}

}



