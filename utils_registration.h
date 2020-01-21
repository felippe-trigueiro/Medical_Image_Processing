#ifndef UTILS_H
#define UTILS_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class UtilsRegistration
{
    public:
        UtilsRegistration();
        std::string readMetaData(const std::string , const std::string);
        std::vector<std::string> stringSplit(const std::string);
        sitk::Image readDicomSeries(const std::string);
        sitk::Image rotateImage3D(sitk::Image, std::vector<double>, double);
        std::vector<double> get_center(sitk::Image);
        sitk::Image imResize3(sitk::Image, sitk::Image);
        void printDimension(sitk::Image, std::string);
        void printImageType(sitk::Image, std::string);
        void printSpacing(sitk::Image, std::string);
};

#endif // UTILS_H
