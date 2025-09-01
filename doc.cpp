% !TeX encoding = UTF-8
% !TeX program = xelatex
% !TeX spellcheck = en_US


\documentclass{exam-zh}
\usepackage{siunitx}

\examsetup{
  page = {
    size            = a3paper,
    show-columnline = true
  },
  style/fullwidth-stop = catcode,
  sealline = {
    show        = true,
    scope       = mod-3,
    circle-show = false,
    line-type   = solid,
    odd-info-content = {
      {\heiti \zihao{4}姓名} {\underline{\hspace*{8em}}},
      {\heiti \zihao{4}准考证号} {\examsquare{9}},
      {\heiti \zihao{4}考场号} {\examsquare{2}},
      {\heiti \zihao{4}座位号} {\examsquare{2}},
    },
    odd-info-xshift = 12mm,
    text = {此卷只装订不密封},
    text-width = 0.98\textheight,
    text-format  = \zihao{-3}\sffamily,
    text-xshift = 20mm
  },
  square = {
    x-length = 1.8em,
    y-length = 1.6em
  }
}


% 行内公式统一按照行间的样式
\everymath{\displaystyle}

\title{辅礽第一卷 · 铜陵一中 2025 级高一入学信心卷}

\subject{数学学科}


\begin{document}

% \tableofcontents

% \chapter{2026 年辅礽十省联考}

% \information{
%   姓名\underline{\hspace{6em}},
%   座位号\underline{\hspace{15em}}
% }
% \warning{（在此卷上答题无效）}

\secret

\maketitle

本试卷共 6 页，19 题。全卷满分 150 分。考试时间 240 分钟。

出卷方：辅礽考试院


\begin{notice}
  \item 答题前，先将自己的姓名、准考证号、考场号、座位号填写在试卷和答题卡上，并将准考证号条形码粘贴在答题卡上的指定位置。
  \item 选择题的作答：每小题选出答案后，用 2B 铅笔把答题卡上对应题目的答案标号涂黑。
    写在试卷、草稿纸和答题卡上的非答题区域均无效。
  \item 填空题和解答题的作答：用黑色签字笔直接答在答题卡上对应的答题区域内。
    写在试卷、草稿纸和答题卡上的非答题区域均无效。
  \item 考试结束后，请将本试卷，答题卡以及草稿纸一并上交。
  \item 考试严禁作弊，包括但不限于传抄答案，使用电子设备等，一经发现立即满分处理。
  \item 本卷的考察范围：必修一前三章、其他基础初等数学内容
\end{notice}



\section{%
  选择题：本题共 8 小题，每小题 5 分，共 40 分。
  在每小题给出的四个选项中，只有一项是符合题目要求的。
}
\begin{question}
    已知集合$A=\{x|2<x<5\}$, 集合$B=\{x|x\ge3\}$, 则$A\cap B=$ \paren
    \begin{choices}
        \item    $\{x|3\le x<5\}$
        \item    $\{x|x>2\}$
        \item    $\{x|x\le2\}$
        \item    $\{x|2<x\le3\}$
    \end{choices}
\end{question}

\begin{question}
    从集合$\{1,2,3,4,5,6,7,8,9\}$中随机地取四个互不相同的数，则其中任意两个数之和均不等于10的概率为 \paren
    \begin{choices}
        \item    $\frac{1}{4}$
        \item    $\frac{5}{21}$
        \item    $\frac{8}{21}$
        \item    $\frac{2}{3}$
    \end{choices}
\end{question}

\begin{question}
    函数$f(x)= \sqrt{2x^2+2} +x$的最小值为 \paren
    \begin{choices}
        \item    $2\sqrt{2}$
        \item    $2\sqrt{3}-1$
        \item    $\sqrt{6}$
        \item    $5 + 16$
    \end{choices}
\end{question}

