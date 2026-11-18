#pragma once
#include<optional>

enum struct TokenType {
	Number,
	Plus,
	Minus,
	Mult,
	Div,
	LPar,
	RPar
};

struct Token {
	TokenType type;
	std::optional<double> value;
};

