#include "camera_matrix.h"
void CameraMatrix::find_ClipSpace(Vector4 clipVec) {
    out_clipVec(clipVec);
}

Vector3 CameraMatrix::out_clipVec(Vector4 clipVec)  {
    return Vector3(clipVec.x/clipVec.w, clipVec.y/clipVec.w, clipVec.z/clipVec.w);
}