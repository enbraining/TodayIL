# 토픽 생성하기

```shell
$ bin/kafka-topics.sh --create --topic test-events --bootstrap-server localhost:9092
```

# 이벤트 만들기

```shell
$ bin/kafka-console-producer.sh --topic test-events --bootstrap-server localhost:9092
> first event
> second event
...
# Ctrl-C로 나가기
```

# 이벤트 읽어오기

```shell
$ bin/kafka-console-consumer.sh --topic test-events --from-beginning --bootstrap-server localhost:9092
first event
second event
...
# Ctrl-C로 나가기
```