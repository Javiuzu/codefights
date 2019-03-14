/**
*Note: Write a solution that only iterates over the string once and uses O(1) additional memory, 
*since this is what you would be asked to do during a real interview.
*Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. 
*If there is no such character, return '_'.
**/

char firstNotRepeatingCharacter(std::string s) {
    std::vector<int> charindex(26, -1); //The size equals the number of English letters in the alphabet
    for(int i = 0; i < s.size(); ++i){
        if (charindex[s[i]-97] == -1) charindex[s[i]-97] = i; //-1 represents that we haven't found the letter yet
        else charindex[s[i] -97] = s.size(); // s.size represents that the letter is repeated
    }
    //We need to now traverse the index array O(26) = 0(1) and O(n)+O(1) = O(n)
    int minimum_index = s.size();
    for (int j = 0; j < 26; ++j) {
        if(charindex[j] >= 0 && charindex[j] < s.size()) 
            if (charindex[j] < minimum_index) minimum_index = charindex[j];
    }
    if (minimum_index == s.size()) return '_';
    else return s[minimum_index];
}
