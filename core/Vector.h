#pragma once
#ifdef VECTOR_H
#define VECTOR_H
#endif
#include<iostream>
#include<vector>
using namespace std;

struct vecclass {
	float x, y, z;
};

class Vector {
	private:
		float x, y, z;
	public:
		Vector(float pointx, float pointy, float pointz) {
			this->x = pointx;
			this->y = pointy;
			this->z = pointz;
		}

		float translateX();
		float translateY();
		float translateZ();

		float getX();
		float getY();
		float getZ();
		
		void changeX(float xval);
		void changeY(float yval);
		void changeZ(float zval);
		
		float vecMag(Vector a);
		
		Vector newVec(float x, float y, float z);

		void * operator new(size_t size) {
			void * vec = ::new Vector(0.0f, 0.0f, 0.0f);
			return vec;
		}

		Vector translateEntireVec();
		Vector getVector();
		Vector addVec(Vector addtional, Vector initial);

		Vector operator+(const Vector& b) {
			Vector vec(0.0f, 0.0f, 0.0f);
			vec.x += this->x + b.x;
			vec.y += this->y + b.y;
			vec.z += this->z + b.z;
			return vec;
		}

		Vector operator*(const Vector& x) {
			Vector vec(0.0f, 0.0, 0.0f);
			vec.x *= this->x * x.x;
			vec.y *= this->y * x.y;
			vec.z *= this->z * x.z;
			return vec;
		}

		Vector operator-(const Vector &vector) {
			Vector vec(0.0f, 0.0f, 0.0f);
			vec.x -= this->x - vector.x;
			vec.y -= this->y - vector.y;
			vec.z -= this->z - vector.z;
			return vec;
		}
 
	 	Vector operator/(const Vector &vector) {
			 Vector vec(0.0f, 0.0f, 0.0f);
			 vec.x /= this->x / vector.x;
			 vec.y /= this->y / vector.y;
			 vec.z /= this->z / vector.z;
			 return vec;
		}




};