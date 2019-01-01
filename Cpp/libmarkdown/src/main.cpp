#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include "lex_parser.h"
#include "genCode.h"
int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        std::wcout << L"Usage: " << argv[0] << L" <infile> <outfile>\n";
        return 1;
    }
    // read file
    std::ifstream in_stream;
    in_stream.open(argv[1]);
    // convert stream into string
    if (in_stream.fail()) {
		std::wstringstream ss;
		std::wcerr << L"Fail to load \"" << argv[1] << L"\"." << std::endl;
		return 1;
	}
	// UTF-8 decode
	std::istreambuf_iterator<char> begin(in_stream), end;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
	std::wstring str;
	try {
		std::string bytes(begin, end);
		str = cvt.from_bytes(bytes);
	}
	catch (std::range_error re) {
		std::wcerr << L"Can only open UTF-8 file!" << std::endl;
		return 1;
	}
    // parse
    std::wostringstream wos;

    auto &&scanned = scanner(str);
   
	parse_fromlex(wos, std::begin(scanned), std::end(scanned));

    // output to file
	std::ofstream f(argv[2]);
	
	f << "<!DOCTYPE><head><meta charset=\"utf-8\"/><style>";
	f << "</style><head><body><main>";
	
	f << cvt.to_bytes(wos.str());
	f << "</main><center><small>Created by <a href=\"https:/" \
	"/github.com/mooction/MyNotePad\">MyNotePad</a>.</small></center><script src=\"https:/"\
	"/cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=default\" type=\""\
	"text/javascript\"></script><script type=\"text/x-mathjax-config;executed=true\">"\
	"MathJax.Hub.Config({\n"\
	"  TeX: {equationNumbers: { autoNumber: \"AMS\" } },\n"\
	"  tex2jax: {inlineMath: [['$','$'], ['\\\\(','\\\\)']]}\n"\
	"});</script></body>";
	f.close();
    return 0;
}
