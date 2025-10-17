#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "snakeai.h"
#include "game_mode.h"
#include <atomic>
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void SetMode(GameMode mode) { current_mode = mode; }
  GameMode GetMode() const { return current_mode; }
  void workerThread(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration); 

 private:
  Snake snake;
  Snakeai snake2;
  SDL_Point food;
  std::atomic<bool> isPaused{false};

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  int speedMultiplier = 0;
  int score{0};
  GameMode current_mode{GameMode::SetSpeed};  // Default to Gameplay
  std::atomic<bool> running{true};  //  Use atomic for thread-safe access

  void PlaceFood();
  void Update();
};

#endif