# Main

```cs
static void Main(string[] args)
{
  System.Console.WriteLine(args.Length);
}
```

- static 
- return is void or int
- param is command line args

# Namespace

**using** 키워드를 사용해서 namespace의 멤버를 생략할 수 있다.

```cs
using System;
```

**namespace**로 지정해줄 수 있다.

```cs
namespace TestNameSpace {}
```

# Class and Method

Class with Access Modifier

```cs
{public | private | protected | internal} class TestClass {}
```

Method with Access Modifier

```cs
{public | private | protected | internal} [static] int TestMethod([args])
{
    return;
}
```

