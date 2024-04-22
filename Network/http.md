## HTTP Request

```
GET /profile HTTP/1.1
Host: show.enbraining.com
Accept-Language: ko
```

- Method (GET)

클라이언트가 수행하고자 하는 동작을 정의한 것으로 GET, POST, DELETE 등의 메소드가 존재함

- Path (/profile)

가져오려는 리소스의 경로임. 프로토콜, 도메인, 포트 등을 제외한 리소스의 URL임

- Version of the protocol (HTTP/1.1)

HTTP 프로토콜의 버전

- Headers (Host: show.en...)

서버에 추가적인 정보를 전달하기 위한 헤더

## HTTP Response

```
HTTP/1.1 200 OK
Server: Apache
Content-Type: text/html
```

- Version of the protocol (HTTP/1.1)

HTTP 프로토콜의 버전

- Status code (200)

요청에 대한 응답 상태를 나타내는 상태 코드

- Status message (OK)

상태 코드에 대한 짧은 설명

- Headers (Content-Type...)

추가적인 정보가 포함된 헤더