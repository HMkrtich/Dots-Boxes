#include <iostream>
#include "Board.h"
#include "Game.h"
#include <bitset>
int main() {

    std::string options[] = {"2 x 2", "3 x 3", "4 x 4"};
//     Choose the size of the board
    std::cout<<"Welcome to the game of Dots and Boxes!"<<std::endl;
    std::cout<<"Choose the size of the board:"<<std::endl;
    for(int i = 0; i < 3; i++){
        std::cout<<i + 1<<". "<<options[i]<<std::endl;
    }
    int choice;
    std::cin>>choice;
    int height = 0;
    int width = 0;
    switch(choice){
        case 1:
            height = 2;
            width = 2;
            break;
        case 2:
            height = 3;
            width = 3;
            break;
        case 3:
            height = 4;
            width = 4;
            break;
        default:
            std::cout<<"Invalid choice"<<std::endl;
            return 0;
    }


    Game game = Game(height, width);

    game.start();

    return 0;
}
