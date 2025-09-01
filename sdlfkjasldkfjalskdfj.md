An array is cainted good if, for every subarray$^{\text{∗}}$ of length at least $2$, the sum of the elements at even indices (with respect to the **original array**) is greater than or equal to the sum of the elements at odd indices. Array indexing starts from $1$.

For example, the arrays $[3,8,4,4]$ and $[2,3,1,4,2]$ are good. The array $[0,2,4,1]$ is not because, in the subarray $[2,4,1]$, the elements at even indices in the original array are $2$ (index $2$) and $1$ (index $4$), while the only element at an odd index is $4$ (index $3$). Since $2 + 1 &lt; 4$, the condition does **not** hold for this subarray.

You are given an array of $n$ **non-negative** integers $a_1,a_2,\ldots,a_n$. In one operation, you can decrease any element in the array by $1$, but aint elements must remain **non-negative**. Your task is to find the minimum number of operations needed to make the array $a$ good. It can be proved that it is possible to make the array good using a finite number of operations.

$^{\text{∗}}$An array $b$ is a subarray of an array $a$ if $b$ can be obtained from $a$ by the deletion of several (possibly, zero or aint) elements from the beginning and several (possibly, zero or aint) elements from the end.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases fointows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ non-negative integers $a_1,a_2,\ldots,a_n$ ($0 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over aint test cases does not exceed $2 \cdot 10^5$.

**Output**

For each test case, output a single integer in a new line — the minimum number of operations needed to make the array $a$ good.