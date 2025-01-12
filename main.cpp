#include <iostream>
#include <cstdlib>
#include <string>


void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
int winn(int grid[7][6]);

int main(int argc, char** argv){
    int grille[7][6] = {};
    std::string choix;
    bool run = true;
    int player = 1;
    int result = 0;
    int c, valeur;
    drawGrid(grille);
    std::cout << "1 : J1 VS IA\n";
    std::cout << "2 : J1 VS J2\n";
    std::cout << "Veuillez choisir votre mode de jeu : ";
    std::cin >> c;
    while (run){
        if(c == 1 && player == 2){
            valeur = rand() % 8 + 0;
            choix = std::to_string(valeur);
            std::cout << choix << "\n";
        }
        else {
            std::cout << "player_" << player << " -> col : ";
            std::cin >> choix;
        }

        if (choix == "exit"){
            break;
        }

        bool success = false;

        if (choix.size() == 1){
            if (choix[0] >= '0' && choix[0] <= '7'){
                int col = choix[0]  - '0';
                success = playTurn(grille, col, player);
            }
        }

        system("clear");

        if (!success){
            std::cout << "votre choix est incorrect\n";
        } else{
            if (player == 1) player = 2;
            else player = 1;
        }

        drawGrid(grille);
        
        result = winn(grille);

        if(result == 1){
            run = false;
            std::cout << "Player_1 a gagne\n";
        }
        else if(result == 2){
            run = false;
            std::cout << "Player_2 a gagne\n";
        }
        else{
            std::cout << "\n";
        }
    }
    return 0;
}

void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}

int winn(int grid[7][6]){
    int win = 0;
    for (int line = 0; line < 7; line++){
        for (int col = 0; col < 6; col++){
            if (col <= 2 && grid[line][col] == 1 &&
                grid[line][col + 1] == 1 &&
                grid[line][col + 2] == 1 &&
                grid[line][col + 3] == 1) {
                win = 1;
            } else if (col <= 2 && grid[line][col] == 2 &&
                grid[line][col + 1] == 2 &&
                grid[line][col + 2] == 2 &&
                grid[line][col + 3] == 2) {
                win = 2;
            } else if (line <= 3 && grid[line][col] == 1 &&
                grid[line + 1][col] == 1 &&
                grid[line + 2][col] == 1 &&
                grid[line + 3][col] == 1) {
                win = 1;
            } else if (line <= 3 && grid[line][col] == 2 &&
                grid[line + 1][col] == 2 &&
                grid[line + 2][col] == 2 &&
                grid[line + 3][col] == 2) {
                win = 2;
            } else if (line <= 3 && col <= 2 && grid[line][col] == 1 &&
                grid[line + 1][col + 1] == 1 &&
                grid[line + 2][col + 2] == 1 &&
                grid[line + 3][col + 3] == 1) {
                win = 1;
            } else if (line <= 3 && col <= 2 && grid[line][col] == 2 &&
                grid[line + 1][col + 1] == 2 &&
                grid[line + 2][col + 2] == 2 &&
                grid[line + 3][col + 3] == 2) {
                win = 2;
            } else if (line >= 3 && col <= 2 && grid[line][col] == 1 &&
                grid[line - 1][col + 1] == 1 &&
                grid[line - 2][col + 2] == 1 &&
                grid[line - 3][col + 3] == 1) {
                win = 1;
            } else if (line >= 3 && col <= 2 && grid[line][col] == 2 &&
                grid[line - 1][col + 1] == 2 &&
                grid[line - 2][col + 2] == 2 &&
                grid[line - 3][col + 3] == 2) {
                win = 2;
            }
        }        
    }
    return win;
}
