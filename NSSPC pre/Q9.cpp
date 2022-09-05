#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <vector>
#include <assert.h>

std::string uniqueElementsInFormula(std::string formula)
{
    // check if the formula is valid
    if (formula.size() > 25)
    {
        return "Invalid Length";
    }

    // remove all non-alpha characters
    formula.erase(std::remove_if(formula.begin(), formula.end(), [](char c)
                                 { return !isalpha(c); }),
                  formula.end());

    // what can I say? REGEX YYDS
    std::regex reg("([A-Z][a-z]*)");
    std::smatch match;
    std::string::const_iterator start = formula.begin();
    std::string::const_iterator end = formula.end();

    std::vector<std::string> elements;

    // fetch all the elements in the formula
    while (std::regex_search(start, end, match, reg))
    {
        elements.push_back(match.str());
        start = match.suffix().first;
    }

    // remove all duplicates while mantaining order
    std::vector<std::string> uniqueElements;

    for (auto &element : elements)
    {
        if (std::find(uniqueElements.begin(), uniqueElements.end(), element) == uniqueElements.end())
        {
            uniqueElements.push_back(element);
        }
    }

    // merge all the elements into a string
    std::string result;
    const char *const delim = " ";
    std::ostringstream joined;
    std::copy(uniqueElements.begin(), uniqueElements.end(), std::ostream_iterator<std::string>(joined, delim));
    result = joined.str();

    return joined.str() + "\n" + std::to_string(uniqueElements.size()) + "\n";
}

int main()
{
    assert(uniqueElementsInFormula("NaHCO3") == "Na H C O \n4\n");
    assert(uniqueElementsInFormula("Ni(C2H3O2)2") == "Ni C H O \n4\n");
    assert(uniqueElementsInFormula("CCCCHHHHOOOOOOKNaH2OH2OH2OH2O") == "Invalid Length");
    assert(uniqueElementsInFormula("Al2(SO4)3·16H2O") == "Al S O H \n4\n");
    assert(uniqueElementsInFormula("(Ca4Si2O6(CO3)(OH,F))2") == "Ca Si O C H F \n6\n");
    assert(uniqueElementsInFormula("ZnCH3COOCH3COOH2OH2O") == "Zn C H O \n4\n");
    assert(uniqueElementsInFormula("((Mg,Fe2+)2(Mg,Fe2+)5Si8O22(OH)2)") == "Invalid Length");

    std::string formula;
    std::cin >> formula;
    std::cout << uniqueElementsInFormula(formula);
}