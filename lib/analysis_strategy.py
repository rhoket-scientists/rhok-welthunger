# -*- coding: utf-8 -*-
import cv
from lib import profile, imagemerge

def count_dry_grass(img):
	""" Feed me with band 3 """
	return profile.evaluate(lambda: count(img, 102, 74), "Counting")


def count_lawn_grass(img):
	""" Feed me with band 4 """
	return profile.evaluate(lambda: count(img,185, 175), "Counting")


def count(img, upper_thresh, lower_thresh):
	img = cv.LoadImage(img, 0)
	assert img.depth == cv.IPL_DEPTH_8U

	cv.Threshold(img, img, upper_thresh, 0, cv.CV_THRESH_TOZERO_INV)
	cv.Threshold(img, img, lower_thresh, 0, cv.CV_THRESH_TOZERO)

	return cv.CountNonZero(img)


def ndvi_to_file(band3_img, band4_img, out_img):
	band3 = cv.LoadImage(band3_img, 0)
	band4 = cv.LoadImage(band4_img, 0)
	for i in [band3, band4]:
		assert i.depth == cv.IPL_DEPTH_8U
	cv.SaveImage(out_img, ndvi(band3, band4))


def ndvi(band3, band4):
	def crunch():
		size = cv.GetSize(band3)
		ndvi_img = cv.CreateImage(size, cv.IPL_DEPTH_32F, 1)
		numerator = cv.CreateImage(size, cv.IPL_DEPTH_32F, 1)
		denominator = cv.CreateImage(size, cv.IPL_DEPTH_32F, 1)
		cv.Sub(band4, band3, numerator)
		cv.Add(band4, band3, denominator)
		cv.Div(numerator, denominator, ndvi_img)

		# (NDVI + 1)
		cv.AddS(ndvi_img, 1, ndvi_img)
		return ndvi_img

	def convert(ndvi_img):
		img8 = cv.CreateImage(cv.GetSize(ndvi_img), cv.IPL_DEPTH_8U, 1)
		cv.ConvertScale(ndvi_img, img8, 100)
		return img8

	img = profile.evaluate(crunch, "NDVI crunching")
	return profile.evaluate(lambda: convert(img), "NDVI converting")
