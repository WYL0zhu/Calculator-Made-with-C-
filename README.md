# 用 C++ 做的计算器！
这里有一个用 C++ 做的计算器。
这个计算器很~~简陋~~**简单**，而且甚至连图片都没有。
## 使用说明
首先，你需要下载、编译（需要一个 C++ 编译器，*例如 gcc*）并运行 Calculator-Made-with-C-/Code/计算器.cpp。然后你会看见一个对话框。你需要在对话框里输入一个只能包含 “0123456789+-\*/^()” 的算式。

在你输入的算式中：
 + **“0123456789”** 代表数字。 *样例：123代表数字123。*
 + **“+”** 代表加法。 *样例：1+1代表1+1这个算式。*
 + **“-”** 代表减法。 *样例：1-1代表1-1这个算式。*
 + **“\*”** 代表乘法。 *样例：1\*1代表1\*1这个算式。*
 + **“/”** 代表除法。 *样例：1/1代表1/1这个算式。*
 + **“^”** 代表乘方。 *样例：1^1代表1的1次方这个算式。*
 + **“()”** 代表括号。括号里的内容先进行计算。括号可以嵌套，并且使用的都是“()”。 *样例：(1+1)\*1代表1+1的和乘1这个算式。*

注意：
 + 程序**不会**判断算式的错误。请输入正确的算式。
 + 输入**不能**包含浮点数（小数）。
 + 输入**不能**包含负数，但是结果可以。
 + 输入算式必须保证**任何**一步运算的结果的绝对值不会超过 **2的63次方-1**因为数据使用 ```long long```存储，而```long long```的存储范围在 -（2的63次方） 到 2的63次方-1 之间。否则会数据溢出，结果会产生错误。
 + 输入的内容中**第二行**为 Ctrl+Z，第一行会当做字符读进去，结果会错，所以请在第二行输入。
 + 输出分为**2**行，**第一行**为结果的分数形式，**第二行**为结果的小数形式。
