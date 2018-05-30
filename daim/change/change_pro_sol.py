#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.
    [BackTracking] easy change [쉬운 거스름돈]
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
import numpy as np

INPUT_FILE_PATH = "./change_input.txt"
CASE_CNT = 10


class Change(object):

    def __init__(self, money):
        self.money = money
        self.changeArray = [50000, 10000, 5000, 1000, 500, 100, 50, 10]
        self.result = []

    def changeMoney(self):
        money = self.money
        while money > 0:
            for change in self.changeArray:
                if money >= change:
                    share = money // change  # 몫
                    rest = money % (change * share)  # 나머지
                    self.result.append(share)
                    money = rest
                else:
                    self.result.append(0)
        return ' '.join(str(e) for e in self.result)  # change list to string

if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline())
        for i in range(0, CASE_CNT):
            money = int(fp.readline())
            change = Change(money)
            result = change.changeMoney()
            print('#{0}\n{1}'.format(i+1, result))
