#include <iostream>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

static string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

class encryption{

public:

    encryption() : m_shift(0)
    {}

    encryption(int shift) : m_shift(shift)
    {
        if(m_shift > 26)
        { m_shift = m_shift % 26; }
    }

    char operator()(char c)
    {
        string::iterator letter(alphabet.begin());
        while(*letter != c and letter != alphabet.end())
        { letter+=1; }
        letter += m_shift;
        return *letter;
    }

private:

    int m_shift;
  
};


int main()
{

    string text("TEXTE A CHIFFRER");

    cout << "Shift : ";
    int shift;
    cin >> shift;

    encryption f(shift);
    string::iterator it_text;

    for(it_text = text.begin(); it_text!=text.end(); ++it_text)
    { *it_text = f(*it_text); }

    ostream_iterator<char> show(cout, ", ");
    string::iterator encrypted_letter;

    for(encrypted_letter = text.begin(); encrypted_letter != text.end(); ++encrypted_letter)
    { *show = *encrypted_letter; }

    return 0;
}

