#include <cv.h>
#include <highgui.h>
#include <iostream>
#include "contour.h"
#include "view.h"


//cv::vector<cv::vector<cv::Point> > processable_contours, sorted_contours;

namespace cont
{
    contours_processor::contours_processor(cv::vector<cv::vector<cv::Point> > contours)
    {
        for(int i=0; i<contours.size(); i++)
        {
            processable_contours.push_back(cv::vector<cv::Point>());
            for(int j=0; j<contours[i].size(); j++)
            {
                processable_contours[i].push_back(contours[i][j]);
            }
        }
    }

    contours_processor::~contours_processor()
    {

    }

    void  contours_processor::get_sorted_contours(cv::vector<cv::vector<cv::Point> > &returned_sorted_contours)
    {
        cv::vector<cv::vector<cv::Point> > sorted_contours;
        cv::vector<cv::Rect > bounding_rects;
        cv::vector<cv::Point> mid_pnts;
        std::vector<int> indicator, sorted_cont_indx;
        int i, j, ln_itr, cnt_itr=0, temp_x[100], t, temp_sorted_indx[100];
        double min;
        for(i=0; i<processable_contours.size(); i++)
        {
            bounding_rects.push_back(boundingRect(cv::Mat(processable_contours[i])));

        }
        std::cout<<bounding_rects.size()<<std::endl;

        for(i=0; i<bounding_rects.size(); i++)
        {

            mid_pnts.push_back(cv::Point(bounding_rects[i].x+bounding_rects[i].width/2, bounding_rects[i].y+bounding_rects[i].height/2));
        }

        for(i=0; i<bounding_rects.size(); i++)
        {
            indicator.push_back(1);
        }
        while(cnt_itr<processable_contours.size())
        {
            min=60000;
            for(i=0; i<mid_pnts.size(); i++)
            {
                if(min>mid_pnts[i].y && indicator[i]!=-1)
                {
                   // std::cout<<"In"<<std::endl;
                    min=mid_pnts[i].y;
                }
            }

            ln_itr=0;

            for(i=0; i<bounding_rects.size(); i++)
            {
                if(min>bounding_rects[i].y && min<(bounding_rects[i].y+bounding_rects[i].height) && indicator[i]==1)
                   {
                        std::cout<<cnt_itr<<std::endl;

                       temp_x[ln_itr]=mid_pnts[i].x;

                       temp_sorted_indx[ln_itr]=i;
                       indicator[i]=-1;
                       cnt_itr++;
                       ln_itr++;

                       if(cnt_itr==processable_contours.size())
                        break;

                   }

            }

            for(i=0; i<ln_itr-1; i++)
            {
                for(j=i+1; j<ln_itr; j++)
                {
                    if(temp_x[i]>temp_x[j])
                    {
                        t=temp_x[i];
                        temp_x[i]=temp_x[j];
                        temp_x[j]=t;

                        t=temp_sorted_indx[i];
                        temp_sorted_indx[i]=temp_sorted_indx[j];
                        temp_sorted_indx[j]=t;

                    }
                }
            }

            for(i=0; i<ln_itr; i++)
            {
                sorted_cont_indx.push_back(temp_sorted_indx[i]);
            }


        }
        std::cout<<sorted_cont_indx.size()<<std::endl;
        std::cout<<processable_contours.size()<<std::endl;

        for(i=0; i<processable_contours.size(); i++)
        {
            sorted_contours.push_back(cv::vector<cv::Point>());
            for(j=0; j<processable_contours[sorted_cont_indx[i]].size(); j++)
                sorted_contours[i].push_back(processable_contours[sorted_cont_indx[i]][j]);
        }


        for(i=0; i<sorted_contours.size(); i++)
        {
            returned_sorted_contours.push_back(cv::vector<cv::Point>());
            for(j=0; j<sorted_contours[i].size(); j++)
            {
                returned_sorted_contours[i].push_back(sorted_contours[i][j]);
            }
        }

    }

    void save_contours_as_image(cv::vector<cv::vector<cv::Point> > cont2im, const char *filepath)
    {
        cv::Mat image=cv::Mat(cont2im);
        view::write_image(image, filepath);

    }

}
