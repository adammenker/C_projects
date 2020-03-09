
void ToUpperWord(char *string, int n){
    int i = wordindex[n]; // index of word
    if(i != 999){
        while(isalpha(string[i])){
            string[i] = toupper(string[i]);
            i++;
        }
    }
    else if(i == 999){
        printf("**ERROR: The %dth word was not found in string \"%s\"\n", n, string);
    }
}