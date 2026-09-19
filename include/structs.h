//
// Created by cdemin on 9/10/26.
//

#pragma once

class Vec3 {       // for 3d space
public:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

class Vec2 {   // for 2D space
public:
    double x = 0.0;
    double y = 0.0;
};

class BlackHole {
public:
    Vec2 position = {0,0};
    //Vec3 position = {0.0,0.0,0.0};
    double mass;
    double radius;
};
class Ray {
public:
    double x; double y;
    Vec2 direction;

};

class Camera {
public:
    int pitch;
    int yaw;
    int distance;
};
