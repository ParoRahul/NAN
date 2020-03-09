{
  "targets": [
    {
      "target_name": "myModule",
      "sources": ["src/test.cpp" ,"src/index.cpp"],
      "include_dirs": ["<!(node -e \"require('nan')\")",
                       "src",
                       "D:/cpp/vcpkg/packages/opencv4_x86-windows/include"],
      "libraries": ["D:/cpp/vcpkg/packages/opencv4_x86-windows/lib/opencv_core.lib",
                    "D:/cpp/vcpkg/packages/opencv4_x86-windows/lib/opencv_calib3d.lib"],
      "cflags!" :  [ "-fno-exceptions"]      
    }
  ]
}