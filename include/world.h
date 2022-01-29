// ZA WARUDOOOOOOOOOOOOOOOOOOOOOO
#ifndef _world_h
#define _world_h

#include "utils.h"
#include "chunk.h"

// number of chunks in each direction
#define VIEW_DISTANCE 8

// also, when allocated the world chunks look like
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]     * is where the player should be at all times
// [ ] [ ] (*) [ ] [ ]    () is the center chunk
// [ ] [ ] [ ] [ ] [ ]    [] are other chunks
// [ ] [ ] [ ] [ ] [ ]
// there should always be (VIEW_DISTANCE * 2 + 1) ^ 2 chunks in the world, no more, no less

struct _world
{
    chunk* chunks;
    struct {
        s32 x, z;
    } center_chunk;
    s32 seed;
};

typedef struct _world world;

world init_world(void);

chunk* load_chunk(world* self, s32 x, s32 z);

void deinit_world(world* self);

#endif