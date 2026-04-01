# Problem 079 - 链表也要传承！

**ACMOJ Problem ID**: 1661

## Table of Contents

- [Problem 079 - 链表也要传承！](#problem-079-链表也要传承)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1661. 链表也要传承！** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/079/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

```
相信奇迹的人，本身就和奇迹一样了不起。 ——《星游记》
```

众所周知，ACM班是有着长远传承的班级。

而链表家族的重要一员——单链表，表示，作为第零次机考的常驻嘉宾，自己也需要传承。

​于是，在本题中，你需要实现一个单链表 $L$ ，支持以下操作：

1. 在单链表第 $i$ 个数后面插入一个数 $x$ 

2. 删除单链表第 $i$ 个数

3. 将单链表的奇偶位相互交换，即，编号为 $2k-1$  和 $2k$ 的元素交换。若单链表长度为奇数，则剩下的最后一个元素无需交换。这个操作只能使用 $O(1)$ 的额外空间

4. 将单链表前 $i$ 个数整体往后移动 $x$ 位。这个操作只能使用 $O(1)$ 的额外空间。(保证不会超出) 

   (例： $a_1 \rightarrow a_2 \rightarrow a_3 \rightarrow a_4 \rightarrow a_5$ ，把单链表前 $2$ 个数整体往后移动 $2$ 位后，变为 $a_3 \rightarrow a_4 \rightarrow a_1 \rightarrow a_2 \rightarrow a_5$ )

5. 输出单链表第 $i$ 个数

6. 输出整个单链表，使用空格隔开

另外，在程序开始时，请先读入一个大小为 $n$ 的数组对单链表进行初始化。

请通过动态申请空间的方式完成单链表。在程序结束后，你应当释放所有动态申请的内存。

以下是可供参考的代码模板，也欢迎同学们自己完成全部代码。

```c++
#include<iostream>
using namespace std;

struct LinkedList {
    // todo: some variables here
    void initialize() {
        int n;
        scanf("%d", &n);
        int *a = new int[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        // todo

        delete[] a;
    }

    void insert(int i, int x) {
        // todo
    }

    void erase(int i) {
        // todo
    }

    void swap() {
        // todo
    }

    void moveback(int i, int x) {
        // todo
    }

    int query(int i) {
        // todo
    }

    void printAll() {
        // todo
    }

    void ClearMemory() {
        // todo
    }
};

int main() {
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        }
        else if(op == 2) {
            scanf("%d", &i);
            List.erase(i);
        }
        else if(op == 3) {
            List.swap();
        }
        else if(op == 4) {
            scanf("%d%d",&i, &x);
            List.moveback(i, x);
        }
        else if(op == 5) {
            scanf("%d", &i);
            printf("%d\n", List.query(i));
        }
        else if(op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}
```



**请务必使用单链表来完成本题**。助教会人工判断你的代码是否合法，若存在问题本题计零分。详细要求如下：

必须使用指针与结构体。

在单链表中，每个结点有一个数据元素和一个后继指针组成，后继指针指向存储该元素直接后继的结点。**单链表只保存直接后继的关系**。

### Input Format

第一行一个自然数 $n$ ，代表初始化数组大小。

第二行 $n$ 个整数，代表初始化数组。

​第三行一个自然数 $m$ ，代表操作数。

​接下来 $m$ 行每行第一个数为 $op$ ，表示操作类型。

- $op = 1$，执行操作1，接下来读入两个整数 $i$，$x$ 
- $op = 2$，执行操作2，接下来读入一个整数 $i$ 
- $op = 3$，执行操作3
- $op = 4$，执行操作4，接下来读入两个整数 $i$，$x$ 
- $op = 5$，执行操作5，接下来读入一个整数 $i$ 
- $op = 6$，执行操作6

### Output Format

对于每个操作5，操作6，一行输出操作的答案。（注意对于每一个操作，输出后**需要换行**）

### Samples

#### Sample 1

**Input:**
```
10
1 2 3 4 5 6 7 8 9 10
9
6
5 2
2 2
1 4 20
6
3
6
4 2 3
6
```

**Output:**
```
1 2 3 4 5 6 7 8 9 10
2
1 3 4 5 20 6 7 8 9 10
3 1 5 4 6 20 8 7 10 9
5 4 6 3 1 20 8 7 10 9
```

### Data Constraints

​$1\leq n,m\leq1000$ 

保证每个链表元素均在`int`范围内。

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/079/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
