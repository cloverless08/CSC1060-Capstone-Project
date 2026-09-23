//
// Created by cdemin on 9/10/26.
//

#pragma once

class Vec3 {    // for 3d space
public:
    std::array<double, 3> position;

    // constructors for empty and 3 arg calls
    Vec3() : position{0.0,0.0,0.0} {};
    Vec3(double position0, double position1, double position2) : position{position0,position1,position2} {};


    // getter functions
    [[nodiscard]] double x() const {
        return position[0];
    }

    [[nodiscard]] double y() const {
        return position[1];
    }

    [[nodiscard]] double z() const {
        return position[2];
    }



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
