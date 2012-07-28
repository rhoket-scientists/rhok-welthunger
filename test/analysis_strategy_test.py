# -*- coding: utf-8 -*-

from oktest import ok, test

from imagetest import Imagetest
from lib import analysis_strategy

class ImageMergeTest(Imagetest):

	def provide_grassy(self):
		# greyscale images that contain oil palmy pixels
		return 'test/fixtures/grassy.tiff'


	def provide_non_grassy(self):
		return 'test/fixtures/non_grassy.tiff'


	@test('should count grassy pixels')
	def _(self, grassy):
		ok (analysis_strategy.count_grass(grassy)) == 4

	@test('should not count nongrassy pixels')
	def _(self, non_grassy):
		ok (analysis_strategy.count_grass(non_grassy)) == 0
