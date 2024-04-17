# koristimo ga kada dinamicki moramo mijenjati ponasanje neke komponente (konteksta)
# ->ponasanje se mijenja odabirom postupka
# obrazac je koristan kada imamo vise nezavisnih postupaka
from FibonacciGenerator import FibonacciGenerator
from DistributionTester import DistributionTester
from LinearInterpolationPercentile import LinearInterpolationPercentile
from NearestRankPercentile import NearestRankPercentile
from RandomNormalDistributionGenerator import RandomNormalDistributionGenerator
from RegularGenerator import RegularGenerator

if __name__ == '__main__':
    gen = RegularGenerator(0, 100, 10)
    #gen = FibonacciGenerator(20)
    #gen = RandomNormalDistributionGenerator(10, 0, 2.5)
    #per = NearestRankPercentile()
    per = LinearInterpolationPercentile()
    distributionTester = DistributionTester(gen, per)
    distributionTester.test()
