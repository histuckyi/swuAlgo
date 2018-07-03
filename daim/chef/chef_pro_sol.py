#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.
    [combinations] chef [요리사]
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question
    and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""

import numpy as np
from itertools import combinations_with_replacement, combinations

CASE_CNT = 10
INPUT_FILE_PATH = "./chef_input.txt"


class Chef(object):

    def __init__(self, length, case):
        self.length = length
        self.case = case
        self.min = None

    def getScore(self, idList):
        pairs = list(combinations(idList, 2))
        score = 0

        for pair in pairs:
            x = int(pair[0])
            y = int(pair[1])
            score += self.case[x][y] + self.case[y][x]
        return score

    def solve(self):
        idx_list = [str(x) for x in range(0, self.length)]

        combi = list(combinations(idx_list, self.length//2))
        for case in combi:
            avail_idx = set(idx_list).symmetric_difference(case)
            score1 = self.getScore(case)
            score2 = self.getScore(avail_idx)
            result = abs(score1 - score2)

            if self.min is None:
                self.min = result
            elif result < self.min:
                self.min = result

        return self.min


def case_generator(fp, CASE_CNT):
    for idx in range(0, CASE_CNT):
        length = int(fp.readline())
        lines = []
        for i in range(0, length):
            line_str = fp.readline()
            line = [int(x) for x in line_str.strip('\n').split()]
            lines.append(line)
        lines = np.array(lines)
        yield idx+1, length, lines


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline())
        # CASE_CNT = 
        for idx, length, case in case_generator(fp, CASE_CNT):
            chef = Chef(length, case)
            print('#{0} {1}'.format(idx, chef.solve()))
