#ifndef NVX_MESCAL_HPP_89301
#define NVX_MESCAL_HPP_89301

#include <codecvt>
#include <string>





namespace nvx
{





inline int hex2dec(char ch)
{
	return
		ch >= '0' && ch <= '9' ? ch - '0' :
		ch >= 'a' && ch <= 'z' ? 10 + ch - 'a' :
		ch >= 'A' && ch <= 'Z' ? 10 + ch - 'A' : -1;
}

inline std::wstring stows(std::string const &s)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(s.data());
}

template<typename T>
T const &choice(std::vector<std::pair<double, T>> const &map)
{
	double sum = 0.0;
	for(auto b = map.begin(), e = map.end(); b != e; ++b)
		sum += b->first;

	double ch = nvx::urdisD(0.0, sum)(dre) - 0.000000001;

	for(auto b = map.begin(), e = map.end(); b != e; ++b)
	{
		if(ch < b->first)
			return b->second;
		ch -= b->first;
	}

	throw "choice out of range";
}





}





#endif // NVX_MESCAL_HPP_89301
