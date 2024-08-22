#include <iostream>

using namespace std;

const int linhas = 15;
const int colunas = 15;

int main () {
    int escolha;

    cout << "========================" << endl;
    cout << "Escolha o modo de jogo: " << endl;
    cout << "1. PvP" << endl;
    cout << "2. PvBot" << endl;
    cout << "3. BotvBot" << endl;
    cout << "4. Sair" << endl;
    cout << "=====================" << endl;
    cout << "Digite sua escolha: ";
    cin >> escolha;

    switch (escolha) {

        case 1: {
            
            cout << "Escolheu PvP" << endl;

            char tabuleiro[linhas][colunas];

            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    tabuleiro[i][j] = '0';
                }
            }

            cout << " ";
            for (int i = 1; i <= colunas; i++) {
                cout << i << " ";
            }

            cout << endl;
            
            for (int i = 0; i < linhas; i++) {
                cout << static_cast<char>('A' + i) << " ";
                for (int j = 0; j < colunas; j++) {
                    cout << tabuleiro[i][j] << " ";
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

    return 0;
}
