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

INPUT_FILE_PATH = "./pool_input.txt"
CASE_CNT = 10


class Pool(object):

    def __init__(self, value, yearList):
        self.value = value
        self.yearList = yearList
        self.monthRateList = []
        self.bestRateforPeriod = []
        
    def compareAtoB(self, value1, value2):
        return value2 if value1 > value2 else value1

    def solve(self):
        # compare days and month rate
        for i in range(0, 12):
            # value[0] : rate by a day, value[1] : rates by a month
            self.monthRateList.append(self.compareAtoB(self.yearList[i] * self.value[0], self.value[1]))
        
        for i in range(0, 12):
            if (i+1) - 3 >= 0:
                if (i+1) == 3:
                    before = 0
                else:
                    before = self.bestRateforPeriod[i-3]
                self.bestRateforPeriod.append(self.compareAtoB(self.bestRateforPeriod[i-1] + self.monthRateList[i], before + self.value[2]))
            else:
                self.bestRateforPeriod.append(sum(self.monthRateList[0:i+1]))

        if self.bestRateforPeriod[11] > self.value[3]:
            return self.value[3]
        else:
            return self.bestRateforPeriod[11]


def case_generator(fp, CASE_CNT):
    for i in range(0, CASE_CNT):
        value = [int(x) for x in fp.readline().strip('\n').split()]
        yearList = [int(x) for x in fp.readline().strip('\n').split()]
        yield i, value, yearList


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline().strip('\n'))
        for index, value, yearList in case_generator(fp, CASE_CNT):
            pool = Pool(value, yearList)
            print('#{0} {1}'.format(int(index) + 1, pool.solve()))
