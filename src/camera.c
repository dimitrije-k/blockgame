#include "camera.h"

camera init_camera(window* window)
{
    camera self = { 0 };
    self.fov = 70.0f;

    self.pos.x = 0.0f;
    self.pos.y = 0.0f;
    self.pos.z = -2.0f;
    
    self.rot.x = 0.0f;
    self.rot.y = 90.0f;

    self.znear = 0.1f;
    self.zfar = 1024.0f;

    self.window = window;

    return self;
}

void project_camera(camera* self)
{
    vec3 target = {
        self->pos.x + sinf(glm_rad(self->rot.x)) * sinf(glm_rad(self->rot.y)),
        self->pos.y + cosf(glm_rad(self->rot.y)),
        self->pos.z + cosf(glm_rad(self->rot.x)) * sinf(glm_rad(self->rot.y))
    };

    glm_mat4_identity(self->v);
    glm_mat4_identity(self->p);

    glm_lookat((vec3){self->pos.x, self->pos.y, self->pos.z}, target, (vec3){0.0f, 1.0f, 0.0f}, self->v);
    glm_perspective(self->fov, 1.33f, self->znear, self->zfar, self->p);
}