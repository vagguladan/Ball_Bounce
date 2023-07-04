#pragma once
#include "CommonInclude.h"
#include <stdlib.h>
#include <time.h>

namespace ya
{

	class Bounce
	{
	public:

		struct Direct
		{
			bool DirectX;
			bool DirectY;
		};


		static void Initailize();
		static void Update();
		static void Render(HDC hdc);
		 

	private:
		    
		static std::vector<Direct> mDriect;
		static std::vector<math::Vector2> mVector2;

	};
}

