# -*- coding: utf-8 -*-

import cv
from oktest import ok, test

from test.imagetest import Imagetest
from lib import analysis_strategy

class ImageMergeTest(Imagetest):

	def provide_image(self):
		return 'test/fixtures/img4x4-1.tiff'


	def provide_image_2(self):
		return 'test/fixtures/img4x4-2.tiff'


	def provide_grassy(self):
		return self.provide_image()


	def provide_non_grassy(self):
		return self.provide_image_2()


	@test('should count grassy pixels')
	def _(self, grassy):
		ok (analysis_strategy.count_dry_grass(grassy)) == 4


	@test('should not count nongrassy pixels')
	def _(self, non_grassy):
		ok (analysis_strategy.count_dry_grass(non_grassy)) == 0


	@test("should compute NDVI as (Band4 - Band3) / (Band4 + Band3) and scale it to (ndvi+1)*100")
	def _(self, image, image_2):
		band3 = cv.LoadImage(image, 0)
		band4 = cv.LoadImage(image_2, 0)
		band4_px = band4[0, 0]
		band3_px = band3[0,0]
		ok(band3_px) == 75.0
		ok(band4_px) == 103.0

		ndvi_px = analysis_strategy.ndvi(image, image_2)[0,0]
		ndvi = (band4_px-band3_px)/(band4_px+band3_px)
		# compare with delta to respect rounding errors
		ok( round((ndvi + 1)*100) ).in_delta(int(ndvi_px), 2)


	@test("should produce histogram as a python list")
	def _(self, image):
		n_buckets = 4
		h = analysis_strategy.histogram(image, n_buckets)
		ok (h[0]) == 6
