#include "shader.h"

char* _read_ascii_file(const char* path, s32* len)
{
    FILE* f = fopen(path, "rb");
    assert(f);

    fseek(f, 0, SEEK_END);
    *len = (int)ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buf = malloc(*len);
    fread(buf, 1, *len, f);

    return buf;
}

shader load_shader(const char* vp, const char* fp)
{
    shader self = { 0 };
    self.id = glCreateProgram();

    u32 vs, fs;

    vs = glCreateShader(GL_VERTEX_SHADER);
    fs = glCreateShader(GL_FRAGMENT_SHADER);

    char* buf;
    s32 len;

    buf = _read_ascii_file(vp, &len);
    glShaderSource(vs, 1, (const char* const*) &buf, &len);
    glCompileShader(vs);

    free(buf);

    buf = _read_ascii_file(fp, &len);
    glShaderSource(fs, 1, (const char* const*) &buf, &len);
    glCompileShader(fs);

    free(buf);

    glAttachShader(self.id, vs);
    glAttachShader(self.id, fs);

    glLinkProgram(self.id);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return self;
}

void use_shader(shader* self)
{
    glUseProgram(self->id);
}

void unload_shader(shader* self)
{
    glDeleteShader(self->id);
}