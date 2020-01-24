#include "Iterationupdate_affine.h"
#include "utils_registration.h"
#include "affine_registration.h"

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

    AffineRegistration affineReg(fixed, moving);
    sitk::Transform outTx = affineReg.run();

    //Saving the transformation
    sitk::WriteTransform(outTx, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/Codes/"
                                "Affine_transform.tfm");

    //Applying the transformation
    sitk::Image transformed_image = sitk::Resample(moving, fixed, outTx, sitk::sitkLinear, -3, moving.GetPixelID());
    sitk::WriteImage(transformed_image, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                        "Results/Affine_MNI_1_MI.mha");
    return 0;
}
