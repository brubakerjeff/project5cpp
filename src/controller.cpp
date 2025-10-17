#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "game_mode.h"

void Controller::IncreaseSpeed(Snake &snake, int &speedMultiplier) const {
  speedMultiplier += 2;
  return;
}

void Controller::DecreaseSpeed(Snake &snake, int &speedMultiplier) const {
  speedMultiplier -= 2;
  return;
}

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, GameMode &gamemode, int &speedMultiplier) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
     
        if(gamemode == GameMode::SetSpeed) 
        {
           switch (e.key.keysym.sym) {
            case SDLK_UP:
              IncreaseSpeed(snake,speedMultiplier);
              break;

            case SDLK_DOWN:
              DecreaseSpeed(snake,speedMultiplier);
              break;

            case SDLK_RETURN:
              gamemode = GameMode::Gameplay;
              break;
           }
        } 
        else 
        {
         switch (e.key.keysym.sym) {
          case SDLK_ESCAPE:
            gamemode = GameMode::SetSpeed;
            break;
          case SDLK_UP:
            ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
            break;

          case SDLK_DOWN:
            ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
            break;

          case SDLK_LEFT:
            ChangeDirection(snake, Snake::Direction::kLeft,
                            Snake::Direction::kRight);
            break;

          case SDLK_RIGHT:
            ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
            break;
        }
      }
    }
  }
}