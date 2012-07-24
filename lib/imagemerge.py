# -*- coding: utf-8 -*-

import cv
import sys

def load_images(images):
	return [cv.LoadImage(img, 0) for img in images]


if __name__ == '__main__':
	load_images(sys.argv[1:])
