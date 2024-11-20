#include "Game.h"

int main(){
    
    Game game;

    bool success = game.Init();
    if(success){
        FN_INFO("Success");
        game.Run();
    }

    // game.Shutdown();
    
    return 0;
}