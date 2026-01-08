#pragma once

#ifdef SEASTARS_PLATFORM_WINDOWS

extern SeaStars::ApplicationSeaStars* SeaStars::CreateApplicationSeaStars();
	//
int main(int argc, char** argv) {
	auto seastarssandbox = SeaStars::CreateApplicationSeaStars();
	seastarssandbox->Run();
	delete seastarssandbox;
}

#endif // 
