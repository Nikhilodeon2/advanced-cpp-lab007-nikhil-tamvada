# Recursive Algorithms Laboratory Notes

The recursive implementations use no loops. Their base and recursive cases are
identified in the source. The comparison implementations use iteration where
appropriate.

## Recursive and Iterative Comparison

| Algorithm | Recursive time / extra space | Iterative time / extra space | Calls and recursion depth |
| --- | --- | --- | --- |
| Factorial | O(n) / O(n) | O(n) / O(1) | The recursive version makes O(n) calls with depth O(n). |
| Fibonacci | O(n) / O(n) | O(n) / O(1) | Memoization limits the recursive version to O(n) calls and O(n) depth; the iterative version stores only two terms. |
| Binary search | O(log n) / O(log n) | O(log n) / O(1) | The recursive version makes O(log n) calls with depth O(log n); each step halves the search range. |
| Array sum | O(n) / O(n) | O(n) / O(1) | Both process n elements; the recursive version makes O(n) calls with depth O(n). |
| Array reversal | O(n) / O(n) | O(n) / O(1) | Both perform O(n) swaps; the recursive version has O(n) call depth. |

The recursive forms express naturally self-similar definitions and can be easy
to follow when each smaller subproblem is apparent. They also use call-stack
space, add function-call overhead, and can overflow the stack for large inputs
(especially a long array sum or reversal). Iterative forms generally use
constant auxiliary space, avoid stack-overflow risk, and are often preferable
for production code where large input sizes are possible. Binary search is a
notable case where recursion depth is logarithmic rather than linear.

Fibonacci is memoized in its recursive form to avoid the exponential repeated
work of the naive recurrence while retaining the recursive relationship. Its
iterative counterpart is simpler in space and also runs in linear time. The
integer-returning factorial and Fibonacci functions reject negative inputs and
throw `std::overflow_error` when the result would exceed `int`; array sums also
report an out-of-range result rather than overflowing.
