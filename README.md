[![Actions Status](https://github.com/AlfredChester/cpp-templates/workflows/verify/badge.svg)](https://github.com/AlfredChester/cpp-templates/actions)

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://alfredchester.github.io/cpp-templates/) 

# Alfred 个人代码库

本仓库借鉴了[南京大学 ACM-ICPC 代码库](https://github.com/nju-icpc/code-library-legacy/) 和 [online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper) 的结构及相关代码，在此表示由衷感谢。

## 重要注意事项及已知的bug

* 为了代码库的整洁、复用，我们要求代码中**不得存在非const的全局变量**，并且**所有中间结果都必须以显式的方式保存下来**。这么做让使用者不需要修改任何代码就能直接使用多种功能，而且允许存在同时运行同一代码库的多个实例而不用手工初始化全局状态。举例来说，一个好的最短路径算法在返回最短路径长度的同时，还以一个vector返回从起点到终点的一条最短路径。这么做所带来的性能损失微乎其微，但却能极大地方便使用者。在这一点上，Watashi的代码做得非常优秀，值得参考。

* 由于listings宏包和XeCJK之间衔接的问题，代码注释的中英文混排可能会出现一些非预期的问题，例如
        /* 将x赋值为1 */

    可能会显示为

        /* 将赋值为x1 */

    为解决这个问题，可以在英文单词后加一个空格: /* 将x 赋值为1就可以了 */

* 希望贡献代码的同学可以使用git标准的合作开发方法，在添加了代码后向该项目发起pull request。如果你只是简单地发现bug或者想在库中添加一些代码，可以将相关的内容直接在issue中写出来。希望通过我们的合作，能让代码库越来越完善。

## 代码库结构

所有代码都应当使用UTF-8编码。

代码文件存放在`src/`目录下。按照子目录分类存放。

代码库的描述文件保存在`scl.yaml`。代码库分为两级，对应`src/`里的子目录。例如：

```
- name: 比赛配置
  dir: config/
  files:
    - title: 代码库校验和
      fname: checksum.py
      desc: |
        计算每一行忽略空白字符和\texttt{//}注释后内容的MD5 Hash。
        使用\texttt{python checksum.py < code.cpp}打印校验和,并与代码库侧面的数值比对。
    - title: Vim配置文件
      fname: vimrc
```

对应了“比赛配置”的Section，指定目录是`src/config/`，为每一个文件指定title (标题)、fname (文件名)、desc (详细描述，可选)。详细描述会被直接粘贴到LaTeX中编译。

## 代码库规范

我们推荐使用Google的编程规范，使代码库有一致的风格。英文原版的[链接](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml)供参考。具体与我们比较直接相关的是命名的规范：

* 变量名应使用小写，并能推断出名称的含义，例如`prime_count`, `current`等。使用缩写时应避免歧义。
* 结构体、类名应用混合大小写单词拼接，其中单词首字母大写，例如`Node`, `WeightedGraph`。
* 函数的名称应该混合大小写，例如`AddEntry`, `SolveLP`。
* 因为我们的程序相对独立，命名规范不用太过严格，只要在同程序中保持一致即可。

代码风格规范：

* 每行不能超过80个字符。过长的行应该想办法断成多行，避免过多层循环、条件的嵌套。如何断行请参考英文原版的Google编程规范，其中有定义、表达式等断行规则的详细说明。
* 不要使用tab，统一使用4个空格作为缩进。在我们的代码库中，程序中的tab会被转换为4个空格。
* 所有左大括号都不新起一行(节约空间)。
* 在二元运算符的左右都有空格；逗号分隔符右边有一个空格，程序中不应用多余的空格。例如a += f(b, c);。为了排版的美观，可以对这个规则做适当的变通，例如以下的写法都是可以的：

        x = -5;
        ++x;
        if (x && !y)
        v = w * x + y / z;
        v = w*x + y/z; 

还有一些基本原则：

* 变量尽量只在局部起作用(减少作用域)，这避免了引用错变量的麻烦，变量应该在定义时初始化。
* 警惕使用自增和自减运算符。
* 多使用`const`修饰变量，减少错误的可能。
* 在不同的场合使用`0`, `0.0`, `NULL`, `'\0'`减少程序的歧义。
* 使用`sizeof(变量)`而不是`sizeof(类型)`。

为了代码库的精确、好用，我们还有一些额外的要求，在整理代码库时可做参考：

* 在每一个程序的头部都应该以注释的方式描述程序的行为：参数如何输入、对输入有什么特别的要求、输出什么。如果有可能，应该大致描述算法的实现，以及中间结果有哪些可能可以利用。
* 说明每一个函数依赖其他哪些函数、类或结构体，这样就可以避免在很大的代码库中录入多余的代码。

## 代码库编译方法

* 编译环境: Linux/Mac OS X, texlive xelatex (Windows未测试)
* 编译方法: 使用make工具编译。由于每一行代码的fingerprint使用了label，在添加新的代码后需要编译两次(Makefile中默认编译两次)
* 编译环境: xelatex & xecjk
* 编译需要以下字体：宋体(SimSun)、黑体(SimHei)和Courier New。如果系统中不包含此字体，可以在`format.tex`中修改。
