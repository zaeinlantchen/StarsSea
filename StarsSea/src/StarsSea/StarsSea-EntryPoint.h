#pragma once

#ifdef STARSSEAPLATFORMWINDOWS

extern StarsSea::ApplicationStarsSea* StarsSea::CreateApplication();
	//
int main(int argc, char** argv) {

	StarsSea::Log::Init();

	STARSEACOREWARN("Initialized Log!");
	STARSEAINFO("Hello from App!");

	auto starsseasandbox = StarsSea::CreateApplication();
	starsseasandbox->Run();
	delete starsseasandbox;
}

#endif // 
