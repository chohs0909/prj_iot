import cv2
import numpy as np
import serial

margin_x = 50
margin_y = 50

_pan = pan = 90
_tilt = tilt = 20

sp  = serial.Serial('COM3', 9600, timeout=1)

pan = _pan = 90
tilt = _tilt = 20

def send_pan(pan):
    tx_dat = "pan" + str(pan) + "\n"
    sp.write(tx_dat.encode())
    print(tx_dat)

def send_tilt(tilt):
    tx_dat = "tilt" + str(tilt) + "\n"
    sp.write(tx_dat.encode())
    print(tx_dat)

def main(args=None):
    global pan; global _pan; global tilt; global _tilt;
    send_pan(75)
    send_tilt(75)

# 웹캠 신호 받기
VideoSignal = cv2.VideoCapture(0)

# YOLO 가중치 파일과 CFG 파일 로드 (절대경로)
weights_path = r"C:\Users\user\Documents\Arduino\_2023_IoT_project\pywork\yolo_vidio\yolov2-tiny.weights"
cfg_path = r"C:\Users\user\Documents\Arduino\_2023_IoT_project\pywork\yolo_vidio\yolov2-tiny.cfg"
YOLO_net = cv2.dnn.readNet(weights_path, cfg_path)

# YOLO NETWORK 재구성
classes = []
with open(r"C:\Users\user\Documents\Arduino\_2023_IoT_project\pywork\yolo_vidio\coco.names", "r") as f:
    classes = [line.strip() for line in f.readlines()]
layer_names = YOLO_net.getLayerNames()
output_layers = [layer_names[i - 1] for i in YOLO_net.getUnconnectedOutLayers()]

while True:
    # 웹캠 프레임
    ret, frame = VideoSignal.read()
    h, w, c = frame.shape

    # YOLO 입력
    blob = cv2.dnn.blobFromImage(frame, 0.00392, (416, 416), (0, 0, 0),
    True, crop=False)
    YOLO_net.setInput(blob)
    outs = YOLO_net.forward(output_layers)

    class_ids = []
    confidences = []
    boxes = []

    for out in outs:

        for detection in out:

            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]

            if confidence > 0.3:
                # Object detected
                center_x = int(detection[0] * w)
                center_y = int(detection[1] * h)
                dw = int(detection[2] * w)
                dh = int(detection[3] * h)
                # Rectangle coordinate
                x = int(center_x - dw / 2)
                y = int(center_y - dh / 2)
                boxes.append([x, y, dw, dh])
                confidences.append(float(confidence))
                class_ids.append(class_id)
                if center_y <= 240-margin_y:########################################### need tilt up 
                    if tilt - 1 >= 0:
                        tilt = tilt - 1
                        send_tilt(tilt); _tilt = tilt
                    else:
                        tilt = 0
                        send_tilt(tilt); _tilt = tilt
                elif center_y < 240+margin_y: ########################################### do not change tilt value
                    tilt = _tilt
                    send_tilt(tilt); _tilt = tilt
                else: ########################################### need tilt right
                    if tilt + 1 <= 180:
                        tilt = tilt + 1
                        send_tilt(tilt); _tilt = tilt
                    else:
                        tilt = 180
                        send_tilt(tilt); _tilt = tilt
                if center_x >= 320-margin_x:########################################### need pan left 
                    if pan - 1 >= 0:
                        pan = pan - 1
                        send_pan(pan); _pan = pan
                    else:
                        pan = 0
                        send_pan(pan); _pan = pan
                elif center_x > 320+margin_x: ########################################### do not change tilt value
                    pan = _pan
                    send_pan(pan); _pan = pan
                else: ########################################### need pan right
                    if pan + 1 <= 180:
                        pan = pan + 1
                        send_pan(pan); _pan = pan
                    else:
                        pan = 180
                        send_pan(pan); _pan = pan   

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.45, 0.4)


    for i in range(len(boxes)):
        if i in indexes:
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]])
            score = confidences[i]

            # 경계상자와 클래스 정보 이미지에 입력
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 5)
            cv2.putText(frame, label, (x, y - 20), cv2.FONT_ITALIC, 0.5, 
            (255, 255, 255), 1)

    cv2.imshow("YOLOv3", frame)

    if cv2.waitKey(100) > 0:
        break