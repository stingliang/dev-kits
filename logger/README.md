# 轻量级日志

使用纯C++标准库和宏定义实现的轻量级日志系统，支持线程安全

在编译期间可以通过定义宏`LOGGER_LEVEL`来指定日志级别，默认为`INFO`

```cmake
add_definitions("-DLOGGER_LEVEL=TRACE")
```

```shell
mkdir build
cd build
cmake -DLOGGER_LEVEL=TRACE ..
```
