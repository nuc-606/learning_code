# 开发作者   ：Tian.Z.L
# 开发时间   ：2022/2/17  18:11 
# 文件名称   ：assignment3.PY
# 开发工具   ：PyCharm
import cv2
import numpy as np
import math

video = cv2.VideoCapture(r'C:\Users\TianZhonglin\Documents\Tencent Files\765808965\FileRecv\MobileFile\1234567.mp4')
print(type(video))


# video = cv2.VideoCapture(r'C:\Users\TianZhonglin\Documents\Tencent Files\765808965\FileRecv\23456789.avi')


def img_show(name, src):
    cv2.imshow(name, src)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


while True:
    ret, img = video.read()
    blue, g, r = cv2.split(img)  # 分离通道，在opencv中图片的存储通道为BGR非RBG
    # 绘制轮廓  是在原图像上进行画轮廓
    ret2, binary = cv2.threshold(blue, 220, 255, 0)
    Gaussian = cv2.GaussianBlur(binary, (5, 5), 0)  # 高斯滤波
    # edge = cv2.Canny(binary, 50, 150)  # 边缘检测
    draw_img = binary.copy()
    whole_h, whole_w = binary.shape[:2]
    # 输出的第一个值为图像，第二个值为轮廓信息，第三个为层级信息
    contours, hierarchy = cv2.findContours(image=draw_img, mode=cv2.RETR_TREE, method=cv2.CHAIN_APPROX_NONE)
    contours = list(contours)
    contours.sort(key=lambda c: cv2.contourArea(c), reverse=True)
    width_array = []
    height_array = []
    point_array = []
    for cont in contours[:5]:
        x, y, w, h = cv2.boundingRect(cont)
        # cv2.rectangle(img, (x,y), (x+w,y+h), (0, 255, 0), 2)
        try:
            if h / w >= 2 and h / whole_h > 0.1 and h > w:
                # if height / h > 0.05:
                width_array.append(w)
                height_array.append(h)
                point_array.append([x, y])
        except:
            continue
    # for cont in contours:
    #     rect = cv2.minAreaRect(cont)
    #     # cv2.boxPoints可以将轮廓点转换为四个角点坐标
    #     box = cv2.boxPoints(rect)
    #     # print(type(box))
    #     # 这一步不影响后面的画图，但是可以保证四个角点坐标为顺时针
    #     startidx = box.sum(axis=1).argmin()
    #     box = np.roll(box, 4 - startidx, 0)
    #     # 在原图上画出预测的外接矩形
    #     box = box.reshape((-1, 1, 2)).astype(np.int32)
    #     distance1 = box[0][0] - box[1][0]
    #     distance2 = box[0][0] - box[3][0]
    #     width = math.hypot(distance1[0], distance1[1])
    #     height = math.hypot(distance2[0], distance2[1])
    #     # if distance1 < distance2:
    #     #     width = distance1
    #     #     height = distance2
    #     # else:
    #     #     width = distance2
    #     #     height = distance1
    #     try:
    #         if height / width >= 2 and height / h > 0.05 and height > width:
    #         # if height / h > 0.05:
    #             width_array.append(width)
    #             height_array.append(height)
    #             point_array.append(box)
    #     except:
    #         continue
    # try:
    #     if height / width >= 2 and height / h > 0.05 and height > width:
    #         cv2.polylines(img, [box], True, (0, 255, 0), 2)
    # except:
    #     continue
    point_near = [0, 0]
    min = 10000
    for i in range(len(width_array) - 1):
        for j in range(i + 1, len(width_array)):
            value = abs(width_array[i] * height_array[i] - width_array[j] * height_array[j])
            if value < min:
                min = value
                point_near[0] = i
                point_near[1] = j
    try:
        rectangle1 = point_array[point_near[0]]
        rectangle2 = point_array[point_near[1]]
        # point1 = (rectangle1[2][0]+rectangle1[3][0])/2
        # point2 = (rectangle1[0][0]+rectangle1[1][0])/2
        # point3 = (rectangle2[2][0]+rectangle2[3][0])/2
        # point4 = (rectangle2[0][0]+rectangle2[1][0])/2
        point1 = [rectangle1[0] + width_array[point_near[0]] / 2, rectangle1[1]]
        point2 = [rectangle1[0] + width_array[point_near[0]] / 2, rectangle1[1] + height_array[point_near[0]]]
        point3 = [rectangle2[0] + width_array[point_near[1]] / 2, rectangle2[1]]
        point4 = [rectangle2[0] + width_array[point_near[1]] / 2, rectangle2[1] + height_array[point_near[1]]]
        print(point1, point2, point3, point4)
        x = np.array([point1, point2, point4, point3], np.int32)
        box = x.reshape((-1, 1, 2)).astype(np.int32)
        cv2.polylines(img, [box], True, (0, 255, 0), 2)
    except:
        continue
    # dst = cv2.drawContours(img, contours, -1, (0, 0, 255), 3)
    cv2.imshow('name', img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        # flag = 1
        break
    # if flag == 1:
    #     break
# 释放资源
video.release()
cv2.destroyAllWindows()
