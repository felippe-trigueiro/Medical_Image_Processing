#ifndef BSPLINE_REGISTRATION_H
#define BSPLINE_REGISTRATION_H

#include <SimpleITK.h>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#include "iterationupdate_bspline.h"
#include "affine_registration.h"
#include "utils_registration.h"
#include "multiresolutioniterationupdate.h"

namespace sitk = itk::simple;

class BsplineRegistration
{
    public:
        //Constructors
        BsplineRegistration(sitk::Image, sitk::Image);
        BsplineRegistration(sitk::Image, sitk::Image, unsigned int);

        //SET Functions
        void set_initial_number_control_points(unsigned int);
        void set_number_of_histogram_bins(unsigned int);
        void set_sampling_percentage(double);
        void set_learning_rate(double);
        void set_convergence_minimum_value(double);
        void set_convergence_window_size(unsigned int);
        void set_number_of_levels(unsigned int);
        void set_fixed(sitk::Image);
        void set_moving(sitk::Image);
        void set_metric(std::string);
        void set_scale_factors(std::vector<unsigned int>);
        void set_smoothing_sigmas(std::vector<double>);
        void set_shrink_factors(std::vector<unsigned int>);
        void set_number_of_iterations(unsigned int);

        //GET Functions
        unsigned int get_initial_number_control_points();
        unsigned int get_number_of_histogram_bins();
        double get_sampling_percentage();
        double get_learning_rate();
        double get_convergence_minimum_value();
        unsigned int get_convergence_window_size();
        unsigned int get_number_of_levels();
        std::string get_metric();
        sitk::Image get_fixed();
        sitk::Image get_moving();
        std::vector<unsigned int> get_scale_factors();
        std::vector<double> get_smoothing_sigmas();
        std::vector<unsigned int> get_shrink_factors();
        unsigned int get_number_of_iterations();

        sitk::Transform run();

    private:
        //Parameters of the Registration
        unsigned int initial_number_control_points;
        unsigned int number_of_histogram_bins; //Used only with MI
        std::string metric;
        double sampling_percentage;
        double learning_rate;
        unsigned int number_of_iterations;
        double convergence_minimum_value;
        unsigned int convergence_window_size;
        unsigned int number_of_levels;
        std::vector<unsigned int> scale_factors;
        std::vector<double> smoothing_sigmas;
        std::vector<unsigned int> shrink_factors;

        sitk::Image moving;
        sitk::Image fixed;
};

#endif // BSPLINE_REGISTRATION_H
