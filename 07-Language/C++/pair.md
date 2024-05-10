두가지의 데이터 쌍

utility 라이브러리에 있으며 algorithm | vector 라이브러리는 utility 라이브러리를 포함하고 있음.

```cs
#include <algorithm>

int main(){
    int a, b;
    std::cin >> a >> b;

    pair<int, int> c;
    c.first = a;
    c.second = b;

    std::cout << c.first << " " << c.second;
}
```