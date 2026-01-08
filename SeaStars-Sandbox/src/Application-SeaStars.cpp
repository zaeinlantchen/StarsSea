#include <SeaStars.h>

class SeaStarsSandbox : public SeaStars::ApplicationSeaStars
{
public:
	SeaStarsSandbox();
	~SeaStarsSandbox();

private:

};

SeaStarsSandbox::SeaStarsSandbox()
{
}

SeaStarsSandbox::~SeaStarsSandbox()
{
}

SeaStars::ApplicationSeaStars* SeaStars::CreateApplicationSeaStars()
{
	return new SeaStarsSandbox();
}