

// na novo spiši Game.cpp > movement() metodo
// zoptimiziraj Playfield.cpp > deleteLines() metodo
// uredi renderer.cpp (to ni nicemur podobno)
// v meniju dodaj scoreboard
// ozadje za intro/main meni
// ozadje za game over
// ozadje za pavzo > nek napis "Paused"
// implementiraj boljši randomizer



#pragma once
#include "Renderer.hpp"


int main() {

    WindowManager windowManager;
    InputManager inputManager(&windowManager);

    Playfield playField;

    Game game(&inputManager, &playField);

    MainMenu mainMenu(&inputManager, &game);


    Renderer renderer(&windowManager, &playField, &game, &mainMenu);



    while (windowManager.getWindow()->isOpen()) {

        if (game.getState() == Quit)
            return 0;


        while (game.getState() == Start) {

            mainMenu.input();
            mainMenu.action();
            renderer.renderMenu(Start);

        }

        while (game.getState() == Playing) {

            game.input();
            game.movement();
            renderer.renderGame();

        }

        while (game.getState() == Pause) {
            
            mainMenu.input();
            mainMenu.action();
            game.updatePlayTime();
            renderer.renderMenu(Pause);

        }

        while (game.getState() == Gameover) {

            mainMenu.input();
            mainMenu.action();
            renderer.renderMenu(Gameover);

        }



    }
        
    return 0;

}

