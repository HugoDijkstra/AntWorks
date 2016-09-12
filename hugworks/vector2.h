#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>
#include <math.h>
#include <iostream>

#define PI 3.14159265359
#define RAD_TO_DEG 57.2957795
#define DEG_TO_RAD 0.0174532925

class Vector2
{
public:
        float x, y;
        Vector2(float x_ = 0.0f,float y_ = 0.0f);
        virtual ~Vector2();
        //Operators
        Vector2& operator+= (const Vector2& oth);
        Vector2& operator+= (const float oth);

        Vector2& operator-= (const Vector2& oth);
        Vector2& operator-= (const float oth);

        Vector2& operator/= (const Vector2& oth);
        Vector2& operator/= (const float oth);

        Vector2& operator*= (const Vector2& oth);
        Vector2& operator*= (const float oth);

        Vector2 operator+ (const Vector2& oth);
        Vector2 operator+ (const float oth);

        Vector2 operator- (const Vector2& oth);
        Vector2 operator- (const float oth);

        Vector2 operator/ (const Vector2& oth);
        Vector2 operator/ (const float oth);

        Vector2 operator* (const Vector2& oth);
        Vector2 operator* (const float oth);

        bool operator== (const Vector2& oth);
        bool operator!= (const Vector2& oth);


        float magnitude(){return sqrt((x*x) + (y*y));}
        float getAngle(){return atan2(y,x);}
        float normalized();
        void normalize();
        void limit(float by);

        static Vector2 getNormalPoint(Vector2 p, Vector2 a, Vector2 b);
        float dot(Vector2 b);
};

#endif
