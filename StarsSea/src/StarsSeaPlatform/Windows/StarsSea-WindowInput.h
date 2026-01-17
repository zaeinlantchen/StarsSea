#pragma once

#include "../../StarsSea-Input/StarsSea-Input.h"

namespace StarsSea {
	class StarsSeaWindowsInput : public StarsSeaInput
	{
		protected:
			virtual bool IsKeyPressedImpl(int keycode) override;
			virtual bool IsMouseButtonPressedImpl(int button) override;
			virtual std::pair<float, float> GetMousePositionImpl() override;
			virtual float GetMouseXImpl() override;
			virtual float GetMouseYImpl() override;
	};
}