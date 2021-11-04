# 调试STL

可以将STL中的、具有`begin()`、`end()`方法的迭代器“打印”出来

> 打印结果是返回一个`std::sstream`，而不是直接打印，由调用者决定输出到哪里（可能是日志）

```c++
#include "utility/utility.h"
#include "logger/logger.h"

int main() {
std::map<int, std::string> _map {
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}
    };

    std::cout << "map: " << devkits::printStl(_map).str() << std::endl;

    std::vector<int> _vector { 1, 2, 3, 4, 5 };
    std::cout << "vector: " << devkits::printStl(_vector).str() << std::endl;
}
```
运行结果：
```
====================[utility]====================
map: [1:one][2:two][3:three][4:four][5:five]
vector: [1][2][3][4][5]
```
