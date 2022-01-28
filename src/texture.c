#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

texture load_texture(const char* path)
{
    texture self = { 0 };
    glGenTextures(1, &self.id);

    glBindTexture(GL_TEXTURE_2D, self.id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int w, h, ch;
    u8* data = stbi_load(path, &w, &h, &ch, 0);
    assert(data);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);

    return self;
}

void use_texture(texture* self)
{
    glBindTexture(GL_TEXTURE_2D, self->id);
}

void unload_texture(texture* self)
{
    glDeleteTextures(1, &self->id);
}