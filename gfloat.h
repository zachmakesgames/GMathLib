//Floating points can get weird some times
//This class is supposed to help with
//floating point comparison. Its not complete
//so use at your own risk!

#pragma once
#include <cmath>
#include <iostream>

#ifndef PRECISION
#define PRECISION 0.0001
#endif

class GFloat{
    protected:
        float val;

    public:
        inline GFloat(){
            val = 0.0;
        }

        inline GFloat(int v){
            val = (float)v;
        }

        inline GFloat(float v){
            val = v;
        }

        inline GFloat(double v){
            val = (float)v;
        }

        inline void operator=(const float& rh){
            this->val = rh;
        }

        inline void operator=(const int& rh){
            this->val = (float)rh;
        }

        inline bool operator==(const GFloat& rh){
            float diff = std::abs(this->val - rh.val);

            return (diff < PRECISION);
        }

        inline GFloat operator+(const GFloat& rh){
            return GFloat(this->val + rh.val);
        }

        inline GFloat operator-(const GFloat& rh){
            return GFloat(this->val - rh.val);
        }

        inline GFloat operator*(const GFloat& rh){
            return GFloat(this->val * rh.val);
        }

        inline GFloat operator/(const GFloat& rh){
            return GFloat(this->val /rh.val);
        }

        friend inline std::ostream& operator<<(std::ostream& os, const GFloat& gf){
            os << gf.val;
            return os;
        }
};
