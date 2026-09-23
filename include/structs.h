//
// Created by cdemin on 9/10/26.
//

#pragma once

class Vec3 {    // for 3d space
public:
    std::array<double, 3> e;

    // constructors for empty and 3 arg calls
    Vec3() : e{0.0,0.0,0.0} {};
    Vec3(double position0, double position1, double position2) : e{position0,position1,position2} {};


    // getter functions
     double x() const {
        return e[0];
    }

    double y() const {
        return e[1];
    }

    double z() const {
        return e[2];
    }


    // operator functions
    Vec3 operator-() const {
        return Vec3{-e[0], -e[1], -e[2]};
    }
    double operator[](int i) const {return e[i];}
    double& operator[](int i) {return e[i];}

};

class Vec2 {   // for 2D space
public:
    double x = 0.0;
    double y = 0.0;
};

class BlackHole {
public:
    Vec3 position = {0.0,0.0,0.0};
    double mass = 100;
    double radius = 0.25;
};

class Camera {
public:
    int pitch = 0;
    int yaw = 0;
    int distance = 0;
};
