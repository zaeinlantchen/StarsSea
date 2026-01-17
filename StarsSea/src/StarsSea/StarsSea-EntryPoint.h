#pragma once

#ifdef STARSSEAPLATFORMWINDOWS

extern StarsSea::ApplicationStarsSea* StarsSea::CreateApplication();
	//
int main(int argc, char** argv) {

	StarsSea::Log::Init();
	STARSEACOREWARN("初始化日志!");

	STARSEAINFO("星海，启动!");

	auto starsseasandbox = StarsSea::CreateApplication();
	starsseasandbox->Run();
	delete starsseasandbox;
}

#endif //
