# 요약
Publisher에게 전달받은 메시지를 Subscriber에게 전달해주는 역할을 하며 응용 소프트웨어 사이에서 메시지를 교환할 수 있게 해준다. 메시지가 쌓이는 공간을 Message Queue, 메시지의 그룹을 Topic이라고 한다.

대표적인 메시지 브로커로는 RabbitMQ, Apache Kafka 등이 있다.
## Producer/Consumer Pattern
작업을 생산하는 역할과 작업을 처리하는 역할을 나누기 위한 패턴이다. Producer는 작업을 만들어 큐에 쌓고, Consumer은 큐에서 작업을 꺼내서 처리한다.
