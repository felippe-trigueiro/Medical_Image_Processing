#include "Iterationupdate_affine.h"
#include "utils_registration.h"
#include "affine_registration.h"
#include "bspline_registration.h"

int main()
{
    UtilsRegistration utils;

    //Reading the Volumes: Fixed, Moving, Atlas
    sitk::Image fixed = sitk::ReadImage( "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                         "Volumes/MNI152_T1_1mm.nii", sitk::sitkFloat32 );
    sitk::Image moving = sitk::ReadImage("/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                         "Volumes/mri_vbm6.dcm", sitk::sitkFloat32 );
    sitk::Image atlas = sitk::ReadImage("/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                        "Codes/Talairach-labels-1mm.nii", sitk::sitkFloat32 );

    //Reading the Talairach Labels
    std::map<int, std::string> talairach_labels = utils.readTalairachLabels("/home/felippe/Área de Trabalho/Felippe/"
                                                                            "Mestrado/Artigos/7_Brainn_2020/Codes/"
                                                                            "Talairach-labels.txt");
    fixed = sitk::Normalize( fixed );
    moving = sitk::Normalize( moving );

    utils.printSpacing(fixed, "Fixed");
    utils.printDimension(fixed, "Fixed");
    utils.printImageType(fixed, "Fixed");

    std::cout << std::endl;

    utils.printSpacing(moving, "Moving");
    utils.printDimension(moving, "Moving");
    utils.printImageType(moving, "Moving");

    std::cout << std::endl << "Doing Affine Registration" << std::endl << std::endl;
    AffineRegistration affineReg(fixed, moving);
    sitk::Transform affine_trans = affineReg.run();

    //Applying the Affine transformation
    sitk::Image transformed_image_affine = sitk::Resample(moving, fixed, affine_trans, sitk::sitkLinear, 0, moving.GetPixelID());

    std::cout << std::endl << "Doing Bspline Registration" << std::endl << std::endl;
    BsplineRegistration bsplineReg(fixed, transformed_image_affine);
    sitk::Transform bspline_trans = bsplineReg.run();

    //Applying the Bspline Transformation
    sitk::Image transformed_image_bspline = sitk::Resample(transformed_image_affine, bspline_trans, sitk::sitkLinear, moving.GetPixelID());

    //Saving the transformation and the images
    sitk::WriteTransform(affine_trans, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/Codes/"
                                "Affine_transform.tfm");
    sitk::WriteTransform(bspline_trans, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/Codes/"
                                "Bspline_transform.tfm");


    sitk::WriteImage(transformed_image_affine, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                        "Results/Affine_MNI_1_MI.mha");
    sitk::WriteImage(transformed_image_bspline, "/home/felippe/Área de Trabalho/Felippe/Mestrado/Artigos/7_Brainn_2020/"
                                        "Results/Bspline_MNI_1_MI.mha");

    std::vector<int64_t> voxels(3);

    std::cout << std::endl << "Enter with voxels coordinates (x, y, z): ";
    std::cin >> voxels[0] >> voxels[1] >> voxels[2];

    sitk::Transform affine_inverse = utils.transform_inverse(affine_trans);
    sitk::Transform bspline_inverse = utils.transform_inverse(bspline_trans);
    float label = utils.returning_label(moving, atlas, voxels, affine_inverse, bspline_inverse);

    std::cout << label << std::endl;
    std::cout << "Name of the Region: " << talairach_labels[static_cast<int>(label)] << std::endl;

    return 0;
}
