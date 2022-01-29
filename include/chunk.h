#ifndef _chunk_h
#define _chunk_h

#include "utils.h"
#include "block.h"
#include "mesh.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 16

// chunky boii
struct _chunk
{
    block_id blocks[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_WIDTH];
};

typedef struct _chunk chunk;

chunk generate_chunk(s32 x, s32 y, s32 seed);

mesh generate_chunk_mesh(chunk* self);

#endif