# -*- coding: utf-8 -*-

import cv
import sys

def load_images(images):
	return [cv.LoadImage(img, 0) for img in images]


def merge_images(img0, img1, img2):
	images = load_images([img0, img1, img2])
	for i in images:
		assert i.depth == cv.IPL_DEPTH_8U
	images = resize(images)
	mergedImage = cv.CreateImage(min_size(images), cv.IPL_DEPTH_8U, 3)
	cv.Merge(images[0], images[1], images[2], None, mergedImage)
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

if __name__ == '__main__':
	merge_images(*sys.argv[1:])
