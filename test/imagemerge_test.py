# -*- coding: utf-8 -*-

import os

from oktest import test, ok
import cv

from lib import imagemerge
from test.imagetest import Imagetest

class ImageMergeTest(Imagetest):

	def provide_loadedImages(self):
		return [cv.LoadImage(img, 0) for img in self.provide_images()]


	def provide_filePath(self):
		return 'test/fixtures/mergedImage.tiff'


	def release_filePath(self, filePath):
		os.system('rm ' + filePath)


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


	@test("should merge three one channel to one three channel image")
	def _(self, loadedImages, images):
		for img in loadedImages:
			if not img == None:
				ok (img.nChannels) == 1
		ok (imagemerge.merge_images(*images).nChannels) == 3


	@test('should merge into minimum horizontal size')
	def _(self, images):
		ok (cv.GetSize(imagemerge.merge_images(*images))) == (1,1)


	@test('should merge 3 images into one file on disk')
	def _(self, images, filePath):
		imagemerge.merge_to_file(images[0], images[1], images[2], filePath)
		ok (open(filePath)).is_a(file)


if __name__ == '__main__':
	oktest.main()
