#pragma once 
#ifdef NODE_H
#define NODE_H
#endif 
#include "core/String.h"
#define NODE_INT int
#define NODE_DOUBLE double
#define NODE_FLOAT float
#define NODE_CHAR char
#define NODE_SHORT short
#define NODE_LONG long
#define NODE_UINT32 uint32_t
#define NODE_UINT16 uint16_t
#define NODE_UINT8 uint8_t
#define NODE_BYTE BYTE
#define NODE_STRING String

union Node
{
    Node *next;
    struct {
        NODE_INT data;
    };

    struct {
        NODE_DOUBLE data;
    };

    struct {
        NODE_FLOAT data;
    };

    struct {
        NODE_STRING data;
    };

    struct {
        NODE_CHAR data;
    };

    struct {
        NODE_SHORT data;
    };

    struct {
        NODE_LONG data;
    };

    struct {
        NODE_UINT32 data;
    };

    struct {
        NODE_UINT16 data;
    };

    struct {
        NODE_UINT8 data;
    };
    
    struct {
        NODE_BYTE data;
    };
};
