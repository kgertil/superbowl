/********************Text Justification**********************/
/*****************YOU MUST EDIT and SUBMIT THIS FILE*********/


#include "main.h"
//#include "justify.h"
#include <sstream>


bool endsWithPunc(string word)
{
    if (word[word.size() - 1] == ',' || word[word.size() - 1] == '.')
        return true;
    else
        return false;
}
unsigned int justify(unsigned int width, string in, vector<string> & out) {
    
    int i = 0;
    string currentLine;
    string word;
    int carrySize = 0;
    bool currentWord = false;
    int c = 0;
    stringstream ss(in);
    
    //get size of input string
    int size = in.size();
    
    //if size of string is zero
    if (size == 0)
        return ERROR_NO_CHARS;
    //check for boundary conditions
    else if (width >= MIN_COL_WIDTH && width <= MAX_COL_WIDTH)
    {
        while (ss >> word)
        {
            //if it ends with punctuation we can do width + 1
            if (endsWithPunc(word))
            {
                carrySize = 2;
            }
            else
                carrySize = 1;
            
            //insert to line if line is not full
            if((currentLine.size() + word.size() + carrySize) < width)
            {
                if (currentLine.size() != 0)
                    currentLine += " ";
                
                currentLine += word;
            }
            else
            {
                currentLine += " ";
                c = (currentLine.size() + word.size()) % (width + (carrySize - 1));
                
                //to counter for hypon placement
                if (c > 0 && c < word.size())
                {
                    if (endsWithPunc(word))
                        c = c + 2;
                    else
                        c = c + 1;
                }
                else if (c != word.size())
                    c = 0;
                
                for (int j = 0; j < word.size() - c; j++)
                {
                    currentLine += word[j];
                }
                
                //place hyphon
                if (c > 0 && c < word.size())
                    currentLine += '-';
                
                out.push_back(currentLine);
                currentLine = "";
                
                //insert remaining word to new line
                for (int j = word.size() - c; j < word.size(); j++)
                {
                    currentLine += word[j];
                }
            }
            
            i++;
        }
        //add last line
        if (currentLine.size() > 0)
            out.push_back(currentLine);
    }
    else
        return ERROR_ILLEGAL_WIDTH;
    
    return ERROR_NONE;
} // end function justify // end function justify


int main() {
    unsigned int result;
    unsigned int width;
    string input;
    vector<string> output;
    
    while (1) {
        // first clear the output string
        output.clear();
        cout << endl << "Welcome to pretty printing!" << endl << endl;
        cout << "Enter the column width (between " << MIN_COL_WIDTH << " and " << MAX_COL_WIDTH << ", or 0 to exit): ";
        cin >> width;
        if (width == 0)
            break;
        cout << "Enter the string to justify below:" << endl << endl;
        
        // read in the input string
        cin.ignore();
        
        getline(cin, input);
        
        // justify the input for given column width
        result = justify(width, input, output);
        
        switch (result) {
            case ERROR_NONE:
                cout << "The justified string is:" << endl << endl;
                for (unsigned int i = 0; i < output.size(); i++)
                    cout << output[i] << endl;
                break;
            case ERROR_NO_CHARS:
                cout << "ERROR: No characters in input text!" << endl;
                break;
            case ERROR_ILLEGAL_WIDTH:
                cout << "ERROR: Column width out of range!" << endl;
                break;
            default:
                cout << "ERROR: Internal error!" << endl;
                break;
        }
    } // enter interactive loop
}
