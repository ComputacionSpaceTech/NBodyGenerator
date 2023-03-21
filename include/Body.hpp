#pragma once

#include <Eigen/Dense>

struct Body
{
    Body(double x, double y, double z, double mass)
        : position{Eigen::Vector3d{x, y, z}}, mass{mass}
    {
    }

    Eigen::Vector3d position;

    Eigen::Vector3d velocity;

    Eigen::Vector3d acceleration;

    double mass;
};
