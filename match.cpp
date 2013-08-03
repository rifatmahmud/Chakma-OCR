
#include "match.h"
#include <cv.h>
#include<highgui.h>
#include <iostream>
#include <vector>
#include <fstream>


namespace cmp
{

    void creat_char_list(std::vector<std::vector<char> > &out_letters)
    {
        int size1, size2, i, vct_cntr=0;
        std::vector<std::vector<char> > letters;
        std::ifstream filereader1("chak_letter_list_simple", std::ios::in | std::ios::binary);
        std::ifstream filereader2("chak_letter_list_compound", std::ios::in | std::ios::binary);
        filereader1.seekg(0, std::ios::end);
        filereader2.seekg(0, std::ios::end);
        size1=filereader1.tellg();
        size2=filereader2.tellg();
        filereader1.seekg(0, std::ios::beg);
        filereader2.seekg(0, std::ios::beg);
        char buffer1[size1], buffer2[size2];
        filereader1.read(buffer1, size1);
        filereader1.close();
        std::cout<<sizeof(buffer1)<<std::endl;
        filereader2.read(buffer2, size2);
        filereader2.close();
        for(i=0;  i<size1-5; i=i+4)
        {
            letters.push_back(std::vector<char> ());
            for(int j=i, k=0; j<i+4 && k<4; j++, k++)
            {
                letters[vct_cntr].push_back(buffer1[j]);

            }


            vct_cntr++;

        }

        for(i=0;  i<size2-9; i=i+8)
        {
            letters.push_back(std::vector<char> ());
            for(int j=i, k=0; j<i+8 && k<8; j++, k++)
            {
                letters[vct_cntr].push_back(buffer2[j]);

            }
            vct_cntr++;
        }


        for(i=0; i<letters.size(); i++)
        {
            out_letters.push_back(std::vector<char> ());
            for(int j=0; j<letters[i].size(); j++)
            {
                out_letters[i].push_back(letters[i][j]);
            }
        }
    }

    void mtch_cnt(cv::vector<cv::vector<cv::Point> > input, cv::vector<cv::vector<cv::Point> > rosetta, std::vector<std::vector<char> > letters)
    {
        std::cout<<"Now Here"<<std::endl;
        std::ofstream filewriter("output", std::ios::app | std::ios::binary);
        char temp[1];
        double min=63000, val;
        int matched_ind, flag=0;
        for(int i=0; i<input.size(); i++)
        {
             flag=0;
             min=63000;
            for(int j=0; j<rosetta.size(); j++)
            {

                val=cv::matchShapes(input[i], rosetta[j], CV_CONTOURS_MATCH_I1, 0);
                std::cout<<val<<std::endl;
                if(val<min)
                {
                    min=val;
                    matched_ind=j;
                    flag=1;
                }

            }
            if(flag==1)
            {
                for(int k=0; k<letters[matched_ind].size(); k++)
                {
                    temp[0]=letters[matched_ind][k];
                    filewriter.write(temp, sizeof(temp));
                }
            }
        }


        filewriter.close();


   }

}
