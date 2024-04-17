import numpy

from AbstractPercentile import AbstractPercentile


class LinearInterpolationPercentile(AbstractPercentile):
    def percentile(self, array, p):
        array.sort()
        n = len(array)
        return numpy.percentile(array, p, method='linear')
