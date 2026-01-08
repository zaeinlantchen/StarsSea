#include <StarsSea.h>

#include "StarsSea/StarsSea-EntryPoint.h"

class StarsSeaSandbox : public StarsSea::ApplicationStarsSea
{
public:
	StarsSeaSandbox();
	~StarsSeaSandbox();

private:

};

StarsSeaSandbox::StarsSeaSandbox()
{
}

StarsSeaSandbox::~StarsSeaSandbox()
{
}

StarsSea::ApplicationStarsSea* StarsSea::CreateApplication()
{
	return new StarsSeaSandbox();
}