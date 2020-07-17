DELETE.TOOLBAR
==============

Equivalent to clicking the Delete button in the Toolbars dialog box,
which appears when you click the Customize command (View menu, Toolbars
submenu). Deletes a custom toolbar.

**Syntax**

**DELETE.TOOLBAR**(**bar\_name**)

Bar\_name    specifies the name of the toolbar that you want to delete.
For detailed information about bar\_name, see ADD.TOOL.

**Remarks**

-   You cannot delete built-in toolbars.

-   If DELETE.TOOLBAR successfully deletes the toolbar, it returns TRUE.
    > If you try to delete a built-in toolbar, DELETE.TOOLBAR returns
    > the \#VALUE! error value, interrupts the macro, and takes no other
    > action.

>  

**Related Functions**

ADD.TOOL   Adds or more buttons to a toolbar

ADD.TOOLBAR   Creates a new toolbar with the specified buttons

RESET.TOOLBAR   Resets a built-in toolbar to its initial default setting

Return to [top](#A)

DEMOTE