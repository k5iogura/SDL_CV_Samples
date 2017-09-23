///
/// @file      application.cc
/// @brief     アプリケーションモジュール。
/// @author    masaniwa
/// @date      2017/3/21
/// @copyright (c) 2017 masaniwa
///

#include "application.h"

#include <iostream>
#include <stdexcept>

#include "sdlutil.h"

namespace
{
	using namespace cv;
	using namespace sdlutil;
	using namespace std;

	constexpr auto name = "Window";

	constexpr auto videoCaptureNotOpened = "VideoCapture object wasn't opened.";

	constexpr auto interval = 16;
}

namespace application
{
App::App()
{
//    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) throw runtime_error(SDL_GetError());
}

App::~App() 
{
    finalize();
    SDL_Quit();
}

void App::Run()
{
    initialize();

    while(continuation && capture.isOpened())
    {
		capture >> frame;
//        tuneFPS();
        checkQuitEvent();
        //render();
        Render("New Render",frame);
        //imshow("New Render",frame);
    }
}

void App::initialize()
{
    finalize();

    continuation = true;
    last = 0;

    capture.open(0);
    //capture.open("./Megamind.avi");

    if(!capture.isOpened()) throw runtime_error(videoCaptureNotOpened);

//    capture >> frame;

//    window = CreateWindow(name, frame.cols, frame.rows);
//    renderer = CreateRenderer(window);
//    texture = CreateStreamingTexture(renderer, frame.cols, frame.rows);
}

void App::finalize() 
{
    capture.release();
    frame.release();
    window.reset();
    renderer.reset();
    texture.reset();
}

void App::tuneFPS() 
{
    const auto elapsed = SDL_GetTicks() - last;

    if(elapsed < interval)
    {
        SDL_Delay(interval - elapsed);
    }

    last = SDL_GetTicks();
}

void App::checkQuitEvent() 
{
    SDL_Event event;

    while(SDL_PollEvent(&event) == 1)
    {
        if(event.type == SDL_QUIT && continuation)
        {
            continuation = false;
        }
    }
}

void App::render()
{
    auto code = 0;

    code += SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    code += SDL_RenderClear(renderer.get());

    capture >> frame;
    Draw(texture, frame);

    code += SDL_RenderCopy(renderer.get(), texture.get(), nullptr, nullptr);

    if(code < 0) throw runtime_error(SDL_GetError());

    SDL_RenderPresent(renderer.get());
}
}
