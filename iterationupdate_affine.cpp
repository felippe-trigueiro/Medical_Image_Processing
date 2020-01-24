#include "Iterationupdate_affine.h"

void IterationUpdateAffine::Execute()
{
    // use sitk's output operator for std::vector etc..
    using sitk::operator<<;

    // stash the stream state
    std::ios state(nullptr);
    state.copyfmt(std::cout);
    std::cout << std::fixed << std::setfill(' ') << std::setprecision( 5 );
    std::cout << std::setw(3) << m_Method.GetOptimizerIteration();
    std::cout << " = " << std::setw(7) << m_Method.GetMetricValue();
    std::cout << " : " << m_Method.GetOptimizerPosition() << std::endl;

    std::cout.copyfmt(state);
}
