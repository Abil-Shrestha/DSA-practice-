class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if(len(digits) == 0):
            return []

        digit2char = {'1': '',     '2': 'abc', '3': 'def',
                      '4': 'ghi',  '5': 'jkl', '6': 'mno',
                      '7': 'pqrs', '8': 'tuv', '9': 'wxyz', '0': ''}

        res = ['']


        for d in digits:
            tem = []
            for c in digit2char[d]:
                tem = tem + [r + c for r in res]

            res = tem

        return res