<h2>
    <a href="https://leetcode.com/problems/sqrtx">69. Sqrt(x)</a>
</h2>

<h3>Easy</h3>

<hr>

<p>
    Given a non-negative integer <code>x</code>, return
    <em>the square root of </em><code>x</code>
    <em>rounded down to the nearest integer</em>.
    The returned integer should be <strong>non-negative</strong> as well.
</p>

<p>
    You <strong>must not use</strong> any built-in exponent function or operator.
</p>

<ul>
    <li>
        For example, do not use
        <code>pow(x, 0.5)</code> in C++ or
        <code>x ** 0.5</code> in Python.
    </li>
</ul>

<br>

<h3>💡 Intuition</h3>

<p>
    We need to find the largest integer whose square is less than or equal to
    <code>x</code>.
</p>

<p>
    For example, if <code>x = 8</code>:
</p>

<pre>
1 × 1 = 1
2 × 2 = 4
3 × 3 = 9
</pre>

<p>
    Since <code>3 × 3 = 9</code> is greater than <code>8</code>,
    the answer is <strong>2</strong>.
</p>

<p>
    Instead of checking every number one by one, we can use
    <strong>Binary Search</strong> because the square of numbers increases
    as the number increases.
</p>

<h3>🔹 Approach</h3>

<ol>
    <li>
        If <code>x</code> is <code>0</code> or <code>1</code>, return
        <code>x</code> directly.
    </li>

    <li>
        Set the search range:
        <code>left = 1</code> and <code>right = x / 2</code>.
    </li>

    <li>
        Calculate the middle element:
        <pre>mid = left + (right - left) / 2;</pre>
    </li>

    <li>
        Check <code>mid × mid</code>:
        <ul>
            <li>
                If <code>mid × mid == x</code>, return <code>mid</code>.
            </li>
            <li>
                If <code>mid × mid &lt; x</code>, search in the right half.
            </li>
            <li>
                If <code>mid × mid &gt; x</code>, search in the left half.
            </li>
        </ul>
    </li>

    <li>
        When the binary search ends, <code>right</code> contains the largest
        integer whose square is less than or equal to <code>x</code>.
    </li>
</ol>

<h3>🧠 C++ Code</h3>

<pre>
class Solution {
public:
    int mySqrt(int x) {
        if (x &lt; 2)
            return x;

        long long left = 1;
        long long right = x / 2;

        while (left &lt;= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid &lt; x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    }
};
</pre>

<h3>⏱️ Time Complexity</h3>

<p>
    <strong>O(log x)</strong>
</p>

<p>
    Binary Search divides the search space into half in every iteration.
    Therefore, the number of iterations is logarithmic with respect to
    <code>x</code>.
</p>

<h3>💾 Space Complexity</h3>

<p>
    <strong>O(1)</strong>
</p>

<p>
    We only use a few variables such as <code>left</code>, <code>right</code>,
    and <code>mid</code>. No additional data structure is required.
</p>

<br>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square root of 4 is 2, so we return 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = 8
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square root of 8 is 2.82842..., and since we
round it down to the nearest integer, 2 is returned.
</pre>

<br>

<p><strong>Constraints:</strong></p>

<ul>
    <li>
        <code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code>
    </li>
</ul>

<hr>

<h3>🎯 Quick Revision</h3>

<table border="1" cellpadding="8">
    <tr>
        <th>Topic</th>
        <th>Answer</th>
    </tr>
    <tr>
        <td>Technique</td>
        <td>Binary Search</td>
    </tr>
    <tr>
        <td>Goal</td>
        <td>Find largest integer whose square ≤ x</td>
    </tr>
    <tr>
        <td>Time Complexity</td>
        <td>O(log x)</td>
    </tr>
    <tr>
        <td>Space Complexity</td>
        <td>O(1)</td>
    </tr>
</table>
