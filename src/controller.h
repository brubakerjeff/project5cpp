#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "game_mode.h"
#include <atomic>


class Controller {
 public:
  void HandleInput(std::atomic<bool> &running, Snake &snake, GameMode &gamemode, 
     int &speedMultiplier,std::atomic<bool> &isPaused) const;
  void IncreaseSpeed(Snake &Snake,  int &speedMultiplier) const;
  void DecreaseSpeed(Snake &snake,  int &speedMultiplier) const;
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif