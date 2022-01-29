#include "block.h"

struct _block_data BLOCK_DATA[BLOCK_ID_LAST+1] = {
    [AIR] = {
        .type = TRANSPARENT
    },
    [GRASS] = {
        .type = SOLID,
        .uv_data = {
            .xn = {
                0.0625f, 0.0f
            },
            .xp = {
                0.0625f, 0.0f
            },
            .yn = {
                0.125f,  0.0f
            },
            .yp = {
                0.0f,    0.0f
            },
            .zn = {
                0.0625f, 0.0f
            },
            .zp = {
                0.0625f, 0.0f
            }
        }
    },
    [DIRT] = {
        .type = SOLID,
        .uv_data = {
            .xn = {
                0.125f, 0.0f
            },
            .xp = {
                0.125f,  0.0f
            },
            .yn = {
                0.125f,  0.0f
            },
            .yp = {
                0.125f,  0.0f
            },
            .zn = {
                0.125f,  0.0f
            },
            .zp = {
                0.125f,  0.0f
            }
        }
    }
};

struct _block_data get_block_data(block_id id)
{
    return BLOCK_DATA[id];
}