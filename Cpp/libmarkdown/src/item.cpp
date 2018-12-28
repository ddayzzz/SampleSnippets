
#include "item.h"
#include <iostream>
#include <string>



Item::Item(const std::wstring &data, MD_TOKEN token, MD_ITEM itemtype, const std::wstring &tag)
	:m_token(token),
	m_mditemtype(itemtype),
	m_tag(tag),m_data(data)
{ 
}


Item::Item(const Item &rhs)
	: m_data(rhs.m_data),
	m_token(rhs.m_token),
	m_mditemtype(rhs.m_mditemtype),
	m_tag(rhs.m_tag)
{ }

std::wostream &Item::operator<<(std::wostream &os) const
{
	os << "<" << m_token << "," << m_data << "," << m_mditemtype << ">";
	return os;
}

void Item::setData(const std::wstring &str)
{
	m_data = str; 
}

const std::wstring &Item::getData() const
{ 
	return m_data;
}

void Item::setToken(MD_TOKEN token)
{
	m_token = token;
}

const MD_TOKEN &Item::getToken() const
{
	return m_token;
}

void Item::setItemType(MD_ITEM itemtype)
{
	m_mditemtype = itemtype;
}

const MD_ITEM &Item::getItemType() const
{
	return m_mditemtype;
}

void Item::setTag(const std::wstring & tag)
{
	m_tag = tag;
}

const std::wstring & Item::getTag() const
{
	return m_tag;
}