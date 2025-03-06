#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class ValidateString 
{
private:
    string text;  

public:
    ValidateString(string t) : text(t) {}
    
    bool validator() const 
	{
        for (size_t i = 0; i < text.length(); i++) 
		{ 
            if (!isalpha(text[i]) && text[i] != ' ') 
			{  
                return false;
            }
        }
        return true;
    }
};

int main() 
{
    ValidateString n1("Baqar Laghari");

    if(n1.validator() == 1)
    cout << "Valid: ";
    else
    cout << "Invalid: ";
    
    cout << "Baqar Laghari";
    

    return 0;
}

