///
/// @file      application.h
/// @brief     アプリケーションモジュール。
/// @author    masaniwa
/// @date      2017/3/21
/// @copyright (c) 2017 masaniwa
///

#ifndef APPLICATION
#define APPLICATION

#include <memory>

#include <opencv2/highgui.hpp>
#include <SDL.h>

namespace application
{
class App final
{
public:
    App();

    ~App() ;

    void Run();

private:
    void initialize();

    void finalize() ;

    void tuneFPS() ;

    void checkQuitEvent() ;

    void render();

    bool continuation = true;
    uint32_t last = 0;      

    cv::VideoCapture capture;
    cv::Mat frame;           

    std::shared_ptr<SDL_Window> window;
    std::shared_ptr<SDL_Renderer> renderer;
    std::shared_ptr<SDL_Texture> texture;
};
}
#endif
