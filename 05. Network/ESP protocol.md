> Encapsulating  Security Payload
> AH protocol과는 다르게 기밀성을 보장한다.
> 물론, AH가 제공하는 서비스를 모두 보장한다.
 
![](https://blog.kakaocdn.net/dn/b4GBoH/btqFaOmOCAJ/UKUdOrI8FGdKdKAl3NlUQK/img.png)
- Authentication Data : AH와는 다르게 인증데이터가 IP헤더를 포함하지 않는다. ESP 헤더까지만 인증데이터로 만들고 ESP Trailer에 붙이게 된다.
# 임시 마무리
- SAD(Security Association Database), SP(Security Parameters) 등에 대해서 알아야 한다더라~