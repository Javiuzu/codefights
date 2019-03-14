/**
*Given an array a that contains only numbers in the range from 1 to a.length, 
*find the first duplicate number for which the second occurrence
*has the minimal index. In other words, if there are more 
*than 1 duplicated numbers, return the number for which the second occurrence 
*has a smaller index than the second occurrence of the other number does. If there are no such elements, return -1
**/


int firstDuplicate(std::vector<int> a) {
    std::vector<int> num_count(a.size(), 1);
    for (int i = 0; i < a.size(); ++i) {
        if(num_count[a[i]-1] == 0) return a[i];
        --num_count[a[i]-1];
    }
    return -1;
}

/**
*This solution has a logarithmic cost of O(n) on n is the size of a. 
*On memory it needs also O(n) numbers. 
**/
