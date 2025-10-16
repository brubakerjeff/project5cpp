#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "game_mode.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, GameMode &gamemode) const;
  void IncreaseSpeed(Snake &Snake) const;
  void DecreaseSpeed(Snake &snake) const;
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif