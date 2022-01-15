#include "main_headers.h"

int main() {

    testCheckBalanceBrackets();
    std::string in = "(8+2*5)/(1+3*2-4)";
    std::string out = "";
    getPostfixFromInfix(in, out);
    std::cout << out << "\n";
    std::cout << "\nbegin form" << in
    << "\npostfix form: " << out
    << "\nresult: " << evaluatePostfix(out) << "\n";
    return 0;
}

bool checkBalanceBrackets(const char *text, int maxDeep) {
    StackArray<char> sequence(maxDeep);
    for (int i = 0; *(text + i) != '\0'; ++i) {
        if (*(text + i) == '(' || *(text + i) == '{' || *(text + i) == '[') {
            if (sequence.isFull()) {
                std::cout << "stackoverflow\n";
                return false;
            }
            sequence.push(*(text + i));
        } else if (*(text + i) == ')' || *(text + i) == '}' || *(text + i) == ']') {
            if (sequence.isEmpty()) {
                return false;
            }
            char deleted = sequence.pop();
            if (deleted == '(' && *(text + i) != ')') {
                return false;
            } else if (deleted == '[' && *(text + i) != ']') {
                return false;
            } else if (deleted == '{' && *(text+i) != '}'){
                return false;
            }
        }
    }
    return sequence.isEmpty();
}

bool checkBalanceBrackets(std::string text, int maxDeep) {
    StackArray<char> sequence(maxDeep);
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '(' || text[i] == '{' || text[i] == '[') {
            if (sequence.isFull()) {
                std::cout << "stackoverflow\n";
                return false;
            }
            sequence.push(text[i]);
        } else if (text[i] == ')' || text[i] == '}' || text[i] == ']') {
            if (sequence.isEmpty()) {
                return false;
            }
            char deleted = sequence.pop();
            if (deleted == '(' && text[i] != ')') {
                return false;
            } else if (deleted == '[' && text[i] != ']') {
                return false;
            } else if (deleted == '{' && text[i] != '}'){
                return false;
            }
        }
    }
    return sequence.isEmpty();
}
bool testCheckBalanceBrackets ()
{
    const char* text00 = " ok ";
    std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << "\n";
    const char* text01 = "( ) ok ";
    std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << "\n";
    const char* text02 = "( ( [] ) ) ok ";
    std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << "\n";
    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << "\n";
    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << "\n";
    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << "\n";
    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << "\n";
    return true;
}

 bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
    StackArray<char> stack;
    std::string temp;
    size_t j = 0,
        flag = 0,
        top = 0;

    for (size_t i = 0; i <= infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            top = stack.getTop();
            stack.push(infix[i]);
            continue;
        }
        if (infix[i] == '+' || infix[i] == '-')
        {
            postfix += ' ';
            stack.push(infix[i]);
            continue;
        }
        if (infix[i] == '*' || infix[i] == '/')
        {
            postfix += ' ';
            stack.push(infix[i]);
            flag = 1;
            continue;
        }
        if (infix[i] == ')')
        {
            for (;stack.getTop() > 0 ; j++)
            {
                temp += stack.pop();
                top = 0;
                if (temp[j] != '(')
                {
                    postfix += temp[j];
                }
            }
            continue;
        }
        if (i == infix.length())
        {
            while (stack.getTop() > 0)
            {
                postfix += stack.pop();
            }
        }
        if (flag == 0)
        {
            postfix += infix[i];
        }
        else
        {
            postfix += infix[i];
            while (stack.getTop() > top && flag == 1)
            {
                temp += stack.pop();
                if (temp[j] != '(')
                {
                    postfix += temp[j];
                }
                else
                {
                    flag = 0;
                    j++;
                    continue;
                }
                j++;
            }
            flag = 0;
        }
    }
    return true;
}


int evaluatePostfix (const std::string& postfix, size_t stackSize)
{
    StackArray<int> stackArray(stackSize);
    std::string src;
    int a = 0, b = 0, c = 0, temp = 0;

    for (int i = 0; i < (postfix.length() - 1); i++)
    {
        if(postfix[i] == ' ')
        {
            continue;
        }
        if(postfix[i] == '+')
        {
            a = stackArray.pop();
            b = stackArray.pop();
            temp = a + b;
            stackArray.push(temp);
            continue;
        }
        if(postfix[i] == '-')
        {
            a = stackArray.pop();
            b = stackArray.pop();
            temp = b - a;
            stackArray.push(temp);
            continue;
        }
        if(postfix[i] == '*')
        {
            a = stackArray.pop();
            b = stackArray.pop();
            temp = a * b;
            stackArray.push(temp);
            continue;
        }
        if(postfix[i] == '/')
        {
            a = stackArray.pop();
            b = stackArray.pop();
            temp = b/a;
            stackArray.push(temp);
            continue;
        }
        if((postfix[i+1] - '0') > 0 && (postfix[i+1] - '0') < 10)
        {
            c = (c + (postfix[i] - '0')) * 10;
        }
        else
        {
            if(c > 0)
            {
                c = c + (postfix[i] - '0');
                stackArray.push(c);
                c = 0;
            }
            else
            {
                stackArray.push(postfix[i] - '0');
            }
        }
    }
    int result;
    result = stackArray.pop();

    return result;
}