//
// Created by cdemin on 9/10/26.
//

#pragma once

class Vec3 {    // for 3d space
public:
    std::array<double, 3> data;

    // constructors for empty and 3 arg calls
    Vec3() : data{0.0,0.0,0.0} {};
    Vec3(double position0, double position1, double position2) : data{position0,position1,position2} {};


    // getter functions
     double x() const {
        return data[0];
    }

    double y() const {
        return data[1];
    }

    double z() const {
        return data[2];
    }


    // operator functions
    Vec3 operator-() const {
        return Vec3{-data[0], -data[1], -data[2]};
    }
    double operator[](int i) const {return data[i];}
    double& operator[](int i) {return data[i];}

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
