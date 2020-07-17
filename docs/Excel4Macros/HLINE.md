HLINE
=====

Scrolls through the active window by a specific number of columns.
Returns the \#VALUE! error value if the active sheet is a chart.

**Syntax**

**HLINE**(**num\_columns**)

Num\_columns    is the number of columns in the active worksheet or
macro sheet you want to scroll through horizontally.

-   If num\_columns is positive, HLINE scrolls to the right.

-   If num\_columns is negative, HLINE scrolls to the left.

-   Num\_columns must be between -256 and 256, inclusive.

>  

**Example**

The following function scrolls the active window by one-half window to
the right:

HLINE(GET.WINDOW(15)/2)

**Related Functions**

HPAGE   Horizontally scrolls through the active window one window at a
time

HSCROLL   Horizontally scrolls through a sheet by percentage or by
column number

VLINE   Vertically scrolls through the active window by rows

VPAGE   Vertically scrolls through the active window one window at a
time

VSCROLL   Vertically scrolls through a sheet by percentage or by row
number

Return to [top](#H)

HPAGE