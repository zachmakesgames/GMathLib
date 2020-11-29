#pragma once
#include <iostream>
#include "vec.h"

template <class T>
class mat2{
    protected:
        vec2<T> vals[2];

    public:
        mat2<T>(vec2<T> r1, vec2<T> r2): vals{r1, r2}{}
        mat2<T>(){
            vals[0] = vec2<T>();
            vals[1] = vec2<T>();
        }

        mat2<T>(T diag){
            vals[0] = vec2<T>(diag, 0);
            vals[1] = vec2<T>(0, diag);
        }
		
		inline mat2<T> InverseTranspose(){
			vec2<T> r1(this->vals[0][0], this->vals[1][0]);
			vec2<T> r2(this->vals[0][1], this->vals[1][1]);
			
			mat2<T> newMat(r1, r2);
			
			return newMat;
		}

        inline vec2<T> operator[](const int& index){
            return this->vals[index];
        }

        friend inline std::ostream& operator<<(std::ostream& os, mat2<T> mat){
            os << std::endl;
            os << "[" << mat[0][0] << ", " << mat[0][1] << "]" << std::endl;
            os << "[" << mat[1][0] << ", " << mat[1][1] << "]";
            return os;
        }

    friend class vec2<T>;
};


template <class T>
class mat3{
    protected:
        vec3<T> vals[3];

    public:
        mat3<T>(vec3<T> r1, vec3<T> r2, vec3<T> r3): vals{r1, r2, r3}{}
        mat3<T>(){
            vals[0] = vec3<T>();
            vals[1] = vec3<T>();
            vals[2] = vec3<T>();
        }

        mat3<T>(T diag){
            vals[0] = vec3<T>(diag, 0, 0);
            vals[1] = vec3<T>(0, diag, 0);
            vals[2] = vec3<T>(0, 0, diag);
        }
		
		inline mat3<T> InverseTranspose(){
			vec3<T> r1(this->vals[0][0], this->vals[1][0], this->vals[2][0]);
			vec3<T> r2(this->vals[0][1], this->vals[1][1], this->vals[2][1]);
			vec3<T> r3(this->vals[0][2], this->vals[1][2], this->vals[2][2]);
			
			mat3<T> newMat(r1, r2, r3);
			
			return newMat;
		}

        inline vec3<T> operator[](const int& index){
            return this->vals[index];
        }

        friend inline std::ostream& operator<<(std::ostream& os, mat3<T> mat){
            os << std::endl;
            os << "[" << mat[0][0] << ", " << mat[0][1] << ", " << mat[0][2] << "]" << std::endl;
            os << "[" << mat[1][0] << ", " << mat[1][1] << ", " << mat[1][2] << "]" << std::endl;
            os << "[" << mat[2][0] << ", " << mat[2][1] << ", " << mat[2][2] << "]";
            return os;
        }
    friend class vec3<T>;
};

template <class T>
class mat4{
    protected:
        vec4<T> vals[4];

    public:
        mat4<T>(vec4<T> r1, vec4<T> r2, vec4<T> r3, vec4<T> r4): vals{r1, r2, r3, r4}{}
        mat4<T>(){
            vals[0] = vec4<T>();
            vals[1] = vec4<T>();
            vals[2] = vec4<T>();
            vals[3] = vec4<T>();
        }

        mat4<T>(T diag){
            vals[0] = vec4<T>(diag, 0, 0, 0);
            vals[1] = vec4<T>(0, diag, 0, 0);
            vals[2] = vec4<T>(0, 0, diag, 0);
            vals[3] = vec4<T>(0, 0, 0, diag);
        }
		
		
		
		inline mat4<T> InverseTranspose(){
			vec4<T> r1(this->vals[0][0], this->vals[1][0], this->vals[2][0], this->vals[3][0]);
			vec4<T> r2(this->vals[0][1], this->vals[1][1], this->vals[2][1], this->vals[3][1]);
			vec4<T> r3(this->vals[0][2], this->vals[1][2], this->vals[2][2], this->vals[3][2]);
			vec4<T> r4(this->vals[0][3], this->vals[1][3], this->vals[2][3], this->vals[3][3]);
			
			mat4<T> newMat(r1, r2, r3, r4);
			
			return newMat;
		}
		
		
		inline mat4<T> RotateLeft(){
			vec4<T> r1(this->vals[0][3], this->vals[1][3], this->vals[2][3], this->vals[3][3]);
			vec4<T> r2(this->vals[0][2], this->vals[1][2], this->vals[2][2], this->vals[3][2]);
			vec4<T> r3(this->vals[0][1], this->vals[1][1], this->vals[2][1], this->vals[3][1]);
			vec4<T> r4(this->vals[0][0], this->vals[1][0], this->vals[2][0], this->vals[3][0]);
			return mat4<T>(r1, r2, r3, r4);
		}
		


        inline vec4<T> operator[](const int& index){
            return this->vals[index];
        }
		

        friend inline std::ostream& operator<<(std::ostream& os, mat4<T> mat){
            os << std::endl;
            os << "[" << mat[0][0] << ", " << mat[0][1] << ", " << mat[0][2] << ", " << mat[0][3] << "]" << std::endl;
            os << "[" << mat[1][0] << ", " << mat[1][1] << ", " << mat[1][2] << ", " << mat[1][3] << "]" << std::endl;;
            os << "[" << mat[2][0] << ", " << mat[2][1] << ", " << mat[2][2] << ", " << mat[2][3] << "]" << std::endl;;
            os << "[" << mat[3][0] << ", " << mat[3][1] << ", " << mat[3][2] << ", " << mat[3][3] << "]";
            return os;
        }
		
		friend inline vec4<T> operator*(vec4<T>& vec, mat4<T>& mat){
			mat4<T> rotate = mat.InverseTranspose();
			
			return vec4<T>(vec.Dot(rotate[0]), vec.Dot(rotate[1]), vec.Dot(rotate[2]), vec.Dot(rotate[3]));
		}


    friend class vec4<T>;
};
