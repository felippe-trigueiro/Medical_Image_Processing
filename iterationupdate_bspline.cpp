#include "iterationupdate_bspline.h"

void IterationUpdateBspline::Execute()
{
    using sitk::operator<<;
    if (m_Method.GetOptimizerIteration() == 0)
    {
        // The BSpline is resized before the first optimizer
        // iteration is completed per level. Print the transform object
        // to show the adapted BSpline transform.
        std::cout << m_BSplineTransform.ToString() << std::endl;
    }

    // stash the stream state
    std::ios  state(nullptr);
    state.copyfmt(std::cout);
    std::cout << std::fixed << std::setfill(' ') << std::setprecision( 5 );
    std::cout << std::setw(3) << m_Method.GetOptimizerIteration();
    std::cout << " = " << std::setw(10) << m_Method.GetMetricValue() << std::endl;
    std::cout.copyfmt(state);
}
