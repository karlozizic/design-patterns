from abc import ABC, abstractmethod
## slijedno u ovisnosti o granicama
## u pythonu se koristi abc za ABC - Abstract Base Class i @abstractmethod
class AbstractGenerator(ABC):
    @abstractmethod
    def generate(self):
        pass