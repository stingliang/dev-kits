# use static libraries
set(Boost_USE_STATIC_LIBS ON)
# find boost
find_package(Boost REQUIRED COMPONENTS
        unit_test_framework
        log
        log_setup
        chrono
        system
        thread
        )