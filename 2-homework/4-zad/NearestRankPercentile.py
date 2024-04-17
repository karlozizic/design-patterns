import math

from AbstractPercentile import AbstractPercentile


class NearestRankPercentile(AbstractPercentile):

    def percentile(self, array, p):
        array.sort()
        n = math.ceil(p / 100 * len(array))
        return array[n - 1]
