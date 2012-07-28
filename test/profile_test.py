# -*- coding: utf-8 -*-

import unittest
from oktest import ok, test
import oktest

from lib import profile

class Profiletest(unittest.TestCase):

	@test("should execute a function, and return its value")
	def _(self):
		ok ( profile.evaluate(lambda: 1, '  ') ) == 1


if __name__ == '__main__':
	oktest.main()
