#ifndef AFFINE_REGISTRATION_H
#define AFFINE_REGISTRATION_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>

namespace sitk = itk::simple;

class AffineRegistration
{
    public:
        AffineRegistration();

        //SET functions
        void set_number_of_histogram_bins(unsigned int);
        void set_sampling_percentage(double);
        void set_learning_rate(double);
        void set_number_of_iterations(unsigned int);
        void set_moving_volume(sitk::Image);
        void set_fixed_volume(sitk::Image);

        //GET functions
        unsigned int get_number_of_histogram_bins();
        double get_sampling_percentage();
        double get_learning_rate();
        unsigned int get_number_of_iterations();
        sitk::Image get_moving_volume();
        sitk::Image get_fixed_volume();

    private:
        //Parameters of the registration
        unsigned int number_of_histogram_bins; //Used only with MI
        double sampling_percentage;
        double learning_rate;
        unsigned int number_of_iterations;

        //Volumes used in the registration
        sitk::Image moving_volume;
        sitk::Image fixed_volume;
};

#endif // AFFINE_REGISTRATION_H