\begin{question}
    定义在$\mathbb{R}$上的函数$f(x)$满足$f(x+1)= \frac{1}{2} + \sqrt{f(x)-[f(x)]^2}$ ,则$f(0)+f(2017)$的最大可能值为 \paren
    \begin{choices}
        \item    $\frac{\sqrt{5}-1}{2}$
        \item    $\frac{\sqrt{6}}{2}$
        \item    $\frac{3\sqrt{3} - 1008}{2017}$
        \item    $1+\frac{\sqrt{2}}{2}$
    \end{choices}
\end{question}

\begin{question}
    设a、b、c为正数，$a<b$，若a,b为一元二次方程 $ax^2-bx+c =0$的两个根，且a,b,c是一个三角形的三边长，则$a+b-c$的取值范围是 \paren
    \begin{choices}
        \item    $(\frac{21}{16}, 2)$
        \item    $(\frac{21}{16}, +\infty)$
        \item    $(\frac{7}{8}, \frac{\sqrt{5}-1}{2})$
        \item    $(\frac{5}{8}, \frac{\sqrt{2}+1}{2})$
    \end{choices}
\end{question}

\begin{question}
    若函数$f(x)= (2x^5+2x^4-53x^3-57x+54)^{2018}$ （$x\in\mathbb{R}$），则$f\left(\frac{\sqrt{11}-1}{2}\right)=$ \paren
    \begin{choices}
        \item    0
        \item    1
        \item    2
        \item    -1
    \end{choices}
\end{question}

\begin{question}
    已知A、B、C为$\{1,2,3,4,5,6,7\}$的子集，且满足两两交集中元素个数为1，$A\cap B\cap C=\emptyset$，则这样的三元组（A,B,C）（无序）的个数为 \paren
    \begin{choices}
        \item    14400
        \item    42300
        \item    53760
        \item    64230
    \end{choices}
\end{question}

\begin{question}
    集合$M=\{a\in\mathbb{Z} | a= \frac{x+y+z}{t} , 3^x+3^y+3^z=3^t ,x,y,z,t\in\mathbb{Z} \}$中所有元素之和为 \paren
    \begin{choices}
        \item    6
        \item    9
        \item    12
        \item    15
    \end{choices}
\end{question}



\section{%
  选择题：本题共 3 小题，每小题 6 分，共 18 分。
  在每小题给出的选项中，有多项符合题目要求的。
  全部选对的得 6 分，部分选择的得部分分，有选错的得 0 分。
}

\begin{question}
    以下数中，在函数$f(x)= \frac{x(x^2+8)(8-x)}{x+1}$ 的值域内的是 \paren
    \begin{choices}
        \item    0
        \item    3
        \item    6
        \item    9
    \end{choices}
\end{question}

\begin{question}
    已知数列$\{ a_n \}$满足：$a_1 =1， a_2 =9， a_{n+2} =10 a_{n+1} - a_n$,其中n为正整数。则下列给出的n中，满足 $a_n$ 不是3的方幂的是（即不存在非负整数k使得 $a_n = 3^k$ ） \paren
    \begin{choices}
        \item    1
        \item    18
        \item    57
        \item    126
    \end{choices}
\end{question}

\begin{question}
    如果正整数n使得任意不同于n的正整数m，均有$\{ \sqrt{2}n \} \neq \{ \sqrt{2}m \}$，则称n为“好数”，这里$\{x\}$表示x的小数部分。则下列形式的n中，一定是好数的是 \paren
    （其中，k,t为任意正整数，p为奇素数）
    \begin{choices}
        \item    $n= (2^{2k}+1)^2$
        \item    $n= 2^k \cdot 3^t$
        \item    $n= \frac{2^{2k}-1}{3}$
        \item    $n= \frac{3^p+2^p}{5}$
    \end{choices}
\end{question}


\section{填空题：本题共 3 小题，每小题 5 分，共 15 分。}

\begin{question}
    若函数$f(x)=2018-a x^2$（$a>0$）的图像与x轴围成的封闭图形内部和边界共有 $2018^2$ 个整点（横纵坐标都是整数的点），则a的取值范围为 \fillin{               }。
