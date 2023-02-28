var longestPalindrome = function(s) {
    let [start,maxLength] = [0,1]; //start is used to store the initial character of a palindrome in answer and maxLength is length from the start of the palindrome answer
    for(let i = 0 ; i < s.length ; i++) {
        //even case
        let left = i-1; //In even case we just need to compare current character with its previous chgaracter
        let right = i;
        while(left>=0 && right<=s.length-1 && s[left] == s[right]) {
            if((right-left+1)>maxLength) {
                maxLength = (right-left+1);
                start = left;
            }
            left--;
            right++;
        }


        //Odd case
         left = i-1; //for every char of string, we check its left and right and if they are equal we expand it by decreasing its left and increasing its right
         right = i+1;
        while(left>=0 && right<=s.length-1 && s[left] == s[right]) {
            if((right-left+1)>maxLength) {
                maxLength = (right-left+1); //if its a palindrome, its length is calculated by substracting it with right character to its starting charactera and we add 1 bcz we did zero based indexing
                start = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(start,maxLength)
};