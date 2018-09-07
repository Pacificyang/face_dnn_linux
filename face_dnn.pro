TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += main.cpp \
    ComputeDistance.cpp \
    ExtractFeature_.cpp \
    FaceDetect.cpp \
    FaceProcessing.cpp \
    Recognition.cpp \
    Register.cpp \
    SaveVector.cpp


#opencv
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
  #      /usr/local/lib/libopencv_imgcodecs.so


# caffe
INCLUDEPATH += /root/server/caffe-master/include \
               /root/server/caffe-master/src \
 #              /home/pacificy/server/caffe/distribute/include

LIBS += -lcaffe -L/root/server/caffe-master/build/lib

#dlib
#LIBS += -L/root/server/dlib/dlib

#INCLUDEPATH += /home/pacificy/server/dlib
#SOURCES += /home/pacificy/server/dlib/dlib/all/source.cpp

#facelib
#INCLUDEPATH += /home/pacificy/server/libfacedetection/include
#LIBS += -L/home/pacificy/server/libfacedetection/lib

#other
LIBS += -lprotobuf #-L/usr/lib/x86_64-linux-gnu/libprotobuf.a
LIBS += -lglog -lboost_system -lpthread -lX11 #-L/usr/lib/x86_64-linux-gnu/lib*.a


#INCLUDEPATH += /home/pacificy/qtprojects/face_dnn

SUBDIRS += \
    face_dnn.pro

DISTFILES += \
    face_dnn.pro.user \
    VGG_FACE.caffemodel \
    mike.jpg \
    vgg_extract_feature_memorydata.prototxt

HEADERS += \
    caffe_net_memorylayer.h \
    ComputeDistance.h \
    ExtractFeature_.h \
    FaceDetect.h \
    FaceProcessing.h \
    FaceRotate.h \
    Recognition.h \
    Register.h \
    SaveVector.h

include(./qtsingleapplication/qtsinglecoreapplication.pri)
