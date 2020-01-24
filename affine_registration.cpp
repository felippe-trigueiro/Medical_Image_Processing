#include "affine_registration.h"

//Constructors
AffineRegistration::AffineRegistration(sitk::Image f, sitk::Image m)
{
    set_fixed_volume(f);
    set_moving_volume(m);

    //Default Values
    set_metric("mi");
    set_number_of_histogram_bins(64);
    set_sampling_percentage(0.1);
    set_learning_rate(1);
    set_number_of_iterations(1000);
}

AffineRegistration::AffineRegistration(sitk::Image f, sitk::Image m, std::string me)
{
    set_fixed_volume(f);
    set_moving_volume(m);
    set_metric(me);

    //Default Values
    set_number_of_histogram_bins(64);
    set_sampling_percentage(0.1);
    set_learning_rate(1);
    set_number_of_iterations(1000);
}

//SET functions
void AffineRegistration::set_fixed_volume(sitk::Image fvolume)
{
    if (fvolume.GetDimension() == 3)
        fixed_volume = fvolume;
    else;
        //Do the error here
}

void AffineRegistration::set_moving_volume(sitk::Image mvolume)
{
    if (mvolume.GetDimension() == 3)
        moving_volume = mvolume;
    else;
        //Do the error here
}

void AffineRegistration::set_learning_rate(double lr)
{
    if (lr > 0)
        learning_rate = lr;
    else;
        //Do the error here
}

void AffineRegistration::set_sampling_percentage(double sp)
{
    if (sp >= 0 && sp <= 1)
        sampling_percentage = sp;
    else;
        //Do the error here
}

void AffineRegistration::set_number_of_iterations(unsigned int ni)
{
    if (ni > 0 && ni < 1000000)
        number_of_iterations = ni;
    else;
        //Do the error here
}

void AffineRegistration::set_number_of_histogram_bins(unsigned int nb)
{
    if (nb > 0 && nb < 1000)
        number_of_histogram_bins = nb;
    else;
        //Do the error here
}

void AffineRegistration::set_metric(std::string m)
{
    std::transform(m.begin(), m.end(), m.begin(), [](unsigned char c){ return std::tolower(c); });

    if (m.compare("mi") == 0 || m.compare("ms") || m.compare("co"))
        metric = m;
    else;
        //Do the error here
}

//GET functions
unsigned int AffineRegistration::get_number_of_iterations()
{
    return number_of_iterations;
}

unsigned int AffineRegistration::get_number_of_histogram_bins()
{
    return number_of_histogram_bins;
}

double AffineRegistration::get_learning_rate()
{
    return learning_rate;
}

double AffineRegistration::get_sampling_percentage()
{
    return sampling_percentage;
}

sitk::Image AffineRegistration::get_fixed_volume()
{
    return fixed_volume;
}

sitk::Image AffineRegistration::get_moving_volume()
{
    return moving_volume;
}

std::string AffineRegistration::get_metric()
{
    return metric;
}

sitk::Transform AffineRegistration::run()
{
    std::cout << "Initializing the Registration!!" << std::endl << std::endl;
    sitk::AffineTransform affine_transformation = sitk::AffineTransform(fixed_volume.GetDimension());

    //Alligning the center of the images
    sitk::Transform center_transform = sitk::CenteredTransformInitializer(fixed_volume, moving_volume,
                                                                          affine_transformation,
                                                                          sitk::CenteredTransformInitializerFilter::GEOMETRY);
    sitk::ImageRegistrationMethod R;
    if (metric.compare("mi") == 0)
        R.SetMetricAsMattesMutualInformation(number_of_histogram_bins);
    else if (metric.compare("ms"))
        R.SetMetricAsMeanSquares();
    else if (metric.compare("co"))
        R.SetMetricAsCorrelation();
    R.SetMetricSamplingStrategy(R.RANDOM);
    R.SetMetricSamplingPercentage(sampling_percentage);

    R.SetInterpolator(sitk::sitkLinear);
    R.SetOptimizerAsGradientDescent(learning_rate, number_of_iterations);
    R.SetOptimizerScalesFromPhysicalShift(); //See the necessity of this
    R.SetInitialTransform(center_transform);

    IterationUpdateAffine cmd(R);
    R.AddCommand( sitk::sitkIterationEvent, cmd);

    std::cout << "Registration Parameters: " << std::endl;
    std::cout << "Learning Rate: " << learning_rate << std::endl;
    std::cout << "Number of Iterations: " << number_of_iterations << std::endl;

    sitk::Transform outAffine = R.Execute( fixed_volume, moving_volume );

    std::cout << "-------" << std::endl;
    std::cout << outAffine.ToString() << std::endl;
    std::cout << "Optimizer stop condition: " << R.GetOptimizerStopConditionDescription() << std::endl;
    std::cout << " Iteration: " << R.GetOptimizerIteration() << std::endl;
    std::cout << " Metric value: " << R.GetMetricValue() << std::endl;

    return outAffine;
}
