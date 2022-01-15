//
// Created by user.v2.0 on 18.02.2021.
//
#pragma once
#ifndef STACK_MAIN_HEADERS_H
#define STACK_MAIN_HEADERS_H
#include <iostream>
#include "stackArray.h"
bool checkBalanceBrackets (const char* text, int maxDeep = 30);
bool checkBalanceBrackets (std::string text, int maxDeep = 30);
bool testCheckBalanceBrackets ();
int evaluatePostfix (const std::string& postfix, size_t stackSize = 100);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 100);
#endif //STACK_MAIN_HEADERS_H
