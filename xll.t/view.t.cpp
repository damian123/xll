// view.t.cpp - test xll::view
#include <cassert>
#include "../xll/view.h"

using namespace xll;

int test_xll_view()
{
	{
		view<int> v;
		assert(v.buf == nullptr);
		assert(v.len == 0);
		assert(!v);
		view v2{ v };
		assert(v2 == v);
		v = v2;
		assert(!(v != v2));
	}
	{
		view v("abc");
		assert(v.len == 4);
		assert(0 == strcmp(v.buf, "abc"));
	}
	{
		mem_view mv;
		assert(mv.len == 0);
		mv.append("test", 4);
		assert(mv.len == 4);
		assert(0 == strncmp(mv.buf, "test", 4));
	}

	return 1;
}
int test_xll_view_ = test_xll_view();
