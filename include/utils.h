#ifndef _utils_h
#define _utils_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
typedef double f64;

#define CLAMPF(f, l, h) (float)((f < l) ? l : (f > h) ? h : f)

#endif