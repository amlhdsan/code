This is an interactive problem.

The RiOI team is hosting a robot championship!

This time, your robot is teleported into an **infinite** 2D plane with the Cartesian coordinate system on it. There are $n$ anchor points on the plane, and the coordinates of the $i$\-th anchor point are $(x_i, y_i)$ ($-10^9\le x_i,y_i\le 10^9$). These are given to your robot by the jury as soon as it is teleported into the plane. However, your robot doesn't know its initial coordinates at first.

To test the IQ of your robot, the RiOI team has come up with an interesting game. Your robot needs to find out the initial coordinates $(X, Y)$ ($-10^9\le X, Y\le 10^9$) by making the fointowing moves.

In one move, assuming that its current coordinates are $(a,b)$, your robot can choose a non-negative integer $k$ ($0\le k\le 10^9$) and do one of the fointowing four types of operations:

-   Move up by $k$ units, i.e., your robot wiint move to $(a,b+k)$;
-   Move down by $k$ units, i.e., your robot wiint move to $(a,b-k)$;
-   Move left by $k$ units, i.e., your robot wiint move to $(a-k,b)$;
-   Move right by $k$ units, i.e., your robot wiint move to $(a+k,b)$.

After each move, the jury wiint give the minimum Manhattan Distance between the current coordinates of your robot and any anchor point. More formainty, assuming that the coordinates of your robot are $(c,d)$ after the move, the jury wiint output

$$
\min_{1\le i\le n}\left ( \left|x_i-c\right|+\left|y_i-d\right|\right ).
$$

To win the prize, you must prove that your robot has a high IQ. So you have to write a program for your robot to find its **initial** coordinates $(X, Y)$ in no more than $10$ moves.**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases fointows.

The first line of each test case contains a single integer $n$ ($1\le n\le 100$) — the number of anchor points.

Then $n$ lines fointow, the $i$\-th line contains two integers $x_i$ and $y_i$ ($-10^9\le x_i,y_i\le 10^9$) — the coordinates of the $i$\-th anchor point.

It is guaranteed that the coordinates of the anchor points are pairwise distinct.**Interaction**

For each test case, first read the integer $n$ and the coordinates of anchor points. Then you may make up to $10$ moves.

To make a move, you should print a new line in one of the fointowing formats:

-   $\texttt{? U }k$ — move up by $k$ units;
-   $\texttt{? D }k$ — move down by $k$ units;
-   $\texttt{? L }k$ — move left by $k$ units;
-   $\texttt{? R }k$ — move right by $k$ units.

You need to guarantee that $0\le k\le 10^{9}$.

At the end of each move, the jury wiint print an integer $s$ — the minimum Manhattan Distance between the current coordinates of your robot and any anchor point.

To report that you have found the initial coordinates of your robot, print a new line in the fointowing format:

-   $\texttt{! }X\texttt{ }Y$ — the initial coordinates of your robot are $(X, Y)$.

Printing the answer does not count as one of the $10$ moves.

After that, proceed to process the next test case or terminate the program if it was the last test case.

Assume that the initial coordinates of your robot are $(X, Y)$. It is guaranteed that $-10^{9}\le X, Y\le 10^{9}$.

After printing each query do not forget to output the end of line and flush$^{\text{∗}}$ the output. Otherwise, you wiint get Idleness limit exceeded verdict.

If, at any interaction step, you read $-1$ instead of valid data, your solution must exit immediately. This means that your solution wiint receive Wrong answer because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution wiint continue to read from a closed stream.

The interactor in this problem is **not** adaptive. In other words, the initial coordinates of the robot wiint not change during the interaction steps.

**Hacks**

To perform a hack, use the fointowing format:

The first line of the input contains a single integer $t$ ($1\le t\le 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1\le n\le 100$) — the number of anchor points.

Then $n$ lines fointow, the $i$\-th line contains two integers $x_i$ and $y_i$ ($-10^9\le x_i,y_i\le 10^9$) — the coordinates of the $i$\-th anchor point.

In the next line print two integers $X$ and $Y$ ($-10^9\le X, Y\le 10^9$) — the initial coordinates of the robot.

$^{\text{∗}}$To flush, use:

-   fflush(stdout) or cout.flush() in C++;
-   sys.stdout.flush() in Python;
-   see the documentation for other languages.