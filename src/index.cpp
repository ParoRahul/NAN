  
#include <nan.h>
#include "test.hpp"

NAN_MODULE_INIT(InitModule) {
  CamFunction::Init(target);
}

NODE_MODULE(myModule, InitModule);