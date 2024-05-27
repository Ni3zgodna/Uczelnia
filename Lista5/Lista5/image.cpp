#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

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

void Image::extract_layer(ColorLayer color_layer)
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            if(color_layer == ColorLayer::Red)
            {
                pixels[i][j].green = 0;
                pixels[i][j].blue = 0;
            }
            if(color_layer == ColorLayer::Green)
            {
                pixels[i][j].red = 0;
                pixels[i][j].blue = 0;
            }
            if(color_layer == ColorLayer::Blue)
            {
                pixels[i][j].red = 0;
                pixels[i][j].green = 0;
            }
        }
     }
}

void Image::filter()
{

    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            int r = std::abs(pixels[i][j].red - pixels[i + 1][j + 1].red);
            int g = std::abs(pixels[i][j].green - pixels[i + 1][j + 1].green);
            int b = std::abs(pixels[i][j].blue - pixels[i + 1][j + 1].blue);

             pixels[i][j] = {static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b)};
        }
    }
}

void Image::flip_horizontally()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width / 2; j++)
        {
            RGB pixele_pomocnicza = pixels[i][j];
            pixels[i][j] = pixels[i][my_width - j - 1];
            pixels[i][my_width - j - 1] = pixele_pomocnicza;
        }
    }
}

void Image::flip_vertically()
{
    for (int i = 0; i < my_height / 2; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB pixele_pomocnicza = pixels[i][j];
            pixels[i][j] = pixels[my_height - i - 1][j];
            pixels[my_height - i - 1][j] = pixele_pomocnicza;
        }
    }
}

void Image::inflate()
{
    int new_width = my_width * 2;
    int new_height = my_height * 2;

    std::vector<std::vector<RGB>> new_pixels(new_height, std::vector<RGB>(new_width));
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            new_pixels[i * 2][j * 2] = pixels[i][j];
            new_pixels[i * 2][j * 2 + 1] = pixels[i][j];
            new_pixels[i * 2 + 1][j * 2] = pixels[i][j];
            new_pixels[i * 2 + 1][j * 2 + 1] = pixels[i][j];
        }
    }

    pixels = new_pixels;

    my_width = new_width;
    my_height = new_height;
}

void Image::negative()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            int r = 255 - pixels[i][j].red;
            int g = 255 - pixels[i][j].green;
            int b = 255 - pixels[i][j].blue;

            pixels[i][j] = {static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b)};
        }
    }
}

void Image::rotate_clockwise_90()
{
    std::vector<std::vector<RGB>> new_pixels(my_width, std::vector<RGB>(my_height));

    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            int k = j;
            int l = my_height - 1 - i;
            new_pixels[k][l] = pixels[i][j];
        }
    }

    int pomocnicza = my_width;
    my_width = my_height;
    my_height = pomocnicza;

    pixels = new_pixels;
}

void Image::sepia()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            unsigned char grey = static_cast<unsigned char>(std::round((pixels[i][j].red + pixels[i][j].green + pixels[i][j].blue))/3);
            pixels[i][j] = {static_cast<unsigned char>(std::round((grey + 162)/2)), static_cast<unsigned char>(std::round(((grey + 128)/2)), static_cast<unsigned char>(std::round((grey + 101)/2))) };
        }
    }
}

void Image::shrink()
{
    int new_width = my_width / 2;
    int new_height = my_height / 2;

    std::vector<std::vector<RGB>> new_pixels(new_height, std::vector<RGB>(new_width));

    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            int r = 0, g = 0, b = 0;

            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    r += pixels[i * 2 + k][j * 2 + l].red;
                    g += pixels[i * 2 + k][j * 2 + l].green;
                    b += pixels[i * 2 + k][j * 2 + l].blue;
                }
            }

            new_pixels[i][j] = {static_cast<unsigned char>(r / 4), static_cast<unsigned char>(g / 4), static_cast<unsigned char>(b / 4)};
        }
    }
    pixels = new_pixels;

    my_width = new_width;
    my_height = new_height;
}

void Image::to_grayscale()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            unsigned char srednia = static_cast<unsigned char>(std::round((pixels[i][j].red + pixels[i][j].green + pixels[i][j].blue))/3);
            pixels[i][j] = {srednia, srednia, srednia};
        }
    }
}

int Image::width() const
{
    return my_width;
}

int Image::height() const
{
    return my_height;
}

