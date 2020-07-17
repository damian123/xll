OPTIONS.CHART
=============

Equivalent to clicking the Options command on the Tools menu and then
clicking the Chart Tab in the Options dialog box when a chart is
activated for editing. Sets various chart settings.

**Syntax**

**OPTIONS.CHART**(Display\_Blanks, Plot\_Visible, Size\_With\_Window)

**OPTIONS.CHART**?( Display\_Blanks, Plot\_Visible, Size\_With\_Window)

Display\_Blanks    is a number indicating how blank cells are plotted.

  ------------ ------------------------------
  **Number**   **Blanks are displayed as**
  1            Not plotted (gaps are shown)
  2            Zero values
  3            Interpolated
  ------------ ------------------------------

Plot\_Visible    is a logical value that if TRUE plots only visible
data. If FALSE, all cells in the selection are plotted.

Size\_With\_Window    is a logical value that if TRUE allows the chart
to resize with window. If FALSE, chart will not size with window.

**Remarks**

If any of the arguments are omitted, then that setting is unchanged
within the Options dialog box.

**Related Functions**

PREFERRED   Changes the format of the active chart

SET.PREFERRED   Changes the default chart format

Return to [top](#H)

OPTIONS.EDIT