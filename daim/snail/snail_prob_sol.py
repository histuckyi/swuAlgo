#  -*-coding:utf-8-*-
"""
    Python ver.
    solution for algorithm problem.

    Two-dimensional array flexibility problem ([2차원 배열 연습 문제] 달팽이 숫자)
    https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
    You can see the question
    and download input, output text file from above link.

    * download input.txt from the link
    * Please, change the value of INPUT_FILE_PATH
"""
import numpy as np
import math

# Constants
INPUT_FILE_PATH = "./snail_input.txt"


class SnailArray(object):
    """
    This class is for array that element has sequential numbers.

    ex) 
    1 2 3       1  2  3  4
    8 9 4       12 13 14 5     ...   ...
    7 6 5       11 16 15 6
                10 9  8  7
    """
    def __init__(self, size):
        self.snail_array = np.zeros((int(size), int(size)))
        # right, down, left, up
        self._direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        self._max_num = int(math.pow(float(size), 2))
        self._size = int(size)
        self.dir_index = 0  # The right direction is default option
        self.current_x = 0
        self.current_y = 0
        self.current_num = 0

    def write_snail_array(self):
        """
        check current path until current_num < max_num
        """
        while self.current_num < self._max_num:
            self.current_num = self.current_num + 1 
            self.check_current_path(self.current_x, self.current_y)
        self.print_all(self.snail_array)

    def check_current_path(self, x, y):
        """
        check availability of next element before going to next element.
        if it's not available,change the next index direction([]) in the order.
        snail_array always changed the direction in order.
        * right ->  down -> left -> up ---> right

        change case
        case 1 : visited element
                - make sure that it's already filled in with the other number.
        case 2 : range of array(x,y >= 0 and x,y < size)
                - make sure that (x,y) is out of range in array.
        """
        # insert current_num
        self.snail_array[x][y] = self.current_num

        # conclusion condition
        if self.current_num == self._max_num:
            return True

        # check whether  it(x,y) is available.
        next_x = x + self._direction[self.dir_index][0]
        next_y = y + self._direction[self.dir_index][1]

        # case 2. check next (x,y) is in the range of arrays 
        if next_x < self._size and next_y >= 0 \
           and next_y < self._size and next_y >= 0:
            # case 1. check visited element
            if self.snail_array[next_x][next_y]:
                self.change_dir_index(self.dir_index)  # change direction index    
                self.current_x = x + self._direction[self.dir_index][0]
                self.current_y = y + self._direction[self.dir_index][1]
            else:
                self.current_x = next_x
                self.current_y = next_y
        else:
            self.change_dir_index(self.dir_index)
            self.current_x = x + self._direction[self.dir_index][0]
            self.current_y = y + self._direction[self.dir_index][1]

    def change_dir_index(self, current_index):
        self.dir_index = (self.dir_index + 1) % 4

    def print_all(self, snail_array):
        for row in snail_array:
            string_array = []
            for x in row:
                if int(x) < 10:
                    string_array.append('  ' + str(int(x)))
                elif int(x) > 9 and int(x) < 100:
                    string_array.append(' ' + str(int(x)))
                else:
                    string_array.append(str(int(x)))
            print(" ".join(string_array))


if __name__ == "__main__":
    np.set_printoptions(threshold=np.inf)
    with open(INPUT_FILE_PATH) as fp:
        CASE_CNT = fp.readline().strip('\n')
        for x in range(0, int(CASE_CNT)):
            n = fp.readline().strip('\n')
            snailArray = SnailArray(n)
            print('#{0}'.format(x+1))
            snailArray.write_snail_array()