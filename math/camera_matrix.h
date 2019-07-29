#pragma once 
#ifdef CAMERA_MATRIX_H
#define CAMERA_MATRIX_H
#endif
using namespace std;
#include "libs.h"

typedef struct  {
    float left;
    float right;
    float bottom;
    float top;
    float near;
    float far;
} Frustrum;
class CameraMatrix : public Matrix4f {
    private:
        float width, height, aspect, fov;

    public: 
        Matrix4f perspec;
        Matrix4f orthoPerspec;
        // 6 view cooordinates for projection matrix
        Frustrum frust;
        // clip vec coords.
        float x_c, y_c, z_c, w_c;    

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

        CameraMatrix(Frustrum frust, float w, float h, float fov) {
            this->frust = frust;
            this->width = w;
            this->height = h;
            this->aspect = this->width/this->height;
            frust.top = frust.near * tan(PI/180 * this->fov/2);
            frust.bottom = -frust.top;
            frust.right = frust.top * aspect;
            frust.left = -frust.right;
        }

        void * operator new(size_t size) {
            void * p = new ::CameraMatrix();
            return p;
        }

        // function meant to find the clip space
        // coordinates or a class
        static void find_ClipSpace(Vector4 clipVec);

        // finds clip_vec for 3d space inline statically for performance.
        static inline Vector3 out_clipVec(Vector4 clipVec);

        // checks if vertex is negative, if negative
        // gets discarded.
        inline bool discard_Vertex(Vector3 lipVec) {
            return (lipVec.initx < -w_c || lipVec.initx > w_c || lipVec.inity < -w_c || lipVec.inity > w_c || lipVec.initz < -w_c || lipVec.initz > w_c) ? true : false;
        }


        void create_perspecMatrix() {
            // row 0
            this->perspec.mat[0][0] = 2 * this->frust.near / this->frust.right - this->frust.left;
            this->perspec.mat[0][1] = 0.0f;
            this->perspec.mat[0][2] = this->frust.right + this->frust.left / this->frust.right - this->frust.left;
            this->perspec.mat[0][3] = 0.0f;

            // row 1
            this->perspec.mat[1][0] = 0.0f;
            this->perspec.mat[1][1] = 2 * this->frust.near / this->frust.top - this->frust.bottom;
            this->perspec.mat[1][2] = this->frust.top + this->frust.bottom / this->frust.top - this->frust.bottom;
            this->perspec.mat[1][3] = 0.0f;

            // row 2
            this->perspec.mat[2][0] = 0.0f;
            this->perspec.mat[2][1] = 0.0f;
            this->perspec.mat[2][2] = -(this->frust.far + this->frust.near/this->frust.far - this->frust.near);
            this->perspec.mat[2][3] = -(2 * this->frust.far *  this->frust.near / this->frust.far - this->frust.near);

            // row 3
            this->mat[3][0] = 0.0f;
            this->mat[3][1] = 0.0f;
            this->mat[3][2] = -1.0f;
            this->mat[3][3] = 0.0f;
        }

        private:
            float x_p, y_p, z_p;
            float x_e, y_e, z_e;
        
};