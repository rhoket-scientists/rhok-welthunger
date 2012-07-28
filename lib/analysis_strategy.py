# -*- coding: utf-8 -*-
import cv
from lib import profile

def count_dry_grass(img):
	""" Feed me with band 3 """
	return profile.evaluate(lambda: count(img, 102, 74), "Counting")


def count_lawn_grass(img):
	""" Feed me with band 4 """
	return profile.evaluate(lambda: count(img,1085, 175), "Counting")


def count(img, upper_thresh, lower_thresh):
	img = cv.LoadImage(img, 0)
	assert img.depth == cv.IPL_DEPTH_8U

	cv.Threshold(img, img, upper_thresh, 0, cv.CV_THRESH_TOZERO_INV)
	cv.Threshold(img, img, lower_thresh, 0, cv.CV_THRESH_TOZERO)

	return cv.CountNonZero(img)
