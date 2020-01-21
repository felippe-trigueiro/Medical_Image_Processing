#ifndef ITERATIONUPDATE_H
#define ITERATIONUPDATE_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class IterationUpdate : public sitk::Command
{
    public:
        IterationUpdate( const sitk::ImageRegistrationMethod &m) : m_Method(m){}
        virtual void Execute();

    private:
        const sitk::ImageRegistrationMethod &m_Method;
};

#endif // ITERATIONUPDATE_H
