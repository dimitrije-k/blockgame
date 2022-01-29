#ifndef _block_h
#define _block_h

#include "utils.h"

#define BLOCK_ID_LAST DIRT
enum _block_id
{
    AIR,
    GRASS,
    DIRT
};

typedef enum _block_id block_id;

enum _block_type
{
    SOLID,
    TRANSPARENT
};

struct _block_data
{
    enum _block_type type;
    struct
    {
        struct
        {
            float x, y;
        } xn, xp, yn, yp, zn, zp;
    } uv_data;
};

struct _block_data get_block_data(block_id id);

#endif