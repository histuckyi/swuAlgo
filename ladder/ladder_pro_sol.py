#  -*-coding:utf-8-*-

import numpy as np
import math
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


    # 알맞은 다음 길을 찾아 이동
    def tracePath(self, _row, _col, _map):
        row = int(_row)
        col = int(_col)
        ladder_map = _map

        # 오른쪽이나 왼쪽에 길이 있을 경우 그쪽으로 이동
        while row < MAX_LENGTH:  # 맨 마지막 줄에 도달할 때까지 이동
            if ladder_map[row][col] == 2:
                # print('row : {0} and col : {1}'.format(row, col))
                return True

            ladder_map[row][col] = 5
            if self.isAvailPath(row, col + 1, ladder_map):  # 오른쪽 체크
                col += 1
            elif self.isAvailPath(row, col - 1, ladder_map):  # 왼쪽 체크
                col -= 1
            else:  # 왼쪽 오른쪽이 모두 길이 없으면 아래로 이동
                row += 1
                   # row가 99일 때, 즉, 맨 마지막 줄에 도달했을 때
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
                    # print('num : {0}'.format(num))
                    return num  # 2에 도착한 num의 수
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
            # print(case)
            # print(case[0][1])
            # print('\n')
            ladder = Ladder(case)
            print("#{0} {1}".format(str(cnt).strip('\n'), str(ladder.findWinner())))