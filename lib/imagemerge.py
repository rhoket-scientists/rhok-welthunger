# -*- coding: utf-8 -*-
import sys

import cv

import profile

def load_images(images):
	return [cv.LoadImage(img, 0) for img in images]


def merge_images(img0, img1, img2):
	""" takes images in bgr order """
	images = profile.evaluate(lambda: load_images([img0, img1, img2]), "Image loading")
	for i in images:
		assert i.depth == cv.IPL_DEPTH_8U
	images = profile.evaluate(lambda: resize(images), "Image resizing")
	mergedImage = cv.CreateImage(min_size(images), cv.IPL_DEPTH_8U, 3)
	profile.evaluate(lambda: cv.Merge(images[0], images[1], images[2], None,
		mergedImage), "Image merging")

	return mergedImage


def resize(images):
	minSize = min_size(images)
	resized = []
	for img in images:
		dst = cv.CreateImage(minSize, img.depth, 0)
		cv.Resize(img, dst)
		resized.append(dst)
	return resized


def min_size(images):
	return min(*[cv.GetSize(img) for img in images])


def merge_to_file(img0, img1, img2, filePath):
	""" Takes images in rgb order """
	img = merge_images(img2, img1, img0)
	profile.evaluate(lambda: cv.SaveImage(filePath, img), "Image saving")


if __name__ == '__main__':
	merge_images(*sys.argv[1:])
