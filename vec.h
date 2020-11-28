#pragma once
#include <cmath>
#include <iostream>


template <class T>
class vec2{
    protected:
        T vals[2];
    public:

        inline vec2(T _x, T _y) : vals{_x, _y}{}

        inline vec2(){
            this->vals[0] = this->vals[1] = 0;
        }

        inline T Length(){
            T sqrd = this->vals[0]*this->vals[0] + this->vals[1]*this->vals[1];
            return sqrt(sqrd);
        }

        inline vec2<T> Normalize(){
            T length = this->Length();

            return vec2<T>(this->vals[0]/length, this->vals[1]/length);
        }

        inline T Dot(vec2<T> v2){
            T product1 = this->vals[0]*v2.vals[0];
            T product2 = this->vals[1]*v2.vals[1];

            return product1 + product2;
        }

        inline bool operator==(const vec2<T>& other){
            return (this->vals[0] == other.vals[0] && this->vals[1] == other.vals[1]);
        }

        inline bool operator!=(const vec2<T>& other){
            return (this->vals[0] != other.vals[0] || this->vals[1] != other.vals[1]);
        }

        inline vec2<T> operator+(const vec2<T>& other){
            return vec2<T>(this->vals[0] + other.vals[0], this->vals[1] + other.vals[1]);
        }

        inline vec2<T> operator-(const vec2<T>& other){
            return vec2<T>(this->vals[0] - other.vals[0], this->vals[1] - other.vals[1]);
        }

        inline void operator=(const vec2<T>& other){
            this->vals[0] = other.vals[0];
            this->vals[1] = other.vals[1];
        }

        inline T operator[](const int& index){
            return this->vals[index];
        }

        //Declaring the * and / operators as friend allows us to
        //overload the operator in a way such that the order doesn't
        //matter.
        template <class S>
        friend vec2<T> operator*(const S& scalar, const vec2<T>& vect){
            return vec2<T>(vect.vals[0]*scalar, vect.vals[1]*scalar);
        }

        template <class S>
        friend vec2<T> operator*(const vec2<T>& vect, const S& scalar){
            return vec2<T>(vect.vals[0]*scalar, vect.vals[1]*scalar);
        }

        template <class S>
        friend vec2<T> operator/(const S& scalar, const vec2<T>& vect){
            return vec2<T>(vect.vals[0]/scalar, vect.vals[1]/scalar);
        }

        template <class S>
        friend vec2<T> operator/(const vec2<T>& vect, const S& scalar){
            return vec2<T>(vect.vals[0]/scalar, vect.vals[1]/scalar);
        }


        friend inline std::ostream& operator<<(std::ostream& os, const vec2<T>& vec){
            os << "<" << vec.vals[0] << ", " << vec.vals[1] << ">";
            return os;
        }
};


template <class T>
class vec3{
    protected:
        T vals[3];
    public:

        inline vec3(T _x, T _y, T _z): vals{_x, _y, _z}{}

        inline vec3(){
            this->vals[0] = this->vals[1] = this->vals[2] = 0;
        }

        inline T Length(){
            T sqrd = this->vals[0]*this->vals[0] + this->vals[1]*this->vals[1] + this->vals[2]*this->vals[2];
            return sqrt(sqrd);
        }

        inline vec3<T> Normalize(){
            T length = this->Length();

            return vec3<T>(this->vals[0]/length, this->vals[1]/length, this->vals[2]/length);
        }

        inline T Dot(vec3<T> v2){
            T product1 = this->vals[0]*v2.vals[1];
            T product2 = this->vals[1]*v2.vals[1];
            T product3 = this->vals[2]*v2.vals[2];

            return product1 + product2 + product3;
        }

        inline vec3<T> Cross(vec3<T> v2){
            return vec3<T>( (this->vals[1] * v2.vals[2]) - (this->vals[2] * v2.vals[1]),
                            (this->vals[2] * v2.vals[0]) - (this->vals[0] * v2.vals[2]),
                            (this->vals[0] * v2.vals[1]) - (this->vals[1] * v2.vals[0]));
        }

        inline bool operator==(const vec3<T>& other){
            return (this->vals[0] == other.vals[0] && this->vals[1] == other.vals[1] && this->vals[2] == other.vals[2]);
        }

        inline bool operator!=(const vec3<T>& other){
            return (this->vals[0] != other.vals[0] || this->vals[1] != other.vals[1] || this->vals[2] != other.vals[2]);
        }

        inline vec3<T> operator+(const vec3<T>& other){
            return vec3<T>(this->vals[0] + other.vals[0], this->vals[1] + other.vals[1], this->vals[2] + other.vals[2]);
        }

        inline vec3<T> operator-(const vec3<T>& other){
            return vec3<T>(this->vals[0] - other.vals[0], this->vals[1] - other.vals[1], this->vals[2] - other.vals[2]);
        }

