#pragma once

#include <ostream>

#include <Eigen/Core>

struct Body
{
    Eigen::Vector3d position;
    Eigen::Vector3d velocity;
    Eigen::Vector3d acceleration;
    double mass;
};

std::ostream &operator<<(std::ostream &os, const Body &body);
