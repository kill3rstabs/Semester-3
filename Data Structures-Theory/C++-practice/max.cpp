#include <iostream>
#include <string>

typedef std::string::const_iterator It;

/*
 * Extract sequences of non-wildcard characters from pattern range
 */
std::string extract_token(It &s, It e) // [s,e) is (sub)pattern
{
    It wcard;
    for (wcard=s; wcard!=e; ++wcard)
        if ('?' == *wcard) break;

    std::string token(s,wcard);

    for (s=wcard; s!=e; ++s)
        if ('?' != *s) break; // treat '??' as '?' in pattern

    return token;
}

/*
 * Match a (sub)pattern against a (sub)input
 *
 * (See "Strategy" above)
 */
bool match(It patb, It pate, const std::string& input)
{
    while (patb != pate)
    {
        // get next token from pattern, advancing patb
        std::string token = extract_token(patb, pate); // updates patb

        if (!token.empty()) // could happen if pattern begins/ends with redundant '?'
        {
            size_t submatch = input.find(token);  // first submatch please

            while (std::string::npos != submatch)  // while we have a submatch
            {
                if (match(patb, pate, input.substr(token.size())))
                    return true; // match completed successfully

                // look for later potential submatches (*backtrack*)
                submatch = input.find(token, submatch+1);
            }
            return false; // required token not found
        }
    }
    return true; // no (remaining) pattern, always match
}

bool match(const std::string& pattern, const std::string& input)
{
    // just relay to overload more suited for recursion
    return match(pattern.begin(), pattern.end(), input); 
}

//////////////////////
// TEST PROGRAM

void test(const std::string& pattern, const std::string& input)
{
    std::cout << std::boolalpha;
    std::cout << "match(\"" << pattern << "\", \"" << input << "\") => " 
              << match(pattern, input) << std::endl;
}

int main()
{
    // matches
    test("?????",               "");
    test("?????",               "?????");
    test("",                    "");
    test("",                    "glorious");
    test("?r?o",                "glorious");
    test("some?words?exist",    "some silly words should, most definitely, be existing");
    test("some??words?exist?",  "some silly words should, most definitely, be existing");

    // failing matches
    test("_",                   "");
    test("_",                   "glorious");
    test("_",                   "glorious");
    test("glorious",            "glo?ious");
    test("?some??words?exist?", "bogus");
}
