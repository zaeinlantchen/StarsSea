#pragma once

#include "SeaStar-Core.h"

namespace SeaStars{

	class SEASTARS_API ApplicationSeaStars
	{
		public:
		ApplicationSeaStars();
		virtual ~ApplicationSeaStars();

		void Run();

	};
	//这是一个用于创建应用程序实例的函数声明
	ApplicationSeaStars* CreateApplicationSeaStars();

}


