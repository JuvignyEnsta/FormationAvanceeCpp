/**
 * @file binary_manipulation.cpp
 * @author Xavier Juvigny (xavier.juvigny@onera.fr)
 * @brief Completer le programme afin de créer les deux masques d'images suivant :
 * 
 *                    0101010101010101
 *                    1010101010101010
 * et le masque 
 *                    0000000110000000
 *                    0000111111110000
 *                    0011111111111100
 *                    0111111111111110
 *                    1111111111111111
 *                    1111111111111111
 *                    0111111111111110
 *                    0011111111111100
 *                    0000111111110000
 *                    0000000110000000
 *
 * @version 0.1
 * @date 2022-06-14 
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cassert>
#include <array>
#include <vector>
#include <iostream>
#include "lodepng/lodepng.h"

const std::string filename1("data/bart.png");
const std::string filename2("data/lise.png");

const std::array masque1   { std::uint16_t{}, 
                             std::uint16_t{} };

const std::array masque2   { std::uint16_t{}, 
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{},
                             std::uint16_t{} };

template<size_t nrows>
std::vector<unsigned char> mixerImages( std::array<unsigned,2> const& t_format, std::vector<unsigned char> const& t_image1,
                                        std::vector<unsigned char> const& t_image2, std::array<std::uint16_t,nrows> const& mask )
{
    assert(t_image1.size() == t_image2.size());
    unsigned width = t_format[0], height = t_format[1];
    assert(width % 16 == 0);
    std::vector<unsigned char> image_mixee(width*height);
    for ( unsigned iy = 0; iy < height; ++iy)
    {
        for ( unsigned ix = 0; ix < width; ix += 16 )
        {
            unsigned begPixel = ix + width*iy;
            for ( int ibits = 0; ibits < 16; ++ibits )
            {
                image_mixee[begPixel+ibits] =  mask[iy % nrows] & (1<<ibits) ? t_image1[4*(begPixel+ibits)] : t_image2[4*(begPixel+ibits)];
            }
        }
    }
    return image_mixee;
}

int main()
{
    unsigned error;
    unsigned width1, height1;
    std::vector<unsigned char> image1;
    unsigned width2, height2;
    std::vector<unsigned char> image2;

    error = lodepng::decode(image1, width1, height1, filename1);
    std::cerr << "Nombre de pixels : " << width1*height1 << std::endl;
    std::cerr << "Size image1 : " << image1.size()  << std::endl;  
    error = lodepng::decode(image2, width2, height2, filename2);

    std::vector imageMixee1 = mixerImages( {width1,height1}, image1, image2, masque1);
    std::vector imageMixee2 = mixerImages( {width1,height1}, image1, image2, masque2);

    // we're going to encode with a state rather than a convenient function, because enforcing a color type requires setting options
    lodepng::State state;
    // input color type
    state.info_raw.colortype = LCT_GREY;
    state.info_raw.bitdepth = 8;
    // output color type
    state.info_png.color.colortype = LCT_GREY;
    state.info_png.color.bitdepth = 8;
    state.encoder.auto_convert = 0; // without this, it would ignore the output color type specified above and choose an optimal one instead

    std::vector<unsigned char> buffer; std::fill(buffer.begin(), buffer.end(), 0);
    error = lodepng::encode(buffer, imageMixee1.data(), width1, height1, state);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
    else lodepng::save_file(buffer, "ImageMixee1.png");

    buffer.clear();
    error = lodepng::encode(buffer, imageMixee2.data(), width1, height1, state);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
    else lodepng::save_file(buffer, "ImageMixee2.png");


    return EXIT_SUCCESS;
}