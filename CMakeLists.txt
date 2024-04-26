cmake_minimum_required(VERSION 3.25)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/2.两数相加.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/3.无重复字符的最长子串.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/6.z-字形变换.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/7.整数反转.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/8.字符串转换整数-atoi.cpp")
target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/11.盛最多水的容器.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/14.最长公共前缀.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/20.有效的括号.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/21.合并两个有序链表.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/28.找出字符串中第一个匹配项的下标.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/42.接雨水.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/102.二叉树的层序遍历.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/103.二叉树的锯齿形层序遍历.cpp")
# target_sources(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/206.反转链表.cpp")
