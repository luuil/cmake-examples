#ifndef _HI_HPP_
#define _HI_HPP_

#ifdef WIN32 // windows

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS

#else // *nix

#define DLL_API

#endif // WIN32

class HI
{
public:
	HI() {}
	~HI() {}
	DLL_API void say_hi();
};

#endif // _HI_HPP_