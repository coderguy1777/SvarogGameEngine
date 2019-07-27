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

        CameraMatrix(float l, float r, float b, float t, float n, float f) {
            this->left = l;
            this->right = r;
            this->bottom = b;
            this->top = t;
            this->near = n;
            this->far = f;
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

        // eye plane function
        void compute_eye_plane();

        // eye plane points
        inline void findX_EYE();
        inline void findY_EYE();
        inline void findZ_EYE();

        // triggers projection_plane computation.
        void compute_project_plane() {
            findX_P();
            findY_P();
            findZ_P();
        }

        // finds projection plane values
        inline void findX_P();
        inline void findY_P();
        inline void findZ_P();


        private:
            float x_p, y_p, z_p;
            float x_e, y_e, z_e;
        
};