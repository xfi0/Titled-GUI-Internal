#pragma once
namespace SDK{
	class CMaterial2
	{
	public:
		virtual const char* GetName() = 0;
		virtual const char* GetShareName() = 0;
	};
} // namespace SDK