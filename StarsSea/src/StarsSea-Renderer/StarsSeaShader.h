#pragma once

namespace StarsSea {
	class STARSSEAAPI StarsSeaShader {
		public:
			StarsSeaShader(const std::string& vertexSrc, const std::string& fragmentSrc);
			~StarsSeaShader();

			void Bind() const;
			void Unbind() const;
		private:
			uint32_t starsseaRendererID;
	};
}