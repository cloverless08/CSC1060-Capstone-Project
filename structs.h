//
// Created by cdemin on 9/10/26.
//

#pragma once

struct Vec3 {       // for 3d space
    double x;
    double y;
    double z;
};

struct Vec2 {       // for 2D space
    double x = 0.0;
    double y = 0.0;
};

class  Engine {

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

struct Camera {
    double pitch;
    double yaw;
    double distance;
};
