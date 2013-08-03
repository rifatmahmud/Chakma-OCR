#ifndef IMAGE_H
#define IMAGE_H
#include <cv.h>
#include <highgui.h>


//This class will contain the input image and process it
//until it segments and find all the characters as contours





namespace iii //Input and Image Interface
{


class Image
{
    public:
        Image(cv::Mat original_image);
        virtual ~Image();
        void binarize();//Performs thresholing
        cv::Mat get_binarized_image();
        void get_contours(cv::vector<cv::vector<cv::Point> > &returned_contours);//returns contours from threshold image
        void get_contours_hierarchy(cv::vector<cv::Vec4i> &hier);//returns contours from threshold image


    protected:
    private:
        cv::Mat processable_image, greyscaled_image, binarized_image;
        cv::vector<cv::vector<cv::Point> > contours;//'contours' will contain the contours
        cv::vector<cv::Vec4i> hierarchy; //'hierarchy' will contain the contour hierarchy
        // The processable_image variable will contain the input image.
        //'binarized_image' will hold the image after binarization
        //'greyscaled_image' will hold the image after converting it to greyscale


};

    void acquire_image(const char *filepath, cv::Mat &out);


}


#endif // IMAGE_H
