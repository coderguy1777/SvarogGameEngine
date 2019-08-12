#pragma once 
#ifdef NODE_H
#define NODE_H
#endif 
#include "macrodefs.h"
#define NODE_INT int
#define NODE_DOUBLE double
#define NODE_FLOAT float
#define NODE_CHAR char
#define NODE_SHORT short
#define NODE_LONG long
#define NODE_UINT32 std::uint32_t
#define NODE_UINT16 std::uint16_t
#define NODE_UINT8 std::uint8_t
struct Node
{
    Node *next;
    struct {
        NODE_INT data_int;
    };

    struct {
        NODE_DOUBLE data_double;
    };

    struct {
        NODE_FLOAT data_float;
    };

    struct {
        NODE_CHAR data_char;
    };

    struct {
        NODE_SHORT data_short;
    };

    struct {
        NODE_LONG data_long;
    };

    struct {
        NODE_UINT32 data_uint32;
    };

    struct {
        NODE_UINT16 data_uint16;
    };

    struct {
        NODE_UINT8 data_uint8;
    };
};
