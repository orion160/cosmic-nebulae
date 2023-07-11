#include "Simulator.hpp"

#include "Integrator.hpp"

Simulator::Simulator(std::unique_ptr<ForceEngine> forceEngine, std::unique_ptr<Integrator> integrator,
                     std::shared_ptr<std::vector<Body>> bodies)
    : forceEngine{std::move(forceEngine)}, integrator{std::move(integrator)}, bodies{bodies}
{
}

void Simulator::initialize()
{
    integrator->initialize(*bodies, *forceEngine);
}

void Simulator::operator()(double deltaTime)
{
    (*integrator)(*bodies, deltaTime, *forceEngine);
}

std::shared_ptr<std::vector<Body>> Simulator::getBodies() const
{
    return bodies;
}
