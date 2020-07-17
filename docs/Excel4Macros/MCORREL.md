MCORREL
=======

Returns a correlation matrix that measures the correlation between two
or more data sets that are scaled to be independent of the unit of
measurement.

If this function is not available, you must install the Analysis ToolPak
add-in.

**Syntax**

**MCORREL**(**inprng**, outrng, grouped, labels)

**MCORREL**?(inprng, outrng, grouped, labels)

Inprng    is the input range.

Outrng    is the first cell (the upper-left cell) in the output table or
the name, as text, of a new sheet to contain the output table. If FALSE,
blank, or omitted, places the output table in a new workbook.

Grouped    is a text character that indicates whether the data in the
input range is organized by row or column.

-   If grouped is \"C\" or omitted, then the data is organized by
    > column.

-   If grouped is \"R\", then the data is organized by row.

>  

Labels    is a logical value that describes where the labels are located
in the input range, as shown in the following table:

  ------------------ ------------- ---------------------------------------------------
  **Labels**         **Grouped**   **Labels are in**
  TRUE               \"C\"         First row of the input range.
  TRUE               \"R\"         First column of the input range.
  FALSE or omitted   (ignored)     No labels. All cells in the input range are data.
  ------------------ ------------- ---------------------------------------------------

**Related Function**

MCOVAR   Returns the covariance between two or more data sets

Return to [top](#H)

MCOVAR