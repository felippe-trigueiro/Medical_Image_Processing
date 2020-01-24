#ifndef ITERATIONUPDATE_AFFINE_H
#define ITERATIONUPDATE_AFFINE_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class IterationUpdateAffine : public sitk::Command
{
    public:
        IterationUpdateAffine( const sitk::ImageRegistrationMethod &m) : m_Method(m){}
        virtual void Execute();

    private:
        const sitk::ImageRegistrationMethod &m_Method;
};

#endif // ITERATIONUPDATE_Affine_H
