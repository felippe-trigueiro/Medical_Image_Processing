#include "utils_registration.h"

UtilsRegistration::UtilsRegistration()
{

}

std::string UtilsRegistration::readMetaData(const std::string path, const std::string field)
{
    sitk::ImageFileReader metadata;
    std::string field_value = "";
    metadata.SetFileName( path );
    metadata.LoadPrivateTagsOn();
    metadata.ReadImageInformation();
    std::vector<std::string> metadata_keys = metadata.GetMetaDataKeys();

    if (field.compare("all") != 0)
        field_value = metadata.GetMetaData(field);
    else
        for (unsigned i = 0; i < metadata_keys.size(); i++)
            std::cout << metadata_keys[i] << ": " << metadata.GetMetaData(metadata_keys[i]) << std::endl;
    return field_value;
}

std::vector<std::string> UtilsRegistration::stringSplit(const std::string input)
{
    std::vector<std::string> splitted_string;
    std::stringstream s_stream(input); //create string stream from the string
    while(s_stream.good())
    {
        std::string substr;
        getline(s_stream, substr, '\\'); //get first string delimited by comma
        splitted_string.push_back(substr);
    }

    return splitted_string;
}

sitk::Image UtilsRegistration::readDicomSeries(const std::string path)
{
    sitk::ImageSeriesReader reader;
    const std::vector<std::string> dicom_names = sitk::ImageSeriesReader::GetGDCMSeriesFileNames( path );

    //Reading the spacing
    std::string origin1 = readMetaData(dicom_names[0], "0020|0032");
    std::string origin2 = readMetaData(dicom_names[1], "0020|0032");
    std::string pixel_spacing = readMetaData(dicom_names[0], "0028|0030");

    std::vector<std::string> splitted_origin1 = stringSplit(origin1);
    std::vector<std::string> splitted_origin2 = stringSplit(origin2);
    std::vector<std::string> splitted_pixel_spacing = stringSplit(pixel_spacing);

    std::vector<double> spacing(3);

    spacing[2] = atof(splitted_origin2[2].c_str()) - atof(splitted_origin1[2].c_str());
    spacing[1] = atof(splitted_pixel_spacing[1].c_str());
    spacing[0] = atof(splitted_pixel_spacing[0].c_str());

    reader.SetFileNames( dicom_names );
    sitk::Image image = reader.Execute();
    image.SetSpacing(spacing);

    return image;
}

sitk::Image UtilsRegistration::rotateImage3D(sitk::Image input, std::vector<double> W, double angle)
{
    sitk::Image copyImage = input;
    std::vector<double> origin = input.GetOrigin();
    copyImage = input;

    std::vector<double> O(3, 0);
    input.SetOrigin(O);
    sitk::VersorTransform transform = sitk::VersorTransform(W, angle);
    std::vector<unsigned int> center = input.GetSize();
    std::vector<double> center_double(center.begin(), center.end());
    for (unsigned i = 0; i < center_double.size(); i++)
        center_double[i] = center_double[i]/2;
    transform.SetCenter(input.TransformContinuousIndexToPhysicalPoint(center_double));

    sitk::Image outImage = sitk::Resample(input, copyImage.GetSize(), transform, sitk::sitkLinear, O, input.GetSpacing(), input.GetDirection());
    outImage.SetOrigin(origin);

    return outImage;
}

std::vector<double> UtilsRegistration::get_center(sitk::Image input)
{
    std::vector<unsigned int> center = input.GetSize();
    std::vector<double> center_double(center.begin(), center.end());
    for (unsigned i = 0; i < center_double.size(); i++)
        center_double[i] = center_double[i]/2;

    return center_double;
}

sitk::Image UtilsRegistration::imResize3(sitk::Image input, sitk::Image output_size_image)
{
    std::vector<unsigned int> new_dims = output_size_image.GetSize();
    std::vector<unsigned int> old_dims = input.GetSize();

    sitk::Transform transform = sitk::Transform(3, sitk::sitkIdentity);

    std::vector<double> spacing(3);
    spacing[0] = static_cast<double>(old_dims[0])/new_dims[0]*input.GetSpacing()[0];
    spacing[1] = static_cast<double>(old_dims[1])/new_dims[1]*input.GetSpacing()[1];
    spacing[2] = static_cast<double>(old_dims[2])/new_dims[2]*input.GetSpacing()[2];

    for (unsigned i = 0; i < spacing.size(); i++)
        std::cout << spacing[i] << std::endl;

    sitk::Image resampled_image = sitk::Resample(input, output_size_image, transform, sitk::sitkBSplineResamplerOrder3);
    resampled_image.SetOrigin(input.GetOrigin());
    resampled_image.SetDirection(input.GetDirection());
    resampled_image.SetSpacing(spacing);
    return resampled_image;
}

void UtilsRegistration::printDimension(sitk::Image image, std::string image_name)
{
    std::vector<unsigned int> image_dims = image.GetSize();
    std::cout << image_name + " Image Dimensions: ";
    for (std::vector<unsigned int>::iterator i = image_dims.begin(); i != image_dims.end(); ++i)
        std::cout << *i << ' ';
}

void UtilsRegistration::printImageType(sitk::Image image, std::string image_name)
{
    std::cout << std::endl << image_name + " Image Pixel Type: " << image.GetPixelIDTypeAsString() << std::endl;
}

void UtilsRegistration::printSpacing(sitk::Image image, std::string image_name)
{
    std::vector<double> image_spacing = image.GetSpacing();
    std::cout << image_name + " Image Spacing: ";
    for (std::vector<double>::iterator i = image_spacing.begin(); i != image_spacing.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
}

void UtilsRegistration::printMeshSize(std::vector<unsigned int> tms) //tms = Transform Mesh Size
{
    std::cout << "Transform Domain Mesh Size: ";
    for (std::vector<unsigned int>::iterator i = tms.begin(); i != tms.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl << std::endl;
}

sitk::Transform UtilsRegistration::transform_inverse(sitk::Transform inverse)
{
    sitk::TransformToDisplacementFieldFilter obj_transformation;
    sitk::Image disp_field = obj_transformation.Execute(inverse);
    sitk::InverseDisplacementFieldImageFilter obj_inv;
    sitk::Image inv_disp_field = obj_inv.Execute(disp_field);
    sitk::Transform inver_transformation = sitk::DisplacementFieldTransform(inv_disp_field);

    return inver_transformation;
}

unsigned int UtilsRegistration::returning_label(sitk::Image moving_volume, sitk::Image atlas,
                                                std::vector<unsigned int> voxels,
                                                sitk::Transform Affine_inverse,
                                                sitk::Transform BS_inverse)
{
    std::vector<double> physical_voxel = moving_volume.TransformIndexToPhysicalPoint(voxels);
    std::vector<double> transformed_point = Affine_inverse.TransformPoint(BS_inverse.TransformPoint(physical_voxel))
    std::vector<unsigned int> atlas_index = atlas.TransformPhysicalPointToIndex(transformed_point);
    unsigned int label = atlas.GetPixel(fixed_index);

    return label;
}
