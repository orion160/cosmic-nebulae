#include "Leapfrog.hpp"

#include "Body.hpp"
#include "ForceEngine.hpp"

LeapfrogIntegrator::LeapfrogIntegrator(const ForceEngine &forceEngine) : Integrator{forceEngine}
{
}

void LeapfrogIntegrator::initialize(std::vector<Body> &bodies)
{
    using size_type = std::vector<Body>::size_type;

    accelerationBuffer = forceEngine(bodies);

    for (size_type i = 0; i < bodies.size(); ++i)
    {
        bodies[i].acceleration = accelerationBuffer[i];
    }

    isInitialized = true;
}

void LeapfrogIntegrator::operator()(std::vector<Body> &bodies, const double deltaTime)
{
    using size_type = std::vector<Body>::size_type;

    // currentAcceleration -> a_i
    const auto &currentAccelerations = accelerationBuffer;

    // Compute position
    // nextPosition -> x_{i + 1}
    // x_{i + 1} = x_i + v_i \Delta t + \frac{1}{2} a_i \Delta t^2
    for (size_type i = 0; i < bodies.size(); ++i)
    {
        bodies[i].position += bodies[i].velocity * deltaTime + currentAccelerations[i] * deltaTime * deltaTime / 2.0;
    }

    // Compute acceleration
    // nextAcceleration -> a_{i + 1}
    const auto &nextAccelerations = forceEngine(bodies);

    // Compute velocity an also store next acceleration into the Body
    // nextPosition -> v_{v + 1}
    // v_{i + 1} = v_i + \frac{1}{2} (a_i + a_{i + 1}) \Delta t
    for (size_type i = 0; i < bodies.size(); ++i)
    {
        bodies[i].velocity += (currentAccelerations[i] + nextAccelerations[i]) * deltaTime / 2.0;

        bodies[i].acceleration = nextAccelerations[i];
    }
}
