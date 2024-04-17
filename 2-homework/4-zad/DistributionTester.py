
# predstavlja Context
class DistributionTester:
    def __init__(self, abstractRegularGenerator, percentileAbstract):
        self.abstractRegularGenerator = abstractRegularGenerator
        self.percentileAbstract = percentileAbstract

    def test(self):
        array = self.abstractRegularGenerator.generate()
        print("Generated array: ", array)
        for i in range(10, 100, 10):
            print(f"{i} percentile is", self.percentileAbstract.percentile(array, i))
