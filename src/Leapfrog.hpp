#pragma once

#include <Eigen/Core>

#include "Integrator.hpp"

class LeapfrogIntegrator : public Integrator
{
  public:
    virtual void initialize(std::vector<Body> &bodies, const ForceEngine &forceEngine) override;
    void operator()(std::vector<Body> &bodies, const double deltaTime, const ForceEngine &forceEngine) override;

  private:
    std::vector<Eigen::Vector3d> accelerationBuffer;
    bool isInitialized{false};
};
