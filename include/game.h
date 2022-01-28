#ifndef _game_h
#define _game_h

#include "window.h"
#include "game_renderer.h"

struct _game
{
    window window;
    game_renderer gr;
};

typedef struct _game game;

game init_game(void);

void run_game(game* self);

void deinit_game(game* self);

#endif