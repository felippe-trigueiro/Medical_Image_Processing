#ifndef MULTIRESOLUTIONITERATIONUPDATE_H
#define MULTIRESOLUTIONITERATIONUPDATE_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class MultiResolutionIterationUpdate : public sitk::Command
{
    public:
        MultiResolutionIterationUpdate( const sitk::ImageRegistrationMethod &m) : m_Method(m){}
    // Override method from parent which is called at for the requested event
    virtual void Execute( );

    private:
        const sitk::ImageRegistrationMethod &m_Method;
};

#endif // MULTIRESOLUTIONITERATIONUPDATE_H
