#include <cv.h>
#include <highgui.h>
#include "image.h"


//cv::Mat img;

namespace iii
{

Image::Image(cv::Mat original_image)
{
    //ctor
    processable_image=original_image.clone();
}

Image::~Image()
{
    //dtor
}

void Image::binarize()
{

    cv::cvtColor(processable_image, greyscaled_image, CV_RGB2GRAY, 1);//This is color space conversion function. Please refer to opencv documents for details.
    cv::threshold(greyscaled_image, binarized_image, 127, 255, cv::THRESH_BINARY_INV);
    //This is the threshold function from opencv. Please refer to the opencv documents.
}

cv::Mat Image::get_binarized_image()
{
    return binarized_image;
}

void Image::get_contours(cv::vector<cv::vector<cv::Point> > &returned_contours)
{
    findContours(binarized_image, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    drawContours(binarized_image, contours, CV_FILLED, cv::Scalar(255));
    //Please refer to the opencv doc for more about the functions.
    std::cout<<contours.size()<<std::endl;
    for(int i=0; i<contours.size(); i++)
    {
        returned_contours.push_back(cv::vector<cv::Point>());
        for(int j=0; j<contours[i].size(); j++)
        {
            returned_contours[i].push_back(contours[i][j]);
        }
    }
}

void Image::get_contours_hierarchy(cv::vector<cv::Vec4i> &hier)
{
    for(int i=0; i<hierarchy.size(); i++)
    {
        hier.push_back(hierarchy[i]);
    }
}

 void acquire_image(const char *filepath, cv::Mat &out)
{
    out=cv::imread(filepath, 1).clone();
}

}

