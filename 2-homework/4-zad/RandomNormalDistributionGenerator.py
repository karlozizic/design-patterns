from AbstractGenerator import AbstractGenerator
import numpy as np


class RandomNormalDistributionGenerator(AbstractGenerator):
    def __init__(self, n, mean, stdDev):
        self.n = n
        self.mean = mean
        self.stdDev = stdDev

    def generate(self):
        floatArr = np.random.normal(self.mean, self.stdDev, self.n)
        return [int(x) for x in floatArr]