        inline void operator=(const vec3<T>& other){
            this->vals[0] = other.vals[0];
            this->vals[1] = other.vals[1];
            this->vals[2] = other.vals[2];
        }

        inline T operator[](const int& index){
            return this->vals[index];
        }


        template <class S>
        friend vec3<T> operator*(const S& scalar, const vec3<T>& vect){
            return vec3<T>(vect.vals[0]*scalar, vect.vals[1]*scalar, vect.vals[2]*scalar);
        }

        template <class S>
        friend vec3<T> operator*(const vec3<T>& vect, const S& scalar){
            return vec3<T>(vect.vals[0]*scalar, vect.vals[1]*scalar, vect.vals[2]*scalar);
        }

        template <class S>
        friend vec3<T> operator/(const vec3<T>& vect, const S& scalar){
            return vec3<T>(vect.vals[0]/scalar, vect.vals[1]/scalar, vect.vals[2]/scalar);
        }

        template <class S>
        friend vec3<T> operator/(const S& scalar, const vec3<T>&vect){
            return vec3<T>(vect.vals[0]/scalar, vect.vals[1]/scalar, vect.vals[2]/scalar);
        }

        friend inline std::ostream& operator <<(std::ostream& os, const vec3<T>& vec){
            os << "<" << vec.vals[0] << ", " << vec.vals[1] << ", " << vec.vals[2] << ">";
            return os;
        }
};


template <class T>
class vec4{
    protected:
        T vals[4];

    public:

        inline vec4(T _x, T _y, T _z, T _w): vals{_x, _y, _z, _w}{}

        inline vec4(){
            this->vals[0] = this->vals[1] = this->vals[2] = this->vals[3] = 0;
        }


        inline T Length(){
            T sqrd = this->vals[0]*this->vals[0] + this->vals[1]*this->vals[1] + this->vals[2]*this->vals[2] + this->vals[3]*this->vals[3];
            return sqrt(sqrd);
        }

        inline T Dot(vec4<T> v2){
            T product1 = this->vals[0]*v2.vals[0];
            T product2 = this->vals[1]*v2.vals[1];
            T product3 = this->vals[2]*v2.vals[2];
            T product4 = this->vals[3]*v2.vals[3];

            return product1 + product2 + product3 + product4;
        }

        inline vec4<T> Normalize(){
            T length = this->Length();

            return vec4<T>(this->vals[0]/length, this->vals[1]/length, this->vals[2]/length, this->vals[3]/length);
        }

        inline bool operator==(const vec4<T>& other){
            return (this->vals[0] == other.vals[0] && this->vals[1] == other.vals[1] && this->vals[2] == other.vals[2] && this->vals[3] == other.vals[3]);
        }


        inline bool operator!=(const vec4<T>& other){
            return (this->vals[0] != other.vals[0] || this->vals[1] != other.vals[1] || this->vals[2] != other.vals[2] || this->vals[3] != other.vals[3]);
        }

        inline vec4<T> operator+(const vec4<T>& other){
            return vec4<T>(this->vals[0] + other.vals[0], this->vals[1] + other.vals[1], this->vals[2] + other.vals[2], this->vals[3] + other.vals[3]);
        }

        inline vec4<T> operator-(const vec4<T>& other){
            return vec4<T>(this->vals[0] - other.vals[0], this->vals[1] - other.vals[1], this->vals[2] - other.vals[2], this->vals[3] - other.vals[3]);
        }

        inline void operator=(const vec4<T>& other){
            this->vals[0] = other.vals[0];
            this->vals[1] = other.vals[1];
            this->vals[2] = other.vals[2];
            this->vals[3] = other.vals[3];
        }

        inline T operator[](const int& index){
            return this->vals[index];
        }

        template <class S>
        friend vec4<T> operator*(const S& scalar, const vec4<T>& vect){
            return vec4<T>(vect.vals[0]*scalar, vect.vals[1]*scalar, vect.vals[2]*scalar, vect.vals[3]*scalar);
        }

        template <class S>
        friend vec4<T> operator*(const vec4<T>& vect, const S& scalar){
            return vec4<T>(vect.vals[0]*scalar, vect.vals[1]*scalar, vect.vals[2]*scalar, vect.vals[3]*scalar);
        }

        template <class S>
        friend vec4<T> operator/(const vec4<T>& vect, const S& scalar){
            return vec4<T>(vect.vals[0]/scalar, vect.vals[1]/scalar, vect.vals[2]/scalar, vect.vals[3]/scalar);
        }

        template <class S>
        friend vec4<T> operator/(const S& scalar, const vec4<T>&vect){
            return vec4<T>(vect.vals[0]/scalar, vect.vals[1]/scalar, vect.vals[2]/scalar, vect.vals[3]/scalar);
        }

        friend inline std::ostream& operator<<(std::ostream& os, const vec4<T>& vec){
            os << "<" << vec.vals[0] << ", " << vec.vals[1] << ", " << vec.vals[2] << ", " << vec.vals[3] << ">";
            return os;
        }
};
