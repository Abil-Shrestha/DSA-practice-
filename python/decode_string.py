class Solution:
    def decodeString(self, s: str) -> str:
        word=""
        wordstack = []
        curnum = 0
        for letter in s:
            if letter == '[':
                wordstack.append(word)
                wordstack.append(curnum)
                word = ''
                curnum = 0
            elif letter == ']':
                num = wordstack.pop()
                prevword = wordstack.pop()
                word = prevword + num * word
            elif letter.isdigit():
                curnum = curnum *10 + int(letter)
            else:
                word += letter
        return word