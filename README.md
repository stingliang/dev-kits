# dev-kits
>  sting's dev utility library

**Dependents**

|        Items        | Minimum version |
| :-----------------: | :-------------: |
| gcc / visual studio |   4.8 / 2015    |
|        cmake        |       3.0       |
|        Boost        |      1.68       |

**Usage with camke**

You can use development kits with cmake like as following:

```cmake
# cmake minimum version requirements
cmake_minimum_required(VERSION 3.0)
# project name
project(sample)
# cpp version
set(CMAKE_CXX_STANDARD 11)
# sting_dev library
add_subdirectory(dev-kits)
# executable files
add_executable(sample main.cpp)
# include path
target_include_directories(sample PUBLIC
        ${CMAKE_SOURCE_DIR}/dev-utility/core
        ${CMAKE_SOURCE_DIR}/sample
        )
# link to development kits
target_link_libraries(${PROJECT_NAME} PRIVATE devkits)
```

Just `git clone` it to your project and use `add_subdirectory(dev-utility)` to import

**components**

The development utility kits includes the following components:

- `logger`

  Lightweight log system based on boost log, try it as following:

  ```c++
  #include "logger/logger.h"
  
  #define SAMPLE_LOG(SEVERITY) LOGGER("Sample", SEVERITY)
  
  void logger_sample() {
      // construct a log_initializer
      auto config = devkits::log_initializer::log_config();
      // config log path
      config.log_path = R"(./log)";
      // config log severity
      config.severity = boost::log::trivial::trace;
      // don't forget to call 'init (log_config)' to make the configuration available
      devkits::log_initializer::init(config);
      
      // use '<<' to output log information
      SAMPLE_LOG(trace) << "A trace severity message";
      SAMPLE_LOG(debug) << "A debug severity message";
      SAMPLE_LOG(info) << "An informational severity message";
      SAMPLE_LOG(warning) << "A warning severity message";
      SAMPLE_LOG(error) << "An error severity message";
      SAMPLE_LOG(fatal) << "A fatal severity message";
  }
  ```

- `utility`

  Useful functions that can easily print STL, it's so easy that everyone who can print `Hello, World!` with cplusplus could use it easily as following:
  
  ```c++
  #include "utility/utility.h"
  
  void utility_sample() {
      std::map<int, std::string> _map {
          {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}
      };
      std::cout << "map: " << devkits::printStl(_map).str() << std::endl;
  
      std::vector<int> _vector { 1, 2, 3, 4, 5 };
      std::cout << "vector: " << devkits::printStl(_vector).str() << std::endl;
  }
  ```
  
  Of course, the elements in STL should be output through the "<<" operation
