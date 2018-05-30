import numpy as np
from collections import Counter
"""
    Python ver.
    solution for algorithm problem.
    [One-dimensional array problem] The most frequent number
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and download input, output text file from above link.

    * Download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""

INPUT_FILE_PATH = "./frequency_input.txt"
CASE_CNT = 10


class Frequency(object):

    def __init__(self, case):
        self.set_case = set(case)  # set
        self.case = case  # list
        self.num = None
        self.count = 0

    def count_frequency(self):
        for num in self.set_case:
            count = self.case.count(num)
            if self.count < count:
                self.count = count
                self.num = num
            elif self.count == count:
                # choose a bigger number if count is equal
                if self.num < num:
                    self.num = num
        return self.num


def case_generator(fp, CASE_CNT):
    for i in range(0, CASE_CNT):
        cnt_number = fp.readline()
        line_str = fp.readline()
        line = [int(x) for x in line_str.strip('\n').split()]
        yield cnt_number, line


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = int(fp.readline())
        for idx, case in case_generator(fp, CASE_CNT):

            # solution 1
            # solution with collections.Counter
            result = Counter(case)
            print('#{0} {1}'.format(idx.strip('\n\r'), max(result, key=result.get)))

            # solution 2
            # frequency = Frequency(case)
            # num = frequency.count_frequency()
            # print('#{0} {1}'.format(idx.strip('\n\r'), num))