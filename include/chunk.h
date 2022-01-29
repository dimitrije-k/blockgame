#ifndef _chunk_h
#define _chunk_h

#include <perlin.h>

#include "utils.h"
#include "block.h"
#include "mesh.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 256

#define CHUNK_GEN_OFFSET 16777216

// chunky boii
struct _chunk
{
    block_id blocks[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_WIDTH];
    mesh chunk_mesh;
};

typedef struct _chunk chunk;

chunk generate_chunk(s32 cx, s32 cz, s32 seed);

mesh generate_chunk_mesh(chunk* self);

#endif