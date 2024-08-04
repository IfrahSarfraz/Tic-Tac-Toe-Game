#include<iostream>
using namespace std;
void displayboard();
void playerchoice();
void blockreset();
void exit_game();
void show_winners_list(const string winners[], int size);
bool gameover();
struct data{
    bool draw = false;
    char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    char turn = 'X';
    char player1[20], player2[20];
    bool decision = false;
    int reset = 0;
};
struct data d;
int main(){
    int choice;
    const int MAX_WINNERS = 100;
    string winners[MAX_WINNERS];
    int winnersCount = 0;
    cout << "\n\n\t\t**************** WELCOME to C++ GAME *****************\n\n";
    cout << "\t\t**************** T I C K  T A C  T O E *****************\n\n\n";
    do{
        cout << "\t\t 1. PLAY GAME\n\n";
        cout << "\t\t 2. SHOW WINNERS LIST\n\n";
        cout << "\t\t 3. EXIT GAME\n\n\n";
        cout << "\t\t=======================================================" << endl;
        cout << "\t\t=======================================================" << endl;
        cout << "\t\t Enter your choice=";
        cin >> choice;
        system("cls"); // Note: This line may not work on all systems, consider using system("clear") for Unix-like systems
        switch (choice){
            case 1:
                cout << "\n\n\tEnter player [X] name=";
                cin >> d.player1;
                cout << "\tEnter player [O] name=";
                cin >> d.player2;
                while (gameover()) {
                    displayboard();
                    playerchoice();
                    gameover();
                }
                if (d.turn == 'X' && d.draw == false){
                    displayboard();
                    cout << "\n\t" << d.player2 << " [O] Wins!!\n\tCongratulations!" << endl;
                    cout << "\n\t\t\''HOPE YOU ENJOY THE GAME''!!!!";
                    cout << "\n\n\tDO YOU WANT TO PLAY AGAIN\n\n" << endl;
                    blockreset();
                    winners[winnersCount++] = d.player2;
                }
                else if (d.turn == 'O' && d.draw == false) {
                    displayboard();
                    cout << "\n\t" << d.player1 << " [X] Wins!!\n\tCongratulations!" << endl;
                    cout << "\n\t\t\tHOPE YOU ENJOY THE GAME!!!!";
                    cout << "\n\n\tDO YOU WANT TO PLAY AGAIN\n\n" << endl;
                    blockreset();
                    winners[winnersCount++] = d.player1;
                }
                else if (d.draw == true){
                    displayboard();
                    cout << "\n\t\tGame Draw" << endl;
                    cout << "\n\t\t\tHOPE YOU ENJOY THE GAME!!!!";
                    cout << "\n\n\tDO YOU WANT TO PLAY AGAIN\n\n" << endl;
                    d.decision = true;
                }
                break;
            case 2:
                show_winners_list(winners, winnersCount);
                break;
            case 3:
                exit_game();
                break;
            default:
                cout << "\n\tINVALID CHOICE" << endl;
        }
    } while (choice != 3);
    return 0;
}
void displayboard(){
    system("cls"); // Note: This line may not work on all systems, consider using system("clear") for Unix-like systems
    cout << "\n   T I C K  T A C  T O E\n" << endl;
    cout << "\t" << d.player1 << " [X]\n\t" << d.player2 << " [0]" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << d.board[0][0] << "  |  " << d.board[0][1] << "  |  " << d.board[0][2] << "  " << endl;
    cout << "\t\t__________________\n" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << d.board[1][0] << "  |  " << d.board[1][1] << "  |  " << d.board[1][2] << "  " << endl;
    cout << "\t\t__________________\n" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << d.board[2][0] << "  |  " << d.board[2][1] << "  |  " << d.board[2][2] << "  " << endl;
}
void playerchoice(){
    int choice;
    int row, column;
    if (d.turn == 'X')
        cout << "\n\t" << d.player1 << " [X] turn:";
    if (d.turn == 'O')
        cout << "\n\t" << d.player2 << " [O] turn:";
    cin >> choice;
    switch (choice){
    case 1:
        row = 0; column = 0;
        break;
    case 2:
        row = 0; column = 1;
        break;
    case 3:
        row = 0; column = 2;
        break;
    case 4:
        row = 1; column = 0;
        break;
    case 5:
        row = 1; column = 1;
        break;
    case 6:
        row = 1; column = 2;
        break;
    case 7:
        row = 2; column = 0;
        break;
    case 8:
        row = 2; column = 1;
        break;
    case 9:
        row = 2; column = 2;
        break;
    default:
        cout << "Invalid choice";
    }
    // Check if the selected position is already taken
    if (d.board[row][column] == 'X' || d.board[row][column] == 'O'){
        cout << "Position already taken. Choose another position." << endl;
        playerchoice(); // Ask the player to choose another position
    }
    else{
        if (d.turn == 'X'){
            d.board[row][column] = 'X';
            d.turn = 'O';
        }
        else if (d.turn == 'O'){
            d.board[row][column] = 'O';
            d.turn = 'X';
        }
    }
}
void blockreset(){
    d.board[0][0] = '1';
    d.board[0][1] = '2';
    d.board[0][2] = '3';

    d.board[1][0] = '4';
    d.board[1][1] = '5';
    d.board[1][2] = '6';

    d.board[2][0] = '7';
    d.board[2][1] = '8';
    d.board[2][2] = '9';

    d.decision = true;
    d.reset = 1;
}
bool gameover(){
    d.decision = false;
    for (int i = 0; i < 3; i++){
        if ((d.board[i][0] == d.board[i][1]) && (d.board[i][0] == d.board[i][2])){
            return d.decision;
        }
        else if ((d.board[0][i] == d.board[1][i]) && (d.board[0][i] == d.board[2][i])){
            return d.decision;
        }
        else if ((d.board[0][0] == d.board[1][1]) && (d.board[0][0] == d.board[2][2])){
            return d.decision;
        }
        else if ((d.board[0][2] == d.board[1][1]) && (d.board[0][2] == d.board[2][0])){
            return d.decision;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if ((d.board[i][j] != 'X') && (d.board[i][j] != 'O'))
                return true;
        }
    }
    d.draw = true;
    return d.decision;
}
void exit_game(){
    cout << "\n\t\t\n";
    cout << "\t\t\n";
    cout << "\n\t\t   *****E X I T  F R O M  G A M E*****\n";
    cout << "\n\t\t   *********GAME DESIGNED BY  Ifrah Sarfraz & Iqra Hafeez*********\t\t\t";
}
void show_winners_list(const string winners[], int size){
    cout << "\n\t************ WINNERS LIST ************\n\n";
    for (int i = 0; i < size; ++i){
        cout << "\t" << i + 1 << ". " << winners[i] << endl;}
}
