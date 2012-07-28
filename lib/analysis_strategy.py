# -*- coding: utf-8 -*-
import cv

def count_grass(img):
	""" Feed me with band 3 """
	img = cv.LoadImage(img, 0)
	assert img.depth == cv.IPL_DEPTH_8U

	cv.Threshold(img, img, 102, 0, cv.CV_THRESH_TOZERO_INV)
	cv.Threshold(img, img, 75-1, 0, cv.CV_THRESH_TOZERO)

	return cv.CountNonZero(img)
