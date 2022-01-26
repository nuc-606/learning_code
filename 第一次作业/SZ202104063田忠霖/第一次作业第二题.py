# 开发作者   ：Tian.Z.L
# 开发时间   ：2022/1/26  13:42 
# 文件名称   ：assignment2.PY
# 开发工具   ：PyCharm
stud_list = []


class Stud:
    def __init__(self, id, name, grade):
        self.id = id
        self.name = name
        self.grade = grade

    def print(self):
        print('学号:' + str(self.id) + ' 姓名:' + str(self.name) + ' 成绩:' + str(self.grade))


def input_message():
    studentNum = input('输入学生的个数')
    index = 0
    while index < int(studentNum):
        id = input('学号:')
        name = input('姓名:')
        grade = input('成绩:')
        while int(grade) < 0 or int(grade) > 100:
            print('输入错误，请重新输入')
            grade = input('成绩:')
        stud_list.append(Stud(id, name, grade))
        choise = input('是否继续输入(y/n)')
        flag = 0
        while True:
            if choise == 'y' or choise == 'Y':
                flag = 0
                break
            elif choise == 'n' or choise == 'N':
                flag = 1
                break
            else:
                choise = input('输入有误重新输入，是否继续输入(y/n)')
        if flag == 1:
            break
        index += 1


def show_information():
    stud_sum = len(stud_list)
    grade_sum = 0
    for i in stud_list:
        print('学号:' + i.id + ' 姓名:' + i.name + ' 成绩' + i.grade)
        grade_sum += int(i.grade)
    print('总人数:' + str(stud_sum) + '平均分' + str(grade_sum / stud_sum))


if __name__ == '__main__':
    input_message()
    show_information()
