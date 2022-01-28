#ifndef _texture_h
#define _texture_h

#include <glad/glad.h>
#include <stb_image.h>

#include "utils.h"

struct _texture
{
    u32 id;
};

typedef struct _texture texture;

texture load_texture(const char* path);

void use_texture(texture* self);

void unload_texture(texture* self);

#endif