#include "bspline_registration.h"

BsplineRegistration::BsplineRegistration(sitk::Image fvolume, sitk::Image mvolume)
{
    set_fixed(fvolume);
    set_moving(mvolume);
}

BsplineRegistration::BsplineRegistration(sitk::Image fvolume, sitk::Image mvolume, unsigned int icp)
{
    set_fixed(fvolume);
    set_moving(mvolume);
    set_initial_number_control_points(icp);
}

//SET Functions
void BsplineRegistration::set_fixed(sitk::Image fvolume)
{
    if (fvolume.GetDimension() == 3)
        fixed = fvolume;
    else;
        //Do the error here
}

void BsplineRegistration::set_moving(sitk::Image mvolume)
{
    if (mvolume.GetDimension() == 3)
        moving = mvolume;
    else;
        //Do the error here
}

void BsplineRegistration::set_learning_rate(double lr)
{
    if (lr > 0)
        learning_rate = lr;
    else;
        //Do the error here
}

void BsplineRegistration::set_number_of_levels(unsigned int nl)
{
    if (nl > 0 && nl < 7)
        number_of_levels = nl;
    else;
        //Do the Error Here
}

void BsplineRegistration::set_sampling_percentage(double sp)
{
    if (sp > 0 && sp <= 1)
        sampling_percentage = sp;
    else;
        //Do the Error Here
}

void BsplineRegistration::set_convergence_window_size(unsigned int cws)
{
    if (cws > 0 && cws < 10)
        convergence_window_size = cws;
    else;
        //Do the error here
}

void BsplineRegistration::set_number_of_histogram_bins(unsigned int hb)
{
    if (hb > 0 && hb < 1000)
        number_of_histogram_bins = hb;
    else;
        //Do the Error Here
}

void BsplineRegistration::set_convergence_minimum_value(double cmv)
{
    if (cmv > 0 && cmv < 5)
        convergence_minimum_value = cmv;
    else;
        //Do the error Here
}

void BsplineRegistration::set_initial_number_control_points(unsigned int ncp)
{
    if (ncp > 0 && ncp < 5)
        initial_number_control_points = ncp;
    else;
        //Do the error here
}

//GET Functions
sitk::Image BsplineRegistration::get_fixed()
{
    return fixed;
}

sitk::Image BsplineRegistration::get_moving()
{
    return moving;
}

double BsplineRegistration::get_learning_rate()
{
    return learning_rate;
}

unsigned int BsplineRegistration::get_number_of_levels()
{
    return number_of_levels;
}

double BsplineRegistration::get_sampling_percentage()
{
    return sampling_percentage;
}

unsigned int BsplineRegistration::get_convergence_window_size()
{
    return convergence_window_size;
}

unsigned int BsplineRegistration::get_number_of_histogram_bins()
{
    return number_of_histogram_bins;
}

double BsplineRegistration::get_convergence_minimum_value()
{
    return convergence_minimum_value;
}

unsigned int BsplineRegistration::get_initial_number_control_points()
{
    return initial_number_control_points;
}

















