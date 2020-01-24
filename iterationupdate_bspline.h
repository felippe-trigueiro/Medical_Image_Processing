#ifndef ITERATIONUPDATE_BSPLINE_H
#define ITERATIONUPDATE_BSPLINE_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class IterationUpdateBspline : public sitk::Command
{
    public:
        IterationUpdateBspline( const sitk::ImageRegistrationMethod &m, const sitk::BSplineTransform &tx) :
                                m_Method(m), m_BSplineTransform(tx){}

    // Override method from parent which is called at for the requested event
    virtual void Execute( );

    private:
        const sitk::ImageRegistrationMethod &m_Method;
        const sitk::BSplineTransform &m_BSplineTransform;
};

#endif // ITERATIONUPDATEBSPLINE_H
