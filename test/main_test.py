# -*- coding: utf-8 -*-
import os

import oktest
from oktest import test, ok, NG

from imagetest import Imagetest

class ApplicationTest(Imagetest):

	def provide_silence(self):
		 return "&>/dev/null"


	def provide_image_string(self):
		return reduce(lambda x, y: x+' '+y,
				super(ApplicationTest, self).provide_images())


	@test("should run with 3 image files as arguments to merge")
	def _(self, image_string, silence):
		ok (os.system("python main.py -c -mi "+ image_string)) == 0


	@test("should fail with 2 image files as arguments to merge")
	def _(self, images, silence):
		NG (os.system("python main.py -c -mi "+
			images[0]+images[1] + silence)) == 0


	@test("should run with 1 images as argument to detect lawn or dry grass")
	def _(self, silence, images):
		ok (os.system("python main.py -c -lg "+ images[0])) == 0
		ok (os.system("python main.py -c -dg "+ images[0])) == 0


	@test("should fail with 1 images as argument to detect lawn or dry grass")
	def _(self, silence, image_string):
		NG (os.system("python main.py -c -lg "+ image_string + silence)) == 0
		NG (os.system("python main.py -c -dg "+ image_string + silence)) == 0


if __name__ == '__main__':
	oktest.main()
