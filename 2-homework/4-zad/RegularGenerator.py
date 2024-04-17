from AbstractGenerator import AbstractGenerator


class RegularGenerator(AbstractGenerator):

    def __init__(self, lowerBound, upperBound, step):
        self.lowerBound = lowerBound
        self.upperBound = upperBound
        self.step = step

    def generate(self):
        array = []
        val = self.lowerBound
        while val <= self.upperBound:
            array.append(val)
            val += self.step
        return array
