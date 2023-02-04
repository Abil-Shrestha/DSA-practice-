var lengthOfLongestSubstring = function(s) {
     let currentString = [];
     let longestStringLength = 0;
     for (let i = 0; i < s.length; i++) {
         const currentCharacterPosition = currentString.indexOf(s[i]);
         if (currentCharacterPosition !== -1) {
            // Chop the array off after the occurence of the character
            currentString.splice(0, currentCharacterPosition + 1);
        }
        currentString.push(s[i]);
         longestStringLength = Math.max(
            longestStringLength,
            currentString.length
        );
     }
      return longestStringLength;
};