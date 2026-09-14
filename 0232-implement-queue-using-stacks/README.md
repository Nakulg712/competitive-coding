
<h2>
    <a href="https://leetcode.com/problems/implement-queue-using-stacks">
        232. Implement Queue using Stacks
    </a>
</h2>

<h3>Easy</h3>

<hr>

<p>
    Implement a first in first out (FIFO) queue using only two stacks.
    The implemented queue should support all the functions of a normal queue
    (<code>push</code>, <code>peek</code>, <code>pop</code>, and <code>empty</code>).
</p>

<p>Implement the <code>MyQueue</code> class:</p>

<ul>
    <li><code>void push(int x)</code> Pushes element x to the back of the queue.</li>
    <li><code>int pop()</code> Removes the element from the front of the queue and returns it.</li>
    <li><code>int peek()</code> Returns the element at the front of the queue.</li>
    <li><code>boolean empty()</code> Returns <code>true</code> if the queue is empty, <code>false</code> otherwise.</li>
</ul>

<p><strong>Notes:</strong></p>

<ul>
    <li>
        You must use <strong>only</strong> standard operations of a stack,
        which means only <code>push to top</code>, <code>peek/pop from top</code>,
        <code>size</code>, and <code>is empty</code> operations are valid.
    </li>

    <li>
        Depending on your language, the stack may not be supported natively.
        You may simulate a stack using a list or deque as long as you use only
        a stack's standard operations.
    </li>
</ul>

<br>

<h3>💡 Intuition</h3>

<p>
    A <strong>Queue</strong> follows <strong>FIFO</strong>:
    <strong>First In, First Out</strong>.
</p>

<p>
    A <strong>Stack</strong> follows <strong>LIFO</strong>:
    <strong>Last In, First Out</strong>.
</p>

<p>
    So, a stack gives us the opposite behavior of a queue.
    We can use <strong>two stacks</strong> to reverse the order of elements.
</p>

<p>
    Suppose we push:
</p>

<pre>
1 → 2 → 3
</pre>

<p>
    In the first stack, <code>3</code> is on top.
    If we move all elements to the second stack:
</p>

<pre>
Stack 1:  3 2 1
Stack 2:  1 2 3
</pre>

<p>
    Now <code>1</code> is on top of Stack 2, so we can remove
    <code>1</code> first, just like a queue.
</p>

<p>
    Therefore, the two stacks together help us convert
    <strong>LIFO behavior into FIFO behavior</strong>.
</p>

<h3>🔹 Approach</h3>

<ol>
    <li>
        Create two stacks:
        <code>s1</code> and <code>s2</code>.
    </li>

    <li>
        For <code>push(x)</code>, simply push the element into
        <code>s1</code>.
    </li>

    <li>
        For <code>pop()</code>, move all elements from <code>s1</code>
        to <code>s2</code>. This reverses their order.
    </li>

    <li>
        The top element of <code>s2</code> is now the front element
        of the queue.
    </li>

    <li>
        Remove and return the top element from <code>s2</code>.
    </li>

    <li>
        Move the remaining elements back from <code>s2</code> to
        <code>s1</code>.
    </li>

    <li>
        For <code>peek()</code>, perform the same transfer but return
        the top element without removing it.
    </li>

    <li>
        For <code>empty()</code>, simply check whether <code>s1</code>
        is empty.
    </li>
</ol>

<h3>🧠 C++ Code</h3>

<pre>
class MyQueue {
public:
    stack&lt;int&gt; s1, s2;

    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int front = s2.top();
        s2.pop();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return front;
    }

    int peek() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int front = s2.top();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return front;
    }

    bool empty() {
        return s1.empty();
    }
};
</pre>

<h3>⏱️ Time Complexity</h3>

<p>
    <strong>push(): O(1)</strong>
</p>

<p>
    We directly insert the element into <code>s1</code>.
</p>

<p>
    <strong>pop(): O(n)</strong>
</p>

<p>
    We move all <code>n</code> elements from <code>s1</code> to
    <code>s2</code> and then move the remaining elements back.
</p>

<p>
    <strong>peek(): O(n)</strong>
</p>

<p>
    Similar to <code>pop()</code>, we move the elements between
    the two stacks to access the front element.
</p>

<p>
    <strong>empty(): O(1)</strong>
</p>

<p>
    We only check whether <code>s1</code> is empty.
</p>

<h3>💾 Space Complexity</h3>

<p>
    <strong>O(n)</strong>
</p>

<p>
    We store all <code>n</code> queue elements inside the two stacks.
</p>

<br>

<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]

<strong>Output</strong>
[null, null, null, 1, 1, false]

<strong>Explanation</strong>

MyQueue myQueue = new MyQueue();

myQueue.push(1);
// queue is: [1]

myQueue.push(2);
// queue is: [1, 2]

myQueue.peek();
// return 1

myQueue.pop();
// return 1
// queue is: [2]

myQueue.empty();
// return false
</pre>

<br>

<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 &lt;= x &lt;= 9</code></li>
    <li>
        At most <code>100</code> calls will be made to
        <code>push</code>, <code>pop</code>, <code>peek</code>, and <code>empty</code>.
    </li>
    <li>
        All the calls to <code>pop</code> and <code>peek</code> are valid.
    </li>
</ul>

<br>

<p><strong>Follow-up:</strong></p>

<p>
    Can you implement the queue such that each operation is
    <strong>amortized O(1)</strong> time complexity?
</p>

<hr>

<h3>🎯 Quick Revision</h3>

<table border="1" cellpadding="8">
    <tr>
        <th>Topic</th>
        <th>Answer</th>
    </tr>

    <tr>
        <td>Data Structure</td>
        <td>Two Stacks</td>
    </tr>

    <tr>
        <td>Technique</td>
        <td>Reverse elements using two stacks</td>
    </tr>

    <tr>
        <td>Goal</td>
        <td>Implement FIFO Queue using LIFO Stacks</td>
    </tr>

    <tr>
        <td>push()</td>
        <td>O(1)</td>
    </tr>

    <tr>
        <td>pop()</td>
        <td>O(n)</td>
    </tr>

    <tr>
        <td>peek()</td>
        <td>O(n)</td>
    </tr>

    <tr>
        <td>empty()</td>
        <td>O(1)</td>
    </tr>

    <tr>
        <td>Space Complexity</td>
        <td>O(n)</td>
    </tr>
</table>

<br>

<h3>🧠 One-Line Interview Intuition</h3>

<p>
    <strong>
        "A queue needs FIFO, but a stack gives LIFO, so we use two stacks
        to reverse the order of elements and achieve FIFO behavior."
    </strong>
</p>
```
