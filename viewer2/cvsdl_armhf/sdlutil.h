///
/// @file      sdlutil.h
/// @brief     SDLライブラリのユーティリティモジュール。
/// @author    masaniwa
/// @date      2017/3/21
/// @copyright (c) 2017 masaniwa
///

#ifndef SDLUTIL
#define SDLUTIL

#include <memory>
#include <string>

#include <opencv2/core.hpp>
#include <SDL.h>

namespace sdlutil
{
/// @brief  ウィンドウを生成する。
/// @param  name   ウィンドウの名前。
/// @param  width  ウィンドウの幅。
/// @param  height ウィンドウの高さ。
/// @return 生成したウィンドウ。
/// @throws runtime_error ウィンドウを生成できなかった場合。
std::shared_ptr<SDL_Window> CreateWindow(const std::string &name, int32_t width, int32_t height);

/// @brief  ウィンドウのレンダラを生成する。
/// @param  window ウィンドウ。
/// @return 生成したレンダラ。
/// @throws invalid_argument ウィンドウが無効だった場合。
/// @throws runtime_error    レンダラを生成できなかった場合。
std::shared_ptr<SDL_Renderer> CreateRenderer(const std::shared_ptr<SDL_Window> &window);

/// @brief  書き込み可能なテクスチャを生成する。
/// @param  renderer 使用するレンダラ。
/// @param  width    テクスチャの幅。
/// @param  height   テクスチャの高さ。
/// @return 生成したテクスチャ。
/// @throws invalid_argument レンダラが無効だった場合。
/// @throws runtime_error    テクスチャを生成できなかった場合。
std::shared_ptr<SDL_Texture> CreateStreamingTexture(const std::shared_ptr<SDL_Renderer> &renderer, int32_t width, int32_t height);

/// @brief  テクスチャに画像を描画する。
/// @param  texture テクスチャ。
/// @param  frame   画像。
/// @throws invalid_argument テクスチャが無効だった場合。
/// @throws runtime_error    テクスチャに描画できなかった場合。
void Draw(const std::shared_ptr<SDL_Texture> &texture, const cv::Mat &frame);

void Render(const std::string& name, const cv::Mat &frame);
}

#endif
