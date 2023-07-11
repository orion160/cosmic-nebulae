#pragma once

#include <Eigen/Core>

#include "Integrator.hpp"

class LeapfrogIntegrator : public Integrator
{
  public:
    LeapfrogIntegrator(const ForceEngine &forceEngine);

    void operator()(std::vector<Body> &bodies, const double deltaTime) override;

  private:
    std::vector<Eigen::Vector3d> accelerationBuffer;
    bool isInitialized{false};
};