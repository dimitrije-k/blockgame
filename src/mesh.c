#include "mesh.h"

mesh init_mesh(struct vertex* vertices, s32 vcount, u32* indices, s32 icount)
{
    mesh self = { 0 };
    glGenBuffers(2, &self.vbo);
    glGenVertexArrays(1, &self.vao);

    glBindVertexArray(self.vao);

    glBindBuffer(GL_ARRAY_BUFFER, self.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct vertex) * vcount, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * icount, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(struct vertex), NULL);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(struct vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, false, sizeof(struct vertex), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    self.icount = icount;

    return self;
}

void render_mesh(mesh* self)
{
    glBindVertexArray(self->vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->ebo);

    glDrawElements(GL_TRIANGLES, self->icount, GL_UNSIGNED_INT, NULL);
}

void deinit_mesh(mesh* self)
{
    glDeleteBuffers(2, &self->vbo);
    glDeleteVertexArrays(1, &self->vao);
}