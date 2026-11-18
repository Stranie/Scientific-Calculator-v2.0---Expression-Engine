#pragma once
#include "Token.h"
#include <vector>
#include <string>
#include <optional>

bool isDigit(char c);
std::optional<std::vector<Token>> Tokenizer(const std::string &input);
std::optional<double> parseNumber(const std::string& input, std::size_t& i);
std::optional<Token> getOperatorToken(char c);