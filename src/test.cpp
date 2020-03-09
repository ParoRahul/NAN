// Copyright 2020 Rahul Das
#include "test.hpp"
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/Calib3D.hpp>
#include <opencv2/core/types.hpp>

Nan::Persistent<v8::FunctionTemplate> CamFunction::constructor;

NAN_MODULE_INIT(CamFunction::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(CamFunction::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("CamFunction").ToLocalChecked());

  // link our getters and setter to the object property
  Nan::SetPrototypeMethod(ctor, "findCorners", FindCorners);

  target->Set(Nan::New("CamFunction").ToLocalChecked(), ctor->GetFunction());
}


NAN_METHOD(CamFunction::New) {
  // throw an error if constructor is called without new keyword
  if(!info.IsConstructCall()) {
    return Nan::ThrowError(Nan::New("CamFunction::New - called without new keyword").ToLocalChecked());
  }

  // expect exactly 3 arguments
  if(info.Length() != 0) {
    return Nan::ThrowError(Nan::New("CamFunction::New - expected fileName arguments").ToLocalChecked());
  }

  // create a new instance and wrap our javascript instance
  CamFunction* camFunction = new CamFunction();
  camFunction->Wrap(info.Holder());

  // return the wrapped javascript instance
  info.GetReturnValue().Set(info.Holder());
}


NAN_METHOD(CamFunction::FindCorners) {
  // unwrap this Vector
  // CamFunction * self = Nan::ObjectWrap::Unwrap<CamFunction>(info.This());

  /* if (!Nan::New(CamFunction::constructor)->HasInstance(info[0])) {
    return Nan::ThrowError(Nan::New("Vector::Add - expected argument to be instance of Vector").ToLocalChecked());
  } */
  try {
    cv::Mat mat;
    // cv::Size patternSize = new Size(8, 6);
    std::vector<cv::Point2f> corners;
    bool found = cv::findChessboardCorners(mat, Size(8, 6), corners);
    info.GetReturnValue().Set(found);
  } catch (cv::Exception &e) {
    const char *err_msg = e.what();
    Nan::ThrowError(err_msg);
    return;
  }
}
