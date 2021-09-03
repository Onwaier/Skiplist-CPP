注：本项目是在原项目[Skiplist-CPP](https://github.com/youngyangyang04/Skiplist-CPP)基础上进行修改.

# 修改说明

1. 使用智能指针（shared_ptr）进行内存管理，避免内存泄漏

2. 修复bug,参考[issue](https://github.com/youngyangyang04/Skiplist-CPP/issues/1)

3. 修改接口 `insert_element`,允许修改已重复键的值

4. 引入线程安全，读共享(查询和展示)，写互斥(插入和删除)

# [English Version](./README-en.md)

# KV存储引擎

众所周知，非关系型数据库redis，以及levedb，rockdb其核心存储引擎的数据结构就是跳表。

本项目就是基于跳表实现的轻量级键值型存储引擎，使用C++实现。插入数据、删除数据、查询数据、数据展示、数据落盘、文件加载数据，以及数据库大小显示。

在随机写读情况下，该项目每秒可处理啊请求数（QPS）: 24.39w，每秒可处理读请求数（QPS）: 18.41w

# 项目中文件

* main.cpp 包含skiplist.h使用跳表进行数据操作
* skiplist.h 跳表核心实现
* README.md 中文介绍    
* README-en.md 英文介绍       
* bin 生成可执行文件目录 
* makefile 编译脚本
* store 数据落盘的文件存放在这个文件夹 
* stress_test_start.sh 压力测试脚本
* LICENSE 使用协议

# 提供接口

* insertElement（插入数据）
* deleteElement（删除数据）
* searchElement（查询数据）
* displayList（展示已存数据）
* dumpFile（数据落盘）
* loadFile（加载数据）
* size（返回数据规模）
