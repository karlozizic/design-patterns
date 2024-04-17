import ast
import re


def eval_expression(exp, variables={}):
    def _eval(node):
        if isinstance(node, ast.Num):
            return node.n
        elif isinstance(node, ast.Name):
            return variables[node.id]
        elif isinstance(node, ast.BinOp):
            return _eval(node.left) + _eval(node.right)
        else:
            raise Exception('Unsupported type {}'.format(node))

    node = ast.parse(exp, mode='eval')
    return _eval(node.body)


class Cell:

    def __init__(self, row, column, sheet, expression=None, value=None):
        self.row = row
        self.column = column
        self.sheet = sheet
        self.expression = expression
        self.value = value
        self.observers = []

    def evaluate(self):
        variables = {}
        for cellMark in re.findall(r'[A-Z]+\d+', self.expression):
            num = int(self.sheet.getCell(cellMark).value)
            variables.update({cellMark: num})
        self.value = eval_expression(self.expression, variables)
        self.notifyObservers()

    def set_expression(self, expression):
        if expression.isdigit():
            self.expression = expression
            self.value = expression
            self.notifyObservers()
            return
        variables = {}
        for cellMark in re.findall(r'[A-Z]+\d+', expression):
            num = int(self.sheet.getCell(cellMark).value)
            variables.update({cellMark: num})
            if cellMark in self.observersCellMarks():
                raise RuntimeError("Circular dependency")
            self.sheet.getCell(cellMark).addObserver(self)
        value = eval_expression(expression, variables)
        self.expression = expression
        self.value = value
        self.notifyObservers()

    def addObserver(self, observer):
        self.observers.append(observer)

    def observersCellMarks(self):
        return [self.sheet.getCellMark(observer.row, observer.column) for observer in self.observers]

    def notifyObservers(self):
        for observer in self.observers:
            observer.evaluate()
