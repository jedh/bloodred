#include <iostream>
#include <BRCore.h>
#include <Eigen/Dense>
#include <memory>
#include <SDL.h>
#include "TestScene.h";

int main( int argc, char* args[] )
{   
    Eigen::Vector2d v1( 2, 3 );
    Eigen::Vector2d v2(1, 2);    
    std::cout << v1 + v2 << std::endl;    

    std::unique_ptr<BRCore::Engine> engine(new BRCore::Engine());
    if ( engine->Start(1024, 768) != 0 )
    {
        std::cout << "Window creation error: " << SDL_GetError() << std::endl;
        return 1;
    }                            

    // TODO: Set up any initial scenes, etc.
    auto testScene = std::make_shared<BRGame::TestScene>("test", engine->Display(), engine->Input(), engine->Rendering(), engine->CameraMain());
    engine->Scenes()->AddScene(testScene);

    engine->Run();        

    return 0;
}