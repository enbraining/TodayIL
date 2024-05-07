# About
> IP security
> 네트워크에서의 안전한 연결을 설정하기 위한 통신 규칙 또는 프로토콜 세트

# 특징
- TLS는 TCP 프로토콜만을 보호하지만 IPsec은 TCP, UDP부터 상위 계층까지 보호하기 위해선 낮은 계층부터 보호하는 것이 효과적이므로 IP 계층에서 IPsec을 사용하는 것이다.

# 모드
## Transport mode
- network layer, transport layer 사이에서 전달되는 payload를 보호한다.
![](https://blog.kakaocdn.net/dn/eMGuHW/btqFbBUnmK1/OeKLdM6nJuk5pOwOdcY2O1/img.png)
- 전송 모드는 end-to-end에서 데이터 보호가 필요할 때 사용된다.
- 왼쪽 host는 IPsec을 적용하여 데이터를 보내고 데이터가 오른쪽 host로 도착한다. 이 사이에서는 다른 사람이 데이터를 가져가도 IPsec에 대한 보호가 있으므로 볼 수 없고 라우터를 거쳐 두 host만 데이터를 볼 수 있다. 그래서 E2EP(End-To-End Protection)이 이루어질 수 있다.
![](https://blog.kakaocdn.net/dn/C0v2n/btqFaDlyhWS/wEEIQAQdQkVsswVu9GUk80/img.png)
## Tunnel mode
- IPsec이 IP 헤더에 포함한 IP 계층의 모든 것을 보호한다.
- IP 헤더까지 완전히 보호하고 IPsec의 헤더를 추가해서 기존의 IP 헤더를 볼 수 없기 때문에 새로운 IP 헤더가 추가된다.
![](https://blog.kakaocdn.net/dn/drY2z8/btqFaTnUijV/OfShxsAuzQzdco711BExE0/img.png)
- IPsec 헤더와 새로운 헤더는 호스트가 아닌 중간자 즉, 라우터가 추가한다.
- Transport mode와 다르게 host에서는 별다른 조치를 취하지 않으며 라우터에서 IPsec를 적용하고 새로운 IP 헤더를 추가한다.
- 이 헤더에는 목적지 라우터의 주소가 있어서 다른 라우터로 보낸다.
- 헤더를 전송받은 라우터는 적절한 조치 + 새로운 IP 헤더와 IPsec 헤더를 제거하고 다른 host에게 전달한다.
![](https://blog.kakaocdn.net/dn/dMSIHN/btqFaCNDnJG/kovdvinHZ0CZDt4w2EKsjK/img.png)

# 프로토콜
## [[AH protocol]]
- 송신자와 수신자가 같은 키를 공유하고 이 키를 이용하여 해시를 구해서 인증을 수행한다.
## [[ESP protocol]]
- 송신자와 수신자가 같은 키를 공유하고 대칭형 암복호화 알고리즘을 사용하여 패킷을 암호화 및 복호화하는 것이다.