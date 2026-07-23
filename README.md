# LeetCode 题解

我的 LeetCode C++ 刷题记录，文件按「题号.题目名称.cpp」命名。

仓库中的代码以学习过程为主，部分题解仍在继续完善。

## 本地编辑环境

- C++20
- clangd
- VS Code

`.leetcode/leetcode_prelude.hpp` 仅用于在本地为 clangd 补充 LeetCode 平台提供的数据结构和常用头文件，不需要随题解提交到 LeetCode。

## 同步到 GitHub

完成题解后运行：

```bash
./sync-leetcode
```

也可以附带自定义提交信息：

```bash
./sync-leetcode "完成 236 二叉树的最近公共祖先"
```

在 VS Code 中可通过“终端 → 运行任务 → 同步 LeetCode 到 GitHub”执行相同操作。
