/*Aluno: Edson Pereira de Castilho Junior
  UFPB - Universidade Federal da Paraíba
  Mestrado em Engenharia Elétrica
*/
#include <iostream>
#include <chrono>
#include <locale.h> 
#include "DFT_OOP.h"
#include "FFT_OOP.h"
#include "Amostras.h"
#include "Amostras_Reversa.h"
#include <AudioFile.h>



using namespace std;
using namespace std::chrono;

int main()
{
	setlocale(LC_ALL, "portuguese");
	
	/*Variables declaration*/
	AudioFile<double> audioFile;
	int escolha_amostras{ 0 };
	int escolha_transformada{ 0 };
	Amostras xn;
	Amostras_Reversa xn_reversa;
	FFT_OOP Xk_FFT;
	DFT_OOP Xk_DFT;
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point stop;
	int escolha_continuar{ 0 };

	/*Open .WAV File*/
	audioFile.load("F:/Mestrado/PDS/Audacity_Teste/WAV Samples/Closed-Hi-Hat-1.wav");

	/*Show .WAV File Summary*/
	audioFile.printSummary();
	std::vector<std::vector<double>> vetorAudio = audioFile.samples;

	do {
		system("CLS");
		cout << "\t\t******************** Transformada Discreta de Fourier ********************";
		cout << "\n\n\nQual algoritmo deseja utilizar?\n\n1 - DFT\n2 - FFT\n\nEscolha: ";
		cin >> escolha_transformada;
		cout << "\n\n\nQual a forma de entrada das amostras (xn)?\n\n1 - Amostras Randômicas\n2 - Amostras Digitadas\n3 - Amostras a Partir de Arquivo Externo\n\n4 - Amostras de Arquivo de Áufio .WAV\nEscolha: ";
		cin >> escolha_amostras;
		system("CLS");
		cout << "\n\n\t\t************************ Obtenção de Amostras **************************\n";

		switch (escolha_amostras)
		{

		case(1):

			xn.setAmostras(xn.ObterAmostras_EntradaRandomica());
			xn.MostrarAmostras(xn.getAmostras());
			break;

		case(2):

			xn.setAmostras(xn.ObterAmostras_EntradaDigitada());
			xn.MostrarAmostras(xn.getAmostras());
			break;

		case(3):

			xn.setAmostras(xn.ObterAmostras_EntradaArquivoExterno());
			xn.MostrarAmostras(xn.getAmostras());
			break;

		case(4):

			xn.setAmostras(audioFile.samples[0]);
			xn.MostrarAmostras(xn.getAmostras());
			break;

		default:

			std::cout << "Entrada Inválida";
			break;
		}

		switch (escolha_transformada)
		{

		case(1):
			
			start = std::chrono::high_resolution_clock::now();
			Xk_DFT.DFT(xn.getAmostras());
			stop = std::chrono::high_resolution_clock::now();
			Xk_DFT.mostrarTransformadaFourier(Xk_DFT.getTransformada());
			
			break;

		case(2):

			std::cout << "aquiFFT";
			xn.ZeroPadding();
			start = std::chrono::high_resolution_clock::now();
			xn_reversa.setAmostras_Reversas(xn_reversa.Reverter_Amostras(xn));
			Xk_FFT.FFT(xn_reversa.getAmostras_Reversas());
			stop = std::chrono::high_resolution_clock::now();
			//Xk_FFT.mostrarTransformadaFourier(Xk_FFT.getTransformada());
			break;

		default:
			break;

		}
		std::cout << "\n\t************** MEDIÇÃO DE DESEMPENHO DA EXECUÇÃO DO ALGORITMO ************* " << endl;
		std::cout << "\n\tTempo requerido para execução do código da transformada escolhida: " << (duration_cast<microseconds>(stop - start)).count() << " microsegundos\n\n\n\n" << endl;

		system("PAUSE");

		cout << "\n\n\n Deseja continuar? 1 - Continuar ; 0 - Sair ";
		cin >> escolha_continuar;
		
	
	
	} while (escolha_continuar);


	system("PAUSE");
	return EXIT_SUCCESS;
}

