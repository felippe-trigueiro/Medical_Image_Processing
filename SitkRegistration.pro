TEMPLATE = app
CONFIG += console c++11 static
CONFIG -= app_bundle
CONFIG -= qt

#Includes
INCLUDEPATH += "/home/felippe/SimpleITK-build/ITK-prefix/include/ITK-4.13"
INCLUDEPATH += "/home/felippe/SimpleITK-build/include/SimpleITK-1.3"

#SimpleITK
LIBS += -L/home/felippe/SimpleITK-build/lib/ \
        -lSimpleITKCommon-1.3 \
        -lSimpleITKIO-1.3 \
        -lSimpleITKRegistration-1.3 \
        -lSimpleITKBasicFilters0-1.3 \
        -lSimpleITK_ITKAnisotropicSmoothing-1.3 \
        -lSimpleITK_ITKAntiAlias-1.3 \
        -lSimpleITK_ITKBiasCorrection-1.3 \
        -lSimpleITK_ITKBinaryMathematicalMorphology-1.3 \
        -lSimpleITK_ITKClassifiers-1.3 \
        -lSimpleITK_ITKColormap-1.3 \
        -lSimpleITK_ITKCommon-1.3 \
        -lSimpleITK_ITKConnectedComponents-1.3 \
        -lSimpleITK_ITKConvolution-1.3 \
        -lSimpleITK_ITKCurvatureFlow-1.3 \
        -lSimpleITK_ITKDeconvolution-1.3 \
        -lSimpleITK_ITKDenoising-1.3 \
        -lSimpleITK_ITKDisplacementField-1.3 \
        -lSimpleITK_ITKDistanceMap-1.3 \
        -lSimpleITK_ITKFFT-1.3 \
        -lSimpleITK_ITKFastMarching-1.3 \
        -lSimpleITK_ITKImageCompare-1.3 \
        -lSimpleITK_ITKImageCompose-1.3 \
        -lSimpleITK_ITKImageFeature-1.3 \
        -lSimpleITK_ITKImageFilterBase-1.3 \
        -lSimpleITK_ITKImageFunction-1.3 \
        -lSimpleITK_ITKImageFusion-1.3 \
        -lSimpleITK_ITKImageGradient-1.3 \
        -lSimpleITK_ITKImageGrid-1.3 \
        -lSimpleITK_ITKImageIntensity-1.3 \
        -lSimpleITK_ITKImageLabel-1.3 \
        -lSimpleITK_ITKImageNoise-1.3 \
        -lSimpleITK_ITKImageSources-1.3 \
        -lSimpleITK_ITKImageStatistics-1.3 \
        -lSimpleITK_ITKLabelMap-1.3 \
        -lSimpleITK_ITKLabelVoting-1.3 \
        -lSimpleITK_ITKLevelSets-1.3 \
        -lSimpleITK_ITKMathematicalMorphology-1.3 \
        -lSimpleITK_ITKPDEDeformableRegistration-1.3 \
        -lSimpleITK_ITKRegionGrowing-1.3 \
        -lSimpleITK_ITKRegistrationCommon-1.3 \
        -lSimpleITK_ITKReview-1.3 \
        -lSimpleITK_ITKSmoothing-1.3 \
        -lSimpleITK_ITKThresholding-1.3 \
        -lSimpleITK_ITKTransform-1.3 \
        -lSimpleITK_ITKWatersheds-1.3 \
        -lSimpleITK_SimpleITKFilters-1.3 \
        -lSimpleITKBasicFilters1-1.3 \
        -lSimpleITKIO-1.3

#ITK
LIBS += -L/home/felippe/SimpleITK-build/ITK-prefix/lib/ \
        -lITKIOBruker-4.13 \
        -lITKIOHDF5-4.13 \
        -lITKIOLSM-4.13 \
        -lITKIOMINC-4.13 \
        -litkminc2-4.13 \
        -lrt \
        -lITKIOMRC-4.13 \
        -lSimpleITKRegistration-1.3 \
        -lITKOptimizersv4-4.13 \
        -litklbfgs-4.13 \

#SimpleITK
LIBS += -L/home/felippe/SimpleITK-build/lib/ \
        -lSimpleITK_ITKAnisotropicSmoothing-1.3 \
        -lSimpleITK_ITKAntiAlias-1.3 \
        -lSimpleITK_ITKBiasCorrection-1.3 \
        -lSimpleITK_ITKBinaryMathematicalMorphology-1.3 \
        -lSimpleITK_ITKClassifiers-1.3 \
        -lSimpleITK_ITKColormap-1.3 \
        -lSimpleITK_ITKCommon-1.3 \
        -lSimpleITK_ITKConnectedComponents-1.3 \
        -lSimpleITK_ITKConvolution-1.3 \
        -lSimpleITK_ITKCurvatureFlow-1.3 \
        -lSimpleITK_ITKDeconvolution-1.3 \
        -lSimpleITK_ITKDenoising-1.3 \
        -lSimpleITK_ITKDisplacementField-1.3 \
        -lSimpleITK_ITKDistanceMap-1.3 \
        -lSimpleITK_ITKFFT-1.3 \
        -lSimpleITK_ITKFastMarching-1.3 \
        -lSimpleITK_ITKImageCompare-1.3 \
        -lSimpleITK_ITKImageCompose-1.3 \
        -lSimpleITK_ITKImageFeature-1.3 \
        -lSimpleITK_ITKImageFilterBase-1.3 \
        -lSimpleITK_ITKImageFunction-1.3 \
        -lSimpleITK_ITKImageFusion-1.3 \
        -lSimpleITK_ITKImageGradient-1.3 \
        -lSimpleITK_ITKImageGrid-1.3 \
        -lSimpleITK_ITKImageIntensity-1.3 \
        -lSimpleITK_ITKImageLabel-1.3 \
        -lSimpleITK_ITKImageNoise-1.3 \
        -lSimpleITK_ITKImageSources-1.3 \
        -lSimpleITK_ITKImageStatistics-1.3 \
        -lSimpleITK_ITKLabelMap-1.3 \
        -lSimpleITK_ITKLabelVoting-1.3 \
        -lSimpleITK_ITKLevelSets-1.3 \
        -lSimpleITK_ITKMathematicalMorphology-1.3 \
        -lSimpleITK_ITKPDEDeformableRegistration-1.3 \
        -lSimpleITK_ITKRegionGrowing-1.3 \
        -lSimpleITK_ITKRegistrationCommon-1.3 \
        -lSimpleITK_ITKReview-1.3 \

