#ifndef _shader_h
#define _shader_h

#include <glad/glad.h>
#include "utils.h"

struct _shader
{
    u32 id;
};

typedef struct _shader shader;

shader load_shader(const char* vp, const char* fp);

void use_shader(shader* self);

void unload_shader(shader* self);

#endif