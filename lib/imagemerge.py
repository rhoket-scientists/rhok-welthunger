# -*- coding: utf-8 -*-

import cv
import sys
import logging
import time

def load_images(images):
	return [cv.LoadImage(img, 0) for img in images]


def merge_images(img0, img1, img2):
	logger = logging.getLogger('vegetation')

	t0 = time.clock()
	images = load_images([img0, img1, img2])
	logger.info("Image loading took " + str(time.clock() - t0))
	for i in images:
		assert i.depth == cv.IPL_DEPTH_8U

	t1 = time.clock()
	images = resize(images)
	logger.info("Image resizing took " + str(time.clock() - t1))

	mergedImage = cv.CreateImage(min_size(images), cv.IPL_DEPTH_8U, 3)
	t2 = time.clock()
	cv.Merge(images[0], images[1], images[2], None, mergedImage)
	logger.info("Image merging took " + str(time.clock() - t2))

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
	img = merge_images(img0, img1, img2)
	t0 = time.clock()
	cv.SaveImage(filePath, img)
	logging.getLogger('vegetation').info("Saving merged image took " +
			str(time.clock() - t0))

if __name__ == '__main__':
	merge_images(*sys.argv[1:])
