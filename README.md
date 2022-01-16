# rescure_rccar #이작품은 동서대학교 AI.SW경진대회에 참여 하였던 작품입니다.
![image](https://user-images.githubusercontent.com/62789342/149654972-1dbacee7-5e8f-4b4a-be4a-1c95f6382c44.png)

1. 차에 전원을 인가하면 자동으로 통신을 시작한다. 데이터 수신용 모듈에도 전원 인가 시 양 측에 연결한 nRF24l01 모듈을 통하여 LoRa 방식으로 통신한다.

![image](https://user-images.githubusercontent.com/62789342/149655029-977f27c2-1363-48f7-9c6c-3a963887edff.png)

2. GPS 신호가 감지되면 다음과 같이 GPS 데이터를 수신하고 그 값을 nRF24l01 모듈이 받아와 출력한다. 기본 코드에서 추가 수정을 하여, 인지하기 쉽고 지도와 연계하기 쉽게 위도, 경도만 나오게 코드를 수정하였습니다.

![image](https://user-images.githubusercontent.com/62789342/149655048-514ddb24-a17e-41ea-80bb-bbb03941efb7.png)

3. 원격 모듈이 무선 LAN 네트워크 망에 연결되었다면 ov2640 카메라가 촬영한 영상을 원격으로 출력한다. 현재는 카메라가 사람을 찍고있는 모습입니다.

![image](https://user-images.githubusercontent.com/62789342/149655057-1384d602-e610-4b76-aee6-d9ef39ec57a8.png)

4. 영상과 더불어 위도,경도 값을 통해 GPS 모듈에서 받아온 정보를 토대로 모듈의 위치가 구체적으로 어디 있는지 특정할 수 있다.

![image](https://user-images.githubusercontent.com/62789342/149655066-e1537de2-bbf3-410b-8699-30526971424c.png)

5. 만약 조도센서의 값이 일정이하로 떨어지게 된다면, 카메라 식별이 불가하므로 인체감지센서를 이용해 식별을 하게 됩니다.

#만약 GPS의 값을 그냥 받게되면,
![image](https://user-images.githubusercontent.com/62789342/149655087-28b3e9a6-fc1b-4253-ab0e-4cf1778ef599.png)

위와 같은 표처럼 필요하지 않은 값들이 함께 출력되므로, 첫 번째 코드를 이용해 위도, 경도 값만 나오게 코딩하였습니다.

![image](https://user-images.githubusercontent.com/62789342/149655098-93f7bfcb-2938-47a9-b734-9b697d06b7c5.png)

![image](https://user-images.githubusercontent.com/62789342/149655104-ff75f928-b6ab-43d5-b3d4-f272f792a6ba.png)

6. 이 코드는 nRF24L01 (로라모듈)의 수신기를 설정하는 코드입니다. 이 코드를 이용해 송신기로부터 받아오는 값을 수신할 수 있게 됩니다.

![image](https://user-images.githubusercontent.com/62789342/149655119-0d16834f-e140-48ea-9b5a-5ac5d2617f3f.png)

7. 이 코드는 nRF24L01 (로라모듈)의 송신기를 설정하는 코드입니다. 이 코드를 이용해 받아오는 값을 수신기로 송신할 수 있게 됩니다.

![image](https://user-images.githubusercontent.com/62789342/149655123-9e35ecd4-3396-475c-8760-317fdc947c85.png)

8. 위 코드는 카메라 모듈이 정상적으로 작동하기 위한 카메라 + 와이파이 + 웹 스트리밍 세 가지를 실행시키기 위한 코드입니다.

![image](https://user-images.githubusercontent.com/62789342/149655130-7d4498e3-7d18-4232-92bf-fc77ea282ca0.png)

9. 최종적인 작동영상 입니다.
