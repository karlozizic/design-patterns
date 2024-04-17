from Cell import Cell


class Sheet:
    cells = None

    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.cells = [[Cell(j, i, self) for i in range(columns)] for j in range(rows)]

    def set(self, cellMark, expression):
        self.getCell(cellMark).set_expression(expression)

    def getCellPosition(self, cellMark):
        column = ord(cellMark[0].upper()) - ord('A')
        row = int(cellMark[1:]) - 1
        if row < 0 or row >= self.rows or column < 0 or column >= self.columns:
            raise Exception("Cell out of range")
        return row, column

    def getCell(self, cellMark):
        row, column = self.getCellPosition(cellMark)
        return self.cells[row][column]

    def getCellMark(self, row, column):
        return chr(column + ord('A')) + str(row + 1)

    def print(self):
        for row in self.cells:
            row_output = ""
            for cell in row:
                row_output += str(cell.value) + " "
            print(row_output)
