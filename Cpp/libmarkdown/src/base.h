// 定义 Markdown 的一些符号的标记
#pragma once
enum MD_TOKEN {
	HEADER1 = 0, HEADER2, HEADER3, HEADER4, HEADER5, HEADER6,
	UNORDERED_LIST, ORDERED_LIST,//- NUM.
	DELIMITER,//分割线---
	IMAGE_IDENTIFIER,//!,用于图片URL定界
	TEXT_LEFT, TEXT_RIGHT,//[ ]
	URI_LEFT, URI_RIGHT,//( )
	QUTOE,//>
	CODE,// ```
	LATEX,//Latex 代码
	ITALIC,//*
	BOLD,//**
	ITALIC_BOLD,//***
	TABLE_ITEM,//表的单元格
	TABLE_COLUMN_LEFT, TABLE_COLUMN_CENTER, TABLE_COLUMN_RIGHT,//表头 左对齐、右对齐、剧中
	DATA,//各种数据
	BEGIN,//Markdown的开头标记
	HTML,//HTML标记
	NEWLINE,//换行
	EMPTY//一开始的循环
};
// 标记 Markdown 是内嵌套显示还是独占一行
enum MD_ITEM {
	LINE,
	NESTED
};