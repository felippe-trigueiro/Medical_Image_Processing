#include "multiresolutioniterationupdate.h"

void MultiResolutionIterationUpdate::Execute( )
{
    using sitk::operator<<;
    // The sitkMultiResolutionIterationEvent occurs before the
    // resolution of the transform. This event is used here to print
    // the status of the optimizer from the previous registration level.
    if (m_Method.GetCurrentLevel() > 0)
    {
        std::cout << "Optimizer stop condition: " << m_Method.GetOptimizerStopConditionDescription() << std::endl;
        std::cout << " Iteration: " << m_Method.GetOptimizerIteration() << std::endl;
        std::cout << " Metric value: " << m_Method.GetMetricValue() << std::endl;
    }

    std::cout << "--------- Resolution Changing ---------" << std::endl;
}