\end{question}

\begin{question}
    已知非负整数a,b,c,d满足 $a^2+b^2+c^2+d^2 =20$,则 $(a+b+c+d)^2 \cdot \left(\frac{1}{a^2+3}+\frac{1}{b^2+3}+\frac{1}{c^2+3}+\frac{1}{d^2+3}\right)$的最大值为 \fillin{               }。
\end{question}

\begin{question}
    从前2008个正整数构成的集合$M=\{1,2，...，2008\}$中取出一个k元子集A，使得A中任意两个元素之和都不能被它们的差（取正值）整除，则k的最大值为 \fillin{               }。
\end{question}


\section{解答题：本题共 5 小题，共 77 分。解答应写出文字说明、证明过程或者演算步骤。}

% 15.
\begin{problem}[points = 13]
  已知$a>0, 12a+5b+2c>0$，证明：关于x的一元二次方程 $ax^2+bx+c =0$在（2,3）上不可能有两个不同的实数根。  
  
  {
    \includegraphics[width=12cm]{white.png}
  }
\end{problem}

% 16.
\begin{problem}[points = 15]
  设二次函数$f(x)= x^2+bx+c$，已知对任意实数b，均存在实数$x\in[1,2]$,使得不等式$|f(x)|\ge x$成立，求实数c的取值范围。
  {
    \includegraphics[width=12cm]{white.png}
  }
\end{problem}

% 17.
\begin{problem}[points = 15]
  解方程：$ \frac{3x}{3+\sqrt{8x-3}} + \frac{3x}{3-\sqrt{8x-3}}  = 1$

  {
    \includegraphics[width=30cm]{white.png}
  }
\end{problem}

% 18.
\begin{problem}[points = 17]
    \begin{enumerate}
        \item 已知$x,y>0$，求证：当$x\ge y$时 $\frac{x}{y}\ge\frac{x+1}{y+1}$ ;当$x\le y$时， $\frac{x}{y}\le\frac{x+1}{y+1}$ 。
        
        \item 已知 $a_1,a_2,...,a_n >0$，令 $a_{n+1} = a_1$，证明：
        $$ \frac{a_2}{a_1}+\frac{a_3}{a_2}+...+\frac{a_n}{a_{n-1}}+\frac{a_{n+1}}{a_n} \ge \frac{\sqrt{a_2^2+1}}{\sqrt{a_1^2+1}}+\frac{\sqrt{a_3^2+1}}{\sqrt{a_2^2+1}}+...+\frac{\sqrt{a_n^2+1}}{\sqrt{a_{n-1}^2+1}}+\frac{\sqrt{a_{n+1}^2+1}}{\sqrt{a_n^2+1}} $$
    \end{enumerate}
  {
    \includegraphics[width=28cm]{white.png}
  }
\end{problem}

% 19.
\begin{problem}[points = 17]
  设A、B为正整数，S是由一些正整数构成的一个集合，具有以下性质：
    \begin{enumerate}
        \item  对任意非负整数k，有 $A^k \in S$；
        \item   若正整数$n\in S$，则n的每个正因数均属于S；
        \item  若$m,n\in S$，且m,n互素（m,n的最大公因数为1），则$mn\in S$；
        \item 若$n\in S$，则$An+B\in S$.
    \end{enumerate}
    （已知裴蜀定理：对任意互素的正整数a,b，一定存在整数x,y使得ax+by=1）
    \begin{enumerate}
        \item A=1时，证明：任意与B互素的正整数m均属于S；
        \item A>1时，证明：若$n\in S$，则 $A^k n + B\frac{A^k-1}{A-1} \in S$ ，其中k为任意正整数；
        \item A>1时，证明：与B互素的所有正整数均属于S。
    \end{enumerate}  
  {
    \includegraphics[width=20cm]{white.png}
  }
\end{problem}

\end{document}