///
/// @file      sdlutil.cc
/// @brief     SDLライブラリのユーティリティモジュール。
/// @author    masaniwa
/// @date      2017/3/21
/// @copyright (c) 2017 masaniwa
///

#include "sdlutil.h"

#include <stdexcept>

namespace
{
using namespace cv;
using namespace std;

constexpr auto invalidWindow = "Window object was invalid.";     ///< ウィンドウが無効だったときのメッセージ。
constexpr auto invalidRenderer = "Renderer object was invalid."; ///< レンダラが無効だったときのメッセージ。
constexpr auto invalidTexture = "Texture object was invalid.";   ///< テクスチャが無効だったときのメッセージ。

constexpr auto textureFormat = SDL_PIXELFORMAT_RGBA8888; ///< 使用するテクスチャのフォーマット。

/// @brief  テクスチャのピクセル配列の長さを計算する。
/// @param  texture 計算するテクスチャ。
/// @return テクスチャのピクセル配列の長さ。
/// @throws invalid_argument テクスチャが無効だった場合。
/// @throws runtime_error    テクスチャの情報を取得できなかった場合。
int32_t calcPixelLength(const shared_ptr<SDL_Texture> &texture)
{
    if(!texture) throw invalid_argument(invalidTexture);

    auto width = 0;
    auto height = 0;

    if(SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height) < 0) throw runtime_error(SDL_GetError());

    return width * height;
}

/// @brief   Mat形式の画像データをテクスチャのピクセル配列にコピーする。
/// @param   pixels コピー先のテクスチャのピクセル配列。
/// @param   length ピクセル配列の長さ。
/// @param   frame  画像データ。
/// @throws  runtime_error テクスチャのフォーマットを取得できなかった場合。
/// @details テクスチャはロックされていなければならない。
void copyMatToPixels(uint32_t *pixels, const int32_t length, const Mat &frame)
{
    const auto format = SDL_AllocFormat(textureFormat);

    if(!format) throw runtime_error(SDL_GetError());

    for(auto row = 0; row < frame.rows; ++row)
    {
        const auto data = frame.ptr<Vec3b>(row);

        for(auto col = 0; col < frame.cols; ++col)
        {
            const auto pixel = data[col];
            const auto index = row * frame.cols + col;

            if(index >= length) return;

            *(pixels + index) = SDL_MapRGB(format, pixel[2], pixel[1], pixel[0]);
        }
    }
}
}

namespace sdlutil
{
shared_ptr<SDL_Window> CreateWindow(const string &name, const int32_t width, const int32_t height)
{
    auto window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    if(!window) throw runtime_error(SDL_GetError());

    return { window, SDL_DestroyWindow };
}

shared_ptr<SDL_Renderer> CreateRenderer(const shared_ptr<SDL_Window> &window)
{
    if(!window) throw invalid_argument(invalidWindow);

    auto renderer = SDL_CreateRenderer(window.get(), -1, 0);

    if(!renderer) throw runtime_error(SDL_GetError());

    return { renderer, SDL_DestroyRenderer };
}

shared_ptr<SDL_Texture> CreateStreamingTexture(const shared_ptr<SDL_Renderer> &renderer, const int32_t width, const int32_t height)
{
    if(!renderer) throw invalid_argument(invalidRenderer);

    auto texture = SDL_CreateTexture(renderer.get(), textureFormat, SDL_TEXTUREACCESS_STREAMING, width, height);

    if(!texture) throw runtime_error(SDL_GetError());

    return { texture, SDL_DestroyTexture };
}

void Draw(const shared_ptr<SDL_Texture> &texture, const Mat &frame)
{
    if(!texture) throw invalid_argument(invalidTexture);

    void *pixels = nullptr;

    auto pitch = 0;

    if(SDL_LockTexture(texture.get(), nullptr, &pixels, &pitch) < 0) throw runtime_error(SDL_GetError());

    const auto length = calcPixelLength(texture);

    copyMatToPixels(reinterpret_cast<uint32_t*>(pixels), length, frame);

    SDL_UnlockTexture(texture.get());
}
}
