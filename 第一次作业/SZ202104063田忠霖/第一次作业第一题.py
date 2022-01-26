# 开发作者   ：Tian.Z.L
# 开发时间   ：2022/1/26  13:33 
# 文件名称   ：assignment.PY
# 开发工具   ：PyCharm
sex_list = ['男', '女']


class Person:

    def __init__(self, name, sex, age):
        self.name = name
        self.sex = sex_list[sex]
        self.age = age

    def print(self):
        print('姓名:' + str(self.name) + ' 性别:' + str(self.sex) + ' 年龄:' + str(self.age))


p1 = Person('一号玩家', 1, 25)
p1.print()
p2 = Person('二号玩家', 0, 22)

p3 = p2
p3.print()
