#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.
    [s/w problem solving basic]  talent2
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question
    and download input, output text file from above link.
    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
import numpy as np
import math

INPUT_FILE_PATH = "./talent2_input.txt"
CASE_CNT = 10


def calculateMaxCandies(total_talent, bundle_cnt):
    """
    if the sum(total_talent) of numbers is fixed,
    For the greatest multiplied All numbers,
    The small difference between the numbers is better.
    
    example1
    input : 10 3
    10 // 3 = 3(n) ...1(x)
    3 * 3 * (3 + x) = 36
    output : 36
    """
    share = total_talent // bundle_cnt
    rest = total_talent % bundle_cnt
    return int(math.pow(share, bundle_cnt - rest) * math.pow((share + 1), rest))


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf, linewidth=1000)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline())
        for i in range(0, CASE_CNT):
            str = fp.readline()
            array = [int(e) for e in str.strip('\n').split(' ')]
            result = calculateMaxCandies(array[0], array[1])
            print('#{0} {1}'.format(i+1, result))
