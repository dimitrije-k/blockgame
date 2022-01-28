#ifndef _camera_h
#define _camera_h

#include <cglm/cglm.h>

#include "utils.h"
#include "window.h"

struct _camera
{
    float fov, znear, zfar;
    mat4 v, p;
    struct { float x, y, z; } pos;
    struct { float x, y; } rot;
    window* window;
};

typedef struct _camera camera;

camera init_camera(window* window);

void project_camera(camera* self);

#endif