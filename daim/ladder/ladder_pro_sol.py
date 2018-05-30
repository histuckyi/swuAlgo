#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.
    [S/W problem solving basic] Ladder1
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
import numpy as np
import copy

INPUT_FILE_PATH = "./ladder_input.txt"
CASE_CNT = 10
MAX_LENGTH = 100
MAX_COL = 100


class Ladder(object):

    def __init__(self, map):
        self.map = map

    def isAvailPath(self, row, col, _map):
        if row < 0:
            return False
        if col < 0:
            return False

        if row >= MAX_LENGTH:
            return False

        if col >= MAX_COL:
            return False

        if _map[row][col] > 0 and _map[row][col] < 5:
            return True
        else:
            return False

    def isAvailMap(self, row, col):
        if row >= MAX_LENGTH or col >= MAX_COL:
            return False
        else:
            return True

    # find the right way to go 
    def tracePath(self, _row, _col, _map):
        row = int(_row)
        col = int(_col)
        ladder_map = _map

        # move and check the right, left path until the last line
        while row < MAX_LENGTH:  
            if ladder_map[row][col] == 2:
                return True

            ladder_map[row][col] = 5
            # check right direction
            if self.isAvailPath(row, col + 1, ladder_map):
                col += 1
            # check left direction
            elif self.isAvailPath(row, col - 1, ladder_map):
                col -= 1
            # if you have no left, right direction, go down.
            else:
                row += 1
        # when row is 99, the last line is reached
        # if ladder_map[row][col] is not 2, return False
        return False

    def findWinner(self):
        num = 0
        while num < MAX_LENGTH:
            # not available path
            if self.map[0][num] == 0:
                num += 1
                continue
            else:
                ladder_map = copy.deepcopy(self.map)
                result = self.tracePath(0, num, ladder_map)
                if result:
                    # The num is reached at 2
                    return num
                num += 1


def case_generator(fp, CASE_CNT):
    for i in range(0, CASE_CNT):
        cnt_number = fp.readline()
        lines = []
        for i in range(0, MAX_LENGTH):
            line_str = fp.readline()
            line = [int(x) for x in line_str.strip('\n').split()]
            lines.append(line)
        lines = np.array(lines)
        yield cnt_number, lines

if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        for cnt, case in case_generator(fp, CASE_CNT):
            ladder = Ladder(case)
            print("#{0} {1}".format(str(cnt).strip('\n'), str(ladder.findWinner())))