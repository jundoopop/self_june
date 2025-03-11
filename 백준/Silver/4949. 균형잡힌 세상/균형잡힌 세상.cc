#include <iostream>
#include <stack>
#include <string>

// This function checks if the brackets in the input string are balanced
bool isBalanced(const std::string &input)
{

    std::stack<char> brackets; // Stack to collect the brackets in the input string

    // Valid opening and closing brackets
    std::string openingBrackets = "({[";
    std::string closingBrackets = ")}]";

    // Iterate an input value
    for (char ch : input)
    {
        /*
        If the iteration is in one of "(, {, [",
        the character ch would be pushed into the stack
        */
        if (openingBrackets.find(ch) != std::string::npos)
        {
            brackets.push(ch);
        }

        /*
        If the iteration is in one of "), }, ]",
        check if the stack is empty
        or the shape of the opening and closing brackets are matched
        */
        else if (closingBrackets.find(ch) != std::string::npos)
        {
            if (brackets.empty() || openingBrackets.find(brackets.top()) != closingBrackets.find(ch))
            {
                return false;
            }
            // Pop an opened bracket after judging
            brackets.pop();
        }
    }
    return brackets.empty();
}

int main()
{
    std::string input;

    while (true)
    {
        // Get the input values
        std::getline(std::cin, input);
        if (input == ".") // End of the sentence
            break;

        // This statement is for printing the answer if the brackets are balanced.

        if (isBalanced(input))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}
