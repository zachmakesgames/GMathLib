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

    friend class vec4<T>;
};
