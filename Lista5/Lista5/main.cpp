#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>



int main()
{
    Image image;

    image.load("obrazek.ppm");
    image.add_watermark();
    image.save_as("watermark.ppm");


    image.load("obrazek.ppm");
    image.blurr();
    image.save_as("blurr.ppm");

    for(int i = 0; i < 10; i++)
    {
        image.load("blurr.ppm");
        image.blurr();
        image.save_as("blurr.ppm");
    }

    image.load("obrazek.ppm");
    image.extract_layer(ColorLayer::Red);
    image.save_as("red-layer.ppm");

    image.load("tree.ppm");
    image.filter();
    image.save_as("filter.ppm");

    image.load("obrazek.ppm");
    image.flip_horizontally();
    image.save_as("flip-horizontally.ppm");

    image.load("obrazek.ppm");
    image.flip_vertically();
    image.save_as("flip-vertically.ppm");

    image.load("obrazek.ppm");
    image.inflate();
    image.save_as("inflate.ppm");

    image.load("obrazek.ppm");
    image.negative();
    image.save_as("negatyw.ppm");

    image.load("obrazek.ppm");
    image.rotate_clockwise_90();
    image.save_as("rotate-clockwise-90.ppm");

    image.load("obrazek.ppm");
    image.sepia();
    image.save_as("sepia.ppm");

    image.load("obrazek.ppm");
    image.shrink();
    image.save_as("shrink.ppm");

    image.load("obrazek.ppm");
    image.to_grayscale();
    image.save_as("grayscale.ppm");

    std::cout << image.width() << "\n";
    std::cout << image.height() << "\n";

    return 0;
}
