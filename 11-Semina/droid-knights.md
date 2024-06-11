# 컴포즈 구조

## 컴포즈 컴파일러
2.0부터 컴포즈 버전과 코틀린 버전이 같아짐

## 컴포즈 런타임

## 컴포즈 UI

## Composable
Composable 함수는 표준 함수와 다르게 재실행이 가능함 (recomposition)

### recomposition을 확인하는 방법
1. 관찰 중인 State의 변경
2. Composable 함수 매개변수 변경

### Stable & Unstable
- Stable
  - Primitive types
  - 람다식으로 표현되는 함수
  - class의 public property가 불변이거나 stable한 경우

```kt
data calss User(
   val id: Int,
   val name: String
)
```

- Unstable
  - 모든 인터페이스 (List, Map etc...)
  - class의 public property 중 하나 이상이 가변적이거나 unstable한 경우

  ```kt
  data calss User(
     val id: Int,
     var name: String
  )
  ```

### Smart Recomposition
데이터 타입이 stable하면 recomposition을 생략

### 최적화
불필요한 recomposition을 최소화해서 최적화할 수 있음

### Restartable & Skippable
재시작할 수 있거나 스킵할 수 있는 함수여야 건너뛰어서 최적화할 수 있음

### Compose Compiler Metrics
stable인지 unstable인지 등의 정보를 지표로 나타내줌
[link](bit.ly/3V2Q1wB)

### Stability Annotations
- @Immutable
  - 절대 수정이 발생하지 않는 경우
  - 모든 property가 불변임을 나타내는 강력한 약속임
  - 모든 public property에 대해 val keyword를 사용해야 함
  - property 중 인터페이스 (List etc..)가 있어서 컴파일러가 Unstable로 분류했어도 바뀔 일이 없다는 판단하에 @Immutbale을 붙여서 Stable하게 만들 수 있음

- @Stable
  - 잠재적인 가변성을 가질 수 있는 경우
  - 컴파일러에 대한 강력한 약속이지만 @Immutable보다는 느슨한 약속

- @NonRestartableComposable
  - recomposition의 영향을 받지 않아야 하는 composable 함수의 경우 사용
  - 표준 함수만을 호출하는 사례

- composable 함수에서 List를 사용하면 Unstable로 간주하며 상황에 따라 최적화를 위해 ImmutableList를 사용할 수 있음

### Stability Comfiguration File

### Multi Module에서의 문제
- Compose Stable Marker (Github)

### 안정성 끌어올리기
- 진입 경로
- 문제가 생기기 전에 마지막으로 실행된 함수

### 기기 특성 파악
국가, 언어, 네트워크 등

# API Mocking
- 카카오뱅크 안드로이드 개발자

## 필요한 이유
서버에서 배포 등의 이유로 잘못된 값을 줄 때 그 사이에서 다른 정보를 줄 수 있음

## Mocking의 방법
1. 테스트 코드
+ 완벽
- 시간이 오래 걸림

2. 임시로 데이터를 넣어줌
- 항상 빌드를 해야함
- 임시로 작성한 코드가 코드 리뷰까지 갈 수 있음

3. 백엔드 개발자에게 요청
+ 서버에서 임시 코드를 작성해서 빠르게 할 수 있음
- 테스트 서버가 아닌 경우 문제가 생길 수 있음

4. 도구 활용
+ Postman, Charles etc..
+ 네트워크 속도 조절 가능
+ 다양한 기능
- 초기 설정 어려움
- 항상 서버 역할을 할 PC가 필요함
- 스니핑, 스푸핑 방지 기능을 제거해야 함

## ADB Reverse

# 효율적인 Github Actions 배포 환경 만들기

- 김태성

## 개발 생명 주기 (SDLC)

## ktlint
- github actions 마켓플레이스에서

## 유닛 테스트

## 빌드 검사

## Git Tag로 빌드 파일 생성
- github actions에서 tags를 이용해서 feature/* 등으로 사용할 수 있음

## PR Comment
- comment의 생성 등을 트리거로 댓글의 내용을 불러와 ex) ./gradlew build 등의 내용인지를 확인하기

## Firebase App Distribution
- 특정 트리거를 기준으로 Firebase App Districution을 이용해서 업로드할 수 있음

## 마일스톤 생성
- 진척상황이 가시화 되지 않음
- 각 배포에 포함되는 PR이 무엇인지 알기 힘듬
- github actions에서 cron을 사용
- curl로 깃허브 API 직접 호출

## 릴리즈 브랜치 생성
- 수동으로 하면 다양한 실수를 할 수 있음
- cron ..

## Lint 검사

## 앱 배포
- 수동으로 하면 다양한 실수 ..
- 구글플레이 앱 배포도 github actions로 할 수 있음

## 릴리즈 노트 생성
- 수동으로 하면 규격화하거나 변경사항을 확인하는데 어려움이 있음
- .github/release.yml

## 다루지 않은 것들
- Build Profiling 등

# 플레이어 SDK 개발자의 Kotlin Multiplatform 도입기

## Kotlin/JS

## Expect actual

# No Silver Bullet

# LookAheadLayout

## SharedTransition

## Modifier.sharedElement()

## Modifier.sharedBounds()
