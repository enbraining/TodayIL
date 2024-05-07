호텔에서 층의 개수와 한 층에 있는 방의 수를 받아오고 엘리베이터에서 가까운 방부터 순서대로 채워나가면 된다.

```c
#include <iomanip>
#include <iostream>

int main() {
    int repeat;
    std::cin >> repeat;

	// 문제에서는 여러개의 데이터가 주어지므로 배열로 여러개를 저장했다.
    int h[repeat], w[repeat], n[repeat];

    for(int i = 0; i < repeat; i++) {
        int count = 0;
        std::cin >> h[i] >> w[i] >> n[i];

		// 가까운 방부터 순서대로 채워나가는 코드
        int y = 0, x = 0;
        for(int j = 1; j <= w[i]; j++) {
            for(int k = 1; k <= h[i]; k++) {
                count++;
                if(count == n[i]) {
                    y = k;
                    x = j;
                }
            }
        }
        
        // x의 경우 한자릿수라면 앞에 '0'을 붙여준다.
        std::cout << y;
        std::cout << std::setw(2) << std::setfill('0') << x << '\n';
    }

    return 0;
}
```