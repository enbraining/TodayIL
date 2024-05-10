# instance

```cs
Test test = new Test();
```

# access modifier

|type|content|
|---|---|
|public|제한 X|
|protected|해당 클래스 및 파생 클래스|
|internal|해당 프로그램|
|private|해당 클래스|

# inheritance

```cs
public class Parent {}
public class Child: Parent {}
```

# constructor

```cs
public class Test 
{
    public void Test(int i){}
}
```

# boxing

```cs
int i = 100;
object o = i;
```

# unboxing

```cs
int j = (int)o;
```