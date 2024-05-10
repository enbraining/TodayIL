# NAT

# NAT-PT
> Network Address Translation - Protocol Translation
> IPv4와 IPv6 사이에서 NAT로 통신하기 위해 사용한다.
## Static NAT-PT
> IPv4와 IPv6 사이에서 1:1로 매칭된다.
### 설정
```
Router(config)#interface f0/0
Router(config-if)#ipv6 nat
Router(config-if)#interface f0/1
Router(config-if)#ipv6 nat
Router(config-if)#ipv6 nat prefix 123:1:1:1:1:1::/96
Router(config-if)#exit
Router(config)#ipv6 nat v6v4 source 1001:1:1:12::1 1.1.12.1
Router(config)#ipv6 nat v6v4 source 1001:1:1:1::1 1.1.1.1
Router(config)#ipv6 nat v4v6 source 1.1.23.3 123:1:1:1:1:1:23:3
Router(config)#ipv6 nat v4v6 source 1.1.3.3 123:1:1:1:1:1:3:3
```
1. 인터페이스에 "IPv6 nat"를 사용해서 NAT-PT를 활성화한다.
   **inside와 outside를 설정할 필요는 없다**
2. IPv6 주소로 변환될 nat prefix 대역을 설정한다.  출구 인터페이스를 지정하면 해당 인터페이스만 변환한다.
3. IPv6에서 IPv4로 변환될 주소를 매칭한다.
4. IPv4에서 IPv6로 변환되어 들어올 목적지 주소를 매칭한다. 위에서 설정한 NAT prefix 대역에서 추가한다.
## Dynamic NAT-PT
> 매칭할 주소를 동적으로 할당한다.
> 정적과 같이 "IPv6 nat", "IPv6 nat prefix" 설정은 유지한다.
### 설정
```
Router(config)#ipv6 access-list IPV6
Router(config-ipv6-acl)#permit ipv6 1001:1:1::/48 any
Router(config-ipv6-acl)#exit
Router(config)#ipv6 nat v6v4 pool IPV4 1.1.12.1 1.1.12.254 prefix-length 24
Router(config)#ipv6 nat v6v4 source list ipv6 pool IPV4
Router(config)#ipv6 nat v4v6 source 1.1.23.3 123:1:1:1:1:1:23:3
Router(config)#ipv6 nat v4v6 source 1.1.3.3 123:1:1:1:1:1:3:3
```
1. 매칭할 출발지 IPv6 주소 대역을 ACL로 지정한다.
2. 변환될 IPv4 주소 대역을 NAT pool로 지정한다. 
3. ACL과 NAT pool 대역을 매칭하도록 NAT 지정한다.
4. 목적지에서 출발지로 매핑할 땐 동적, 정적 NAT 설정에 관계없이 한쪽 방향에서는 정적으로 구성한다.
## V4-mapped Dynamic NAT-PT
> V4-mapped를 구성하면, IPv4 주소 형태가 IPv6 포맷에 맞게 자동 변환되므로
> 목적지 주소에서 정적 NAT를 매핑할 필요가 없다.
```
Router(config)#ipv6 access-list IPV6
Router(config-ipv6-acl)#permit 1001:1:1::/48 any
Router(config-ipv6-acl)#exit
Router(config)#int f0/1
Router(config-if)#ipv6 nat prefix 123:1:1:1:1:1::/96 v4-mapped IPV6
Router(config-if)#exit
Router(config)#ipv6 nat v6v4 pool IPV4 1.1.12.1 1.1.12.254 prefix-length 24
Router(config)#ipv6 nat v6v4 source list IPV6 pool IPV4
```
1. 출발지 IPv6 주소 대역을 ACL로 설정한다.
2. V4-mapped를 구성하도록 한다. nat prefix 96bit 뒤에 ipv4 주소를 변형한 32bit를 붙이고
   출발지 IPv6 주소 대역을 함께 설정한다.
3. 목적지 IPv4 주소 pool을 생성한다.
4. 위에서 설정한 출발지 IPv6 주소를 IPv4 pool로 변환하도록 설정한다.
## PAT-PT
> 포트별로 IPv6 주소를 할당하는 PAT를 설정한다.
```
Router(config)#ipv6 access-list IPV6
Router(config-ipv6-acl)#permit 1001:1:1::/48 any
Router(config-ipv6-acl)#int fa0/1
Router(config-if)#ipv6 nat prefix 123:1:1:1:1:1::/96
Router(config-if)#exit
Router(config)#ipv6 nat v6v4 pool IPV4 1.1.12.1 1.1.12.1 prefix-length 24
Router(config)#ipv6 nat v6v4 source list IPV6 pool IPV4 overload
Router(config)#ipv6 nat v4v6 source 1.1.23.3 123:1:1:1:1:1:23:3
Router(config)#ivp6 nat v4v6 source 1.1.3.3 123:1:1:1:1:1:3:3
```
1. N:1 PAT를 구성하기 위해 nat pool에 IPv4 주소를 1.1.12.1만 설정하였다.
   대부분의 중소규모 네트워크에서 PAT를 사용하는 이유는 사설 IP를 훨씬 적은 몇개의 공인 IP로 변환하여
   통신하도록 해서 부족한 IPv4 주소를 극복하고자 함이기 때문에 여기서도 이렇게 설정해봤다.
2. IPv6 주소 대역을 지정한 ACL과 nat pool IPV4 주소를 매칭시킨다.
3. V4-mapped 자동 변환 매칭이 아니기 때문에 목적지 주소에서 정적으로 구성되도록 하였다.
## 출발지가 IPv4
```
Router(config)#int f0/1
Router(config-if)#ipv6 nat prefix 123:1:1:1:1:1::/96
Router(config-if)#exit
Router(config)#ip access-list extended IPV4
Router(config-ext-nacl)#permit ip 1.1.0.0 0.0.255.255 any
Router(config-ext-nacl)#exit
Router(config)#ipv6 nat v4v6 pool IPV6 123:1:1:1:1:1:1:0 123:1:1:1:1:1:1:199 prefix-length 96
Router(config)#ipv6 nat v4v6 source list IPV4 pool IPV6
Router(config)#ipv6 nat v6v4 source 1001:1:1:1::1 1.1.1.1
Router(config)#ipv6 nat v6v4 source 1001:1:1:12::1 1.1.12.1
```
1. 목적지 IPv6에서 IPv4로 되돌아오는 패킷을 변화시키기 위해 IPv4 네트워크에서도 nat prefix를 지정한다.
2. 출발지 IPv4 주소 대역을 ip ACL로 지정한다. extended지만 standard나 넘버모드를 사용해도 된다.
3. ipv6 네트워크로 변환할 주소 대역을 nat pool로 설정한다. 1:0 ~ 1:199로 설정했다.
4. 위에서 설정한 IPv4 주소 대역과 IPv6 주소를 변환한다.
5. 마찬가지로 IPv4 네트워크 설정에서도 목적지 주소를 IPv6 출발과 동일한 정적 NAT로 설정해야한다. 