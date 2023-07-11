#include <iostream>
#include <vector>

#include <Eigen/Core>

#include "BasicForceEngine.hpp"
#include "Body.hpp"
#include "Leapfrog.hpp"

int main(int argc, char **argv)
{
    std::cout << "Hello world!\n";

    std::vector<Body> bodies{Body{.position = Eigen::Vector3d{0.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 1e12},
                             Body{.position = Eigen::Vector3d{10.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 1e11},
                             Body{.position = Eigen::Vector3d{19.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 5e11}};

    std::cout << "Initial state:\n";
    for (auto &body : bodies)
    {
        std::cout << body << '\n';
    }

    BasicForceEngine forceEngine{};
    LeapfrogIntegrator integrator{forceEngine};

    std::cout << "After the initialization:\n";
    integrator.initialize(bodies);
    for (auto &body : bodies)
    {
        std::cout << body << '\n';
    }

    integrator(bodies, 1);

    std::cout << "After the integration:\n";
    for (auto &body : bodies)
    {
        std::cout << body << '\n';
    }

    return 0;
}