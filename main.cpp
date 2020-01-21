#include "Iterationupdate.h"
#include "utils_registration.h"

int main()
{
    UtilsRegistration utils = UtilsRegistration();

    //Reading the Fixed Image
    sitk::Image fixed = sitk::ReadImage( "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                         "Volumes/MNI152_T1_1mm.nii", sitk::sitkFloat32 );
    sitk::Image moving = sitk::ReadImage("/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                         "Volumes/mri_vbm6.dcm", sitk::sitkFloat32 );

    fixed = sitk::Normalize( fixed );
    moving = sitk::Normalize( moving );

    utils.printSpacing(fixed, "Fixed");
    utils.printDimension(fixed, "Fixed");
    utils.printImageType(fixed, "Fixed");

    std::cout << std::endl;

    utils.printSpacing(moving, "Moving");
    utils.printDimension(moving, "Moving");
    utils.printImageType(moving, "Moving");

    //Affine Registration
    std::cout << "Initializing the Registration!!" << std::endl << std::endl;

    sitk::AffineTransform affine_transformation = sitk::AffineTransform(fixed.GetDimension());
    //Alligning the center of the images
    sitk::Transform center_transform = sitk::CenteredTransformInitializer(fixed, moving,
                                                                          affine_transformation,
                                                                          sitk::CenteredTransformInitializerFilter::GEOMETRY);
    //Registration settings
    sitk::ImageRegistrationMethod R;
    unsigned int number_of_histogram_bins = 64;
    double samplingPercentage = 0.1;
    const double learningRate = 1;
    const unsigned int number_of_iterations = 4000;

    R.SetMetricAsMattesMutualInformation(number_of_histogram_bins);
    R.SetMetricSamplingStrategy(R.RANDOM);
    R.SetMetricSamplingPercentage(samplingPercentage);

    R.SetInterpolator(sitk::sitkLinear);
    R.SetOptimizerAsGradientDescent(learningRate, number_of_iterations);
    R.SetOptimizerScalesFromPhysicalShift(); //Ver qual a necessidade disso
    R.SetInitialTransform(center_transform);

    IterationUpdate cmd(R);
    R.AddCommand( sitk::sitkIterationEvent, cmd);

    std::cout << "Registration Parameters: " << std::endl;
    std::cout << "Learning Rate: " << learningRate << std::endl;
    std::cout << "Number of Iterations: " << number_of_iterations << std::endl;

    sitk::Transform outTx = R.Execute( fixed, moving );

    std::cout << "-------" << std::endl;
    std::cout << outTx.ToString() << std::endl;
    std::cout << "Optimizer stop condition: " << R.GetOptimizerStopConditionDescription() << std::endl;
    std::cout << " Iteration: " << R.GetOptimizerIteration() << std::endl;
    std::cout << " Metric value: " << R.GetMetricValue() << std::endl;

    //Saving the transformation
    sitk::WriteTransform(outTx, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/Codes/"
                                "Affine_transform.tfm");

    //Applying the transformation
    sitk::Image transformed_image = sitk::Resample(moving, fixed, outTx, sitk::sitkLinear, -3, moving.GetPixelID());
    sitk::WriteImage(transformed_image, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                        "Results/Affine_MNI_1_MI.mha");
    return 0;
}
