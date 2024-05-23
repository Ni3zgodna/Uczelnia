#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::save_as(const std::string& filename)
{

    std::ofstream out(filename, std::ios::binary);

    out << magic << "\n";
    out << my_width << " " << my_height << "\n" << color_depth << "\n";

    for (auto& line : pixels)
    {
        out.write(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
    }
}

void Image::add_watermark()
{
    RGB czarny;

    czarny.blue = 0;
    czarny.green = 0;
    czarny.red = 0;

    for(int i = 0; i < my_height && i < my_width; i++)
    {
            pixels[i][i] = czarny;
            pixels[my_width - i -1][i] = czarny;
    }
}

RGB srednia_elementow(const std::vector<RGB> &tablica)
{
    RGB wynik;
    int r = 0,g = 0,b = 0;

    for(int i = 0; i < tablica.size(); i++)
    {
     b += tablica[i].blue;
     g += tablica[i].green;
     r += tablica[i].red;
    }

    wynik.blue = b/tablica.size();
    wynik.green = g/tablica.size();
    wynik.red = r/tablica.size();

    return wynik;
}

void Image::blurr()
{
    for(int i = 0; i < my_height; i++)
    {
        std::vector<RGB> tablica;

        for(int j = 0; j < my_width; j++)
        {

            // rogi

            if(i == 0 && j == 0)
            {
                tablica = {pixels[i + 1][j], pixels[i][j + 1], pixels[i + 1][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(i == 0 && j == my_width - 1)
            {
                tablica = {pixels[i + 1][j], pixels[i][j - 1], pixels[i + 1][j - 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(i == my_height - 1 && j == 0)
            {
                tablica = {pixels[i - 1][j], pixels[i][j + 1], pixels[i - 1][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(i == my_height - 1 && j == my_width - 1)
            {
                tablica = {pixels[i - 1][j], pixels[i][j - 1], pixels[i - 1][j - 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }


            // narożniki

            else if(i == 0)
            {
                tablica = {pixels[i][j - 1], pixels[i + 1][j - 1],pixels[i + 1][j], pixels[i][j + 1], pixels[i + 1][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(j == 0)
            {
                tablica = {pixels[i - 1][j], pixels[i + 1][j], pixels[i - 1][j + 1], pixels[i][j + 1], pixels[i + 1][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(i == my_height - 1)
            {
                tablica = {pixels[i - 1][j - 1], pixels[i][j - 1], pixels[i - 1][j], pixels[i - 1][j + 1], pixels[i][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            else if(j == my_width - 1)
            {
                tablica = {pixels[i - 1][j - 1], pixels[i][j - 1], pixels[i + 1][j - 1], pixels[i - 1][j], pixels[i + 1][j]};
                pixels[i][j] = srednia_elementow(tablica);
            }

            // reszta

            else
            {
                tablica = {pixels[i - 1][j - 1], pixels[i][j - 1], pixels[i + 1][j - 1], pixels[i - 1][j], pixels[i + 1][j], pixels[i - 1][j + 1], pixels[i][j + 1], pixels[i + 1][j + 1]};
                pixels[i][j] = srednia_elementow(tablica);
            }
        }
     }
}


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

    // image.load("obrazek.ppm");
    // image.extract_layer(ColorLayer::Red);
    // image.save_as("red-layer.ppm");

    // image.load("tree.ppm");
    // image.filter();
    // image.save_as("filter.ppm");

    // image.load("obrazek.ppm");
    // image.flip_horizontally();
    // image.save_as("flip-horizontally.ppm");

    // image.load("obrazek.ppm");
    // image.flip_vertically();
    // image.save_as("flip-vertically.ppm");

    // image.load("obrazek.ppm");
    // image.inflate();
    // image.save_as("inflate.ppm");

    // image.load("obrazek.ppm");
    // image.negative();
    // image.save_as("negatyw.ppm");

    // image.load("obrazek.ppm");
    // image.rotate_clockwise_90();
    // image.save_as("rotate-clockwise-90.ppm");

    // image.load("obrazek.ppm");
    // image.sepia();
    // image.save_as("sepia.ppm");

    // image.load("obrazek.ppm");
    // image.shrink();
    // image.save_as("shrink.ppm");

    // image.load("obrazek.ppm");
    // image.to_grayscale();
    // image.save_as("grayscale.ppm");

    // std::cout << image.width() << "\n";
    // std::cout << image.height() << "\n";

    return 0;
}
