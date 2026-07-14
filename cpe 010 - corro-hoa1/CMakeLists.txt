cmake_minimum_required(VERSION 4.2)
project(cpe_010___corro)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ILOA_1
        ILOA_1.cpp
        ILOA_1.h
        ILOA_3.cpp
        ILOA_3.h
        ILOB_1.cpp
        ILOB_1.h
        SUPP_1_CORRO.cpp
        SUPP_1_CORRO.h
        SUPP_2_CORRO.cpp
        SUPP_2_CORRO.h
        SUPP_3_CORRO.cpp
        SUPP_3_CORRO.h
        supp_4_CORRO.cpp
        supp_4_CORRO.h
)

add_executable(ILOA_2
        ILOA_2.cpp
        ILOA_2.h)

add_executable(ILOA_3 ILOA_3.cpp)

add_executable(ILOB_1 ILOB_1.cpp)

add_executable(SUPP_1_CORRO SUPP_1_CORRO.cpp)
add_executable(SUPP_2_CORRO SUPP_2_CORRO.cpp)
add_executable(SUPP_3_CORRO SUPP_3_CORRO.cpp)
add_executable(supp_4_CORRO supp_4_CORRO.cpp)


