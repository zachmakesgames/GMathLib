#include "vec.h"
#include "mat.h"
#include "gfloat.h"
#include <iostream>
#include <string>
#include <assert.h>


#define VERBOSE false


void cassert(std::string message, bool expression){
    if(expression){
        if(VERBOSE){
            std::cout << "Assertion: " << message << std::endl;
            std::cout << "PASS" << std::endl;
        }
        return;
    }

    std::cout << "Assertion: " << message << std::endl;
    std::cout << "FAIL" << std::endl;
    assert(false);
}


void test_vec2(){
    if(VERBOSE){
        std::cout << "Testing vec2<float>" << std::endl;
    }


    cassert("sizeof(vec2<float>) == 2*sizeof(float)", sizeof(vec2<float>) == 2*sizeof(float));
    vec2<float> vn;
    vec2<float> v0(0, 0), v1(1,1), v2(1,2), v3(1,1), v4(2,2);

    cassert("vn != v1", vn != v1);

    vn = v1;
    cassert("vn = v1, vn == v1", vn == v1);

    cassert("v1 == v3", v1 == v3);
    cassert("v1 != v2", v1 != v2);

    cassert("2*v1 == v4", 2*v1 == v4);
    cassert("v1*2 == v4", v1*2 == v4);

    cassert("v1 == v4/2", v1 == v4/2);

    cassert("v1 + v0 == v1", v1 + v0 == v1);
    cassert("v0 + v1 == v1", v0 + v1 == v1);


    cassert("v1 - v0 == v1", v1 - v0 == v1);

    cassert("v1 + v1 == v4", v1 + v1 == v4);
    cassert("v1 - v1 == v0", v1 - v1 == v0);

    //comparing floating point equality is a little
    //like hearding cats.......
    float v1dot = v1.Dot(v1);
    float len2 = v1.Length()*v1.Length();

    float diff = v1dot-len2;
    if(diff <0) {
        diff *= -1;
    }

    //ensure that the difference is below the acceptible threshold
    cassert("v1.Dot(v1) == v1.Length()*v1.Length()", diff < 0.0001);

    if(VERBOSE){
        std::cout << "All tests passed." << std::endl;
    }

}


void test_vec3(){
    if(VERBOSE){
        std::cout << "Testing vec3<float>" << std::endl;
    }

    vec3<float> v0(0, 0, 0), v1(1,1,1), v2(1,2,3), v3(1,1,1), v4(2,2,2);

    cassert("v1 == v3", v1 == v3);
    cassert("v1 != v2", v1 != v2);

    cassert("2*v1 == v4", 2*v1 == v4);
    cassert("v1*2 == v4", v1*2 == v4);

    cassert("v1 == v4/2", v1 == v4/2);

    cassert("v1 + v0 == v1", v1 + v0 == v1);
    cassert("v0 + v1 == v1", v0 + v1 == v1);


    cassert("v1 - v0 == v1", v1 - v0 == v1);
    cassert("v1 + v1 == v4", v1 + v1 == v4);
    cassert("v1 - v1 == v0", v1 - v1 == v0);


    if(VERBOSE){
        std::cout << "All tests passed." << std::endl;
    }
}


void test_vec4(){

    if(VERBOSE){
        std::cout << "Testing vec4<float>" << std::endl;
    }

    vec4<float> v0(0,0,0,0), v1(1,1,1,1), v2(1,2,3,4), v3(1,1,1,1), v4(2,2,2,2);
    cassert("v1 == v3", v1 == v3);
    cassert("v1 != v2", v1 != v2);

    cassert("2*v1 == v4", 2*v1 == v4);
    cassert("v1*2 == v4", v1*2 == v4);

    cassert("v1 == v4/2", v1 == v4/2);

    cassert("v1 + v0 == v1", v1 + v0 == v1);
    cassert("v0 + v1 == v1", v0 + v1 == v1);


    cassert("v1 - v0 == v1", v1 - v0 == v1);
    cassert("v1 + v1 == v4", v1 + v1 == v4);
    cassert("v1 - v1 == v0", v1 - v1 == v0);


    if(VERBOSE){
        std::cout << "All tests passed." << std::endl;
    }
}



//Can typedef the vectors and matricies
//to be whatever type you need
typedef mat2<float> Mat2;
typedef mat3<float> Mat3;
typedef mat4<float> Mat4;

typedef vec2<float> Vec2;
typedef vec3<float> Vec3;
typedef vec4<float> Vec4;

int main(int argc, char** argv){


    test_vec2();

    test_vec3();

    test_vec4();



    std::cout << "All vector tests passed successfully" << std::endl;

    std::cout << std::endl;



    Vec2 mr1(1, 2);
    Vec2 mr2(3, 4);

    Mat2 m1(mr1, mr2);

    std::cout << "Matrix 1: " << std::endl << m1 << std::endl;

    Mat2 ident2(1);
    Mat3 ident3(1);
    Mat4 ident4(1);


    std::cout << "2x2 identity matrix: " << ident2 << std::endl;
    std::cout << "3x3 identity matrix: " << ident3 << std::endl;
    std::cout << "4x4 identity matrix: " << ident4 << std::endl;
    return 0;
}
