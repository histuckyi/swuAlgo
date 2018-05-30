# !/usr/lib/python3.6 python3
#  -*-coding:utf-8-*-
"""
    Python ver. 
    solution for algorithm problem.
    
    Two-dimensional array flexibility problem.
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question and downdolad input, output text file from above link.
    
    * douwnload input.txt from the link
    * Please, change the value of INPUT_fILE_PATH
"""
import numpy as np

# Constants
SIZE = 100
CASE_CNT = 10
INPUT_FILE_PATH = "./sum_input.txt"


class SumArray(object):
    """
    This Class is for Arrays that need to be computed
    """

    def __init__(self, array):
        """
        params
        - (self) array : data to process
        variables
        - (self) size : x, y size
        - (self) max_num : result of the operation of sum()
        """
        self.array = array
        self.size = SIZE
        self.max_num = 0

    def __compareTo(self, sum):
        """
        check which value is larger
        """
        if self.max_num < sum:
            self.max_num = sum

    def __sum(self):
        """
        The function checks four cases.

        case 1. sum of row          ex) 6(1+2+3), 15(4+5+6) ...
        case 2. sum of column       largerex) 12(1+4+7), 15(2+5+8) ...
        case 3. sum of diagonal(\)  ex) 15(1+5+9)
        case 4. sum of diagonal(/)  ex) 15(3+5+7) 

        ex)
        1 2 3     (0,0)(0,1)(0,2)
        4 5 6     (1,0)(1,1)(1,2)
        7 8 9     (2,0)(2,1)(2,2)

        tip.
        case 3. coordinate (x, y) the elements of the array, x == y
                (0,0)(1,1)(2,2)
        case 4. coordinate (x, y) the elements of the array, x + y == size-1
                 (0,2)(1,1)(2,0)
                 0 + 2 = 2
                 1 + 1 = 2
                 2 + 1 = 2
        """
        sum_right_diagonal = 0
        sum_left_diagonal = 0

        for i1 in range(0, self.size):
            col_sum = 0

            # case 1. sum of row
            row_sum = sum(self.array[i1])
            self.__compareTo(row_sum)

            # case 2. sum of column
            for i2 in range(0, self.size):
                col_sum = col_sum + array[i2][i1]
                self.__compareTo(col_sum)

            # case 3. sum of diagonal(\)
            sum_right_diagonal = sum_right_diagonal + array[i1][i1]
            self.__compareTo(sum_right_diagonal)

            # case 4. sum of diagonal(/)
            sum_left_diagonal = sum_left_diagonal + array[i1][self.size-1-i1]
            self.__compareTo(sum_left_diagonal)

        return self.max_num

    def get_max_sum_result(self):
        return self.__sum()


def array_generator(fp, case_cnt, size):
    for i1 in range(0, case_cnt):   
        fp.readline()
        lines = []
        for i2 in range(0, 100):
            line_str = fp.readline()
            # print(line_str)
            line = [int(x) for x in line_str.strip('\n').split()]
            lines.append(line)
        lines = np.array(lines)
        yield i1, lines

if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf)
    with open(INPUT_FILE_PATH) as fp:
        for i, array in array_generator(fp, CASE_CNT, SIZE):
            sumArray = SumArray(array)
            print('#{0} {1}'.format(i+1, sumArray.get_max_sum_result()))
