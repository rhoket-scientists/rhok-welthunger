import logging
import time

def evaluate(func, msg):
	t = time.clock()
	val = func()
	l = logging.getLogger('vegetation')
	l.debug(msg + " took " + str(time.clock() - t))
	return val
