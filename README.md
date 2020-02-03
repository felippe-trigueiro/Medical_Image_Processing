# Medical_Image_Processing
This repository is associated with the projects that I developed in my Master's Degree. Here it can be found the implementation of a Deformable Registration algorithm using B-Splines. That algorithm consists in align two images, 2D or 3D, according with some similarity measure.

For this implementation, I used the SimpleITK library which is a specialized one for working with 3D images specially for the problems of registration and segmentation.

Before of doing the deformable registration, I did an affine registration which just alligns the images using rotations, translations, shearing and scaling transformations.

After the registration process I try to label some of the neuroanatomical structures using the Talairach Atlas.
