cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

project(Variadic_Templates)

#set(BOOST_INCLUDEDIR "F:/Boost/include/boost-1_64")
#set(BOOST_LIBRARYDIR "F:/Boost/lib")

#find_package(Boost 1.64.0 REQUIRED COMPONENTS
#        thread)
add_executable(Variadic_Templates main.cpp)

# link against the boost libraries
#target_link_libraries( Variadic_Templates
#        PRIVATE
#        Boost::thread
#        )