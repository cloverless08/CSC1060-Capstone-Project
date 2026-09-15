#pragma once

#include "structs.h"
#include <SDL2/SDL.h>

std::thread GetKeyPress(SDL_Event &event, bool &running, Camera &cam);