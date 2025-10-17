#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

#include <mutex>
class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);

  void UpdateWindowTitle(int score, int fps, float speedMultiplier);
  void RenderSpeedSelection();
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  std::mutex render_mutex;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif