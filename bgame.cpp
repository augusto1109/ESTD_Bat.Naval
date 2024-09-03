#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

const int b_size = 15;

void inicializaTabuleiro(char tabuleiro[b_size][b_size]) {
  for (int i = 0; i < b_size; i++) {
    for (int j = 0; j < b_size; j++) {
      tabuleiro[i][j] = '0';
    }
  }
}

void imprimeTabuleiro(char tabuleiro[b_size][b_size]) {
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

bool podePosicionarNavio(char tabuleiros[b_size][b_size], int linha, int coluna,
                         int tamanho, char direcao) {
  if (direcao == 'H') {
    if (coluna + tamanho > b_size)
      return false;

    for (int i = 0; i < tamanho; i++) {
      if (tabuleiros[linha][coluna + i] != '0')
        return false;
    }
  } else if (direcao == 'V') {
    if (linha + tamanho > b_size)
      return false;
    for (int i = 0; i < tamanho; i++) {
      if (tabuleiros[linha + i][coluna] != '0')
        return false;
    }
  }
  return true;
}

void posicionarNavio(char tabuleiro[b_size][b_size], int tamanho) {
  char linhaChar;
  int x, y;
  char direcao;
  bool posicionado = false;

  while (!posicionado) {
    cout << endl << "Posicione o navio de tamanho " << tamanho << " (linha coluna direcao [H/V]): ";
    cin >> linhaChar >> y >> direcao;

    if (cin.fail()) {
      cout << "Entrada inválida. Tente novamente." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    x = linhaChar - 'A';
    y -= 1;

    if (direcao != 'H' && direcao != 'V') {
      cout << "Direcao invalida. Tente novamente." << endl;
      continue;
    }

    if (x >= 0 && x < b_size && y >= 0 && y < b_size &&
        podePosicionarNavio(tabuleiro, x, y, tamanho, direcao)) {
      if (direcao == 'H') {
        for (int i = 0; i < tamanho; i++) {
          tabuleiro[x][y + i] = 'N';
        }
      } else if (direcao == 'V') {
        for (int i = 0; i < tamanho; i++) {
          tabuleiro[x + i][y] = 'N';
        }
      }
      posicionado = true;
    } else {
      cout << "Posicao invalida. Tente novamente." << endl;
    }
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

        char tabuleiro[b_size][b_size];
        inicializaTabuleiro(tabuleiro);

        int numNavios = 3;
        cout << "O jogo começou!!\n" << endl;

        imprimeTabuleiro(tabuleiro);
        posicionarNavio(tabuleiro, numNavios);
        imprimeTabuleiro(tabuleiro);
        cout << endl;

        posicionarNavio(tabuleiro, numNavios);
        imprimeTabuleiro(tabuleiro);
        cout << endl;

        posicionarNavio(tabuleiro, numNavios);
        imprimeTabuleiro(tabuleiro);
        cout << endl;

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
        break;
      }
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
