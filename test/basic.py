#!/usr/bin/env python
# -*- coding: utf-8 -*-

import unittest
from oktest import test, ok, NG

class SampleTest(unittest.TestCase):

   @test("1 + 1 should be 2")
   def _(self):
      ok (1+1) == 2          # same as assertEqual(2, 1+1)

if __name__ == '__main__':
    unittest.main()