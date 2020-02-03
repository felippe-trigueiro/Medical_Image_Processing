#ifndef UTILS_H
#define UTILS_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>
#include <fstream>
#include <map>

namespace sitk = itk::simple;

class UtilsRegistration
{
    public:
        UtilsRegistration();
        std::string readMetaData(const std::string , const std::string);
        std::vector<std::string> stringSplit(const std::string, char);
        sitk::Image readDicomSeries(const std::string);
        sitk::Image rotateImage3D(sitk::Image, std::vector<double>, double);
        std::vector<double> get_center(sitk::Image);
        sitk::Image imResize3(sitk::Image, sitk::Image);
        sitk::Transform transform_inverse(sitk::Transform);
        float returning_label(sitk::Image, sitk::Image, std::vector<int64_t>, sitk::Transform, sitk::Transform);
        std::map<int, std::string> readTalairachLabels(std::string);

        //Printing Functions
        void printDimension(sitk::Image, std::string);
        void printImageType(sitk::Image, std::string);
        void printSpacing(sitk::Image, std::string);
        void printMeshSize(std::vector<unsigned int>);
};

#endif // UTILS_H
