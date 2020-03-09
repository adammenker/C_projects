// Symbolic Constants
#define DIGITTEST1 "12345abcd67890"

#define DIGITTEST2 "1234567890"

#define LOWERTEST1 "hifromJimRies"

#define LOWERTEST2 "hifromjimries"

#define UPPERTEST1 "JIMRIESWASHERE"

#define UPPERTEST2 "JIMRIESWASHERe"

// Prototypes
void PrintCategory(char *s);

// Main
int main(void)
{
    PrintCategory(DIGITTEST1);

    PrintCategory(DIGITTEST2);

    PrintCategory(LOWERTEST1);

    PrintCategory(LOWERTEST2);

    PrintCategory(UPPERTEST1);

    PrintCategory(UPPERTEST2);
}