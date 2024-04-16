#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


vector<unsigned char> extract(unsigned char input[], int width, int height, int startx, int starty, int endx, int endy)
{
    vector<unsigned char> filter;
    for(int i = starty; i <= endy; i++)
    {
        for(int j = startx; j <= endx; j++)
        {
            int idx = i * width + j;
            filter.push_back(input[idx]);
        }
    }
    std::sort(filter.begin(), filter.end());
    return filter;
}

void medianFilter(unsigned char input[], int width, int height, int k, unsigned char output[])
{
    int halfk = floor(k*0.5f);
    for(int i = 0; i < height; i++) {
        int startx = i-halfk, endx = i+halfk;

        if(i < halfk)
        {
            startx = i;
        }
        else if(i > width - halfk)
        {
            endx = width-1;
        }
        for(int j = 0; j < width; j++)
        {
            int starty = j-halfk, endy = i+halfk;
            if(j < halfk)
            {
                starty = j;
            }
            else
            {
                endy = height-1;
            }
            vector<unsigned char> list = extract(input, width, height, startx, starty, endx, endy);
            unsigned char midValue = 0;
            int mid = list.size() * 0.5f;
            if(list.size() % 2 == 1)
            {
                midValue = list[mid];
            }
            else 
            {
                midValue = (list[mid] + list[mid+1])*0.5;
            }

            int idx = i*width + j;
            output[idx] = midValue;
        }
    }
}


void print(unsigned char arr[], int width, int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int idx = i*width + j;
            cout<<int(arr[idx])<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char** argv)
{
    std::cout<<"MedianFilter"<<std::endl;
    unsigned char input[12] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };
    cout<<"input: "<<endl;
    print(input, 4, 3);

    unsigned char output[12] = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };
    medianFilter(input, 4, 3, 3, output);
    cout<<"output: "<<endl;
    print(output, 4, 3);

    return 0;
}