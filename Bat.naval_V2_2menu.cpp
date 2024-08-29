#include <iomanip>
#include <iostream>

using namespace std;

const int linhas = 15;
const int colunas = 15;

int main() {

  int escolhajogo;

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

      char tabuleiro[linhas][colunas];

      for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
          tabuleiro[i][j] = '0';
        }
      }

      cout << "    ";
      for (int i = 1; i <= colunas; i++) {
        cout << setw(3) << i;
      }

      cout << endl;

      for (int i = 0; i < linhas; i++) {
        cout << " " << static_cast<char>('A' + i) << " |";
        for (int j = 0; j < colunas; j++) {
          cout << setw(3) << tabuleiro[i][j];
        }

        cout << endl;
      }
      break;
    }

    case 2:

      cout << "Escolheu a opcao 2" << endl;
      break;

    case 3:

      cout << "Escolheu a opcao 3" << endl;
      break;

    case 4:

      cout << "Saindo do programa..." << endl;
      break;

    default:
      cout << "Opcao inválida!" << endl;
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
  }

  return 0;
}
