#pragma once
#include <string>
#include "base.h"

class Item {
	MD_TOKEN m_token;
	std::wstring m_data;
	std::wstring m_tag;//自定义的HTML标签属性
	MD_ITEM m_mditemtype;
public:
	Item(const std::wstring &data, MD_TOKEN token, MD_ITEM itemtype, const std::wstring &tag=L"");
	Item(const Item&);
	std::wostream &operator<<(std::wostream &os) const;
	void setData(const std::wstring &str);
	const std::wstring &getData() const;
	void setToken(MD_TOKEN);
	const MD_TOKEN &getToken() const;
	void setItemType(MD_ITEM);
	const MD_ITEM &getItemType() const;
	void setTag(const std::wstring &tag);
	const std::wstring &getTag() const;
};