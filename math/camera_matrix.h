#pragma once 
#ifdef CAMERA_MATRIX_H
#define CAMERA_MATRIX_H
#endif
using namespace std;
#include "libs.h"

class CameraMatrix : public Matrix4f {
    public: 
        // 6 view cooordinates for projection matrix
        float left, right, bottom, top, near, far;

        // matricie dimensions
        const int matrow = 4;
        const int matcol = 4;

        // class constructor
        CameraMatrix() : Matrix4f() {
            for(int i = 0; i < matrow; i++) {
                for(int j = 0; j < matcol; j++) {
                    this->mat[i][j] = 0.0f;
                }
            }
        }

        // function meant to find the clip space
        // coordinates or a class
        static void find_ClipSpace(Vector4 clipVec);

        // finds clip_vec for 3d space inline statically for performance.
        static inline Vector3 out_clipVec(Vector4 clipVec) {
            return Vector3(clipVec.x/clipVec.w, clipVec.y/clipVec.w, clipVec.z/clipVec.w);
        }
        
};