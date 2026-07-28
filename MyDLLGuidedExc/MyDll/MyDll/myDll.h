#pragma once
#ifdef DLL_EXPORT
// ifdef and ifndef are preprocessor directives used for conditional compilation if some macro is defined do an action like printf?
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif
extern "C"
// treat the following code as C code, not C++ code, to avoid name mangling
{
	DECLDIR void Share();
	// DECLDIR is a macro used to import or export function from dll if there is a DLL_EXPORT macro defined, it will export the function, otherwise it will import the function
	void Keep();
	// Keep is a function that is not exported from the dll, it can only be used within the dll
}