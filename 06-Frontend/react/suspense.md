어떤 작업이 끝날 때까지 기다리지 않고 다른 컴포넌트부터 렌더링할 수 있는 기술이다.

```js
// Posts 함수를 바로 실행한다.
<Posts />

// Posts 함수의 작업이 끝날 때까지 Loading 함수를 보여준다.
<Suspense fallback={<Loading />}>
    <Posts />
</Suspense>
```