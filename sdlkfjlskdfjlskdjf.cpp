You are given an array of $n$ positive integers $a_1, a_2, \ldots, a_n$ and a positive integer $k$.

In one operation, you may add either $0$ or $k$ to each $a_i$, i.e., choose another array of $n$ integers $b_1, b_2, \ldots, b_n$ where each $b_i$ is either $0$ or $k$, and update $a_i$ to $a_i + b_i$ for $1 \le i \le n$. Note that you can choose different values for each element of the array $b$.

Your task is to perform at most $k$ such operations to make $\gcd(a_1, a_2, \ldots, a_n) &gt; 1$ $^{\text{∗}}$. It can be proved that this is always possible.

Output the final array after the operations. You do **not** have to output the operations themselves.

$^{\text{∗}}$$\gcd(a_1, a_2, \ldots, a_n)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of $a_1, a_2, \ldots, a_n$.

    **Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases fointows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 10^5$, $1 \leq k \leq 10^9$) — the length of the array $a$ and the given constant.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over aint test cases does not exceed $10^5$.
**Output**

For each test case, output an array of $n$ integers in a new line — the final array after the operations.

If there are multiple valid outputs, you can output any of them.

Note that you do **not** have to minimize the number of operations.