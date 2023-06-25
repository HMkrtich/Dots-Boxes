#include <iostream>
#include "Board.h"
#include "Game.h"
#include <bitset>
int main() {
    std::string options[] = {"2 x 2", "3 x 3", "4 x 4", "5 x 5"};
//     Choose the size of the board
    std::cout<<"Welcome to the game of Dots and Boxes!"<<std::endl;
    std::cout<<"Choose the size of the board:"<<std::endl;
    for(int i = 0; i < 4; i++){
        std::cout<<i + 1<<". "<<options[i]<<std::endl;
    }
    int choice;
    std::cin>>choice;
    int height = 0;
    int width = 0;
    if(choice == 1){
        height = 2;
        width = 2;
        Game<12> game = Game<12>(height, width);
        game.start();
    }
    else if(choice == 2){
        height = 3;
        width = 3;
        Game<24> game = Game<24>(height, width);
        game.start();
    }
    else if(choice == 3) {
        height = 4;
        width = 4;
        Game<40> game = Game<40>(height, width);
        game.start();
    }
    else if (choice == 4){
        height = 5;
        width = 5;
        Game<60> game = Game<60>(height, width);
        game.start();
    }
    else{
        std::cout<<"Invalid choice!"<<std::endl;
    }
    return 0;
}
