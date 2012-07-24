# -*- coding: utf-8 -*-

import cv
import unittest
from oktest import test, ok, NG
from lib import imagemerge

class ImageMergeTest(unittest.TestCase):

	def provide_images(self):
		return ['test/fixtures/img3x4.tiff',\
				'test/fixtures/img1x1.tiff',\
				'test/fixtures/img3x4.tiff']

	def provide_loadedImages(self):
		return [cv.LoadImage(img) for img in self.provide_images()]


	def provide_matrices(self):
		return [cv.CreateMat(2,2, cv.CV_8UC1)]


	@test("should load 3 cv images")
	def _(self, images):
		ok (len(imagemerge.load_images(images))) == 3


if __name__ == '__main__':
	unittest.main()
