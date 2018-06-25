#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.
    [S/W problem solving basic] partial sequence
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
import numpy as np
import copy

INPUT_FILE_PATH = "/home/daim/workspaces/swuAlgo/daim/sequence/sum_of_partial_sequences_input.txt"
CASE_CNT = 10


class PartialSequence(object):

    def __init__(self, n, k, case):
        self.n = n  # case length
        self.k = k  # result of sum
        self.case = case
        self.sumCnt = {}

    def findSumCnt(self, value):
        return value in self.sumCnt.keys()

    def addSumCnt(self, value, cnt=1):
        
        if self.findSumCnt(value):
            self.sumCnt[value] += cnt
        else:
            # 가지 치기 (self.k보다 큰 경우는 기록 x)
            if value <= self.k:
                self.sumCnt[value] = cnt

    def returnCntByValue(self, value):
        if value not in self.sumCnt:
            return 0
        else:
            return self.sumCnt[value]

    def solve(self):
        for i in range(0, self.n):
            value = int(self.case[i])
            tempSumCnt = copy.deepcopy(self.sumCnt)
            self.addSumCnt(value, 1)  # init

            if len(self.sumCnt) > 1:  # 처음 제외
                for key, cnt in tempSumCnt.items():
                    self.addSumCnt(int(key) + value, cnt)

        return self.returnCntByValue(self.k)


def case_generator(fp, CASE_CNT):
    for i in range(0, CASE_CNT):
        info = [int(x) for x in fp.readline().strip('\n').split()]
        # print(info)
        n = info[0]
        k = info[1]
        case = [int(x) for x in fp.readline().strip('\n').split()]
        yield n, k, case


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline().strip('\n'))
        for n, k, case in case_generator(fp, CASE_CNT):
            ps = PartialSequence(n, k, case)
            print(ps.solve())
