#ifndef _game_h
#define _game_h

#include "window.h"

#include "game_renderer.h"
#include "chunk.h"

struct _game
{
    window window;
    game_renderer gr;
    chunk chunk;
    struct {
        bool w, a, s, d, shift, space;
    } keys;
    float last_update;
    float delta_time;
};

typedef struct _game game;

game init_game(void);

void run_game(game* self);

void deinit_game(game* self);

#endif