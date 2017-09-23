///
/// @file      main.cc
/// @brief     SDLとOpenCVを連携しました。
/// @author    masaniwa
/// @date      2017/3/21
/// @copyright (c) 2017 masaniwa
///

#include <iostream>

#include <SDL.h>

#include "application.h"

namespace
{
using namespace application;
using namespace std;
}

int main(int argc, char *argv[])
{
    try
    {
        App().Run();
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}


