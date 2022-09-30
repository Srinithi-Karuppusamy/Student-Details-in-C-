
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

enum Identifiers
{
    UPPER,
    LOWER,
    DIGIT,
    EOW,
    EOS,
    IGNORE
};

typedef struct
{
    int upperCase;
    int lowerCase;
    int digit;
    int word;
    int sentence;
    int ignore;
} Counters;

// Function Prototypes
void OpenFile(ifstream &); // This function reads a file specified in the parameter. If the file doesnt exist returns error

Identifiers Decode(char character); // This opens the file and decodes characters and returns the identifiers encounterd

void IncrementCounters(Counters &counters, char character); // This function increments the appropriate counters based on the character in the input

void PrintResults(Counters counters); // Prints the results

void Initialize(Counters counters);

int main()
{
    ifstream text;
    Counters counters;
    char character;
    text.open("sampleFile.txt");
    if (!text)
    {
        cout << "File was not found, exiting" << endl;
        return 1;
    }

    Initialize(counters);

    text.get(character); // get 1 character

    do
    {
        IncrementCounters(counters, character);
        text.get(character);
    } while (text);

    PrintResults(counters);
    text.close();
    return 0;
}

void Initialize(Counters counters)
{
    counters.digit = 0;
    counters.ignore = 0;
    counters.lowerCase = 0;
    counters.upperCase = 0;
    counters.word = 0;
    counters.sentence = 0;
}

// This function examines the character and increments appropriate counter
void IncrementCounters(Counters &counters, char character)
{
    static bool endOfWord = false;

    switch (Decode(character))
    {
    case UPPER:
        counters.upperCase++;
        endOfWord = false;
        break;

    case LOWER:
        counters.lowerCase++;
        endOfWord = false;
        break;

    case DIGIT:
        counters.digit++;
        endOfWord = false;
        break;

    case EOW:
        if (!endOfWord)
        {
            counters.word++;
            endOfWord = true;
        }
        break;

    case EOS:
        counters.sentence++;
        endOfWord = true;
        break;

    case IGNORE:
        counters.ignore++;
        break;
    }
}

Identifiers Decode(char character)
{
    if (isupper(character))
        return UPPER;

    else if (islower(character))
        return LOWER;

    else if (isdigit(character))
        return DIGIT;

    switch (character)
    {
    case '.':
    case '?':
    case '!':
        return EOS;

    case ' ':
    case ':':
    case ';':
        return EOW;

    default:
        return IGNORE;
    }
    return IGNORE;
}

void PrintResults(Counters counter)
{
    cout << "Words : " << counter.word << "\n";
    cout << "sentences : " << counter.sentence << std::endl;
    cout << "lowercase : " << counter.lowerCase << std::endl;
    cout << "uppercase are : " << counter.upperCase << std::endl;
    cout << "digits are : " << counter.digit << std::endl;
    cout << "Average word Length : " << (counter.digit + counter.upperCase + counter.lowerCase) / (counter.word) << endl;
    cout << "Average Sentences Length : " << (counter.word) / (counter.sentence) << endl;
}
