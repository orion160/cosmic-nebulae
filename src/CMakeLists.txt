set(BODY Body.hpp Body.cpp)
set(FORCE_ENGINE ForceEngine.hpp BasicForceEngine.hpp BasicForceEngine.cpp) 
set(INTEGRATOR Integrator.hpp Integrator.cpp Leapfrog.hpp Leapfrog.cpp)
set(COSMIC_NEBULAE_CORE ${BODY} ${FORCE_ENGINE} ${INTEGRATOR})

add_executable(cosmic-nebulae main.cpp ${COSMIC_NEBULAE_CORE})
target_link_libraries(cosmic-nebulae PRIVATE Eigen3::Eigen)
