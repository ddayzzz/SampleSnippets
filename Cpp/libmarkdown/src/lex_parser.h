#pragma once
#include "item.h"
#include <string>
#include <list>
#include <vector>
#include <regex>

static const std::wregex REGEX_LT(std::wregex(L"<"));
static const std::wregex REGEX_GT = std::wregex(L">");

size_t determineData(MD_TOKEN tokenType, const std::wstring &str, size_t start = 0u);

std::wstring parse_inner(const std::wstring &str, size_t begin);

std::wstring mdToHTMLDoc(const std::wstring &str);

size_t getClosedRegion(const std::wstring &str, wchar_t start_ch, wchar_t end_ch,size_t start);

std::wstring trim(const std::wstring &str, size_t start, size_t count);

std::vector<std::wstring> split(const std::wstring &str, const wchar_t delimiter,bool allowSpace=false);

std::list<Item> scanner(const std::wstring &str, bool onlynested=false);