PROMOTE
=======

Equivalent to clicking the Ungroup button. Promotes, or ungroups, the
currently selected rows or columns in an outline. Use PROMOTE to change
the configuration of an outline by promoting rows or columns of
information.

**Syntax**

**PROMOTE**(rowcol)

**PROMOTE**?(rowcol)

Rowcol    specifies whether to promote rows or columns.

  -------------- -------------
  **Rowcol**     **Demotes**
  1 or omitted   Rows
  2              Columns
  -------------- -------------

**Remarks**

-   If the selection consists of an entire row or rows, then rows are
    > promoted even if rowcol is 2. Similarly, selection of an entire
    > column overrides rowcol 1.

-   Also, if the selection is unambiguous (an entire row or column),
    > then PROMOTE? will not display the dialog box.

>  

**Related Functions**

DEMOTE   Demotes the selection in an outline

SHOW.DETAIL   Expands or collapses a portion of an outline

SHOW.LEVELS   Displays a specific number of levels of an outline

Return to [top](#H)

PROTECT.DOCUMENT