#include "bspline_registration.h"

BsplineRegistration::BsplineRegistration(sitk::Image fvolume, sitk::Image mvolume)
{
    set_number_of_levels(3);
    std::vector<unsigned int> scaleFactors(number_of_levels);
    scaleFactors[0] = 1;
    scaleFactors[1] = 2;
    scaleFactors[2] = 4;

    std::vector<unsigned int> shrinkFactors(number_of_levels);
    shrinkFactors[0] = 4;
    shrinkFactors[1] = 2;
    shrinkFactors[2] = 1;

    std::vector<double> smoothingSigmas(number_of_levels);
    smoothingSigmas[0] = 4.0;
    smoothingSigmas[1] = 2.0;
    smoothingSigmas[2] = 1.0;

    set_fixed(fvolume);
    set_moving(mvolume);
    set_metric("mi");
    set_initial_number_control_points(2);
    set_learning_rate(2);
    set_scale_factors(scaleFactors);
    set_shrink_factors(shrinkFactors);
    set_smoothing_sigmas(smoothingSigmas);
    set_sampling_percentage(0.01);
    set_convergence_window_size(5);
    set_number_of_histogram_bins(64);
    set_convergence_minimum_value(1e-4);
    set_number_of_iterations(100);
}

BsplineRegistration::BsplineRegistration(sitk::Image fvolume, sitk::Image mvolume, unsigned int icp)
{
    set_number_of_levels(3);
    std::vector<unsigned int> scaleFactors(number_of_levels);
    scaleFactors[0] = 1;
    scaleFactors[1] = 2;
    scaleFactors[2] = 4;

    std::vector<unsigned int> shrinkFactors(number_of_levels);
    shrinkFactors[0] = 4;
    shrinkFactors[1] = 2;
    shrinkFactors[2] = 1;

    std::vector<double> smoothingSigmas(number_of_levels);
    smoothingSigmas[0] = 4.0;
    smoothingSigmas[1] = 2.0;
    smoothingSigmas[2] = 1.0;

    set_fixed(fvolume);
    set_moving(mvolume);
    set_metric("mi");
    set_initial_number_control_points(icp);
    set_learning_rate(2);
    set_scale_factors(scaleFactors);
    set_shrink_factors(shrinkFactors);
    set_smoothing_sigmas(smoothingSigmas);
    set_sampling_percentage(0.01);
    set_convergence_window_size(5);
    set_number_of_histogram_bins(64);
    set_convergence_minimum_value(1e-4);
    set_number_of_iterations(100);
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

void BsplineRegistration::set_metric(std::string m)
{
    std::transform(m.begin(), m.end(), m.begin(), [](unsigned char c){ return std::tolower(c); });

    if (m.compare("mi") == 0 || m.compare("ms") || m.compare("co"))
        metric = m;
    else;
        //Do the error here
}

void BsplineRegistration::set_scale_factors(std::vector<unsigned int> sf)
{
    if (sf.size() == number_of_levels)
        scale_factors = sf;
    else;
        //Do the error here
}

void BsplineRegistration::set_smoothing_sigmas(std::vector<double> ss)
{
    if (ss.size() == number_of_levels)
        smoothing_sigmas = ss;
    else;
        //Do the error here
}

void BsplineRegistration::set_shrink_factors(std::vector<unsigned int> sh_f)
{

    if (sh_f.size() == number_of_levels)
        shrink_factors = sh_f;
    else;
        //Do the error here
}

void BsplineRegistration::set_number_of_iterations(unsigned int ni)
{
    if (ni > 0 && ni < 1000000)
        number_of_iterations = ni;
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

std::string BsplineRegistration::get_metric()
{
    return metric;
}

std::vector <unsigned int> BsplineRegistration::get_scale_factors()
{
    return scale_factors;
}

std::vector <unsigned int> BsplineRegistration::get_shrink_factors()
{
    return shrink_factors;
}

std::vector <double> BsplineRegistration::get_smoothing_sigmas()
{
    return smoothing_sigmas;
}

unsigned int BsplineRegistration::get_number_of_iterations()
{
    return number_of_iterations;
}


//RUN
sitk::Transform BsplineRegistration::run()
{
    std::vector<unsigned int> transformDomainMeshSize(fixed.GetDimension(), initial_number_control_points);
    sitk::BSplineTransform tx = sitk::BSplineTransformInitializer(fixed, transformDomainMeshSize);

    UtilsRegistration ut;
    ut.printMeshSize(transformDomainMeshSize);

    std::cout << "Initial Number of Parameters:" << tx.GetNumberOfParameters() << std::endl;
    sitk::ImageRegistrationMethod R;
    R.SetMetricAsMattesMutualInformation(number_of_histogram_bins);
    R.SetMetricSamplingStrategy(R.RANDOM);
    R.SetMetricSamplingPercentage(sampling_percentage);

    sitk::ImageRegistrationMethod::EstimateLearningRateType estimateLearningRate = R.EachIteration;
    R.SetOptimizerAsGradientDescent(learning_rate,
                                    number_of_iterations,
                                    convergence_minimum_value,
                                    convergence_window_size,
                                    estimateLearningRate);
    R.SetOptimizerScalesFromPhysicalShift();
    R.SetInterpolator(sitk::sitkLinear);
    R.SetInitialTransformAsBSpline(tx,
                                   true,
                                   scale_factors);
    R.SetShrinkFactorsPerLevel(shrink_factors);
    R.SetSmoothingSigmasPerLevel(smoothing_sigmas);
    IterationUpdateBspline cmd1(R, tx);
    R.AddCommand( sitk::sitkIterationEvent, cmd1);

    MultiResolutionIterationUpdate cmd2(R);
    R.AddCommand( sitk::sitkMultiResolutionIterationEvent, cmd2);

    std::cout << "Initializing the Registration!!" << std::endl << std::endl;
    sitk::Transform outBspline = R.Execute( fixed, moving );

    std::cout << "-------" << std::endl;
    std::cout << outBspline.ToString() << std::endl;
    std::cout << "Optimizer stop condition: " << R.GetOptimizerStopConditionDescription() << std::endl;
    std::cout << " Iteration: " << R.GetOptimizerIteration() << std::endl;
    std::cout << " Metric value: " << R.GetMetricValue() << std::endl;

    return outBspline;
}











