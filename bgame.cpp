#include <iostream>
#include <vector>


using namespace std;

const int rows = 16;
const int cols = 15;

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < rows; ++j) {
            board[i][j] = '0';
        }
    }
}

void printBoard(const vector<vector<char>>& board) {
    cout << "  ";
    for (int i = 1; i <= cols; ++i) {
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 1; i < rows; ++i) {
        cout << i << " ";
        for (int j = 0; j < rows; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

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

            vector<vector<char>> board(rows, vector<char>(cols));
            initializeBoard(board);
            printBoard(board);
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
