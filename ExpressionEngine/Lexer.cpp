#include "Lexer.h"
#include <stdexcept>
#include <cctype>

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

std::optional<double> parseNumber(const std::string& input, std::size_t& i) {
	bool hasDecimal = false, hasDigit = false;
	std::string result;
	while (i < input.size() && (isDigit(input[i]) || (input[i] == '.' && hasDecimal == false))) {
		if (input[i] == '.') {
			hasDecimal = true;
		}
		if (isDigit(input[i])) {
			hasDigit = true;
		}
		result += input[i];
		i++;
	}
	if (!hasDigit) {
		return std::nullopt;
	}
	try {
		return std::stod(result);
	}
	catch (const std::out_of_range& e){
		return std::nullopt;
	}
}

std::optional<Token> getOperatorToken(char c) {
	Token result;
	switch (c) {
	case '+':
		result = { TokenType::Plus, std::nullopt };
		break;
	case '-':
		result = { TokenType::Minus, std::nullopt };
		break;
	case '*':
		result = { TokenType::Mult , std::nullopt };
		break;
	case '/':
		result = { TokenType::Div , std::nullopt };
		break;
	case '(':
		result = { TokenType::LPar , std::nullopt };
		break;
	case ')':
		result = { TokenType::RPar , std::nullopt };
		break;
	default:
		return std::nullopt;
	}
	return result;
}

std::optional<std::vector<Token>> Tokenizer(const std::string& input) {
	std::size_t i = 0;
	std::vector<Token> tokens;
	
	while (i < input.size()) {
		if (std::isspace(static_cast<unsigned char>(input[i]))) {
			i++;
			continue;
		}

		if (isDigit(input[i]) || input[i] == '.') {
			auto number = parseNumber(input, i);
			if (!number) {
				return std::nullopt;
			}
			if (i < input.size() && input[i] == '.') {
				return std::nullopt;
			}
			tokens.push_back({ TokenType::Number, *number });
			continue;
		}

		auto op = getOperatorToken(input[i]);
		if (op) {
			tokens.push_back(*op);
			i++;
			continue;
		}
		return std::nullopt;
	}

	if (tokens.empty()) {
		return std::nullopt;
	}

	return tokens;
}

