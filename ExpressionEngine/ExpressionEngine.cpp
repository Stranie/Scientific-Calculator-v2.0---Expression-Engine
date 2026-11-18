#include <iostream>
#include <string>
#include "Token.h"
#include "Lexer.h"

int main() {
	std::string input;
	std::getline(std::cin, input);
	auto tokens = Tokenizer(input);

}

