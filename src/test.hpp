// code for camra calibration

#ifndef __NODE_CALIB3D_H
#define __NODE_CALIB3D_H

#include <nan.h>

class CamFunction : public Nan::ObjectWrap {
    public:
        static NAN_MODULE_INIT(Init);
        static NAN_METHOD(New);
        static NAN_METHOD(FindCorners);
        /* static NAN_METHOD(DrawChessboardCorners);
        static NAN_METHOD(CalibrateCamera);
        static NAN_METHOD(SolvePnP);
        static NAN_METHOD(GetOptimalNewCameraMatrix);
        static NAN_METHOD(StereoCalibrate);
        static NAN_METHOD(StereoRectify);
        static NAN_METHOD(ComputeCorrespondEpilines);
        static NAN_METHOD(ReprojectImageTo3D); */
        static Nan::Persistent<v8::FunctionTemplate> constructor;
};

#endif