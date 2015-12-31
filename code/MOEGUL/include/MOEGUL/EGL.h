//
// Copyright (c) 2015 Yoshiaki JITSUKAWA
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//

#pragma once

#include <functional>
#include <vector>
#include <JAFObj.h>

namespace MOEGUL
{
	namespace EGL
	{
		class ContextIF {
			MAKE_JAFOBJ(ContextIF);
		public:
			typedef std::unique_ptr<ContextIF> Ptr;
			virtual ~ContextIF() { };

			virtual void makeCurrent() = 0;
			virtual void swapBuffers() = 0;

			// Context破棄時に呼ばれるCleanupFunctionを登録する
			virtual void registerCleanupFunction(std::function<void()>) = 0;

		};

		/// 現在CurrentになっているContextを取得する
		ContextIF* getCurrentContext();

		/// CurrentContextにCleanupFunctionを登録する
		bool registerCleanupFunction(std::function<void()>);
	}
	typedef EGL::ContextIF::Ptr EGLContextPtr;

	/// Native window 用のContextを生成する
	EGLContextPtr createNativeEGLContext();
}
