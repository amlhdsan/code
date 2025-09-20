You are given an array $a$ of $n$ positive integers. Alice and Bob will play a game with this array. They will take alternating turns, with Alice going first.

At each turn, the player must choose a value $x&gt;0$ that appears in $a$ at least once. Then,

1.  the player earns $1$ point for each value $x$ in the array,
2.  each value $x$ in the array is decreased by $1$ and becomes $x-1$.

Note that the player can choose $x$ only if it is present in $a$ at the moment, so each valid move earns a positive amount of points. For example, if the array is $[3,8,5,8]$ and Alice chooses $x=8$, the array will become $[3,7,5,7]$ and Alice will earn $2$ points.

The game ends when no $x$ can be chosen; that is, when all the elements in the array are zero.

Given that both players want to maximize their points and play optimally, calculate the amount of points that each player will end up with.
**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^3$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2\cdot 10^{5}$) — the size of the array.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^{9}$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^{5}$.
**Output**

For each test case, output two integers, the amount of points Alice and Bob will get if both play optimally.