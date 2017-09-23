# SDL_CV_Samples

Samples using SDL instead of OpenCV GTK+ for darknet witout GTK+.
  
Why this post  
*We try implimentation of Darknet DNN Framework on SoC-FPGA(Altera)*  
Darknet is pure C lang.  
So, very easy to implement on ARM.  
When build Darknet with OpenCV, we had problems for OpenCV-GTK+.  
OpenCV-GTK+ is C++ implementation and depends on many other packages.  
SO, it is not easy implenent GTK+ on ARM.  
  
After long fight against GTK+ packages, we stopped implementation for ARM.  
And we use SDL instead of GTK+.
Only cvNamedWindow, cvShowImage, cvDestroyAllWindows are supported.  
we satisfy only its support.  
  
If you need GTK+ on ARM, use SDL instead of GTK+, it's easy to implement.  
  
*Prerequirement*   
1. OpenCV library buit without GTK+ implementation for x86 or ARM.  
2. SDL library for x86 or ARM    
3. Darknet library for x86 or ARM  
4. gcc and g++ for x86 or arm-linux-gnueabihf-gcc and arm-linux-gnueabihf-g++ for ARM

*make samples*  
1. set paths for pkg-config and LD_LIBRARY_PATH in each Makefiles.  
2. make

by.  
