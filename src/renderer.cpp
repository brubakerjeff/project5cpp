#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {

  SDL_Surface* gScreenSurface = NULL;
  SDL_Surface* gHelloWorld = NULL;
  SDL_Surface* gOne = NULL;
  SDL_Surface* gTwo = NULL;
  SDL_Surface* gThree = NULL;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

    gScreenSurface = SDL_GetWindowSurface( sdl_window );

    gHelloWorld = SDL_LoadBMP( "sprites/speedprompt.bmp" );
 
    gOne = SDL_LoadBMP( "sprites/one.bmp" );
    gTwo = SDL_LoadBMP( "sprites/two.bmp" );
    gThree = SDL_LoadBMP( "sprites/three.bmp" );
 

    if (!gHelloWorld) {
      std::cerr << "Unable to load image hello.bmp! SDL Error: " << SDL_GetError() << "\n";
    }

    SDL_Rect destRect;
    destRect.x = 25;       // Horizontal position (left side)
    destRect.y = 225;     // Vertical position (lower it by 200 pixels, adjust as needed)
    destRect.w = 0;       // These can be 0 because SDL_BlitSurface ignores w/h of dest
    destRect.h = 0;

    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, &destRect );

    SDL_Rect destRect2;
    destRect2.x = 175;       // Horizontal position (left side)
    destRect2.y = 230;     // Vertical position (lower it by 200 pixels, adjust as needed)
    destRect2.w = 0;       // These can be 0 because SDL_BlitSurface ignores w/h of dest
    destRect2.h = 0;

    SDL_BlitSurface( gOne, NULL, gScreenSurface, &destRect2 );

    SDL_UpdateWindowSurface( sdl_window );
    std::cin.get(); // Waits for the user to press Enter


}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
