/*
*A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits, 
*such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

*You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution. 
*The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], 
*which should be interpreted as the word1 + word2 = word3 cryptarithm.
*If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution, 
*becomes a valid arithmetic equation containing no numbers with leading zeroes, 
*the answer is true. If it does not become a valid arithmetic solution, the answer is false.
*Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).
*/
bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    std::vector<int> letterValue(26,0);
    for (int i = 0; i < solution.size(); ++i) {
        letterValue[solution[i][0]-'A'] = solution[i][1] - '0';
    }
    //letterValue will contain the arithmetic value of the letter
    std::vector<int> cryptValue(3,0);
    for (int i = 0; i < 3; ++i) {
        for(int j= 0; j < crypt[i].length(); ++j) {
            int tmp = letterValue[crypt[i][j]-'A'];
            if (j == 0 && tmp == 0 && crypt[i].length() > 1) return false; //Leading character zero
            cryptValue[i] *=10;
            cryptValue[i] += tmp;
            std::cout<<"tmp= " << tmp <<  endl;
        }
    }
    return (cryptValue[0] + cryptValue[1] == cryptValue[2]);
}

//The algorithm cost is O(n + m) where n  is the size of crypt and m the size of solution. In the problem m <= n always, because
//every letter on crypt will be on solution once and only once. So in the end the cost is O(n)
