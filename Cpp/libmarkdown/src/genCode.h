#pragma once
#include <iostream>
#include <list>
#include "item.h"
#include "base.h"

std::wostream &parse_fromlex(std::wostream &os, std::list<Item>::iterator beg, std::list<Item>::iterator end);
std::wostream &writeInner(std::wostream &os, const std::wstring &data);
std::wostream &writeAlignTableItem(std::wostream &os, MD_TOKEN table_token);
bool isTableItem(const MD_TOKEN token);