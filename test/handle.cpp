// handle.cpp - Illustrate the use of handles
//#define XLOPERX XLOPER
#include "../xll/xll.h"

using namespace xll;

class base {
	OPERX x;
public:
	base() { }
	base(const OPERX& x) : x(x) { }
	/*
	base(const base&) = default;
	base(base&&) = default;
	base& operator=(const base&) = default;
	base& operator=(base&&) = default;
	*/
	virtual ~base() { }
	OPERX& get() 
	{ 
		return x; 
	}
	base& set(const OPERX& _x)
	{
		x = _x;

		return *this;
	}
};

AddInX xai_base(
	FunctionX(XLL_DOUBLEX, X_("?xll_base"), X_("XLL.BASE"))
	.Args({
		ArgX(XLL_LPOPERX, X_("cell"), X_("is a cell or range of cells"))
	})
	.FunctionHelp(X_("Return a handle to a base object."))
	.Uncalced() // required for functions creating handles
);
HANDLEX WINAPI xll_base(LPOPERX px)
{
#pragma XLLEXPORT
	xll::handle<base> h(new base(*px));

	return h.get();
}

AddInX xai_base_get(
	FunctionX(XLL_LPOPERX, X_("?xll_base_get"), X_("XLL.BASE.GET"))
	.Args({
		ArgX(XLL_HANDLEX, X_("handle"), X_("is a handle returned by XLL.BASE"))
	})
	.FunctionHelp(X_("Return the value stored in base."))
);
LPOPERX WINAPI xll_base_get(HANDLEX _h)
{
#pragma XLLEXPORT
	xll::handle<base> h(_h);

	return h ? &h->get() : (LPOPERX)&ErrNAX;
}

AddInX xai_base_set(
	FunctionX(XLL_HANDLEX, X_("?xll_base_set"), X_("XLL.BASE.SET"))
	.Args({
		ArgX(XLL_HANDLEX, X_("handle"), X_("is a handle returned by XLL.BASE")),
		ArgX(XLL_LPOPERX, X_("cell"), X_("is a cell or range of cells"))
	})
	.FunctionHelp(X_("Set the value of base to cell."))
);
HANDLEX WINAPI xll_base_set(HANDLEX _h, LPOPERX px)
{
#pragma XLLEXPORT
	xll::handle<base> h(_h);

	if (h) {
		h->set(*px);
	}

	return _h;
}

class derived : public base {
	OPERX x2;
public:
	derived(const OPERX x, const OPERX x2)
		: base(x), x2(x2)
	{ }
	OPERX& get2()
	{
		return x2;
	}
};

AddInX xai_derived(
	FunctionX(XLL_DOUBLEX, X_("?xll_derived"), X_("XLL.DERIVED"))
	.Args({
		ArgX(XLL_LPOPERX, X_("cell"), X_("is a cell or range of cells")),
		ArgX(XLL_LPOPERX, X_("cell2"), X_("is a cell or range of cells"))
	})
	.FunctionHelp(X_("Return a handle to a derived object."))
	.Uncalced() // required for functions creating handles
);
HANDLEX WINAPI xll_derived(LPOPERX px, LPOPERX px2)
{
#pragma XLLEXPORT
	// derived isa base
	xll::handle<base> h(new derived(*px, *px2));

	return h.get();
}

// XLL.BASE.GET calls base::get for handles returned by XLL.DERIVED.
AddInX xai_derived_get(
	FunctionX(XLL_LPOPERX, X_("?xll_derived_get"), X_("XLL.DERIVED.GET"))
	.Args({
		ArgX(XLL_HANDLEX, X_("handle"), X_("is a handle returned by XLL.DERIVED"))
	})
	.FunctionHelp(X_("Return the second value stored in derived."))
);
LPOPERX WINAPI xll_derived_get(HANDLEX _h)
{
#pragma XLLEXPORT
	// get handle to base class
	xll::handle<base> h(_h);
	// cast to derived
	derived* pd = dynamic_cast<derived*>(h.ptr());

	return pd ? &pd->get2() : (LPOPERX)&ErrNAX;
}
