from abc import ABC, abstractmethod


class AbstractPercentile(ABC):
    @abstractmethod
    def percentile(self, array, p):
        pass