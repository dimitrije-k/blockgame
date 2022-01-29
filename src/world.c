#include "world.h"

typedef struct _world world;

world init_world(void)
{
    world self = { 0 };
    self.seed = rand();
    self.center_chunk.x = 0;
    self.center_chunk.z = 0;

    self.chunks = malloc(sizeof(chunk) * ((VIEW_DISTANCE * 2 + 1) * (VIEW_DISTANCE * 2 + 1)));

    for (s32 x = 0; x < VIEW_DISTANCE * 2 + 1; x++)
    {
        for (s32 z = 0; z < VIEW_DISTANCE * 2 + 1; z++)
        {
            self.chunks[x * (VIEW_DISTANCE * 2 + 1) + z] = generate_chunk(x * 16 - VIEW_DISTANCE, z * 16 - VIEW_DISTANCE, self.seed);
            self.chunks[x * (VIEW_DISTANCE * 2 + 1) + z].chunk_mesh = generate_chunk_mesh(&self.chunks[x * (VIEW_DISTANCE * 2 + 1) + z]);
        }
    }

    return self;
}

chunk* load_chunk(world* self, s32 x, s32 z)
{
    if (x > self->center_chunk.x + VIEW_DISTANCE || x < self->center_chunk.x - VIEW_DISTANCE)
    {
        return NULL;
    }
    else if (z > self->center_chunk.z + VIEW_DISTANCE || z < self->center_chunk.z - VIEW_DISTANCE)
    {
        return NULL;
    }
    else
    {
        return &self->chunks[(x-self->center_chunk.x) * (VIEW_DISTANCE * 2 + 1) + (z-self->center_chunk.z)];
    }
}

void deinit_world(world* self)
{
    free(self->chunks);
}