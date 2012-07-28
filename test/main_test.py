# -*- coding: utf-8 -*-
import os

import unittest
from oktest import ok, test

from imagetest import Imagetest

class ImageMergeTest(Imagetest):

	@test("should run with 3 image files as arguments")
	def _(self, images):
		print os.system("python main.py -c -i "+ reduce(lambda x, y: x+' '+y, images))

if __name__ == '__main__':
	oktest.main()
