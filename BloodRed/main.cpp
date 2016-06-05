#include <iostream>
#include <BRCore.h>
#include <Eigen/Dense>
#include <memory>


int main( int argc, char* args[] )
{   
    Eigen::Vector2d v1( 2, 3 );
    Eigen::Vector2d v2(1, 2);    
    std::cout << v1 + v2 << std::endl;

    std::unique_ptr<BRCore::Engine> engine(new BRCore::Engine());
    if ( engine->Start() != 0 )
    {
        std::cout << "Window creation error: " << SDL_GetError() << std::endl;
        return 1;
    }                            

    // TODO: Set up any initial scenes, etc.

    engine->Run();    

    return 0;
}