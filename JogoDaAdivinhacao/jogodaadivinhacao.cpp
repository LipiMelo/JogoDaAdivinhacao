#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main() {
	cout << " *************************************" << endl;
	cout << " *Bem - vindo ao jogo da adivinhação *" << endl;
	cout << " *************************************" << endl << endl;

	char dificuldade;
	cout << " Escolha seu nivel de dificuldade: " << endl;
	cout << "Facil(F), Medio (M), Dificil (D)." << endl;
	cin >> dificuldade;

	srand(time(NULL));
	const int NUMERO_SECRETO = rand()%100;

	cout << "numero secreto: " << NUMERO_SECRETO << endl;

	int numero_de_tentativas;

	if (dificuldade == 'F') {
		numero_de_tentativas = 15;
	}
	else if (dificuldade == 'M') {
		numero_de_tentativas = 10;
	}
	else {
		numero_de_tentativas = 5;
	}

	bool nao_acertou = true;
	int tentativas = 0;

	double pontos = 1000.0;

	for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {

		int chute;
		cout << "Tentativa numero " << tentativas << endl << endl;
		cout << "Qual o seu chute? " << endl;
		cin >> chute;

		double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
		pontos = pontos - pontos_perdidos;

		bool acertou = chute == NUMERO_SECRETO;
		bool maior = chute > NUMERO_SECRETO;

		if (acertou) {
			cout << "Parabens voce acertou, o numero era: " << chute << endl << endl;
			nao_acertou = false;
			break;
		}
		else if (maior) {
			cout << "Seu chute foi maior que o numero escolhido. Tente novamente." << endl << endl;
		}
		else {
			cout << "Seu numero foi menor que o numero secreto. Tente novamente." << endl << endl;
		}
		
	}
	
	cout << "Fim de jogo!" << endl;
	if (nao_acertou) {

		cout<<"Voce errou todas as tentativas, boa sorte na proxima." << endl;

	}else {

		cout << "Voce acertou em " << tentativas << " tentativas." << endl;
		cout.precision(2);
		cout << fixed;
		cout << "Sua pontuacao foi de: " << pontos << "pontos."<< endl;

	}
	
	
}