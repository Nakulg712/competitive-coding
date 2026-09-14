<h2>
    <a href="https://leetcode.com/problems/largest-rectangle-in-histogram">
        84. Largest Rectangle in Histogram
    </a>
</h2>

<h3>Hard</h3>

<hr>

<p>
    Given an array of integers <code>heights</code> representing the histogram's
    bar height where the width of each bar is <code>1</code>, return the area
    of the largest rectangle in the histogram.
</p>

<p>
    A histogram is a graphical representation of the heights of bars where
    each bar has a width of <code>1</code>.
</p>

<br>

<h3>💡 Intuition</h3>

<p>
    For every bar, we want to know how far that bar can extend to the
    <strong>left and right</strong> while keeping its height.
</p>

<p>
    The area of a rectangle is:
</p>

<pre>
Area = Height × Width
</pre>

<p>
    Suppose we have:
</p>

<pre>
heights = [2, 1, 5, 6, 2, 3]
</pre>

<p>
    The bars with heights <code>5</code> and <code>6</code> can form a rectangle
    of height <code>5</code> and width <code>2</code>.
</p>

<pre>
Area = 5 × 2 = 10
</pre>

<p>
    The challenge is efficiently finding the width for every bar.
</p>

<p>
    We use a <strong>Monotonic Increasing Stack</strong>.
    The stack stores indices of bars whose heights are in increasing order.
</p>

<p>
    When we find a smaller bar, it means that the taller bars in the stack
    can no longer extend to the right. We can then calculate their maximum
    possible rectangle.
</p>

<h3>🔹 Approach</h3>

<ol>
    <li>
        Create a stack to store the <strong>indices</strong> of bars.
    </li>

    <li>
        Maintain the stack in <strong>increasing order of heights</strong>.
    </li>

    <li>
        Traverse through the histogram.
    </li>

    <li>
        If the current bar is taller than or equal to the bar at the top
        of the stack, push its index into the stack.
    </li>

    <li>
        If the current bar is smaller, pop bars from the stack because
        those bars cannot extend any further to the right.
    </li>

    <li>
        For every popped bar:
        <ul>
            <li>
                Its height is <code>heights[stack.top()]</code> before popping.
            </li>
            <li>
                The current index gives the first smaller bar on the right.
            </li>
            <li>
                The new stack top gives the first smaller bar on the left.
            </li>
        </ul>
    </li>

    <li>
        Calculate the width:
        <pre>
width = currentIndex - stack.top() - 1
        </pre>
    </li>

    <li>
        Calculate:
        <pre>
area = height × width
        </pre>
        and update the maximum area.
    </li>

    <li>
        Finally, add a virtual bar of height <code>0</code> at the end.
        This forces all remaining bars in the stack to be processed.
    </li>
</ol>

<h3>🧠 C++ Code</h3>

<pre>
class Solution {
public:
    int largestRectangleArea(vector&lt;int&gt;&amp; heights) {
        stack&lt;int&gt; st;
        int maxArea = 0;

        for (int i = 0; i &lt;= heights.size(); i++) {

            int currentHeight;

            if (i == heights.size())
                currentHeight = 0;
            else
                currentHeight = heights[i];

            while (!st.empty() &amp;&amp; currentHeight &lt; heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                int area = height * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};
</pre>

<h3>⏱️ Time Complexity</h3>

<p>
    <strong>O(n)</strong>
</p>

<p>
    Every bar index is pushed into the stack once and popped from the stack
    at most once.
</p>

<p>
    Therefore, even though there is a <code>while</code> loop inside the
    <code>for</code> loop, the total number of stack operations is
    <strong>O(n)</strong>.
</p>

<h3>💾 Space Complexity</h3>

<p>
    <strong>O(n)</strong>
</p>

<p>
    In the worst case, all the bar indices can be stored in the stack.
</p>

<br>

<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong>
heights = [2,1,5,6,2,3]

<strong>Output:</strong>
10

<strong>Explanation:</strong>
The largest rectangle has height 5 and width 2.

Area = 5 × 2 = 10
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong>
heights = [2,4]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
The largest rectangle has height 2 and width 2.

Area = 2 × 2 = 4
</pre>

<br>

<p><strong>Constraints:</strong></p>

<ul>
    <li>
        <code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code>
    </li>
    <li>
        <code>0 &lt;= heights[i] &lt;= 10<sup>4</sup></code>
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
        <td>Monotonic Increasing Stack</td>
    </tr>

    <tr>
        <td>Goal</td>
        <td>Find the maximum rectangle area</td>
    </tr>

    <tr>
        <td>Formula</td>
        <td>Area = Height × Width</td>
    </tr>

    <tr>
        <td>Stack Stores</td>
        <td>Indices of increasing-height bars</td>
    </tr>

    <tr>
        <td>Time Complexity</td>
        <td>O(n)</td>
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
        "Use a monotonic increasing stack to find how far each bar can extend
        left and right, then calculate Height × Width for every bar."
    </strong>
</p>
