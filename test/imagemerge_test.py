# -*- coding: utf-8 -*-

import cv
import unittest
from oktest import test, ok, NG, skip
from lib import imagemerge

class ImageMergeTest(unittest.TestCase):

	def provide_images(self):
		return ['test/fixtures/img3x4.tiff',\
				'test/fixtures/img1x1.tiff',\
				'test/fixtures/img3x4.tiff']

	def provide_loadedImages(self):
		return [cv.LoadImage(img, 0) for img in self.provide_images()]


	@test("should load 3 cv images")
	def _(self, images):
		ok (len(imagemerge.load_images(images))) == 3


	@test('should compute the minimum size of n images')
	def _(self, loadedImages):
		ok (imagemerge.min_size(loadedImages)) == (1,1)
		ok (imagemerge.min_size(loadedImages)[0]) == 1


	@test("should resize images to the smallest")
	def _(self, loadedImages):
		images = imagemerge.resize(loadedImages)
		ok (len(images)) == len(loadedImages)
		for img in images:
			ok (cv.GetSize(img)) == (1, 1)


	@test("should merge to 3 channel image")
	def _(self, loadedImages, images):
		for img in loadedImages:
			if not img == None:
				ok (img.nChannels) == 1
		ok (imagemerge.merge_images(images).nChannels) == 3


	@test('should merge into minimum x size')
	def _(self, images):
		ok (cv.GetSize(imagemerge.merge_images(images))) == (1,1)

if __name__ == '__main__':
	unittest.main()
