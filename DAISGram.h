#ifndef DAISGRAM_H
#define DAISGRAM_H

#include <iostream>
#include <string>

#include "dais_exc.h"
#include "tensor.h"
#include "libbmp.h"

using namespace std;

class DAISGram{

    private:

        Tensor data;

    public:

        DAISGram();

        ~DAISGram();

        /**
         * Load a bitmap from file
         *
         * @param filename String containing the path of the file
         */
        void load_image(string filename);


        /**
         * Save a DAISGram object to a bitmap file.
         * 
         * Data is clamped to 0,255 before saving it.
         *
         * @param filename String containing the path where to store the image.
         */
        void save_image(string filename);

        /**
         * Get rows
         *
         * @return returns the number of rows in the image
         */
        int getRows();

        /**
         * Get columns
         *
         * @return returns the number of columns in the image
         */
        int getCols();

        /**
         * Get depth
         *
         * @return returns the number of channels in the image
         */
        int getDepth();

        /**
         * Brighten the image
         * 
         * It sums the bright variable to all the values in the image.
         * 
         * Before returning the image, the corresponding tensor should be clamped in [0,255]
         * 
         * @param bright the amount of bright to add (if negative the image gets darker)
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram brighten(float bright);

        /**
         * Create a grayscale version of the object
         * 
         * A grayscale image is produced by substituting each pixel with its average on all the channel
         *  
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram grayscale();

        /**
         * Create a Warhol effect on the image
         * 
         * This function returns a composition of 4 different images in which the:
         * - top left is the original image
         * - top right is the original image in which the Red and Green channel are swapped
         * - bottom left is the original image in which the Blue and Green channel are swapped
         * - bottom right is the original image in which the Red and Blue channel are swapped
         *  
         * The output image is twice the dimensions of the original one.
         * 
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram warhol();

        /**
         * Sharpen the image
         * 
         * This function makes the image sharper by convolving it with a sharp filter
         * 
         * filter[3][3]
         *    0  -1  0
         *    -1  5 -1
         *    0  -1  0
         *  
         * Before returning the image, the corresponding tensor should be clamped in [0,255]
         * 
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram sharpen();

        /**
         * Emboss the image
         * 
         * This function makes the image embossed (a light 3D effect) by convolving it with an
         * embossing filter
         * 
         * filter[3][3]
         *    -2 -1  0
         *    -1  1  1
         *     0  1  2
         * 
         * Before returning the image, the corresponding tensor should be clamped in [0,255]
         *  
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram emboss();

        /**
         * Smooth the image
         * 
         * This function remove the noise in an image using convolution and an average filter
         * of size h*h:
         * 
         * c = 1/(h*h)
         * 
         * filter[3][3]
         *    c c c
         *    c c c
         *    c c c
         *  
         * @param h the size of the filter
         * @return returns a new DAISGram containing the modified object
         */
        DAISGram smooth(int h=3);

        /**
         * Edges of an image
         * 
         * This function extract the edges of an image by using the convolution 
         * operator and the following filter
         * 
         * 
         * filter[3][3]
         * -1  -1  -1
         * -1   8  -1
         * -1  -1  -1
         * 
         * Remeber to convert the image to grayscale before running the convolution.
         * 
         * Before returning the image, the corresponding tensor should be clamped in [0,255]
         *  
         * @return returns a new DAISGram containing the modified object
         */  
        DAISGram edge();

        /**
         * Blend with anoter image
         * 
         * This function generate a new DAISGram which is the composition 
         * of the object and another DAISGram object
         * 
         * The composition follows this convex combination:
         * results = alpha*this + (1-alpha)*rhs 
         * 
         * rhs and this obejct MUST have the same dimensions.
         * 
         * @param rhs The second image involved in the blending
         * @param alpha The parameter of the convex combination  
         * @return returns a new DAISGram containing the blending of the two images.
         */  
        DAISGram blend(const DAISGram & rhs, float alpha=0.5);

        /**
         * Green Screen
         * 
         * This function substitutes a pixel with the corresponding one in a background image 
         * if its colors are in the surrounding (+- threshold) of a given color (rgb).
         * 
         * (rgb - threshold) <= pixel <= (rgb + threshold)
         * 
         * 
         * @param bkg The second image used as background
         * @param rgb[] The color to substitute (rgb[0] = RED, rgb[1]=GREEN, rgb[2]=BLUE) 
         * @param threshold[] The threshold to add/remove for each color (threshold[0] = RED, threshold[1]=GREEN, threshold[2]=BLUE) 
         * @return returns a new DAISGram containing the result.
         */  
        DAISGram greenscreen(DAISGram & bkg, int rgb[], float threshold[]);

        /**
         * Equalize
         * 
         * Stretch the distribution of colors of the image in order to use the full range of intesities.
         * 
         * See https://it.wikipedia.org/wiki/Equalizzazione_dell%27istogramma
         * 
         * @return returns a new DAISGram containing the equalized image.
         */  
        DAISGram equalize();


        /**
         * Generate Random Image
         * 
         * Generate a random image from nois
         * 
         * @param h height of the image
         * @param w width of the image
         * @param d number of channels
         * @return returns a new DAISGram containing the generated image.
         */  
        void generate_random(int h, int w, int d);
};

#endif
