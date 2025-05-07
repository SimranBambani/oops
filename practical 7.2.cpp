#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    int line_count = 0, word_count = 0, ch_count = 0, i;
    string my_string;
    ifstream inputFile("prac_7.2.txt");

    if (inputFile.is_open())
    {
        cout << "Your content in the file: \n";
        while (getline(inputFile, my_string))
        {
            cout << my_string << endl;
            line_count++;

            for (i = 0; i < int(my_string.length()); i++)
            {
                ch_count++;
                if (my_string[i] == ' ' || my_string[i] == '.')
                {
                    word_count++;
                }
            }


            if (!my_string.empty() && my_string.back() != ' ' && my_string.back() != '.')
            {
                word_count++;
            }
        }
        inputFile.close();
    }
    else
    {
        cout << "ERROR: unable to open file!";
    }

    cout << "Characters are: " << ch_count << endl;
    cout << "Words are: " << word_count << endl;
    cout << "Lines are: " << line_count << endl;

    return 0;
}