LIBS += -L/home/felippe/SimpleITK-build/ITK-prefix/lib/ \
        -lITKReview-4.13 \
        -lITKIOGDCM-4.13 \
        -litkgdcmMSFF-4.13 \
        -litkgdcmDICT-4.13 \
        -litkgdcmIOD-4.13 \
        -litkgdcmDSED-4.13 \
        -litkgdcmCommon-4.13 \
        -litkgdcmjpeg8-4.13 \
        -litkgdcmjpeg12-4.13 \
        -litkgdcmjpeg16-4.13 \
        -litkgdcmopenjp2-4.13 \
        -litkgdcmcharls-4.13 \
        -litkgdcmuuid-4.13 \
        -lITKIOBMP-4.13 \
        -lITKIOBioRad-4.13 \
        -lITKIOGE-4.13 \
        -lITKIOGIPL-4.13 \
        -lITKIOJPEG-4.13 \
        -lITKIOMeta-4.13 \
        -lITKIONIFTI-4.13 \
        -lITKniftiio-4.13 \
        -lITKznz-4.13 \
        -lITKIONRRD-4.13 \
        -lITKNrrdIO-4.13 \
        -lITKIOPNG-4.13 \
        -litkpng-4.13 \
        -lITKIOStimulate-4.13 \
        -lITKIOTIFF-4.13 \
        -litktiff-4.13 \
        -litkjpeg-4.13 \
        -lITKIOVTK-4.13 \
        -lITKIOTransformHDF5-4.13 \
        -litkhdf5_cpp \
        -litkhdf5 \
        -lITKIOTransformInsightLegacy-4.13 \
        -lITKIOTransformMatlab-4.13 \
        -lITKQuadEdgeMesh-4.13 \
        -lITKBiasCorrection-4.13 \
        -lITKPolynomials-4.13 \
        -lITKBioCell-4.13 \
        -lITKFEM-4.13 \
        -lITKOptimizers-4.13 \
        -lITKIOSpatialObjects-4.13 \
        -lITKIOSiemens-4.13 \
        -lITKIOIPL-4.13 \
        -lITKIOXML-4.13 \
        -lITKIOImageBase-4.13 \
        -lITKEXPAT-4.13 \
        -lITKKLMRegionGrowing-4.13 \
        -litkopenjpeg-4.13 \
        -lITKVTK-4.13 \

#SimpleITK
LIBS += -L/home/felippe/SimpleITK-build/lib/ \
        -lSimpleITK_ITKSmoothing-1.3 \
        -lSimpleITK_ITKThresholding-1.3 \
        -lSimpleITK_ITKTransform-1.3 \
        -lSimpleITK_ITKWatersheds-1.3

#ITK
LIBS += -L/home/felippe/SimpleITK-build/ITK-prefix/lib/ \
        -lITKWatersheds-4.13

#SimpleITK
LIBS += -L/home/felippe/SimpleITK-build/lib/ \
        -lSimpleITK_SimpleITKFilters-1.3 \
        -lSimpleITKBasicFilters0-1.3 \
        -lSimpleITKCommon-1.3

#ITK
LIBS += -L/home/felippe/SimpleITK-build/ITK-prefix/lib/ \
        -lITKIOTransformBase-4.13 \
        -lITKTransformFactory-4.13


#SimpleITK
LIBS += -L/home/felippe/SimpleITK-build/lib/ \
         -lSimpleITKExplicit-1.3

#ITK
LIBS += -L/home/felippe/SimpleITK-build/ITK-prefix/lib/ \
        -lITKSpatialObjects-4.13 \
        -lITKMesh-4.13 \
        -lITKTransform-4.13 \
        -lITKPath-4.13 \
        -lITKMetaIO-4.13 \
        -litkzlib-4.13 \
        -lITKLabelMap-4.13 \
        -lITKStatistics-4.13 \
        -lITKCommon-4.13 \
        -litksys-4.13 \
        -litkdouble-conversion-4.13 \
        -lITKVNLInstantiation-4.13 \
        -litkvnl_algo-4.13 \
        -litkvnl-4.13 \
        -litknetlib-4.13 \
        -litkvcl-4.13 \
        -lpthread \
        -lm \
        -ldl \
        -litkNetlibSlatec-4.13 \
        -litkv3p_netlib-4.13 \
        -lm

SOURCES += \
        affine_registration.cpp \
        bspline_registration.cpp \
        iterationupdate_affine.cpp \
        iterationupdate_bspline.cpp \
        main.cpp \
        multiresolutioniterationupdate.cpp \
        utils_registration.cpp

HEADERS += \
    Iterationupdate_affine.h \
    affine_registration.h \
    bspline_registration.h \
    iterationupdate_bspline.h \
    multiresolutioniterationupdate.h \
    utils_registration.h
