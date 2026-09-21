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
