# downTo

다음은 1676 - 팩토리얼 0의 개수 문제이다. 맨 끝에 있는 0의 개수를 판단하기 위해서 downTo를 사용했다.

```kotlin
import java.math.BigInteger
import java.util.Scanner

fun main() {
	val scan = Scanner(System.`in`)

	val n = scan.nextInt()
	var count = 0
	var fat: BigInteger = BigInteger.ONE

	for(i in 2..n) {
		fat = fat.multiply(BigInteger(i.toString()))
	}

    // fat.toString().length가 5일때 4부터 0까지
	for(i in fat.toString().length - 1 downTo 0) {
		if(count != 0 && fat.toString()[i] != '0') break
		if(fat.toString()[i] == '0') count++
	}

	println(count)
}
```