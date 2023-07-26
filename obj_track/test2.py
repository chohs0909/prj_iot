import serial

# 시리얼 포트 설정 (아두이노와 연결된 포트를 확인하고, 해당 포트를 사용해야 합니다.)
ser = serial.Serial('COM3', 9600)  # 'COM3'을 연결된 포트 이름으로 변경

try:
    while True:
        # 시리얼 데이터 읽기
        line = ser.readline().decode().strip()
        if line:
            print("Received:", line)

except KeyboardInterrupt:
    # Ctrl+C를 누르면 프로그램 종료
    ser.close()
    print("Serial connection closed.")