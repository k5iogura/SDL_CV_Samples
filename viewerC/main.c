#include <stdio.h>
#include <darknet.h>
#ifndef __cplusplus
    #include "opencv2/highgui/highgui_c.h"
    #include "opencv2/imgproc/imgproc_c.h"
    #include "opencv2/core/version.hpp"
    #if CV_MAJOR_VERSION == 3
        #include "opencv2/videoio/videoio_c.h"
    #endif
#endif
#include "sdl_image.h"
static errors(const char* s){perror(s);assert(0);exit(-1);}
extern image get_image_from_stream(CvCapture *cap);

int main(){
    int test=2000;
    int cam_index=0;
    CvCapture * cap;

    static image in;
    int width=512, height=512;
    sdlNamedWindow(NULL,width, height);
    cap = cvCaptureFromCAM(cam_index);
    if(!cap) errors("Could not connect to webcam.\n");

    in = get_image_from_stream(cap);	// dummy capture
    printf("image   w:h=%d:%d\n",in.w,in.h);
    printf("texture w:h=%d:%d\n",width,height);

    while(test-->0){
        if(sdlWaitKey()) break;
        in = get_image_from_stream(cap);
        sdlShowImage(in,width,height);
        free_image(in);
    }
    sdlDestroyAllWindows();
}
