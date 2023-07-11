#include <cmath>

#include "BasicForceEngine.hpp"
#include "Body.hpp"

std::vector<Eigen::Vector3d> BasicForceEngine::operator()(std::vector<Body> &bodies) const
{
    using size_type = std::vector<Body>::size_type;

    std::vector<Eigen::Vector3d> accelerations(bodies.size(), Eigen::Vector3d::Zero());

    for (size_type i = 0; i < bodies.size(); ++i)
    {
        for (size_type j = 0; j < bodies.size(); ++j)
        {
            accelerations[i] += bodyBodyInteraction(bodies[i], bodies[j]);
        }
    }

    return accelerations;
}

Eigen::Vector3d BasicForceEngine::bodyBodyInteraction(Body &current, Body &other) const
{
    Eigen::Vector3d r{other.position - current.position};
    double distSqr{r.squaredNorm() + BasicForceEngine::Epsilon2};
    double invDistCube{1.0 / std::pow(distSqr, 1.5)};

    Eigen::Vector3d acceleration{ForceEngine::G * other.mass * invDistCube * r};

    return acceleration;
}
