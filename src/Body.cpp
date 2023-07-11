#include "Body.hpp"

std::ostream &operator<<(std::ostream &os, const Body &body)
{
    os << "Position: (" << body.position.x() << ", " << body.position.y() << ", " << body.position.z() << "), "
       << "Velocity: (" << body.velocity.x() << ", " << body.velocity.y() << ", " << body.velocity.z() << "), "
       << "Acceleration: (" << body.acceleration.x() << ", " << body.acceleration.y() << ", " << body.acceleration.z()
       << "), "
       << "Mass: " << body.mass;
    return os;
}