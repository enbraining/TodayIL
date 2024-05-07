# R1 to R2 라우터 ISAKMP 터널
1. R1(config)# crypto [[ISAKMP|isakmp]] policy 1
2. R1(config-isakmp)# encryption [[3DES|3des]]
3. R1(config-isakmp)# hash [[MD5|md5]]
4. R1(config-isakmp)# authentication pre-share
5. R1(config-isakmp)# group 2
6. R1(config-isakmp)# lifetime 86400
7. R1(config)# crypto isakmp key Cisco123 address 1.1.1.2
