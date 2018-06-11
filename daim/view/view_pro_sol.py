#  -*-coding:utf-8-*-
import numpy as np
"""
    Python ver.
    solution for algorithm problem.
    [One-dimensional array problem] View rights
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
INPUT_FILE_PATH = "./view_input.txt"
CASE_CNT = 10


class Building(object):
    """
    This class is for array that element is each height of buildings.

    ex)
    [0, 0, 0, 3, 5 ,2, 0 ,0]
    The tallest building is 5 (index of 4)
    That's building have only View rights.
    If Which building want to have view rights, both 2 sides of building must be lower than this one.
    In other words, Only 2 head of household in that building(height 5, index of 4) has view rights.
    """

    def __init__(self, heightList):
        self.heightList = heightList
        self.checkPoint = [-2, -1, 1, 2]

    def checkSides(self, idx):
        cv = self.heightList[idx]  # current value
        checkHeight = []
        for v in self.checkPoint:
            index = idx + v
            # if this one is lower than others -> False
            if self.heightList[index] >= cv:
                return False
            # collect other height of building
            else:
                checkHeight.append(self.heightList[index])
        # choose the max height of sides buildings 
        top = max(checkHeight)
        return cv - top

    def checkBuildings(self):
        availCount = 0
        for i, v in enumerate(self.heightList):
            # pick available number up
            # v should be over 0
            if v:
                result = self.checkSides(i)
                if result:
                    availCount += result
        return availCount


def case_generator(fp, CASE_CNT):
    for i in range(0, CASE_CNT):
        cnt_count = fp.readline()
        line_str = fp.readline()
        line = [int(x) for x in line_str.strip('\n').split()]
        yield i, line


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        for idx, case in case_generator(fp, CASE_CNT):
            building = Building(case)
            print('#{0} {1}'.format(idx+1, building.checkBuildings()))

