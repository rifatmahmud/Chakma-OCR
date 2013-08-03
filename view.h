#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <cv.h>
#include <highgui.h>

namespace view
{

    void show_image(cv::Mat image);
    void write_image(cv::Mat image, const char *filepath);

}



#endif // VIEW_H_INCLUDED
