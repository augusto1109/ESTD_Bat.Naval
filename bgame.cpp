#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

const int b_size = 15;
int navios[5] = {2, 2, 3, 3, 4};

void inicializaTabuleiro(char tabuleiro[b_size][b_size]) {
	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			tabuleiro[i][j] = '0';
		}
	}
}

void imprimeTabuleiro(const char tabuleiro[b_size][b_size]) {
	cout << endl;
	cout << "    ";
	for (int i = 1; i <= b_size; i++) {
		cout << setw(3) << i;
	}
	
	cout << endl;
	for (int i = 0; i < b_size; i++) {
		cout << " " << (char)('A' + i) << " |";
		for (int j = 0; j < b_size; j++) {
			cout << setw(3) << tabuleiro[i][j];
		}
		
		cout << endl;
	}
}

bool podePosicionarNavioManual(const char tabuleiro[b_size][b_size], int linha,
	int coluna) {
		return tabuleiro[linha][coluna] == '0';
	}

bool posicaoEhAdjacente(int linhaAnterior, int colunaAnterior, int linhaAtual,
	int colunaAtual) {
		return (abs(linhaAnterior - linhaAtual) == 1 &&
			colunaAnterior == colunaAtual) ||
		(abs(colunaAnterior - colunaAtual) == 1 &&
			linhaAnterior == linhaAtual);
	}

void posicionarNavioManual(char tabuleiro[b_size][b_size], int tamanho,
	const string &jogador) {
		char linhaChar;
		int x, y;
		bool posicionado = false;
		
		int linhaAnterior = -1, colunaAnterior = -1;
		for (int i = 0; i < tamanho; i++) {
			while (!posicionado) {
				cout << endl
				<< jogador << ", posicione a parte " << i + 1
				<< " do navio (linha coluna): ";
				cin >> linhaChar >> y;
				
				if (cin.fail()) {
					cout << "Entrada inválida. Tente novamente." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				
				x = linhaChar - 'A';
				y -= 1;
				
				if (x >= 0 && x < b_size && y >= 0 && y < b_size &&
					podePosicionarNavioManual(tabuleiro, x, y)) {
					if (i == 0 || posicaoEhAdjacente(linhaAnterior, colunaAnterior, x, y)) {
						tabuleiro[x][y] = 'N';
						linhaAnterior = x;
						colunaAnterior = y;
						posicionado = true;
					} else {
						cout << "Posição inválida. Tente novamente." << endl;
					}
				} else {
					cout << "Posição inválida ou já ocupada. Tente novamente." << endl;
				}
			}
			posicionado = false;
		}
	}

int main() {
	int escolhajogo;
	bool executando = true;
	
	while (executando) {
		cout << "================" << endl;
		cout << "Escolha o jogo: " << endl;
		cout << "1. Batalha naval" << endl;
		cout << "2. Jogo 2" << endl;
		cout << "3. Sair" << endl;
		cout << "================" << endl;
		cout << "Digite sua escolha: ";
		cin >> escolhajogo;
		
		switch (escolhajogo) {
			case 1: {
				cout << endl;
				cout << "* BATALHA NAVAL *" << endl;
				int escolhamodo;
				
				cout << "=======================" << endl;
				cout << "Escolha o modo de jogo: " << endl;
				cout << "1. PvP" << endl;
				cout << "2. PvBot" << endl;
				cout << "3. BotvBot" << endl;
				cout << "4. Sair" << endl;
				cout << "=====================" << endl;
				cout << "Digite sua escolha: ";
				cin >> escolhamodo;
				
				switch (escolhamodo) {
					case 1: {
						cout << endl;
						cout << "* Escolheu PvP *\n" << endl;
						
						char tabuleiro1[b_size][b_size];
						char tabuleiro2[b_size][b_size];
						inicializaTabuleiro(tabuleiro1);
						inicializaTabuleiro(tabuleiro2);
						
						cout << "O jogo começou!!\n" << endl;
						
						cout << "Jogador 1, posicione seus navios:" << endl;
						imprimeTabuleiro(tabuleiro1);
						for (int i = 0; i < 5; i++) {
							posicionarNavioManual(tabuleiro1, navios[i], "Jogador 1");
							imprimeTabuleiro(tabuleiro1);
						}
						
						cout << endl;
						cout << "Jogador 2, posicione seus navios:" << endl;
						imprimeTabuleiro(tabuleiro2);
						for (int i = 0; i < 5; i++) {
							posicionarNavioManual(tabuleiro2, navios[i], "Jogador 2");
							imprimeTabuleiro(tabuleiro2);
						}
						break;
					}
					
					case 2:
						cout << "Escolheu a opção 2" << endl;
						break;
					case 3:
						cout << "Escolheu a opção 3" << endl;
						break;
					case 4:
						cout << "Saindo do programa..." << endl;
						break;
					default:
						cout << "Opção inválida!" << endl;
						break;
					}
					break;
			}
			
			case 2:
				cout << "Nada ainda..." << endl;
				break;
			case 3:
				cout << "Saindo..." << endl;
				break;
			default:
				cout << "Opção inválida." << endl;
				return 0;
		}
	}
}
