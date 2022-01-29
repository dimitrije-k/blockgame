#include "chunk.h"

#define F32(v) (float) (v)

chunk generate_chunk(s32 x, s32 y, s32 seed)
{
    chunk self = { GRASS };

    for (int x = 0; x < CHUNK_WIDTH; x++)
    {
        for (int y = 0; y < CHUNK_HEIGHT; y++)
        {
            for (int z = 0; z < CHUNK_WIDTH; z++)
            {
                self.blocks[x][y][z] = DIRT;
            }
        }
    }

    return self;
}

mesh generate_chunk_mesh(chunk* self)
{
    u32 faces = 0;

    for (int x = 0; x < CHUNK_WIDTH; x++)
    {
        for (int y = 0; y < CHUNK_HEIGHT; y++)
        {
            for (int z = 0; z < CHUNK_WIDTH; z++)
            {
                if (get_block_data(self->blocks[x][y][z]).type == SOLID)
                {
                    if (x == 0 || get_block_data(self->blocks[x-1][y][z]).type == TRANSPARENT) faces++;
                    if (y == 0 || get_block_data(self->blocks[x][y-1][z]).type == TRANSPARENT) faces++;
                    if (z == 0 || get_block_data(self->blocks[x][y][z-1]).type == TRANSPARENT) faces++;

                    if (x == CHUNK_WIDTH  - 1 || get_block_data(self->blocks[x+1][y][z]).type == TRANSPARENT) faces++;
                    if (y == CHUNK_HEIGHT - 1 || get_block_data(self->blocks[x][y+1][z]).type == TRANSPARENT) faces++;
                    if (z == CHUNK_WIDTH  - 1 || get_block_data(self->blocks[x][y][z+1]).type == TRANSPARENT) faces++;
                }
            }
        }
    }

    u32 gen = 0;
    u32* indices = malloc(faces * 24);
    struct vertex* vertices = malloc(faces * 4 * sizeof(struct vertex));

    for (int x = 0; x < CHUNK_WIDTH; x++)
    {
        for (int y = 0; y < CHUNK_HEIGHT; y++)
        {
            for (int z = 0; z < CHUNK_WIDTH; z++)
            {
                struct _block_data bd = get_block_data(self->blocks[x][y][z]);

                if (bd.type == SOLID)
                {
                    if (x == 0 || get_block_data(self->blocks[x-1][y][z]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x), F32(y), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.xn.x, bd.uv_data.xn.y + 0.0625f};
                        vertices[gen*4+1] = (struct vertex){F32(x), F32(y), F32(z+1),   0.8f, 0.8f, 0.8f,   bd.uv_data.xn.x+0.0625f, bd.uv_data.xn.y+0.0625f};
                        vertices[gen*4+2] = (struct vertex){F32(x), F32(y+1), F32(z+1),   0.8f, 0.8f, 0.8f,   bd.uv_data.xn.x+0.0625f, bd.uv_data.xn.y};
                        vertices[gen*4+3] = (struct vertex){F32(x), F32(y+1), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.xn.x, bd.uv_data.xn.y};

                        indices[gen * 6] = gen * 4;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen*4+2;
                        indices[gen*6+3] = gen*4;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen*4+3;

                        gen++;
                    }

                    if (y == 0 || get_block_data(self->blocks[x][y-1][z]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x), F32(y), F32(z),   0.7f, 0.7f, 0.7f,   bd.uv_data.yn.x, bd.uv_data.yn.y + 0.0625f};
                        vertices[gen*4+1] = (struct vertex){F32(x), F32(y), F32(z+1),   0.7f, 0.7f, 0.7f,   bd.uv_data.yn.x+0.0625f, bd.uv_data.yn.y+0.0625f};
                        vertices[gen*4+2] = (struct vertex){F32(x+1), F32(y), F32(z+1),   0.7f, 0.7f, 0.7f,   bd.uv_data.yn.x+0.0625f, bd.uv_data.yn.y};
                        vertices[gen*4+3] = (struct vertex){F32(x+1), F32(y), F32(z),   0.7f, 0.7f, 0.7f,   bd.uv_data.yn.x, bd.uv_data.yn.y};

                        indices[gen * 6] = gen*4+2;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen * 4;
                        indices[gen*6+3] = gen*4+3;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen * 4;

                        gen++;
                    }

                    if (z == 0 || get_block_data(self->blocks[x][y][z-1]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x+1), F32(y), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.zn.x, bd.uv_data.zn.y + 0.0625f};
                        vertices[gen*4+1] = (struct vertex){F32(x), F32(y), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.zn.x+0.0625f, bd.uv_data.zn.y+0.0625f};
                        vertices[gen*4+2] = (struct vertex){F32(x), F32(y+1), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.zn.x+0.0625f, bd.uv_data.zn.y};
                        vertices[gen*4+3] = (struct vertex){F32(x+1), F32(y+1), F32(z),   0.8f, 0.8f, 0.8f,   bd.uv_data.zn.x, bd.uv_data.zn.y};

                        indices[gen * 6] = gen * 4;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen*4+2;
                        indices[gen*6+3] = gen*4;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen*4+3;

                        gen++;
                    }

                    if (x == CHUNK_WIDTH  - 1 || get_block_data(self->blocks[x+1][y][z]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x+1), F32(y+1), F32(z),   0.9f, 0.9f, 0.9f,   bd.uv_data.xp.x, bd.uv_data.xp.y};
                        vertices[gen*4+1] = (struct vertex){F32(x+1), F32(y+1), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.xp.x+0.0625f, bd.uv_data.xp.y};
                        vertices[gen*4+2] = (struct vertex){F32(x+1), F32(y), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.xp.x+0.0625f, bd.uv_data.xp.y+0.0625f};
                        vertices[gen*4+3] = (struct vertex){F32(x+1), F32(y), F32(z),   0.9f, 0.9f, 0.9f,   bd.uv_data.xp.x, bd.uv_data.xp.y+0.0625f};

                        indices[gen * 6] = gen * 4;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen*4+2;
                        indices[gen*6+3] = gen*4;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen*4+3;

                        gen++;
                    }

                    if (y == CHUNK_HEIGHT - 1 || get_block_data(self->blocks[x][y+1][z]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x+1), F32(y+1), F32(z),   1.0f, 1.0f, 1.0f,   bd.uv_data.yp.x, bd.uv_data.yp.y + 0.0625f};
                        vertices[gen*4+1] = (struct vertex){F32(x+1), F32(y+1), F32(z+1),   1.0f, 1.0f, 1.0f,   bd.uv_data.yp.x+0.0625f, bd.uv_data.yp.y+0.0625f};
                        vertices[gen*4+2] = (struct vertex){F32(x), F32(y+1), F32(z+1),   1.0f, 1.0f, 1.0f,   bd.uv_data.yp.x+0.0625f, bd.uv_data.yp.y};
                        vertices[gen*4+3] = (struct vertex){F32(x), F32(y+1), F32(z),   1.0f, 1.0f, 1.0f,   bd.uv_data.yp.x, bd.uv_data.yp.y};

                        indices[gen * 6] = gen*4+2;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen * 4;
                        indices[gen*6+3] = gen*4+3;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen * 4;

                        gen++;
                    }
                    
                    if (z == CHUNK_WIDTH  - 1 || get_block_data(self->blocks[x][y][z+1]).type == TRANSPARENT)
                    {
                        vertices[gen * 4] = (struct vertex){F32(x+1), F32(y+1), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.zp.x, bd.uv_data.zp.y};
                        vertices[gen*4+1] = (struct vertex){F32(x), F32(y+1), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.zp.x+0.0625f, bd.uv_data.zp.y};
                        vertices[gen*4+2] = (struct vertex){F32(x), F32(y), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.zp.x+0.0625f, bd.uv_data.zp.y+0.0625f};
                        vertices[gen*4+3] = (struct vertex){F32(x+1), F32(y), F32(z+1),   0.9f, 0.9f, 0.9f,   bd.uv_data.zp.x, bd.uv_data.zp.y+0.0625f};

                        indices[gen * 6] = gen * 4;
                        indices[gen*6+1] = gen*4+1;
                        indices[gen*6+2] = gen*4+2;
                        indices[gen*6+3] = gen*4;
                        indices[gen*6+4] = gen*4+2;
                        indices[gen*6+5] = gen*4+3;

                        gen++;
                    }
                }
            }
        }
    }

    mesh chunk_mesh = init_mesh(vertices, faces * 4, indices, faces * 6);

    free(vertices);
    free(indices);

    return chunk_mesh;
}