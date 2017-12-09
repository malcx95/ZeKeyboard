#!/usr/bin/python3

"""
Python script for generating some of the code for 
the characters for the keyboard.
"""

import argparse
import numpy
from scipy import ndimage
import matplotlib.pyplot as plt
import math

SKELETON = \
        """
#ifndef FONT_H
#define FONT_H

{}

#endif // FONT_H
"""

LOWER_LETTERS = "abcdefghijklmnopqrstuvwxyz"
UPPER_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
SYMBOLS = "0123456789.:,;(*!?')"


def split_characters(image, characters):
    length = len(characters)
    _, width, _ = image.shape

    character_width = width/length

    result = []
    for i in range(length):
        c = characters[i]
        lower_bound = round(i*character_width)
        upper_bound = round(i*character_width + character_width + 3)
        result.append((c, image[:, lower_bound:upper_bound]))

    plt.imshow(result[25][1])
    plt.show()


def main():
    argparser = argparse.ArgumentParser(
        description="Generate the font C++ file")

    argparser.add_argument("--lower", 
                           help="The image of the lower case characters",
                           type=str, required=True)

    argparser.add_argument("--upper", 
                           help="The image of the upper case characters",
                           type=str, required=True)

    argparser.add_argument("--symbols", 
                           help="The image of the symbols",
                           type=str, required=True)

    args = argparser.parse_args()
    
    lower_image = ndimage.imread(args.lower)
    upper_image = ndimage.imread(args.upper)
    symbols_image = ndimage.imread(args.symbols)

    lower_split = split_characters(lower_image, LOWER_LETTERS)
    # upper_split = split_characters(upper_image, UPPER_LETTERS)
    # symbols_split = split_characters(symbols_image, SYMBOLS)

    # plt.imshow(symbols_image)
    # plt.show()

if __name__ == '__main__':
    main()

