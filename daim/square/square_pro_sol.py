#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.

    1952. [모의 SW 역량테스트] pool(수영장)
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question
    and download input, output text file from above link.

    * download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""

import numpy as np

INPUT_FILE_PATH = "./square_input.txt"
CASE_CNT = 10


class Square(object):

    def __init__(self, array, length):
        self._direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        self.array = array
        self.connectionArray = {}
        self.length = length
        self.maxCount = 1
        self.maxValue = 0  # start value
        self.currentMax = 1
        self.currentValue = 0  # start current value

    def checkDirection(self, value, _x, _y):
        for pos in self._direction:
            x = _x + pos[0]
            y = _y + pos[1]

            if x < 0 or x >= self.length or y < 0 or y >= self.length:
                continue
            else:
                connectValue = self.array[x][y]
                if value in self.connectionArray.keys():
                    self.connectionArray[value].append(connectValue)
                else:
                    self.connectionArray[value] = [connectValue]

    def setConnectionArray(self):
        for x in range(0, self.length):
            for y in range(0, self.length):
                self.checkDirection(self.array[x][y], x, y)

        return self.connectionArray

    def solve(self):
        self.setConnectionArray()
        for v in range(1, (self.length * self.length) + 1):
            self.currentValue = v
            value = v + 1
            centerV = v
            while value in self.connectionArray[centerV]:
                self.currentMax += 1
                value += 1
                centerV += 1
            if self.currentMax > self.maxCount:
                self.maxCount = self.currentMax
                self.maxValue = self.currentValue
            self.currentMax = 1
        return self.maxValue, self.maxCount


def case_generator(fp, CASE_CNT):
    for i in range(0, int(CASE_CNT)):
        length = int(fp.readline().strip('\n'))
        lines = []
        for i in range(0, length):
            line_str = fp.readline()
            line = [int(x) for x in line_str.strip('\n').split()]
            lines.append(line)
        lines = np.array(lines)
        yield length, lines


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline().strip('\n'))
        # CASE_CNT = 3
        for length, case in case_generator(fp, CASE_CNT):
            sq = Square(case, length)
            value, count = sq.solve()
            print('# {0} {1}'.format(value, count))
