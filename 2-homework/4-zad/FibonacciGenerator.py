from AbstractGenerator import AbstractGenerator


class FibonacciGenerator(AbstractGenerator):
    def __init__(self, n):
        self.n = n

    def generate(self):
        array = []
        for i in range(0, self.n):
            array.append(self.fib(i))
        return array

    def fib(self, n):
        if n == 0:
            return 0
        elif n == 1 or n == 2:
            return 1
        else:
            return self.fib(n - 1) + self.fib(n - 2)
