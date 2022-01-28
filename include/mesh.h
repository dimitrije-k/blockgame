#ifndef _mesh_h
#define _mesh_h

#include <glad/glad.h>
#include "utils.h"

struct _mesh
{
    u32 vbo, ebo, vao;
    s32 icount;
};

struct vertex
{
    float x, y, z;
};

typedef struct _mesh mesh;

mesh init_mesh(struct vertex* vertices, s32 vcount, u32* indices, s32 icount);

void render_mesh(mesh* self);

void deinit_mesh(mesh* self);

#endif