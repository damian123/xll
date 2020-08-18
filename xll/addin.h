// addin.h - convenience wrapper for Excel add-ins
// Copyright (c) KALX, LLC. All rights reserved. No warranty made.
#pragma once
#include <map>
#include "args.h"

namespace xll {

    /// <summary>
    /// Store argument add-in data for xlfRegister
    /// </summary>
    template<class X>
	struct XAddIn {
        static inline std::map<XOPER<X>, XArgs<X>> Map;
        XAddIn(const XArgs<X>& args)
        {
            Map[args.FunctionText()] = args;
        }

        // Get arguments using Excel function text name.
        static XArgs<X>& Args(const char* name)
        {
            return Args(XOPER<X>(name));
        }
        static XArgs<X>& Args(const XOPER<X>& name)
        {
            auto i = Map.find(name);
            ensure(i != Map.end());

            return *i;
        }
    };

	using AddIn4 = XAddIn<XLOPER>;
    using AddIn12 = XAddIn<XLOPER12>;
    using AddIn = XAddIn<XLOPERX>;

} // xll namespace


